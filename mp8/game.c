#include "game.h"
/*
This file houses key functions essential for playing the game 2048 within main.c. 
Authored functions include make_game, remake_game, get_cell, move_w, move_s, move_a, 
move_d, and legal_move_check.

make_game initializes a new game struct with specified rows, columns, score, and 
cell array. remake_game adjusts an existing game struct to accommodate new row and 
column dimensions.

get_cell retrieves a pointer to a designated cell based on row and column coordinates. 
The move functions drive gameplay by shifting cells and combining them as per game rules.

legal_move_check assesses available moves by checking for empty cells and matching 
neighboring cell values. These functions form the core mechanics of the game.
*/

game * make_game(int rows, int cols)
/*! Create an instance of a game structure with the given number of rows
    and columns, initializing elements to -1 and return a pointer
    to it. (See game.h for the specification for the game data structure) 
    The needed memory should be dynamically allocated with the malloc family
    of functions.
*/
{
    //Dynamically allocate memory for game and cells (DO NOT modify this)
    game * mygame = malloc(sizeof(game));
    mygame->cells = malloc(rows*cols*sizeof(cell));

    //YOUR CODE STARTS HERE:  Initialize all other variables in game struct
    (*mygame).score = 0;//set score to 0
    (*mygame).rows = rows;//set new row
    (*mygame).cols = cols;//set new col
    for(int i=0;i<rows*cols;i++){//set every cell to -1
        *((*mygame).cells +i) = -1;
    }
    return mygame;//return the pointer
}

void remake_game(game ** _cur_game_ptr,int new_rows,int new_cols)
/*! Given a game structure that is passed by reference, change the
	game structure to have the given number of rows and columns. Initialize
	the score and all elements in the cells to -1. Make sure that any 
	memory previously allocated is not lost in this function.	
*/
{
	/*Frees dynamically allocated memory used by cells in previous game,
	 then dynamically allocates memory for cells in new game.  DO NOT MODIFY.*/
	free((*_cur_game_ptr)->cells);
	(*_cur_game_ptr)->cells = malloc(new_rows*new_cols*sizeof(cell));

	 //YOUR CODE STARTS HERE:  Re-initialize all other variables in game struct
    (**_cur_game_ptr).score = 0;//reset score to 0
    (**_cur_game_ptr).rows = new_rows;//set new row
    (**_cur_game_ptr).cols = new_cols;//set new col
    for(int i=0;i<new_rows*new_cols;i++){//set every cell to -1
        *((**_cur_game_ptr).cells +i) = -1;
    }
	return;	
}

void destroy_game(game * cur_game)
/*! Deallocate any memory acquired with malloc associated with the given game instance.
    This includes any substructures the game data structure contains. Do not modify this function.*/
{
    free(cur_game->cells);
    free(cur_game);
    cur_game = NULL;
    return;
}

cell * get_cell(game * cur_game, int row, int col)
/*! Given a game, a row, and a column, return a pointer to the corresponding
    cell on the game. (See game.h for game data structure specification)
    This function should be handy for accessing game cells. Return NULL
	if the row and col coordinates do not exist.
*/
{
    //YOUR CODE STARTS HERE
    if(row < 0 || (*cur_game).rows <= row){//retune null if the row is not in the range
        return NULL;
    }
    if(col < 0 || (*cur_game).cols <= col){//retune null if the col is not in the range
        return NULL;
    }
    return (*cur_game).cells + row * (*cur_game).cols + col;//return the printer of the cell.
}

