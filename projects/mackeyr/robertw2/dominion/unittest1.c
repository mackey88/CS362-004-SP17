#include "dominion.h" 
#include "dominion_helpers.h" 
#include <string.h> 
#include <stdio.h> 
#include <assert.h> 
#include "rngs.h" 
#include <stdlib.h>

#define TESTFUNCTION "fullDeckCount"

int main() {

	//Set Up ints
      
    int seed = 1000;     
    int numPlayers = 2;
    int testPlayer = 1;    
    int results;
    int tests = 1000;
    int matchCount;
	int matchCard;
	int currentCard;
	int i, j, m, n;
	int deckCount;
	int handCount;
	int dicardCount;
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


	

	

	//Start test loop
	for(i = 0; i < tests; i++) {


		//CSet count to 0
		matchCount = 0;

		//Set card to check for
		matchCard = (rand() % 27);

		//Set counts for testing
		deckCount = (rand() % 500);
		handCount = (rand() % 500);
		dicardCount = (rand() % 500);

		//Set counts in game state
		G.deckCount[testPlayer] = deckCount;
		G.handCount[testPlayer] = handCount;
		G.discardCount[testPlayer] = dicardCount;

		//Fill users cards
		for(j = 0; j < deckCount; j++) {
			currentCard = (rand() % 27);
			if(currentCard == matchCard) matchCount++;
			G.deck[testPlayer][j] = currentCard;
		}

		for(m = 0; m < handCount; m++) {
			currentCard = (rand() % 27);
			if(currentCard == matchCard) matchCount++;
			G.hand[testPlayer][m] = currentCard;
		}

		for(n = 0; n < dicardCount; n++) {
			currentCard = (rand() % 27);
			if(currentCard == matchCard) matchCount++;
			G.discard[testPlayer][n] = currentCard;
		}

		//Check function
		results = fullDeckCount(testPlayer, matchCard, &G);

		if(results == matchCount) {
			//printf("Test %d : %d matches %d \n", i, results, matchCount);
			sucessfulTests++;
		} else {
			//printf("Test %d : %d does not match %d \n", i, results, matchCount);
		}

		//printf("Conducted %d : %d does not match %d \n", i, results, matchCount);


	}

	printf("Conducted %d Tests. %d returned the number of cards that were expected.", i, sucessfulTests);

	
	 printf("\n >>>>> Testing complete %s <<<<<\n\n", TESTFUNCTION);
	
	return 0;
}
