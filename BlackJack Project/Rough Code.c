#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

int deck[416];
int deckSize = 0;
int dealtCount = 0;

int playerHand[30];
int dealerHand[30];
int playerCount = 0;
int dealerCount = 0;

double playerFunds = 500.00;
int currentBet = 0;

void initializeDeck(int numDecks);
int drawCard(void);
int cardValue(int card);
int handTotal(int hand[], int count);
int isBlackjack(int hand[], int count);
void cardName(int card, char name[]);
void displayBothHands(int hideDealerSecond);
void declareWinner(int playerTotal, int dealerTotal, int playerBusted, int dealerBusted);
void playWinTune(void);
void playLossTune(void);
void playBeethovenFive(void);
void playPushTune(void);
void flushInput(void);

int main(void)
{
    int numDecks;
    int playerBusted;
    int dealerBusted;
    int playerTotal;
    int dealerTotal;
    int cardsLeft;

    char again = 'Y';
    char choice;
    char reshuffleChoice;
    char drawnCard[20];

    srand((unsigned int)time(NULL));

    printf("Welcome to Blackjack\n");

    do {
        printf("Choose number of decks to use (1-8): ");
        scanf("%d", &numDecks);
        flushInput();

        if (numDecks < 1 || numDecks > 8) {
            printf("Invalid input. Enter 1 to 8.\n");
        }

    } while (numDecks < 1 || numDecks > 8);

    initializeDeck(numDecks);
    playBeethovenFive();

    while ((again == 'Y' || again == 'y') && playerFunds > 0) {

        cardsLeft = deckSize - dealtCount;
        if (cardsLeft < 10) {
            printf("\nNot enough cards left to start a new round.\n");
            initializeDeck(numDecks);
            printf("Deck reshuffled.\n");
        }

        playerBusted = 0;
        dealerBusted = 0;
        playerCount = 0;
        dealerCount = 0;

        printf("\n----------------------------------------\n");
        printf("Current balance: $%.2f\n", playerFunds);

        do {
            printf("Enter your bet: $");
            scanf("%d", &currentBet);
            flushInput();

            if (currentBet <= 0 || currentBet > playerFunds) {
                printf("Invalid bet. Enter a value from 1 to %.0f.\n", playerFunds);
            }

        } while (currentBet <= 0 || currentBet > playerFunds);

        playerHand[playerCount++] = drawCard();
        dealerHand[dealerCount++] = drawCard();
        playerHand[playerCount++] = drawCard();
        dealerHand[dealerCount++] = drawCard();

        displayBothHands(1);
        printf("\nYour total: %d\n", handTotal(playerHand, playerCount));

        if (isBlackjack(playerHand, playerCount)) {
            printf("\nBLACKJACK!\n");
            displayBothHands(0);

            if (isBlackjack(dealerHand, dealerCount)) {
                printf("\nDealer also has Blackjack. Push.\n");
            } else {
                playerFunds = playerFunds + (currentBet * 1.5);
                printf("\nYou win $%.2f!\n", currentBet * 1.5);
                playWinTune();
            }
        } else {

            while (1) {
                playerTotal = handTotal(playerHand, playerCount);

                displayBothHands(1);
                printf("\nYour total: %d\n", playerTotal);

                if (playerTotal == 21) {
                    printf("You reached 21. Standing automatically.\n");
                    break;
                }

                printf("(H)it or (S)tand? ");
                scanf(" %c", &choice);
                flushInput();

                if (choice == 'H' || choice == 'h') {
                    playerHand[playerCount++] = drawCard();
                    cardName(playerHand[playerCount - 1], drawnCard);
                    printf("You drew: %s\n", drawnCard);

                    playerTotal = handTotal(playerHand, playerCount);

                    if (playerTotal > 21) {
                        displayBothHands(1);
                        printf("\nYou busted with %d!\n", playerTotal);
                        playerBusted = 1;
                        break;
                    }
                } else if (choice == 'S' || choice == 's') {
                    printf("You stand at %d.\n", playerTotal);
                    break;
                } else {
                    printf("Invalid choice. Enter H or S.\n");
                }
            }

            if (!playerBusted) {
                printf("\nDealer's turn:\n");
                displayBothHands(0);
                printf("\nDealer total: %d\n", handTotal(dealerHand, dealerCount));

                while (handTotal(dealerHand, dealerCount) < 17) {
                    dealerHand[dealerCount++] = drawCard();
                    cardName(dealerHand[dealerCount - 1], drawnCard);
                    printf("Dealer draws: %s\n", drawnCard);

                    displayBothHands(0);
                    printf("\nDealer total: %d\n", handTotal(dealerHand, dealerCount));
                }

                dealerTotal = handTotal(dealerHand, dealerCount);

                if (dealerTotal > 21) {
                    printf("Dealer busted!\n");
                    dealerBusted = 1;
                } else {
                    printf("Dealer stands at %d.\n", dealerTotal);
                }
            }

            playerTotal = handTotal(playerHand, playerCount);
            dealerTotal = handTotal(dealerHand, dealerCount);

            printf("\nFinal results:\n");
            displayBothHands(0);
            printf("\nYour total: %d\n", playerTotal);

            if (!dealerBusted) {
                printf("Dealer total: %d\n", dealerTotal);
            }

            declareWinner(playerTotal, dealerTotal, playerBusted, dealerBusted);
        }

        printf("Balance now: $%.2f\n", playerFunds);

        printf("\nWould you like to reshuffle the deck? (Y/N): ");
		scanf(" %c", &reshuffleChoice);
		flushInput();

		if (reshuffleChoice == 'Y' || reshuffleChoice == 'y') {
    	initializeDeck(numDecks);
    	printf("Deck reshuffled.\n");
}
        if (playerFunds <= 0) {
            printf("\nYou are out of money. Game over.\n");
            break;
        }

        printf("\nPlay another round? (Y/N): ");
        scanf(" %c", &again);
        flushInput();
    }

    printf("\nThanks for playing.\n");
    printf("Final balance: $%.2f\n", playerFunds);

    return 0;
}