int move_w(game * cur_game)
/*!Slides all of the tiles in cur_game upwards. If a tile matches with the 
   one above it, the tiles are merged by adding their values together. When
   tiles merge, increase the score by the value of the new tile. A tile can 
   not merge twice in one turn. If sliding the tiles up does not cause any 
   cell to change value, w is an invalid move and return 0. Otherwise, return 1. 
*/
{

    int flag = 0; // Signal a change in game

    for (int col = 0; col < cur_game->cols; col++) {
        int last_combined_row = -2; // Last row where cells were combined
        for (int row = 1; row < cur_game->rows; row++) {
            cell current_cell = cur_game->cells[row * cur_game->cols + col];

            if (current_cell != -1) { // Non-empty cell
                int target_row = row; // Reset target row
                // Find the target row for the current cell
                for (int k = 0; k < row; k++) {
                    cell cell_above = cur_game->cells[k * cur_game->cols + col];
                    if (cell_above == -1) {
                        target_row = k;
                        break;
                    }
                }
                // Move the cell to the target row if necessary
                if (target_row != row) {
                    cur_game->cells[target_row * cur_game->cols + col] = current_cell;
                    cur_game->cells[row * cur_game->cols + col] = -1;
                    flag = 1; // Signal a change in game
                }

                // Combine cells if conditions are met
                if (target_row - 1 != last_combined_row &&
                    cur_game->cells[(target_row - 1) * cur_game->cols + col] == current_cell) {
                    cur_game->cells[(target_row - 1) * cur_game->cols + col] *= 2;
                    cur_game->cells[target_row * cur_game->cols + col] = -1;
                    last_combined_row = target_row - 1;
                    flag = 1; // Signal a change in game
                    cur_game->score += cur_game->cells[(target_row - 1) * cur_game->cols + col];
                }
            }
        }
    }

    return flag;
}



int move_s(game * cur_game) //slide down
{
    //YOUR CODE STARTS HERE
    int flag = 0; // Signal a change in game

    for (int col = 0; col < cur_game->cols; col++) {
        int last_combined_row = cur_game->rows; // Last row where cells were combined, initialize to a value outside the range of rows
        for (int row = cur_game->rows - 2; row >= 0; row--) { // Iterate backward from the second last row
            cell current_cell = cur_game->cells[row * cur_game->cols + col];

            if (current_cell != -1) { // Non-empty cell
                int target_row = row; // Reset target row
                // Find the target row for the current cell
                for (int k = cur_game->rows - 1; k > row; k--) { // Iterate backward from the last row
                    cell cell_below = cur_game->cells[k * cur_game->cols + col];
                    if (cell_below == -1) {
                        target_row = k;
                        break;
                    }
                }
                // Move the cell to the target row if necessary
                if (target_row != row) {
                    cur_game->cells[target_row * cur_game->cols + col] = current_cell;
                    cur_game->cells[row * cur_game->cols + col] = -1;
                    flag = 1; // Signal a change in game
                }

                // Combine cells if conditions are met
                if (target_row + 1 != last_combined_row &&
                    cur_game->cells[(target_row + 1) * cur_game->cols + col] == current_cell) {
                    cur_game->cells[(target_row + 1) * cur_game->cols + col] *= 2;
                    cur_game->cells[target_row * cur_game->cols + col] = -1;
                    last_combined_row = target_row + 1;
                    flag = 1; // Signal a change in game
                    cur_game->score += cur_game->cells[(target_row + 1) * cur_game->cols + col];
                }
            }
        }
    }

    return flag;
}

int move_a(game * cur_game) //slide left
{
    //YOUR CODE STARTS HERE
    int flag = 0; // Signal a change in game

    for (int row = 0; row < cur_game->rows; row++) {
        int last_combined_col = -2; // Last column where cells were combined
        for (int col = 1; col < cur_game->cols; col++) { // Iterate from the second column
            cell current_cell = cur_game->cells[row * cur_game->cols + col];

            if (current_cell != -1) { // Non-empty cell
                int target_col = col; // Reset target column
                // Find the target column for the current cell
                for (int k = 0; k < col; k++) {
                    cell cell_left = cur_game->cells[row * cur_game->cols + k];
                    if (cell_left == -1) {
                        target_col = k;
                        break;
                    }
                }
                // Move the cell to the target column if necessary
                if (target_col != col) {
                    cur_game->cells[row * cur_game->cols + target_col] = current_cell;
                    cur_game->cells[row * cur_game->cols + col] = -1;
                    flag = 1; // Signal a change in game
                }

                // Combine cells if conditions are met
                if (target_col - 1 != last_combined_col &&
                    cur_game->cells[row * cur_game->cols + target_col - 1] == current_cell) {
                    cur_game->cells[row * cur_game->cols + target_col - 1] *= 2;
                    cur_game->cells[row * cur_game->cols + target_col] = -1;
                    last_combined_col = target_col - 1;
                    flag = 1; // Signal a change in game
                    cur_game->score += cur_game->cells[row * cur_game->cols + target_col - 1];
                }
            }
        }
    }

    return flag;
}

