#include <stdio.h>

/* 
 * Your code is included as part of this file.
 */
#include "prog5.h"



/* This is the main code for the program, which calls the functions in prog4.c */
int main ()
{
    char buf[200]; //Character array to get string from user
    int number; //Tracks guess number, game terminates after 12
    int solution[4]; //arrays track solution and current guess
    int guess[4];

    //Get seed and call set_seed
    do {
	printf ("Please enter a seed: ");
	if (NULL == fgets (buf, 200, stdin)) {
	    printf ("\nProgram terminated.\n");
	    return 3;
	}
    } while (!set_seed (buf));

    //Call start game to get solution
    start_game (&solution[0], &solution[1], &solution[2], &solution[3]);

    //Go until 12 guesses, or user wins
    for (number = 1; 12 >= number; number++) {
	printf ("Guess %d\n", number);
	do {
	    printf ("Enter your guess (#1 #2 #3 #4): ");
	    if (NULL == fgets (buf, 200, stdin)) {
		printf ("\nProgram terminated.\n");
		return 3;
	    }
	} while (!make_guess (buf, &guess[0], &guess[1], &guess[2], &guess[3]));
        //If guess is correct, we are done
	if (guess[0] == solution[0] && guess[1] == solution[1] && guess[2] == solution[2] &&
	    guess[3] == solution[3]) {
	    printf ("You guessed correctly in %d guesses.\n", number);
	    return 0;
	}
    }
    //User has lost, print solution
    puts ("You failed to guess correctly in 12 guesses.\n");
    printf ("The solution was %d %d %d %d.\n", solution[0], solution[1], solution[2], solution[3]);

    return 0;
}

