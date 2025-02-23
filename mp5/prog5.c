/*			
 *
 * prog5.c - source file adapted from UIUC ECE198KL Spring 2013 Program 4
 *           student code -- GOLD VERSION by Steven S. Lumetta
 */


/*
 * The functions that you must write are defined in the header file.
 * Blank function prototypes with explanatory headers are provided
 * in this file to help you get started.
 */

/*
This program take three funtion to run the code, set_seed, start_game, and make guess.
set seed check the user input and use the input seed to generate the number for the user to guess.
start_game set the value of each interger using the randum number generate with the seed.
store the vaule using pointer.
make guess check take the user input, check if it is valid. Then check the input with the number.
modifi the number based on compare the user input with answer. Print the status.
*/

#include <stdio.h>
#include <stdlib.h>

#include "prog5.h"


/*
 * You will need to keep track of the solution code using file scope
 * variables as well as the guess number.
 */

static int guess_number;
static int solution1;
static int solution2;
static int solution3;
static int solution4;


/*
 * set_seed -- This function sets the seed value for pseudorandom
 * number generation based on the number the user types.
 * The input entered by the user is already stored in the string seed_str by the code in main.c.
 * This function should use the function sscanf to find the integer seed value from the 
 * string seed_str, then initialize the random number generator by calling srand with the integer
 * seed value. To be valid, exactly one integer must be entered by the user, anything else is invalid. 
 * INPUTS: seed_str -- a string (array of characters) entered by the user, containing the random seed
 * OUTPUTS: none
 * RETURN VALUE: 0 if the given string is invalid (string contains anything
 *               other than a single integer), or 1 if string is valid (contains one integer)
 * SIDE EFFECTS: initializes pseudo-random number generation using the function srand. Prints "set_seed: invalid seed\n"
 *               if string is invalid. Prints nothing if it is valid.
 */
int
set_seed (const char seed_str[])
{
//    Example of how to use sscanf to read a single integer and check for anything other than the integer
//    "int seed" will contain the number typed by the user (if any) and the string "post" will contain anything after the integer
//    The user should enter only an integer, and nothing else, so we will check that only "seed" is read. 
//    We declare
//    int seed;
//    char post[2];
//    The sscanf statement below reads the integer into seed. 
//    sscanf (seed_str, "%d%1s", &seed, post)
//    If there is no integer, seed will not be set. If something else is read after the integer, it will go into "post".
//    The return value of sscanf indicates the number of items read succesfully.
//    When the user has typed in only an integer, only 1 item should be read sucessfully. 
//    Check that the return value is 1 to ensure the user enters only an integer. 
//    Feel free to uncomment these statements, modify them, or delete these comments as necessary. 
//    You may need to change the return statement below
    int seed;
    char post[2];
    int valid = sscanf(seed_str, "%d%1s", &seed, post);//check if the input is valid
    if (valid == 1){//generate the randum using the seed
        srand(seed);
        return 1;
    }else{//print invalid statement if invalid
        printf("set_seed: invalid seed\n");
        return 0;
    }
    
}


/*
 * start_game -- This function is called by main.c after set_seed but before the user makes guesses.
 *               This function creates the four solution numbers using the approach
 *               described in the wiki specification (using rand())
 *               The four solution numbers should be stored in the static variables defined above. 
 *               The values at the pointers should also be set to the solution numbers.
 *               The guess_number should be initialized to 1 (to indicate the first guess)
 * INPUTS: none
 * OUTPUTS: *one -- the first solution value (between 1 and 8)
 *          *two -- the second solution value (between 1 and 8)
 *          *three -- the third solution value (between 1 and 8)
 *          *four -- the fourth solution value (between 1 and 8)
 * RETURN VALUE: none
 * SIDE EFFECTS: records the solution in the static solution variables for use by make_guess, set guess_number
 */
void
start_game (int* one, int* two, int* three, int* four)
{
    //your code here
    guess_number = 1;//initialize the guess number
    *one = rand() % 8 +1;//generate random number and store using the pointer
    *two = rand() % 8 +1;
    *three = rand() % 8 +1;
    *four = rand() % 8 +1;
    solution1 = *one;//load the value using the pointer
    solution2 = *two;
    solution3 = *three;
    solution4 = *four;
}