int move_d(game * cur_game){ //slide to the right
    //YOUR CODE STARTS HERE
    int flag = 0; // Signal a change in game

    for (int row = 0; row < cur_game->rows; row++) {
        int last_combined_col = cur_game->cols; // Last column where cells were combined, initialize to a value outside the range of columns
        for (int col = cur_game->cols - 2; col >= 0; col--) { // Iterate backward from the second last column
            cell current_cell = cur_game->cells[row * cur_game->cols + col];

            if (current_cell != -1) { // Non-empty cell
                int target_col = col; // Reset target column
                // Find the target column for the current cell
                for (int k = cur_game->cols - 1; k > col; k--) { // Iterate backward from the last column
                    cell cell_right = cur_game->cells[row * cur_game->cols + k];
                    if (cell_right == -1) {
                        target_col = k;
                        break;
                    }
                }
                // Move the cell to the target column if necessary
                if (target_col != col) {
                    cur_game->cells[row * cur_game->cols + target_col] = current_cell;
                    cur_game->cells[row * cur_game->cols + col] = -1;
                    flag = 1; // Signal a change in game
                }

                // Combine cells if conditions are met
                if (target_col + 1 != last_combined_col &&
                    cur_game->cells[row * cur_game->cols + target_col + 1] == current_cell) {
                    cur_game->cells[row * cur_game->cols + target_col + 1] *= 2;
                    cur_game->cells[row * cur_game->cols + target_col] = -1;
                    last_combined_col = target_col + 1;
                    flag = 1; // Signal a change in game
                    cur_game->score += cur_game->cells[row * cur_game->cols + target_col + 1];
                }
            }
        }
    }

    return flag;
}

int legal_move_check(game * cur_game)
/*! Given the current game check if there are any legal moves on the board. There are
    no legal moves if sliding in any direction will not cause the game to change.
	Return 1 if there are possible legal moves, 0 if there are none.
 */
{
    //YOUR CODE STARTS HERE
    game * new_game = make_game((*cur_game).rows,(*cur_game).cols);//make a new board to check if there is any posible move.
    for(int i = 0;i < (*cur_game).rows * (*cur_game).cols;i++){
        *((*new_game).cells+i)=*((*cur_game).cells+i);//copy every value to the new board
    }
    if(move_w(new_game) || move_a(new_game) || move_s(new_game) || move_d(new_game)){//check if there is any posible move
        return 1;
    }else{
        return 0;
    }
    
}


/*! code below is provided and should not be changed */

void rand_new_tile(game * cur_game)
/*! insert a new tile into a random empty cell. First call rand()%(rows*cols) to get a random value between 0 and (rows*cols)-1.
*/
{
	
	cell * cell_ptr;
    cell_ptr = 	cur_game->cells;
	
    if (cell_ptr == NULL){ 	
        printf("Bad Cell Pointer.\n");
        exit(0);
    }
	
	
	//check for an empty cell
	int emptycheck = 0;
	int i;
	
	for(i = 0; i < ((cur_game->rows)*(cur_game->cols)); i++){
		if ((*cell_ptr) == -1){
				emptycheck = 1;
				break;
		}		
        cell_ptr += 1;
	}
	if (emptycheck == 0){
		printf("Error: Trying to insert into no a board with no empty cell. The function rand_new_tile() should only be called after tiles have succesfully moved, meaning there should be at least 1 open spot.\n");
		exit(0);
	}
	
    int ind,row,col;
	int num;
    do{
		ind = rand()%((cur_game->rows)*(cur_game->cols));
		col = ind%(cur_game->cols);
		row = ind/cur_game->cols;
    } while ( *get_cell(cur_game, row, col) != -1);
        //*get_cell(cur_game, row, col) = 2;
	num = rand()%20;
	if(num <= 1){
		*get_cell(cur_game, row, col) = 4; // 1/10th chance
	}
	else{
		*get_cell(cur_game, row, col) = 2;// 9/10th chance
	}
}

