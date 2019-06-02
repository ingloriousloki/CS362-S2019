#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "village"

int assertTrue(int a, int b);
int assertTrue(int a, int b){
    return a == b;
}

int main() {
    int newCards = 0;
    int discarded = 1;
    int xtraActions = 0;
    int shuffledCards = 0;

    int i, j, m;
    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    int remove1, remove2;
    int seed = 1000;
    int numPlayers = 2;
    int thisPlayer = 0;
	struct gameState G, testG;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};

	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);

	printf("----------------- Testing Card: %s ----------------\n", TESTCARD);

	// ----------- TEST 1: choice1 = 1 = +2 cards --------------
	printf("TEST 1: Were Actions and cards added to deck\n");

	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));
	choice1 = 1;
	cardEffect(village, choice1, choice2, choice3, &testG, handpos, &bonus);
	newCards = 1;
	xtraActions = 2;
	printf("hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] + newCards - discarded);



    if (!assertTrue(testG.handCount[thisPlayer], G.handCount[thisPlayer] + newCards - discarded)){
        printf("Hand Count Incorrect!\n");
    }
    else{
        printf("Hand Count Correct!\n");
    }
    printf("hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] + newCards - discarded);



    if (!assertTrue(testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - newCards + shuffledCards)){
        printf("Deck Count Incorrect!\n");
    }
    else{
        printf("Deck Count Correct!\n");
    }
    printf("deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - newCards + shuffledCards);



    if (!assertTrue(testG.numActions, G.numActions + xtraActions)){
        printf("Action Count Incorrect!\n");
    }
    else{
        printf("Action Count Correct!\n");
    }
    printf("actions = %d, expected = %d\n", testG.numActions, G.numActions + xtraActions);


	printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);


	return 0;
}


