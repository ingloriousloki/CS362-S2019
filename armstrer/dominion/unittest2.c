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

    printf("Testing coins spent after buy card\n\n");
    int failFlag = 0;
    initializeGame(numPlayer, k, seed, &G);
    for(i; i < 10;i++){
        G.numBuys = 1;
        G.coins = 10;
        buyCard(i,&G);
        printf("Coins = %d, expected = %d\n", G.coins,10-getCost(i));
        if (asserttrue(G.coins, 10-getCost(i)) == 0){
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