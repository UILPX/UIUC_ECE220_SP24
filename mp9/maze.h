#define WALL    '%'
#define EMPTY   ' '
#define START   'S'
#define END     'E'
#define PATH    '*'
#define VISITED '~'

typedef struct {
    int width;
    int height;
    int startColumn;
    int startRow;
    int endColumn;
    int endRow;
    char ** cells;
} maze_t;

int checkMaze(maze_t * maze);

// These functions must be implemented correctly for full functionality points 
maze_t * createMaze(char * fileName);
void destroyMaze(maze_t * maze);
int solveMazeDFS(maze_t * maze, int col, int row);
void printMaze(maze_t * maze);