int print_game(game * cur_game) 
{
    cell * cell_ptr;
    cell_ptr = 	cur_game->cells;

    int rows = cur_game->rows;
    int cols = cur_game->cols;
    int i,j;
	
	printf("\n\n\nscore:%d\n",cur_game->score); 
	
	
	printf("\u2554"); // topleft box char
	for(i = 0; i < cols*5;i++)
		printf("\u2550"); // top box char
	printf("\u2557\n"); //top right char 
	
	
    for(i = 0; i < rows; i++){
		printf("\u2551"); // side box char
        for(j = 0; j < cols; j++){
            if ((*cell_ptr) == -1 ) { //print asterisks
                printf(" **  "); 
            }
            else {
                switch( *cell_ptr ){ //print colored text
                    case 2:
                        printf("\x1b[1;31m%04d\x1b[0m ",(*cell_ptr));
                        break;
                    case 4:
                        printf("\x1b[1;32m%04d\x1b[0m ",(*cell_ptr));
                        break;
                    case 8:
                        printf("\x1b[1;33m%04d\x1b[0m ",(*cell_ptr));
                        break;
                    case 16:
                        printf("\x1b[1;34m%04d\x1b[0m ",(*cell_ptr));
                        break;
                    case 32:
                        printf("\x1b[1;35m%04d\x1b[0m ",(*cell_ptr));
                        break;
                    case 64:
                        printf("\x1b[1;36m%04d\x1b[0m ",(*cell_ptr));
                        break;
                    case 128:
                        printf("\x1b[31m%04d\x1b[0m ",(*cell_ptr));
                        break;
                    case 256:
                        printf("\x1b[32m%04d\x1b[0m ",(*cell_ptr));
                        break;
                    case 512:
                        printf("\x1b[33m%04d\x1b[0m ",(*cell_ptr));
                        break;
                    case 1024:
                        printf("\x1b[34m%04d\x1b[0m ",(*cell_ptr));
                        break;
                    case 2048:
                        printf("\x1b[35m%04d\x1b[0m ",(*cell_ptr));
                        break;
                    case 4096:
                        printf("\x1b[36m%04d\x1b[0m ",(*cell_ptr));
                        break;
                    case 8192:
                        printf("\x1b[31m%04d\x1b[0m ",(*cell_ptr));
                        break;
					default:
						printf("  X  ");

                }

            }
            cell_ptr++;
        }
	printf("\u2551\n"); //print right wall and newline
    }
	
	printf("\u255A"); // print bottom left char
	for(i = 0; i < cols*5;i++)
		printf("\u2550"); // bottom char
	printf("\u255D\n"); //bottom right char
	
    return 0;
}

int process_turn(const char input_char, game* cur_game) //returns 1 if legal move is possible after input is processed
{ 
	int rows,cols;
	char buf[200];
	char garbage[2];
    int move_success = 0;
	
    switch ( input_char ) {
    case 'w':
        move_success = move_w(cur_game);
        break;
    case 'a':
        move_success = move_a(cur_game);
        break;
    case 's':
        move_success = move_s(cur_game);
        break;
    case 'd':
        move_success = move_d(cur_game);
        break;
    case 'q':
        destroy_game(cur_game);
        printf("\nQuitting..\n");
        return 0;
        break;
	case 'n':
		//get row and col input for new game
		dim_prompt: printf("NEW GAME: Enter dimensions (rows columns):");
		while (NULL == fgets(buf,200,stdin)) {
			printf("\nProgram Terminated.\n");
			return 0;
		}
		
		if (2 != sscanf(buf,"%d%d%1s",&rows,&cols,garbage) ||
		rows < 0 || cols < 0){
			printf("Invalid dimensions.\n");
			goto dim_prompt;
		} 
		
		remake_game(&cur_game,rows,cols);
		
		move_success = 1;
		
    default: //any other input
        printf("Invalid Input. Valid inputs are: w, a, s, d, q, n.\n");
    }

	
	
	
    if(move_success == 1){ //if movement happened, insert new tile and print the game.
         rand_new_tile(cur_game); 
		 print_game(cur_game);
    } 

    if( legal_move_check(cur_game) == 0){  //check if the newly spawned tile results in game over.
        printf("Game Over!\n");
        return 0;
    }
    return 1;
}
