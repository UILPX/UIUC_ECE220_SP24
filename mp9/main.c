#include <stdio.h>
#include "maze.h"

 
int main(int argc, char **argv)
{
    if (argc < 2)
    {
        printf("You need a valid input maze file.\n");
        return -1;
    }

    printf("Creating maze with file %s\n", argv[1]);
    maze_t * maze = createMaze(argv[1]);

    printf("\nUnsolved maze:\n");
    printMaze(maze);

    if(solveMazeDFS(maze, maze->startColumn, maze->startRow))
    {
        printf("\nSolved maze:\n");
        printMaze(maze);
        if(checkMaze(maze))
        {
            printf("Solution to maze is valid\n");
        }
        else
        {
            printf("Incorrect solution to maze\n");
        }
    }
    else
    {
        printf("\nMaze is unsolvable\n");
    }

    printf("\nDestroying maze\n");

    destroyMaze(maze);
 
    return 0;
}
