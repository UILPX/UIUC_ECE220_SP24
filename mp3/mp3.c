/* this project is to output a row of Pascal's triangle based on user input. The value to output can be determind through the formula provided.
 */
#include <stdio.h>
#include <stdlib.h>

int main()
{
  int row;

  printf("Enter a row index: ");
  scanf("%d",&row);

  // Write your code here

  unsigned long out = 1;//out was set to 1 because
    
  for (int i = 0; i <=row; i++){//for loop for calculating each number
    for (int j = 1; j <= row -i; j++){//for loop for calculat the PI
      out = (out*(row + 1 -j))/j;//this is the formula provied
    }
    printf("%lu ",out);//lu is to print any unsigned long
    out = 1;//set out back to 1 for the next value to be calculated
  }
  
  return 0;
}
