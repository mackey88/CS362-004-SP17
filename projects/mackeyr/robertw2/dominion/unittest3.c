#include "dominion.h" 
#include "dominion_helpers.h" 
#include <string.h> 
#include <stdio.h> 
#include <assert.h> 
#include "rngs.h" 
#include <stdlib.h>

#define TESTFUNCTION "whoseTurn"

int main() {

	//Set Up ints
      
    int seed = 1000;     
    int numPlayers = 4;   
    int results;
    int tests = 1000;
	int i;
	int sucessfulTests = 0;
	int currentTurn;
	

    //Set up 2 game states
	struct gameState G;

	//init random number generator
	srand(seed); 

	//Select Cards for games
	int k[10] = {adventurer, gardens, village, minion, mine, cutpurse, great_hall, tribute, smithy, council_room};

	// initialize a game state and player cards initializeGame(numPlayers, k, seed, &G);
	printf("----------------- Testing Function: %s ----------------\n", TESTFUNCTION);

	//**Not needed for this test-copy the game state to a test case 
	//memcpy(&testG, &G, sizeof(struct gameState));

	initializeGame(numPlayers, k, seed, &G);

	//Start test loop
	for(i = 0; i < tests; i++) {

		//Pick random player for turn
		currentTurn = (rand() % numPlayers);
		
		//Set random players turn
		G.whoseTurn = currentTurn;

		
		//Check function
		results = whoseTurn(&G);

		if(results == currentTurn) {
			//printf("Test %d : %d matches %d \n", i, results, currentTurn);
			sucessfulTests++;
		} else {
			//printf("Test %d : %d does not match %d \n", i, results, currentTurn);
		}


	}


	printf("Conducted %d Tests. %d returned the correct players turn.", i, sucessfulTests);
	
	 printf("\n >>>>> Testing complete %s <<<<<\n\n", TESTFUNCTION);
	
	return 0;
}
