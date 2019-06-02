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
    int numPlayer = 2;
    int maxBonus = 10;
    int p, r, handCount;
    int bonus;
    int k[10] = {adventurer, council_room, feast, gardens, mine
            , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    // Test endTurn/whose turn works


    printf("Testing coin value added\n\n");
    int failFlag = 0;
    initializeGame(numPlayer, k, seed, &G);
    printf("Game initialized\n");
    G.coins = 0;

    printf("Adding Gold\n");
    for(i=0; i < 5;i++){
        G.hand[0][i] = gold;
    }
    updateCoins(0,&G,0);
    printf("Coins = %d, expected = %d\n", G.coins,15);

    if (asserttrue(G.coins, 30) == 1){
        printf("Failed gold!\n");
        failFlag = 1;
    }
    else{
        printf("Passed\n");
    }


    printf("Adding silver\n");
    for(i=0; i < 5;i++){
        G.hand[0][i] = 5;
    }
    updateCoins(0,&G,0);
    printf("Coins = %d, expected = %d\n", G.coins,10);
    if (asserttrue(G.coins, 30) == 1){
        printf("Failed silver!\n");
        failFlag = 1;
    }
    else{
        printf("Passed\n");
    }

    printf("Adding Copper\n");
    for(i=0; i < 5;i++){
        G.hand[0][i] = copper;
    }
    updateCoins(0,&G,0);
    printf("Coins = %d, expected = %d\n", G.coins,5);
    if (asserttrue(G.coins, 10) == 1){
        printf("Failed copper!\n");
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