void initializeDeck(int numDecks)
{
    int i;
    int j;
    int r;
    int temp;

    deckSize = numDecks * 52;
    dealtCount = 0;

    for (i = 0; i < deckSize; i++) {
        deck[i] = (i % 13) + 1;
    }

    for (j = deckSize - 1; j > 0; j--) {
        r = rand() % (j + 1);

        temp = deck[j];
        deck[j] = deck[r];
        deck[r] = temp;
    }
}

int drawCard(void)
{
    if (dealtCount >= deckSize) {
        return -1;
    }

    return deck[dealtCount++];
}

int cardValue(int card)
{
    if (card == 1) {
        return 11;
    }

    if (card >= 10) {
        return 10;
    }

    return card;
}

int handTotal(int hand[], int count)
{
    int i;
    int total = 0;
    int aceCount = 0;

    for (i = 0; i < count; i++) {
        total = total + cardValue(hand[i]);

        if (hand[i] == 1) {
            aceCount++;
        }
    }

    while (total > 21 && aceCount > 0) {
        total = total - 10;
        aceCount--;
    }

    return total;
}

int isBlackjack(int hand[], int count)
{
    if (count != 2) {
        return 0;
    }

    if ((hand[0] == 1 && hand[1] >= 10) || (hand[1] == 1 && hand[0] >= 10)) {
        return 1;
    }

    return 0;
}

void cardName(int card, char name[])
{
    if (card == 1) {
        sprintf(name, "Ace");
    } else if (card == 11) {
        sprintf(name, "Jack");
    } else if (card == 12) {
        sprintf(name, "Queen");
    } else if (card == 13) {
        sprintf(name, "King");
    } else {
        sprintf(name, "%d", card);
    }
}

void displayBothHands(int hideDealerSecond)
{
    int i;
    int maxCount;
    char playerCard[20];
    char dealerCard[20];

    if (playerCount > dealerCount) {
        maxCount = playerCount;
    } else {
        maxCount = dealerCount;
    }

    printf("\n%-20s %-20s\n", "Your hand:", "Dealer's hand:");

    for (i = 0; i < maxCount; i++) {

        if (i < playerCount) {
            cardName(playerHand[i], playerCard);
        } else {
            sprintf(playerCard, "");
        }

        if (i < dealerCount) {
            if (i == 1 && hideDealerSecond == 1) {
                sprintf(dealerCard, "[Hidden]");
            } else {
                cardName(dealerHand[i], dealerCard);
            }
        } else {
            sprintf(dealerCard, "");
        }

        printf("%-20s %-20s\n", playerCard, dealerCard);
    }
}

void declareWinner(int playerTotal, int dealerTotal, int playerBusted, int dealerBusted)
{
    if (playerBusted) {
        printf("You lose $%d.\n", currentBet);
        playerFunds = playerFunds - currentBet;
        playLossTune();
    } else if (dealerBusted) {
        printf("You win $%d!\n", currentBet);
        playerFunds = playerFunds + currentBet;
        playWinTune();
    } else if (playerTotal > dealerTotal) {
        printf("You win $%d!\n", currentBet);
        playerFunds = playerFunds + currentBet;
        playWinTune();
    } else if (playerTotal < dealerTotal) {
        printf("Dealer wins. You lose $%d.\n", currentBet);
        playerFunds = playerFunds - currentBet;
        playLossTune();
    } else {
        printf("Push. Bet returned.\n");
        playPushTune();
    }
}

void playWinTune(void)
{
    Beep(523, 200);
    Beep(659, 200);
    Beep(784, 200);
    Beep(1047, 400);
}

void playLossTune(void)
{
    Beep(392, 300);
    Beep(349, 300);
    Beep(330, 300);
    Beep(262, 600);
}

void playBeethovenFive(void)
{
    Beep(392, 150);
    Beep(392, 150);
    Beep(392, 150);
    Beep(311, 500);
}
void playPushTune(void)
{
    Beep(440, 150);
    Beep(440, 150);
    Beep(523, 250);
}
void flushInput(void)
{
    int c;

    while ((c = getchar()) != '\n' && c != EOF) {
    }
}
