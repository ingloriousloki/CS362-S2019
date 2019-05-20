#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include <math.h>

#define TESTCARD "great hall"

int asserttrue(int a, int b);
int asserttrue(int a, int b){
    return a == b;
}

int main() {
    int newCards = 3;
    int discarded = 1;
    int xtraActions,i,j = 0;
    int deck;
    int shuffledCards = 0;
    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    int seed = 1000;
    int cards = 0;
    int currentCards = 0;
    int pos = 0, discard = 0;
    int numPlayers = 2;
    int thisPlayer = 0;
    int nextPlayer = 1;
    int returnVal,failed,discardFail = 0;
    int hand=0;
    struct gameState G, testG;
    int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
                 sea_hag, tribute, smithy, council_room};
    srand(1000);
    // initialize a game state and player cards

    printf("----------------- Testing Card: %s ----------------\n", TESTCARD);

    for(i=0;i<2000;i++){
        initializeGame(numPlayers, k, seed, &G);
        cards = 0;
        deck = rand()%500+1;
        deck = rand()%500+1;
        hand = rand()%200;
        G.handCount[0]=hand;
        G.deckCount[0]=deck;
        int p = floor(rand()*2);
        newCards = 1;
        xtraActions = 2;
        int preDiscard = G.playedCardCount; 

        for(j=0;j<2;j++){
            int playerDeckCount = G.deckCount[j];
            int playerDeck = 0;

            while(playerDeck < playerDeckCount){
                shuffledCards = rand() % 200;
                pos = rand() % 10;
                playerDeck++;
            }
        }
        currentCards=0;
        cards=0;
        for(j=0;j<G.handCount[thisPlayer];j++){
            cards++;
        }
        int numActions = G.numActions;
        cardEffect(great_hall, choice1, choice2, choice3, &G, handpos, &bonus);
        int postDiscard = G.playedCardCount;
        for(j=0;j<G.handCount[thisPlayer];j++){
            currentCards++;
        }

        if(currentCards < cards){
            failed = 1;
        }


        if(currentCards - 1 > cards){
            failed = 1;
        }
        if(G.numActions != (numActions+1))
            if(failed == 1)
                failed = 3;
            else
                failed = 2;
        if(preDiscard + 1 != postDiscard){
            failed, discardFail = 1;
        }
    }
    if(failed == 0)
        printf("Test passed\n");
    else if(failed == 1)
        printf("Test failed, incorrect amount of cards in hand...\n");
    else if(failed == 2)
        printf("Test failed, incorrect amount actions...\n");
    else if(failed == 3)
        printf("Test failed, incorrect amount actions and incorrect number of cards...\n");
    if(discardFail != 0)
        printf("Test failed, incorrect amount of cards discarded...\n");
    return 0;
}


