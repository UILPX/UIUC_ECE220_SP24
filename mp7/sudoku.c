#include "sudoku.h"

//-------------------------------------------------------------------------------------------------
// Start here to work on your MP7
//-------------------------------------------------------------------------------------------------
/*
The provided code consists of functions and procedures aimed at solving Sudoku puzzles. 
The is_val_in_row, is_val_in_col, and is_val_in_3x3_zone functions check if a given value 
exists in the specified row, column, or 3x3 zone of the Sudoku grid, respectively. The 
is_val_valid function verifies if a value can be placed at a certain position in the 
Sudoku grid without violating the puzzle's rules. The solve_sudoku function recursively 
attempts to solve the Sudoku puzzle using backtracking. Overall, these functionalities 
provide the necessary tools to analyze, solve, and interact with Sudoku puzzles programmatically.
*/


// You are free to declare any private functions if needed.

// Function: is_val_in_row
// Return true if "val" already existed in ith row of array sudoku.
int is_val_in_row(const int val, const int i, const int sudoku[9][9]) {

  assert(i>=0 && i<9);

  // BEG TODO
  for(int j=0;j<9;j++){//go through every value in this row
    if(sudoku[i][j]==val){//check if this value already exist.
      return 1;
    }
  }
  return 0;
  // END TODO
}

// Function: is_val_in_col
// Return true if "val" already existed in jth column of array sudoku.
int is_val_in_col(const int val, const int j, const int sudoku[9][9]) {

  assert(j>=0 && j<9);

  // BEG TODO
  for(int i=0;i<9;i++){//go through every value is this collume
    if(sudoku[i][j]==val){//check if the number alrady exist in this collume
      return 1;
    }
  }
  return 0;
  // END TODO
}

// Function: is_val_in_3x3_zone
// Return true if val already existed in the 3x3 zone corresponding to (i, j)
int is_val_in_3x3_zone(const int val, const int i, const int j, const int sudoku[9][9]) {
   
  assert(i>=0 && i<9);
  
  // BEG TODO
  int i_start = i-(i%3);//set the starting point of the 3x3 matrix it belong
  int j_start = j-(j%3);

  for(int x=i_start;x<i_start+3;x++){//go through every collume in this group
    for(int y=j_start;y<j_start+3;y++){//go through every row in this group
      if(sudoku[x][y]==val){//check if the value conflict
        return 1;
      }
    }
  }

  return 0;
  // END TODO
}

// Function: is_val_valid
// Return true if the val is can be filled in the given entry.
int is_val_valid(const int val, const int i, const int j, const int sudoku[9][9]) {

  assert(i>=0 && i<9 && j>=0 && j<9);

  // BEG TODO
  if(is_val_in_3x3_zone(val,i,j,sudoku) || is_val_in_col(val,j,sudoku) || is_val_in_row(val,i,sudoku)){
    return 0;//check all the three condisions to see if the value is valid to be here
  }
  return 1;
  // END TODO
}

// Procedure: solve_sudoku
// Solve the given sudoku instance.
int solve_sudoku(int sudoku[9][9]) {

  // BEG TODO.
  int i, j;
  for(i=0;i<9;i++){//go through each collume
    for(j=0;j<9;j++){//go through each row
      if(sudoku[i][j]==0){//check if that spot is empty
        goto fill;//if empty, try fill the spot
      }
    }
  }

  fill:
  if(i == 9 && j==9){//if index is alrady 9, return1
    return 1;
  }
  for (int num = 1; num <= 9; num++) { //go through every number posible
    if (is_val_valid(num,i,j,sudoku)) {//check if the value is valid in the spot
      sudoku[i][j] = num;
      if (solve_sudoku(sudoku)) {//check if the sudoku can be sulved with the number
        return 1;
      }
      sudoku[i][j] = 0; //set the value back to 0 if the test did not pass
    }
  }
  return 0;
  // END TODO.
}

// Procedure: print_sudoku
void print_sudoku(int sudoku[9][9])
{
  int i, j;
  for(i=0; i<9; i++) {
    for(j=0; j<9; j++) {
      printf("%2d", sudoku[i][j]);
    }
    printf("\n");
  }
}

// Procedure: parse_sudoku
void parse_sudoku(const char fpath[], int sudoku[9][9]) {
  FILE *reader = fopen(fpath, "r");
  assert(reader != NULL);
  int i, j;
  for(i=0; i<9; i++) {
    for(j=0; j<9; j++) {
      fscanf(reader, "%d", &sudoku[i][j]);
    }
  }
  fclose(reader);
}





