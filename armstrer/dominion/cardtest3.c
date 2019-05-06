#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "great_hall"

int asserttrue(int a, int b);
int asserttrue(int a, int b){
    return a == b;
}

int main() {
    int newCards = 3;
    int discarded = 1;
    int xtraCoins,i = 0;
    int shuffledCards = 0;
    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    int seed = 1000;
    int treasure = 0;
    int currentTreasure = 0;
    int pos = 0, discard = 0;
    int numPlayers = 2;
    int thisPlayer = 0;
    int nextPlayer = 1;
    struct gameState G, testG;
    int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
                 sea_hag, tribute, smithy, council_room};

    // initialize a game state and player cards
    initializeGame(numPlayers, k, seed, &G);
    printf("----------------- Testing Card: %s ----------------\n", TESTCARD);

    // ----------- TEST 1: Check for appropriate number of cards in deck --------------
    printf("TEST 1: \n");
    printf("\nChecking if right amount of cards were added!\n");

    // copy the game state to a test case
    memcpy(&testG, &G, sizeof(struct gameState));
    cardEffect(great_hall, choice1, choice2, choice3, &testG, handpos, &bonus);


    if (asserttrue(testG.handCount[thisPlayer], G.handCount[thisPlayer] + 1) == 0){
        printf("Hand Count Incorrect!\n");
    }
    else{
        printf("Hand Count Correct!\n");
    }
    printf("hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] + 1);


    if (asserttrue(testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - 1) == 0){
        printf("Deck Count incorrect!\n");
    }
    else{
        printf("Deck Count Correct!\n");
    }
    printf("deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer] -1);


    if(asserttrue(testG.coins, G.coins) == 0){
        printf("Coins incorrect");
    }
    else{
        printf("Coins Correct!\n");
    }
    printf("coins = %d, expected = %d\n\n", testG.coins, G.coins);


    // ----------- TEST 2: Check Action was added --------------
    printf("\nTEST 2: \n");
    printf("\nChecking extra action was added!\n");
    if (asserttrue(testG.numActions, G.numActions + 1) == 1){
        printf("Success, additional action added!\n");
    }
    else{
        printf("Failed, correct amount of action not added!\n");
    }
    printf("Number of actions = %d, expected = %d\n", testG.numActions, G.numActions + 1);


    // ----------- TEST 3: Check next players hand --------------
    printf("\nTEST 3: \n");
    printf("Check card was discarded \n");
    if (asserttrue(testG.handCount[thisPlayer], G.handCount[thisPlayer]) == 0){
        printf("Hand Count Incorrect!\n");
    }
    else{
        printf("Hand Count Correct!\n");
    }
    printf("hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer]);


    printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);

    return 0;
}