/*
 * make_guess -- This function is called by main.c after the user types in a guess.
 *               The guess is stored in the string guess_str. 
 *               The function must calculate the number of perfect and misplaced matches
 *               for a guess, given the solution recorded earlier by start_game
 *               The guess must be valid (contain only 4 integers, within the range 1-8). If it is valid
 *               the number of correct and incorrect matches should be printed, using the following format
 *               "With guess %d, you got %d perfect matches and %d misplaced matches.\n"
 *               If valid, the guess_number should be incremented.
 *               If invalid, the error message "make_guess: invalid guess\n" should be printed and 0 returned.
 *               For an invalid guess, the guess_number is not incremented.
 * INPUTS: guess_str -- a string consisting of the guess typed by the user
 * OUTPUTS: the following are only valid if the function returns 1 (A valid guess)
 *          *one -- the first guess value (between 1 and 8)
 *          *two -- the second guess value (between 1 and 8)
 *          *three -- the third guess value (between 1 and 8)
 *          *four -- the fourth color value (between 1 and 8)
 * RETURN VALUE: 1 if the guess string is valid (the guess contains exactly four
 *               numbers between 1 and 8), or 0 if it is invalid
 * SIDE EFFECTS: prints (using printf) the number of matches found and increments guess_number(valid guess) 
 *               or an error message (invalid guess)
 *               (NOTE: the output format MUST MATCH EXACTLY, check the wiki writeup)
 */
int
make_guess (const char guess_str[], int* one, int* two, 
	    int* three, int* four)
{
//  One thing you will need to read four integers from the string guess_str, using a process
//  similar to set_seed
//  The statement, given char post[2]; and four integers w,x,y,z,
//  sscanf (guess_str, "%d%d%d%d%1s", &w, &x, &y, &z, post)
//  will read four integers from guess_str into the integers and read anything else present into post
//  The return value of sscanf indicates the number of items sucessfully read from the string.
//  You should check that exactly four integers were sucessfully read.
//  You should then check if the 4 integers are between 1-8. If so, it is a valid guess
//  Otherwise, it is invalid.  
//  Feel free to use this sscanf statement, delete these comments, and modify the return statement as needed
    int w,x,y,z,valid_v,p_m,m_m;//set the valriable to use in this function
    char post[2];//set the char to check for input
    int valid_s = sscanf(guess_str,"%d%d%d%d%1s",&w,&x,&y,&z, post);
    if(0<w && w<9 && 0<x && x<9 && 0<y && y<9 && 0<z && z<9){//check the input value is in the correct range
        valid_v = 1;
    }
    if(valid_s == 4 && valid_v == 1){//if the value is valid, go check the number
        p_m = 0;
        m_m = 0;
        int one_p, two_p, thr_p, four_p = 0;
        *one = w;//store the value
        *two = x;
        *three = y;
        *four = z;
    //check perfect match
        if(*one == solution1){
            p_m++;
            one_p = 1;
        }
        if(*two == solution2){
            p_m++;
            two_p = 1;
        }
        if(*three == solution3){
            p_m++;
            thr_p = 1;
        }
        if(*four == solution4){
            p_m++;
            four_p = 1;
        }
    //check miss match

        if(one_p !=1){
            if(two_p != 1 && *one == solution2){
                m_m++;
            }else if(thr_p != 1 && *one == solution3){
                m_m++;
            }else if(four_p != 1 && *one == solution4){
                m_m++;
            }
        }
        if(two_p !=1){
            if(one_p != 1 && *two == solution1){
                m_m++;
            }else if(thr_p != 1 && *two == solution3){
                m_m++;
            }else if(four_p != 1 && *two == solution4){
                m_m++;
            }
        }
        if(thr_p !=1){
            if(two_p != 1 && *three == solution2){
                m_m++;
            }else if(one_p != 1 && *three == solution1){
                m_m++;
            }else if(four_p != 1 && *three == solution4){
                m_m++;
            }
        }
        if(four_p !=1){
            if(two_p != 1 && *four == solution2){
                m_m++;
            }else if(thr_p != 1 && *four == solution3){
                m_m++;
            }else if(one_p != 1 && *four == solution1){
                m_m++;
            }
        }
        //print the current status using printf
        printf("With guess %d, you got %d perfect matches and %d misplaced matches.\n",guess_number,p_m,m_m);
        guess_number++;
        return 1;
    }else{//print invalid message
        printf("make_guess: invalid guess\n");
        return 0;
    }
}


