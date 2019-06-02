#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include<time.h>

int asserttrue(int a, int b);
int asserttrue(int a, int b){
    return a == b;
}

int main() {
    srand(time(0));
    int i;
    int seed = 1000;
    int numPlayer = 2;
    int maxBonus = 10;
    int p, r, handCount;
    int bonus;
    int k[10] = {adventurer, council_room, feast, gardens, mine
            , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    int result;

    printf("Testing game over when no provinces are left\n\n");
    int failFlag = 0;
    initializeGame(numPlayer, k, seed, &G);
    printf("Game initialized\n");
    int baseCase = isGameOver(&G);
    printf("Check if game is over prior before setting provinces to 0:\n");
    printf("Game over state = %d\n", baseCase);
    G.supplyCount[province] = 0;
    result = isGameOver(&G);
    printf("Game state = %d\n", result);
    printf("isGameover = %d, expected = %d\n", result,1);

    if (asserttrue(isGameOver(&G), 0) == 1){
        printf("Failed game over!\n");
        failFlag = 1;
    }
    else{
        printf("Passed\n");
    }

    printf("Resetting provinces...\n");
    G.supplyCount[province] = 1;

    printf("isGameover = %d, expected = %d\n", isGameOver(&G),0);

    if (asserttrue(isGameOver(&G), 1) == 1){
        printf("Failed game over!\n");
        failFlag = 1;
    }
    else{
        printf("Passed\n");
    }
    printf("Setting random supply cards to 0...\n");
    for(i = 0; i < 6; i++){
        int randomCard = rand()%25;
        G.supplyCount[randomCard] = 0;
        printf("Supply Card = %d\n",randomCard);
    }

    result = isGameOver(&G);
    printf("Game state = %d\n", result);
    printf("isGameover = %d, expected = %d\n", result,1);

    if (asserttrue(isGameOver(&G), 0) == 1){
        printf("Failed game over!\n");
        failFlag = 1;
    }
    else{
        printf("Passed\n");
    }

    if(failFlag){
        printf("Test Failed!\n");
    }
    else
        printf("All tests passed!\n");


    return 0;
}