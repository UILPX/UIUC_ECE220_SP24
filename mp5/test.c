#include <stdlib.h>
#include <stdio.h>

/* 
 * Your code is included as part of this file.
 */
#include "prog5.h"




int 
main (int argc, char *argv[] )
{
    if (argc == 1){
	printf("Enter Test No, 0 for set_seed, 1 for start_game, 2 for make_guess\n");
	return 0;
    }
    int command;
    sscanf(argv[1],"%d",&command);
    if (command == 0){
	int score = 0;
	printf("Testing set_seed:\n");
	int ret = set_seed("what?");
	int ret2 = set_seed("12321");
	if(ret==0 && ret2==1){
		printf("set_seed return value correct (10pts)\n");
		score = score+10;		
	}else{
		printf("set_seed return value incorrect (0pts)\n");
	}
	set_seed("12325");
        int test = rand();
	if (test == 18534142){
		printf("set_seed call srand correct (10pts)\n");
		score = score+10;				
	}else{
		printf("set_seed call srand incorrect (0pts)\n");
	}
	printf("*******total set_seed score: %d/20*******\n",score);
    }
    if (command == 1){
	int score = 0;
	printf("Testing start_game:\n");
	int one,two,three,four;
	srand(12321);
	start_game(&one,&two,&three,&four);
	int test=rand();
	if (test == 1385017724){
		printf("start_game random number correct (15pts)\n");
		score = score+15;
	}else{
		printf("start_game random number incorrect (0pts)\n");
        }
	if (one == 8 && two==4 && three==8 && four==8){
		printf("start_game output correct (5pts)\n");
		score = score+5;
	}else{
		printf("start_game output incorrect (0pts)\n");
	}
	printf("*******total start_game score: %d/20*******\n",score);
    }
    if (command == 2){
	int score = 0;
	printf("Testing make_guess output:\n");
	int one,two,three,four;
	srand(12321);
	start_game(&one,&two,&three,&four);
	int ret = make_guess("blahblah",&one,&two,&three,&four);
	int ret2 = make_guess("1 2 3 4",&one,&two,&three,&four);
	if (ret==0 && ret2==1){
		printf("make_guess return value correct (10pts) \n");
		score = score+10;
	}else{
		printf("make_guess return value incorrect (0pts) \n");
        }
	ret = make_guess("8 4 8 8",&one,&two,&three,&four);
	if (one==8 && two==4 && three==8 && four==8){
		printf("make_guess output value correct (10pts)\n");
		score = score+10;
	}else{
		printf("make_guess output value incorrect (0pts)\n");	
	}
	printf("*******make_guess output score: %d/20*******\n",score);
    }
    if (command==3){
	int one,two,three,four;
	srand(12321);
	start_game(&one,&two,&three,&four);
	printf("*******make_guess perfect: If next line shows 4 perfect, 0 misplaced, 10/10*******\n");
	make_guess("8 4 8 8",&one,&two,&three,&four);
    }
    if (command==4){
	int one,two,three,four;
	srand(12321);
	start_game(&one,&two,&three,&four);
	printf("*******make_guess perfect: If next line shows 0 perfect, 2 misplaced, 10/10*******\n");
	make_guess("1 8 4 1",&one,&two,&three,&four);
    }
    return 0;
}

