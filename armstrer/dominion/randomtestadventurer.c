#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include <math.h>

#define TESTCARD "adventure"

int asserttrue(int a, int b);
int asserttrue(int a, int b){
    return a == b;
}

int main() {
    int newCards = 3;
    int discarded = 1;
    int xtraCoins, i, j = 0;
    int deck;
    int shuffledCards = 0;
    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    int seed = 1000;
    int treasure, cards = 0;
    int currentTreasure, currentCards, currentDeck = 0;
    int pos = 0, discard = 0;
    int numPlayers = 2;
    int thisPlayer = 0;
    int nextPlayer = 1;
    int returnVal, failed = 0;
    int hand;
    struct gameState G, testG;
    int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
                 sea_hag, tribute, smithy, council_room};
    srand(1000);
    // initialize a game state and player cards

    printf("----------------- Testing Card: %s ----------------\n", TESTCARD);

    for (i = 0; i < 2000; i++) {
        initializeGame(numPlayers, k, seed, &G);
        treasure = 0;
        deck = rand() % 500 + 1;
        deck = rand() % 500 + 1;
        hand = rand() % 200;
        G.handCount[0] = hand;
        G.deckCount[0] = deck;

        for (j = 0; j < 2; j++) {
            int playerDeckCount = G.deckCount[j];
            int playerDeck = 0;

            while (playerDeck < playerDeckCount) {
                shuffledCards = rand() % 200;
                pos = rand() % 10;
                if (pos == 3) {
                    G.deck[j][playerDeck] = gold;
                } else if (pos == 2) {
                    G.deck[j][playerDeck] = silver;
                } else if (pos == 1) {
                    G.deck[j][playerDeck] = copper;
                } else {
                    G.deck[j][playerDeck] = k[pos];
                }
                playerDeck++;
            }
        }
        currentTreasure = 0;
        treasure = 0;
        currentCards = G.handCount[thisPlayer];

        for (j = 0; j < G.handCount[thisPlayer]; j++) {
            if (G.hand[thisPlayer][j] == gold)
                treasure++;
            else if (G.hand[thisPlayer][j] == silver)
                treasure++;
            else if (G.hand[thisPlayer][j] == copper)
                treasure++;
        }

        cardEffect(adventurer, choice1, choice2, choice3, &G, handpos, &bonus);

        for (j = 0; j < G.handCount[thisPlayer]; j++) {
            if (G.hand[thisPlayer][j] == gold)
                currentTreasure++;
            else if (G.hand[thisPlayer][j] == silver)
                currentTreasure++;
            else if (G.hand[thisPlayer][j] == copper)
                currentTreasure++;
        }

        if (currentTreasure - 2 != treasure) {
            failed = 1;
        }

        if (currentCards + 2 < G.handCount[thisPlayer]) {
            failed = 2;
        }
    }
    if (failed == 0)
        printf("Test passed\n");
    else {
        if (failed == 1) {
            printf("Test failed, incorrect amount of treasure cards in hand...\n");
        }
        if (failed == 2) {
            printf("Test failed Number of cards in hand incorrect...\n");
        }
    }


    return 0;
}

