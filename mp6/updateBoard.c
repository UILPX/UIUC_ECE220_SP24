/*
 * countLiveNeighbor
 * Inputs:
 * board: 1-D array of the current game board. 1 represents a live cell.
 * 0 represents a dead cell
 * boardRowSize: the number of rows on the game board.
 * boardColSize: the number of cols on the game board.
 * row: the row of the cell that needs to count alive neighbors.
 * col: the col of the cell that needs to count alive neighbors.
 * Output:
 * return the number of alive neighbors. There are at most eight neighbors.
 * Pay attention for the edge and corner cells, they have less neighbors.
 */

 /*
 In this mp I finish 3 function to help the live game run. First is the count live neighbor function that 
 count how many cell is alive around the current cell. This function is called by the updateboard function
 where it check every cell and make a new array to store the new status based on the current status.This
 is then called by the alivestable funtion where it check if there is any changes to the current board. If
 there is changes, it make the changes and save the new one. Else it end the game by return 1 to the main.
 */

int countLiveNeighbor(int* board, int boardRowSize, int boardColSize, int row, int col){

    //set the number of live neighbors to 0
    int live_n = 0;

    //rows from currRow-1 to currRow+1, inclusive
    for(int i = row-1;i <= row+1;i++){
        //the row is within the bounds of the board
        if(i>=0 && i<boardRowSize){
            //columns from currCol-1 to currCol+1, inclusive
            for(int j = col-1;j <= col+1;j++){
                //the column is within the bounds of the board
                if(j>=0 && j<boardColSize){
                    //the cell isn't' at (currRow, currCol)
                    if((i!=row) || (j!=col)){
                        //the cell is alive
                        if(board[(i*boardColSize)+j]==1){
                            live_n++;
                        }
                    }
                }
            } 
        }
    }           
    return live_n;
}


/*
 * Update the game board to the next step.
 * Input: 
 * board: 1-D array of the current game board. 1 represents a live cell.
 * 0 represents a dead cell
 * boardRowSize: the number of rows on the game board.
 * boardColSize: the number of cols on the game board.
 * Output: board is updated with new values for next step.
 */
void updateBoard(int* board, int boardRowSize, int boardColSize) {
    //set a new array to store change
    int newboard[boardColSize * boardRowSize];
    //loop to go over every cell in the array.
    for(int i=0;i<boardRowSize;i++){
        for(int j=0;j<boardColSize;j++){
            int live_neighbors = countLiveNeighbor(board, boardRowSize, boardColSize, i, j);
            //logic when the cell is alive
            if(board[(i*boardColSize)+j]==1){
                //reamian alive only when live neighbor cell is 2 or 3.
                newboard[(i*boardColSize+j)] = 1;
                if((live_neighbors==2)||(live_neighbors==3)){
                    continue;
                }else{//change the cell to dead
                    newboard[(i*boardColSize+j)] = 0;
                }
            }
            else{
                //logic when the cell is dead
                //remain in dead
                newboard[(i*boardColSize+j)] = 0;
                //be alive when there is exactly 3 live cell
                if(live_neighbors == 3){
                    newboard[(i*boardColSize+j)] = 1;
                }
            }
        }
    }
    //store the changes back to the origional array
    int update;
    for(update = 0; update < (boardColSize*boardRowSize);update++){
        board[update] = newboard[update];
    }
}



/*
 * aliveStable
 * Checks if the alive cells stay the same for next step
 * board: 1-D array of the current game board. 1 represents a live cell.
 * 0 represents a dead cell
 * boardRowSize: the number of rows on the game board.
 * boardColSize: the number of cols on the game board.
 * Output: return 1 if the alive cells for next step is exactly the same with 
 * current step or there is no alive cells at all.
 * return 0 if the alive cells change for the next step.
 */ 
int aliveStable(int* board, int boardRowSize, int boardColSize){

    int newboard[boardColSize*boardRowSize];

    int i;
    //save board for comparison
    for(i=0;i<(boardColSize*boardRowSize);i++){
        newboard[i]=board[i];
    }

    //update the board
    updateBoard(newboard,boardRowSize,boardColSize);

    //check each value in the array
    for(i=0;i<(boardColSize*boardRowSize);i++){
        //check if any value changed
        if(newboard[i]!=board[i]){
            //atleast one value changed, so return 0
            return 0;
        }
    }
    //no value changed, so return 1.
    return 1;
}
				
				
			

