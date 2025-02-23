#include "curses.h"
#include <stdlib.h>
#include <unistd.h>
#include "updateBoard.h"
int main(){
	int row,col,ret,step;
	step = 0;
	printf("Input the dimension m n for the game board:");
	ret = scanf("%d %d",&row,&col);
	if(ret != 2){
		printf("Two inputs needed!\n");
		return 0;
	}
	printf("Rows:%d,Cols:%d\n",row,col);
	int* game_board = malloc(row*col*sizeof(int));
	int i,j;
	for(i = 0; i < row; i++){
		for(j = 0; j < col; j++){
			ret = scanf("%d",&game_board[col*i+j]);
			if(ret != 1){
				printf("Board input wrong at row:%d,col:%d\n",row,col);
				return 0;
			}
		}
	}
	initscr();
	while(1){
		clear();
		for(i=0;i<row;i++){
			for(j=0;j<col;j++){
				if(game_board[col*i+j]==1){
					printw("X");
				}
				else{
					printw(".");
				}
			}
			printw("\n");
		}
		refresh();
		sleep(1);
		if( aliveStable(game_board,row,col)){
			endwin();
			printf("No More Changes, Game Ended\n");
			return 0;
		}
		if(step >= 20){
			endwin();
			printf("20 steps reached. Simulation ended\n");
			return 0;
		}	
		updateBoard(game_board,row,col);
		step++;
	}
	endwin();
	return 0;
}
