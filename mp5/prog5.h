/*									
 *
 * prog4.h - header file adapted from 
 * UIUC ECE198KL Spring 2013 Program 4
 * student code by Steven S. Lumetta
 */

#if !defined(PROG_4_H)
#define PROG_4_H

int set_seed (const char seed_str[]);

void start_game (int* one, int* two, int* three, int* four);

int make_guess (const char guess_str[], int* one, int* two, 
		    int* three, int* four);

#endif /* PROG_4_H */


