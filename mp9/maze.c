#include <stdio.h>
#include <stdlib.h>
#include "maze.h"
/*
In this project, I employed a Depth-First Search (DFS) technique to navigate through a maze, 
marking my first foray into this method of maze resolution. The assignment not only tasked 
us with solving the maze but also with the creation, dynamic memory allocation, and eventual 
deallocation of the maze structure, along with its visual presentation. Formulating the 
foundational case alongside the recursive logic to methodically examine adjacent cells 
(up, down, left, right) for the most direct route to the finale proved to be uncomplicated.
*/

/*
 * createMaze -- Creates and fills a maze structure from the given file
 * INPUTS:       fileName - character array containing the name of the maze file
 * OUTPUTS:      None 
 * RETURN:       A filled maze structure that represents the contents of the input file
 * SIDE EFFECTS: None
 */
maze_t * createMaze(char * fileName){
    // Your code here. Make sure to replace following line with your own code.
    FILE * file = fopen(fileName,"r"); // Opening the input file as the file pointer file in read
    if(file == NULL){ // if file is NULL then we failed to open the file
        printf("error opening file\n");
        return NULL;
    }
    maze_t * maze = (maze_t *) malloc(sizeof(maze_t)); // allocate memory and cast the returned pointer
    // maze_t* and store it in the pointer maze
    if(maze == NULL){ // if maze is NULL then we failed to allocate memory
        printf("error allocating memory to maze\n");
        return NULL;
    }
    fscanf(file,"%d %d",&maze->width,&maze->height); //input the width and height of the matrix from the file
    //printf("%d %d",maze->width,maze->height);
    int width = maze->width;
    int height = maze->height;
    maze->cells = (char**) malloc(sizeof(char*) * height); //allocate an 1D array of char* pointers and
    //save it in maze->cells
    if(maze->cells == NULL){ // if the pointer is NULL we failed to allocate memory
        printf("error allocating memory to rows\n");
        return NULL;
    }
    for(int i = 0 ; i < height; ++i){ // loop through the created 1D array of pointers
        maze->cells[i] = (char *) malloc(sizeof(char) * width); //point each pointer in that array to 
        //an individual 1D array of dimension width
        if(maze->cells[i] == NULL){ // if the pointer is NULL we failed to allocate memory
            printf("error allocating memory to columns\n");
            return NULL;
        }
        //printf("%s\n",maze->cells[i]);
    }
    char x = fgetc(file); //take in newline character from previous row
    for(int i = 0 ;i < height; ++i){ // loop through the created map
        for(int j = 0;j < width; ++j){
            x = fgetc(file); //take in a character and store it in the map
            maze->cells[i][j] = x;
            //printf("%c",x);
        }
        //printf("\n");
        x = fgetc(file); //take in newline character
    }
    for(int i = 0 ;i < height; ++i) {// loop through the created map
        for(int j = 0;j < width; ++j){
            if(maze->cells[i][j] == START) {// find START and END and store their locations
            // in the designated location in maze
                maze -> startRow = i;
                maze -> startColumn = j;
            }
            if(maze->cells[i][j] == END){
                maze -> endRow = i;
                maze -> endColumn = j;
            }
        }
    }
    fclose(file); // close the file as we don't need to scan anything anymore
    return maze; //return the maze pointer
}


/*
 * destroyMaze -- Frees all memory associated with the maze structure, including the structure itself
 * INPUTS:        maze -- pointer to maze structure that contains all necessary information 
 * OUTPUTS:       None
 * RETURN:        None
 * SIDE EFFECTS:  All memory that has been allocated for the maze is freed
 */
void destroyMaze(maze_t * maze){
    // Your code here.
    for(int i=0; i<maze->height; i++){
        free(maze->cells[i]);
    }
    free(maze->cells);
    free(maze);
}

/*
 * printMaze --  Prints out the maze in a human readable format (should look like examples)
 * INPUTS:       maze -- pointer to maze structure that contains all necessary information 
 *               width -- width of the maze
 *               height -- height of the maze
 * OUTPUTS:      None
 * RETURN:       None
 * SIDE EFFECTS: Prints the maze to the console
 */
void printMaze(maze_t * maze){
    for(int i = 0 ; i < maze->height; ++i){
        puts(maze->cells[i]); // we loop through the 1D array and print each row
    }
}

/*
 * solveMazeManhattanDFS -- recursively solves the maze using depth first search,
 * INPUTS:               maze -- pointer to maze structure with all necessary maze information
 *                       col -- the column of the cell currently beinging visited within the maze
 *                       row -- the row of the cell currently being visited within the maze
 * OUTPUTS:              None
 * RETURNS:              0 if the maze is unsolvable, 1 if it is solved
 * SIDE EFFECTS:         Marks maze cells as visited or part of the solution path
 */ 
int solveMazeDFS(maze_t * maze, int col, int row) {   
    // Check to make sure row, col values are within maze bounds
    if(col < 0 || row < 0 || col >= maze->width || row >= maze->height){
        return 0;
    }
    // Base case - check if current cell is the end
    if(maze->cells[row][col] == 'E') {
        return 1;
    }
    // Check if cell is not start 'S' and not empty ' ', then it's not a valid path
    if(maze->cells[row][col] != 'S' && maze->cells[row][col] != ' ') {
        return 0;
    }
    // Mark the current cell as part of the solution path, unless it's the start
    if(maze->cells[row][col] != 'S') {
        maze->cells[row][col] = '*';
    }
    // Directions to move: right, down, left, up
    int directions[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    
    for (int i = 0; i < 4; i++) {
        int nextCol = col + directions[i][0];
        int nextRow = row + directions[i][1];
        
        // Attempt to solve from the next position
        if(solveMazeDFS(maze, nextCol, nextRow)) 
            return 1; // If solution found, return true
    }
    
    // Backtrack - mark the current cell to indicate it's not on the correct path
    if(maze->cells[row][col] != 'S') {
        maze->cells[row][col] = '~';
    }
    return 0; // If no solution is found in any direction, return false
}
