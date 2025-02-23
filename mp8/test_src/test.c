#include "../game.h"
#include "../getch_fun.h"
#include "game_test.h"
#include <string.h>

int main(){
	
	/*If you wish to make your own test cases against the gold code, all of the functions
	that you need to implement can be called with an underscore before the function. For example
	to call the gold version of make_game(), use the function _make_game(). See game_test.h */
	
	game * game1 = make_game(14,32);
	if( game1 == NULL){
		printf("test 1: fail - make_game() does not return a pointer correctly\n");
		exit(0);
	}
	else{
		printf("test 1: pass - make_game() returns pointer to game structure\n");
	}
	
	cell * cell_ptr1;
	cell_ptr1 = game1->cells;
	int i;
	
	
	
	if( cell_ptr1 == NULL){
		printf("test 2: fail - make_game() cell pointer is not initialized\n");
		exit(0);
	}
	else{
		printf("test 2: pass - make_game() returns pointer to game structure\n");
	}
	
	

	int flag = 0;
	for(i = 0; i < 14*32;i++){
		if(*cell_ptr1 != -1){
			flag = 1;
			printf("test 3: fail - cells are not initialized\n");
			break;
		}
		cell_ptr1++;
	}
	
	if( flag == 0){
		printf("test 3: pass - cells are initialized to -1\n");
	}
	
	if(( game1->rows == 14 )&&	(game1->cols == 32 )){
		printf("test 4: pass - number of rows and cols stored correctly\n");
	}
	else{
		printf("test 4: fail - number of rows and cols stored incorrectly\n");
	}
	
	game * game_orig;
	cell * cell_ptr_orig;
	cell * ptr1;
	cell * ptr2;
	
	game_orig = _make_game(4,3);
	game * game_cpy1 = _make_game(4,3);
	game * game_cpy2 = _make_game(4,3);
	
	cell_ptr_orig = game_orig->cells;
	
	ptr1 = game_cpy1->cells;
	ptr2 = game_cpy2->cells;
	
	cell temparray[12] = {2, 4, 4, 8, 4, -1, -1, 4, -1, 2, 4, 8};
	for( i =0; i<12;i++){
		*cell_ptr_orig = temparray[i];
		*ptr1 = temparray[i];
		*ptr2 = temparray[i];
		cell_ptr_orig++;
		ptr1++;
		ptr2++;
	}
	
	//print_game(game_cpy2);
	
	if( move_w(game_cpy1) == _move_w(game_cpy2))
		printf("test 5: pass - move_w returns the correct value\n");
	else
		printf("test 5: fail - move_w returns the incorrect value\n");
	
	
	ptr1 = game_cpy1->cells;
	ptr2 = game_cpy2->cells;
	
	for( i = 0; i < 12; i ++){
		if (*ptr1 != *ptr2){
			printf("test 6: fail - move_w does not move tiles correctly\n");
			//exit(0);
			printf("Your output:");
			print_game(game_cpy1);
			printf("Correct output:");
			print_game(game_cpy2);
			exit(0);
		}
		ptr1++;
		ptr2++;
	}
	printf("test 6: pass - move_w moves the tiles around correctly\n");
	
	
	
	
	if( move_a(game_cpy1) == _move_a(game_cpy2))
		printf("test 7: pass - move_a returns the correct value\n");
	else
		printf("test 7: fail - move_a returns the incorrect value\n");
	
			
	ptr1 = game_cpy1->cells;
	ptr2 = game_cpy2->cells;
	
	for( i = 0; i < 12; i ++){
		if (*ptr1 != *ptr2){
			printf("test 8: fail - move_a does not move tiles correctly\n");
			printf("Your output:");
			print_game(game_cpy1);
			printf("Correct output:");
			print_game(game_cpy2);
			exit(0);
		}
		ptr1++;
		ptr2++;
	}
	printf("test 8: pass - move_a moves the tiles around correctly\n");
	
	
	if( move_a(game_cpy1) == _move_a(game_cpy2))
		printf("test 9: pass - move_a returns the correct value\n");
	else
		printf("test 9: fail - move_a returns the incorrect value\n");
	

	
	
	if( move_d(game_cpy1) == _move_d(game_cpy2))
		printf("test 10: pass - move_d returns the correct value\n");
	else
		printf("test 10: fail - move_d returns the incorrect value\n");
	
			
	ptr1 = game_cpy1->cells;
	ptr2 = game_cpy2->cells;
	
	for( i = 0; i < 12; i ++){
		if (*ptr1 != *ptr2){
			printf("test 11: fail - move_d does not move tiles correctly\n");
			printf("Your output:");
			print_game(game_cpy1);
			printf("Correct output:");
			print_game(game_cpy2);
			exit(0);
		}
		ptr1++;
		ptr2++;
	}
	printf("test 11: pass - move_d moves the tiles around correctly\n");
	
	remake_game(&game_cpy1,12,8);
	
	if(game_cpy1 == NULL){
		printf("1test 12: fail - remake game does not work correctly.\n");
		exit(0);
	}
	if(game_cpy1->cells == NULL){
		printf("2test 12: fail - remake game causes cells to point to NULL.\n");
		exit(0);
	}
	
	ptr1 = game_cpy1->cells;
	
	if(!(game_cpy1->rows == 12 && game_cpy1->cols==8)){
		printf("3test 12: fail - remake game does not set rows / cols correctly.\n");
		exit(0);
	}
	
	for(i = 0; i < 12*8 ; i++){
		if(*ptr1 != -1){
			printf("test 12: fail - remake game does not initialize cells.\n");
			exit(0);
		}
		ptr1++;
	}
	printf("test 12: pass - remake game works correctly.\n");
	
	
	
	
	//print_game(game_cpy2);
	//print_game(game_cpy1);
	
	return 0;
}
