#include "game.h"
#include "getch_fun.h"
#include <malloc.h>

int main(int argc, char *argv[])
{
	int rows,cols;
	char buf[200];
	char garbage[2];
	printf("2048: Enter dimensions (rows columns):");
	if (NULL == fgets(buf,200,stdin)) {
		printf("\nProgram Terminated.\n");
		return 2;
	}
	if (2 != sscanf(buf,"%d%d%1s",&rows,&cols,garbage) ||
	rows < 0 || cols < 0){
		printf("invalid dimensions\n");
		return 2;
	}
	
    game * cur_game = make_game(rows,cols); //make new game entity called cur_game and insert the first random tile
	if( cur_game == NULL ){
		printf("Bad game pointer\n");
		return 2;
	}
    printf("%lf\n",((double)malloc_usable_size(cur_game->cells))/sizeof(int));	
    rand_new_tile(cur_game);
    print_game(cur_game);

    char c;
    do {
        c = getch(); //get character input; does not require a return keypress after input. See getch_fun.c

    }while( process_turn(c, cur_game ) == 1); //call process_turn and check if successful



	return 0;
}
