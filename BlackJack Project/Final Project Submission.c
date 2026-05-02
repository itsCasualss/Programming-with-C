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

/*
   Function Prototypes: Tells compiler that these functions exist later in the function and allows the main()
   to call upon them.
*/

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

    srand((unsigned int)time(NULL)); // Uses current time as way to create randomness for the deck shuffling.

    printf("Welcome to Blackjack\n");

// Repeats until the player enters a valid number of decks from 1 to 8.
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
// Main game loop. Continues while the player wants another round and still has money.
    while ((again == 'Y' || again == 'y') && playerFunds > 0) {

        cardsLeft = deckSize - dealtCount; // Checks whether enough cards remain for another round. If not, the deck is reshuffled.
        if (cardsLeft < 10) {
            printf("\nNot enough cards left to start a new round.\n");
            initializeDeck(numDecks);
            printf("Deck reshuffled.\n");
        }
	// Resets round-specific values before starting a new hand.
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
	//deals 2 cards to player and two to the dealer. player>dealer>player>dealer
        playerHand[playerCount++] = drawCard();
        dealerHand[dealerCount++] = drawCard();
        playerHand[playerCount++] = drawCard();
        dealerHand[dealerCount++] = drawCard();

        displayBothHands(1);
        printf("\nYour total: %d\n", handTotal(playerHand, playerCount));
//checks if natural BJ
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
//hit or stand loop, autostops at 21.
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
//if Hit, checks bust or BJ, asks H/S til bust or S
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
//dealer plays, forced to hit if hand <17.
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
//finds sum of hands, compares.
            playerTotal = handTotal(playerHand, playerCount);
            dealerTotal = handTotal(dealerHand, dealerCount);

            printf("\nFinal results:\n");
            displayBothHands(0);
            printf("\nYour total: %d\n", playerTotal);

            if (!dealerBusted) {
                printf("Dealer total: %d\n", dealerTotal);
            }
//declares winner,
            declareWinner(playerTotal, dealerTotal, playerBusted, dealerBusted);
        }
//updates balance, offeres a reshuffle or play again.
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

/*
   initializeDeck: Creates decks to play with as user selects. Each card is stored as a #
   between 1-13, where 1=Ace, 11=Jack, 12=Queen, & 13=King.
   After selected, shuffles deck randomly.
*/
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

/*
   drawCard: Deals cards for initial play,
   dealCount tracks # cards used,
   if its empty, function returns -1
*/
int drawCard(void)
{
    if (dealtCount >= deckSize) {
        return -1;
    }

    return deck[dealtCount++];
}

/*
   cardValue: Converts the K,Q,J and A to their proper BJ value of 10, 11, or 1.
*/
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

/*
   handTotal:
   Finds user's and dealers hand total based on current cards
   if Ace exists, initially counts as 11, but if hand >21, counts as 1
   by subtracting 10.
*/
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

/*
   isBlackjack: Checks if hand is natural BJ, returns 1 if is else 0
   hand has exactly 2 cards.
*/
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

/*
   cardName:
   Converts the numberic value for the card into printabple name.
   Converts a numeric card value into a readable card name.
   Number cards are converted into their matching number as text.
**Sprintf() is used to store the card as a string, so it stores the name as "Ace" if its ==1
since the display functions prints the cards as a string.

*/
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

/*
   displayBothHands:
   Prints the player's hand and dealer's hand in two side-by-side columns.
   If hideDealerSecond is 1, the dealer's second card is shown as [Hidden].
   If hideDealerSecond is 0, all dealer cards are shown.

*/
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

/*
   declareWinner: Decides whether the Dealer or user won the round, plays corresponding sound
   and updates player's money
*/
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

/*
   playWinTune & playLossTune
   'Tune' itself was provided by AI to play a more pleasent note.
*/
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

/*
   Plays 1st 4 notes of Beethoven's Fifth Symphony.
   This runs once after the deck is initialized.
*/
void playBeethovenFive(void)
{
    Beep(392, 150);
    Beep(392, 150);
    Beep(392, 150);
    Beep(311, 500);
}

/*
   playPushTune:
   Added special tone for when dealer's hand matches the players hand ..
   I have yet to see this live so i hope it sounds pleasent.
*/
void playPushTune(void)
{
    Beep(440, 150);
    Beep(440, 150);
    Beep(523, 250);
}

/*
   flushInput:
   Clears leftover characters from the input buffer after using scanf.
   Prevents old inputs from messing with the next input
*/
void flushInput(void)
{
    int c;

    while ((c = getchar()) != '\n' && c != EOF) {
    }
}
