#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define MAX_DECK_SIZE 416
#define MAX_HAND_SIZE 30
#define STARTING_FUNDS 500

int deck[MAX_DECK_SIZE];
int deckSize = 0, dealtCount = 0;

int playerFunds = STARTING_FUNDS;
int currentBet = 0;

/* function prototypes */
void initializeDeck(int numDecks);
int drawCard(void);
int cardValue(int card);
int handTotal(int hand[], int count);
int isBlackjack(int hand[], int count);
const char *cardName(int card);
void displayHand(int hand[], int count, int hideSecond);
void declareWinner(int playerTotal, int dealerTotal, int playerBusted, int dealerBusted);
void playWinTune(void);
void playLossTune(void);
void playBeethovenFive(void);
void flushInput(void);

void dealInitialCards(int playerHand[], int *playerCount, int dealerHand[], int *dealerCount);
int playerTurn(int playerHand[], int *playerCount);
int dealerTurn(int dealerHand[], int *dealerCount);
int getDeckChoice(void);
int getBetAmount(void);
char getYesNo(const char *prompt);
void reshuffleIfNeeded(int numDecks);

int main(void)
{
    int numDecks;
    char again = 'Y';

    srand((unsigned int)time(NULL));

    printf("=========================================\n");
    printf("         Welcome to Blackjack!\n");
    printf("=========================================\n");

    numDecks = getDeckChoice();
    initializeDeck(numDecks);
    playBeethovenFive();

    while ((again == 'Y' || again == 'y') && playerFunds > 0) {
        int playerHand[MAX_HAND_SIZE], dealerHand[MAX_HAND_SIZE];
        int playerCount = 0, dealerCount = 0;
        int playerBusted = 0, dealerBusted = 0;
        int playerTotal, dealerTotal;

        printf("\n-----------------------------------------\n");
        printf("Balance: $%d\n", playerFunds);

        currentBet = getBetAmount();
        dealInitialCards(playerHand, &playerCount, dealerHand, &dealerCount);

        printf("\nYour hand:\n");
        displayHand(playerHand, playerCount, 0);
        playerTotal = handTotal(playerHand, playerCount);
        printf("Your total: %d\n", playerTotal);

        printf("\nDealer's hand:\n");
        displayHand(dealerHand, dealerCount, 1);

        if (isBlackjack(playerHand, playerCount)) {
            printf("\n*** BLACKJACK! ***\n");
            printf("Dealer's full hand:\n");
            displayHand(dealerHand, dealerCount, 0);

            if (isBlackjack(dealerHand, dealerCount)) {
                printf("Dealer also has Blackjack. Push - bet returned.\n");
            } else {
                int winnings = (int)(currentBet * 1.5);
                playerFunds += winnings;
                printf("You win $%d!\n", currentBet + winnings);
                playWinTune();
            }
        } else {
            playerBusted = playerTurn(playerHand, &playerCount);

            if (!playerBusted) {
                dealerBusted = dealerTurn(dealerHand, &dealerCount);
            }

            playerTotal = handTotal(playerHand, playerCount);
            dealerTotal = handTotal(dealerHand, dealerCount);

            printf("\n--- Result ---\n");
            if (!playerBusted) printf("Your total: %d\n", playerTotal);
            if (!playerBusted && !dealerBusted) printf("Dealer total: %d\n", dealerTotal);

            declareWinner(playerTotal, dealerTotal, playerBusted, dealerBusted);
        }

        printf("Balance: $%d\n", playerFunds);
        reshuffleIfNeeded(numDecks);

        if (playerFunds <= 0) {
            printf("\nYou have run out of funds. Game over!\n");
            break;
        }

        again = getYesNo("\nPlay another round? (Y/N): ");
    }

    printf("\n=========================================\n");
    printf("Thanks for playing!\n");
    printf("Final balance: $%d\n", playerFunds);
    printf("=========================================\n");

    return 0;
}

int getDeckChoice(void)
{
    int numDecks;

    do {
        printf("How many decks would you like to play with? (1-8): ");
        scanf("%d", &numDecks);
        flushInput();

        if (numDecks < 1 || numDecks > 8) {
            printf("Invalid choice. Enter 1 to 8.\n");
        }
    } while (numDecks < 1 || numDecks > 8);

    return numDecks;
}

int getBetAmount(void)
{
    int bet;

    do {
        printf("Enter your bet: $");
        scanf("%d", &bet);
        flushInput();

        if (bet <= 0 || bet > playerFunds) {
            printf("Invalid bet. Enter an amount from $1 to $%d.\n", playerFunds);
        }
    } while (bet <= 0 || bet > playerFunds);

    return bet;
}

char getYesNo(const char *prompt)
{
    char choice;
    printf("%s", prompt);
    scanf(" %c", &choice);
    flushInput();
    return choice;
}

