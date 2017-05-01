#include "dominion.h" 
#include "dominion_helpers.h" 
#include <string.h> 
#include <stdio.h> 
#include <assert.h> 
#include "rngs.h" 
#include <stdlib.h>

#define TESTFUNCTION "playSmithy"

int main() {

	//Set Up ints
      
    int seed = 1000;     
    int numPlayers = 2;
    int testPlayer = 0;    
    int tests = 2;
	int i;
	int sucessfulTests = 0;
	int handPosition = 1;
	int roundSuccess;


    //Set up game state
	struct gameState G, testG;

	//init random number generator
	srand(seed); 

	//Select Cards for games
	int k[10] = {adventurer, gardens, village, minion, mine, cutpurse, great_hall, tribute, smithy, council_room};

	// initialize a game state and player cards initializeGame(numPlayers, k, seed, &G);
	printf("----------------- Testing Card: %s ----------------\n", TESTFUNCTION);

	//**Not needed for this test-copy the game state to a test case 
	//memcpy(&testG, &G, sizeof(struct gameState));

	initializeGame(numPlayers, k, seed, &G);


	

	

	//Start test loop
	for(i = 0; i < tests; i++) {

	roundSuccess = 1;

	initializeGame(numPlayers, k, seed, &G);
	memcpy(&testG, &G, sizeof(struct gameState));

	//Run Function
	playSmithy(handPosition, &G);

	//Step by step
	drawCard(testPlayer, &testG);
	drawCard(testPlayer, &testG);
	drawCard(testPlayer, &testG);

	if(testG.deckCount[testPlayer] == G.deckCount[testPlayer]) {
		printf("Test %d :  Deckcount from drawing cards matches  \n", i);
	} else {
		printf("Test %d :  Deckcount from drawing cards does not match  \n", i);
		roundSuccess = 0;
	} 

	
	discardCard(handPosition, testPlayer, &testG, 0);
	if(testG.handCount[testPlayer] == G.handCount[testPlayer]) {
		printf("Test %d :  handcount matches  \n", i);
	} else {
		printf("Test %d :  handcount does not match  \n", i);
		roundSuccess = 0;
	}

	if(roundSuccess == 1) sucessfulTests++;


	}

	printf("Conducted %d Tests. %d returned the correct results.", i, sucessfulTests);

	
	 printf("\n >>>>> Testing complete %s <<<<<\n\n", TESTFUNCTION);
	
	return 0;
}
