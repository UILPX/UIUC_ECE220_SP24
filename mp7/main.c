#include "sudoku.h"
#include "sudoku_golden.h"

int main(int argc, char **argv) {

  int sudoku[9][9];

  if(argc != 2) {
    printf("Usage: ./mp7 sudoku_instance.txt\n");
    exit(EXIT_FAILURE);
  }

  printf("------------------\n");
  parse_sudoku(argv[1], sudoku);
  printf("Input sudoku:\n");
  print_sudoku(sudoku);
  
  solve_sudoku(sudoku);
  printf("Your output sudoku:\n");
  print_sudoku(sudoku);
  printf("------------------\n");


  golden_score_checker(argv[1], sudoku);
  
  return 0;
}