void dealInitialCards(int playerHand[], int *playerCount, int dealerHand[], int *dealerCount)
{
    *playerCount = 0;
    *dealerCount = 0;

    playerHand[(*playerCount)++] = drawCard();
    dealerHand[(*dealerCount)++] = drawCard();
    playerHand[(*playerCount)++] = drawCard();
    dealerHand[(*dealerCount)++] = drawCard();
}

int playerTurn(int playerHand[], int *playerCount)
{
    char choice;
    int total;

    while (1) {
        total = handTotal(playerHand, *playerCount);

        printf("\nYour hand:\n");
        displayHand(playerHand, *playerCount, 0);
        printf("Your total: %d\n", total);

        if (total == 21) {
            printf("21 reached. Standing automatically.\n");
            return 0;
        }

        printf("(H)it or (S)tand? ");
        scanf(" %c", &choice);
        flushInput();

        if (choice == 'H' || choice == 'h') {
            playerHand[(*playerCount)++] = drawCard();
            printf("You drew: %s\n", cardName(playerHand[*playerCount - 1]));

            total = handTotal(playerHand, *playerCount);
            if (total > 21) {
                printf("Your total: %d - BUST!\n", total);
                return 1;
            }
        } else if (choice == 'S' || choice == 's') {
            printf("You stand at %d.\n", total);
            return 0;
        } else {
            printf("Invalid input. Enter H or S.\n");
        }
    }
}

int dealerTurn(int dealerHand[], int *dealerCount)
{
    int total;

    printf("\n--- Dealer's Turn ---\n");
    printf("Dealer reveals hole card.\n");
    printf("Dealer's hand:\n");
    displayHand(dealerHand, *dealerCount, 0);

    total = handTotal(dealerHand, *dealerCount);
    printf("Dealer's total: %d\n", total);

    while (total < 17) {
        dealerHand[(*dealerCount)++] = drawCard();
        printf("Dealer draws: %s\n", cardName(dealerHand[*dealerCount - 1]));

        total = handTotal(dealerHand, *dealerCount);
        printf("Dealer's total: %d\n", total);

        if (total > 21) {
            printf("Dealer BUSTS!\n");
            return 1;
        }
    }

    printf("Dealer stands at %d.\n", total);
    return 0;
}

void reshuffleIfNeeded(int numDecks)
{
    char choice;

    if (dealtCount >= deckSize * 3 / 4) {
        printf("\nThe deck is running low (%d cards remaining).\n", deckSize - dealtCount);
        choice = getYesNo("Would you like to reshuffle? (Y/N): ");

        if (choice == 'Y' || choice == 'y') {
            initializeDeck(numDecks);
            printf("Deck reshuffled.\n");
        }
    }
}

void initializeDeck(int numDecks)
{
    int i, j, r, temp;

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
        printf("ERROR: Deck is empty.\n");
        return -1;
    }

    return deck[dealtCount++];
}

int cardValue(int card)
{
    if (card == 1) return 11;
    if (card >= 10) return 10;
    return card;
}

int handTotal(int hand[], int count)
{
    int i, total = 0, aceCount = 0;

    for (i = 0; i < count; i++) {
        total += cardValue(hand[i]);
        if (hand[i] == 1) aceCount++;
    }

    while (total > 21 && aceCount > 0) {
        total -= 10;
        aceCount--;
    }

    return total;
}

int isBlackjack(int hand[], int count)
{
    if (count != 2) return 0;

    return ((hand[0] == 1 && hand[1] >= 10) ||
            (hand[1] == 1 && hand[0] >= 10));
}

const char *cardName(int card)
{
    static char buf[4];

    switch (card) {
        case 1:  return "Ace";
        case 11: return "Jack";
        case 12: return "Queen";
        case 13: return "King";
        default:
            sprintf(buf, "%d", card);
            return buf;
    }
}

void displayHand(int hand[], int count, int hideSecond)
{
    int i;

    for (i = 0; i < count; i++) {
        if (i == 1 && hideSecond) {
            printf("  [Hidden]\n");
        } else {
            printf("  %s\n", cardName(hand[i]));
        }
    }
}

void declareWinner(int playerTotal, int dealerTotal, int playerBusted, int dealerBusted)
{
    if (playerBusted) {
        printf("You busted! You lose $%d.\n", currentBet);
        playerFunds -= currentBet;
        playLossTune();
    } else if (dealerBusted) {
        printf("Dealer busts! You win $%d!\n", currentBet);
        playerFunds += currentBet;
        playWinTune();
    } else if (playerTotal > dealerTotal) {
        printf("You win $%d!\n", currentBet);
        playerFunds += currentBet;
        playWinTune();
    } else if (playerTotal == dealerTotal) {
        printf("Push - bet returned.\n");
    } else {
        printf("Dealer wins. You lose $%d.\n", currentBet);
        playerFunds -= currentBet;
        playLossTune();
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

void flushInput(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}
