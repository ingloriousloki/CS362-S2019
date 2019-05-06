#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "smithy"

int asserttrue(int a, int b);
int asserttrue(int a, int b){
    return a == b;
}

int main() {
    int newCards = 3;
    int discarded = 1;
    int xtraCoins = 0;
    int shuffledCards = 0;
    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    int seed = 1000;
    int numPlayers = 2;
    int thisPlayer = 0;
    int nextPlayer = 1;
    struct gameState G, testG;
    int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
                 sea_hag, tribute, smithy, council_room};

    // initialize a game state and player cards
    initializeGame(numPlayers, k, seed, &G);
    printf("----------------- Testing Card: %s ----------------\n", TESTCARD);

    // ----------- TEST 1: hand +3 cards, deck -3 cards --------------
    printf("TEST 1: +3 cards\n");

    // copy the game state to a test case
    memcpy(&testG, &G, sizeof(struct gameState));
    choice1 = 1;
    cardEffect(smithy, choice1, choice2, choice3, &testG, handpos, &bonus);

    newCards = 3;
    xtraCoins = 0;
    if (asserttrue(testG.handCount[thisPlayer], G.handCount[thisPlayer] + newCards - discarded) == 0){
        printf("Hand Count Incorrect!\n");
    }
    else{
        printf("Hand Count Correct!\n");
    }
    printf("hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] + newCards - discarded);



    if (asserttrue(testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - newCards + shuffledCards) == 0){
        printf("Deck Count incorrect!\n");
    }
    else{
        printf("Deck Count Correct!\n");
    }
    printf("deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - newCards + shuffledCards);


    if(asserttrue(testG.coins, G.coins + xtraCoins) == 0){
        printf("Coins incorrect");
    }
    else{
        printf("Coins Correct!\n");
    }
    printf("coins = %d, expected = %d\n\n\n", testG.coins, G.coins + xtraCoins);


    printf("\nChecking next players hand!\n");

    if (asserttrue(testG.handCount[nextPlayer], G.handCount[nextPlayer]) == 0){
        printf("Next Player Hand Count Incorrect!\n");
    }
    else{
        printf("Next Player Hand Count Correct!\n");
    }
    printf("hand count = %d, expected = %d\n", testG.handCount[nextPlayer], G.handCount[nextPlayer]);
    if (asserttrue(testG.deckCount[nextPlayer], G.deckCount[nextPlayer]) == 0){
        printf("Next Player Deck Count incorrect!\n");
    }
    else{
        printf("Next Player Deck Count Correct!\n");
    }
    printf("deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer]);

    printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);

    return 0;
}


