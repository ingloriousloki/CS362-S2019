#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

int asserttrue(int a, int b);
int asserttrue(int a, int b){
    return a == b;
}

int main() {
    int i;
    int seed = 1000;
    int numPlayer = 4;
    int maxBonus = 10;
    int p, r, handCount;
    int bonus;
    int k[10] = {adventurer, council_room, feast, gardens, mine
            , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    int maxHandCount = 5;
    // Test endTurn/whose turn works
    printf("Testing endTurn returns correct player to whose Turn\n\n");
    int failFlag = 0;
    initializeGame(numPlayer, k, seed, &G);
    for (i = 0; i < numPlayer; i++)
    {
        printf("Check if whose turn is correct before endTurn is called\n");
        printf("Player = %d, expected = %d\n", whoseTurn(&G),i);
        printf("Calling endTurn...\n");
        endTurn(&G);
        printf("Player = %d, expected = %d\n", whoseTurn(&G),i);
        if (asserttrue(i, whoseTurn(&G)) == 1){
            printf("Failed!\n");
            failFlag = 1;
        }
        else{
            printf("Passed\n");
        }
    }
    if(failFlag){
        printf("Test Failed!\n");
    }
    else
        printf("All tests passed!\n");

    return 0;
}