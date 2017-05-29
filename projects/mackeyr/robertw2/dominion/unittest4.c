#include "dominion.h" 
#include "dominion_helpers.h" 
#include <string.h> 
#include <stdio.h> 
#include <assert.h> 
#include "rngs.h" 
#include <stdlib.h>

#define TESTFUNCTION "handCard"

int main() {

	//Set Up ints
      
    int seed = 1000;     
    int numPlayers = 2;
    int testPlayer = 1;    
    int results;
    int tests = 1000;
    int handCount;
    int matchCardPosition;
	int handCardValue;
	int currentCard;
	int i, m;
	
	int sucessfulTests = 0;


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

	G.whoseTurn = testPlayer;

printf("Test");
	//Start test loop
	for(i = 0; i < tests; i++) {



		//Set counts for testing
		handCount = (rand() % 500);
		

		//Set counts in game state
		G.handCount[testPlayer] = handCount;

		
		//Set card to check for
		matchCardPosition = (rand() % 500);
		while(matchCardPosition > handCount) {
			
			matchCardPosition = (rand() % 500);
		}

		//Fill users cards
		for(m = 0; m < handCount + 1; m++) {
			//Pick random card
			currentCard = (rand() % 27);
			
			//Set Card in hand
			G.hand[testPlayer][m] = currentCard;

			if(matchCardPosition == m) {handCardValue = currentCard;}

		}


		//Check function
		results = handCard(matchCardPosition, &G);

		if(results == handCardValue) {
			//printf("Test %d : %d matches %d \n", i, results, handCardValue);
			sucessfulTests++;
		} else {
			printf("Test %d : %d does not match %d handCount: %d matchCardPosition: %d \n", i, results, handCardValue, handCount, matchCardPosition);
		}

		//printf("Conducted %d : %d does not match %d \n", i, results, matchCount);

	}

	
	printf("Conducted %d Tests. %d returned the correct score.", i, sucessfulTests);
	
	 printf("\n >>>>> Testing complete %s <<<<<\n\n", TESTFUNCTION);
	
	return 0;
}