#include <stdlib.h>
#include <stdio.h>
#include "updateBoard.h"
#include "updateBoardGold.h"

const unsigned num_steps = 1000; //modify this to change the number of steps updated through

const int row = 18; //constants for how many rows and cols there are (change if changing the initial board)
const int col = 35;

//initial status of the board (can be modified to do your own tests)
const int initial[18*35] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
                            1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,
                            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,
                            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,
                            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,
                            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,1,1,0,0,0,0,0,0,0,0,0,
                            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,0,0,0,0,0,
                            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,1,1,0,0,0,0,0,0,0,0,0,
                            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,
                            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,
                            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,
                            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,
                            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

int main(){
  int step;
  int i,j;
  
  //initial block for board (with 2 extra rows to check for OOB up/down in countLiveNeighbor)
  int *gb_stu_alloc = (int*) malloc(sizeof(int) * (row+2) * col);
  
  //intial game board (shifted one row forward for top/bottom padding to fill with ones)
  int *game_board_stu = gb_stu_alloc+col;
  
  int *game_board_gold = (int*) malloc(sizeof(int) * row * col); //initial gold game board (no need for padding)
  
  //fill top and bottom rows with ones for OOB testing
  for(i=0;i<col;i++){
    gb_stu_alloc[i]=1; //fill from the start
    gb_stu_alloc[(row+2)*col-1-i]=1; //fill from the end
  }      
  
  //fill student and gold boards
  for(i = 0; i < row*col; i++)
  {
   game_board_gold[i] = initial[i];
   game_board_stu[i] = initial[i];
  }

  //countLiveNeighbor test
  int stuCount,goldCount;
  for(i=0;i<row;i++){
   for(j=0;j<col;j++){
      stuCount = countLiveNeighbor(game_board_stu, row, col, i, j);
      goldCount = countLiveNeighbor_gold(game_board_gold,row,col,i,j);
      if(stuCount != goldCount){
         printf("countLiveNeighbor test failed\n");
         free(game_board_gold);
         free(gb_stu_alloc);
         return 0;
      }
   }
  }
  printf("countLiveNeighbor test passed\n");
  
  int stabilityFail = 0; //updated to 1 if stability ever disagrees in loop (without ruining update test)
  
  //board update test (goes through num_steps updates, stability checking for flag only)
  for(step=0;step<num_steps;step++){
   updateBoard_gold(game_board_gold,row,col);
   updateBoard(game_board_stu,row,col);
   for(i=0;i<row;i++){
      for(j=0;j<col;j++){
         if(game_board_stu[i*col+j]!= game_board_gold[i*col+j]){
            printf("updateBoard test failed\n");
            free(game_board_gold);
            free(gb_stu_alloc);
            return 0;
         }
      }
   }
   //check if stability functions disagree about identical boards
   if(aliveStable_gold(game_board_gold,row,col)!=aliveStable(game_board_stu,row,col))stabilityFail=1;
  }
  printf("updateBoard test passed\n");
  
  //stability checking (after all num_steps steps iterated through)
  if(!aliveStable_gold(game_board_stu,row,col)){
   printf("updateBoard test stopped after %u steps (no stable state reached)\n",num_steps);
  }
  if(stabilityFail){ //student stability function wrong at some point
     printf("aliveStable test failed\n");
  }
  else{
     printf("aliveStable test passed\n");
  }
  free(game_board_gold);
  free(gb_stu_alloc);
  return 0;
}
