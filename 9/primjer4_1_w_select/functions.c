#include "functions.h"

int** allocateMaze(int rows, int columns) {
    int **maze;
    int i;
    maze = (int**)malloc(sizeof(int*) * rows);
    for (i = 0; i < rows; i++) {
        maze[i] = (int*)malloc(sizeof(int) * columns);
    }
    return maze;
}

int loadMaze(const char* filename, Maze* maze, Maze* sol) {
    int yy,xx;
    FILE *f = fopen(filename, "r");
    if( f == NULL )
        return 0;
    int nx, ny;
    int **maze_array;
    int **sol_array;
    char maze_row[255];
    fscanf(f, "%d", &ny);
    fscanf(f, "%d", &nx);
    fgetc(f);
    maze_array = allocateMaze(ny, nx);
    sol_array = allocateMaze(ny, nx);
    for (yy = 0; yy < ny; ++yy) {
        fgets(maze_row,255, f);
        for (xx = 0; xx < nx ; ++xx) {
            //fill maze array
            if( maze_row[xx] == '1')
                maze_array[yy][xx] = 1;
            else
                maze_array[yy][xx] = 0;
            //initialize sol array to 0
            sol_array[yy][xx] = 0;
        }
    }
    maze->nx = nx;
    maze->ny = ny;
    maze->m = maze_array;
    sol->nx = nx;
    sol->ny = ny;
    sol->m = sol_array;
    return 1;
}

int solveMazeUntil(Maze* maze, int x, int y, Maze* sol, int endX, int endY) {
    dbgMazeWithCurrentLocation(maze, x, y, sol);
    //Exit 1: Check if we have reached the end
    if( x == endX && y == endY && maze->m[y][x] == 1 ) {
        sol->m[y][x] = 1;
        return 1;
    }
    //if x,y are valid and safe indices for the maze
    if( isSafe(maze,x,y) && maze->m[y][x] == 1 ) {
        //Exit 2: Check if x,y already in our solution path.
        //Prevents us from getting stuck in an infinite recursion
        if( sol->m[y][x] == 1 ) {
            return 0;
        }
        //Add x,y to the solution path
        sol->m[y][x] = 1;
        //Move down
        if( solveMazeUntil(maze, x, y+1, sol, endX, endY))
            return 1;
        //Move left
        if( solveMazeUntil(maze, x-1, y, sol, endX, endY))
            return 1;
        //Move up
        if( solveMazeUntil(maze, x, y-1, sol, endX, endY))
            return 1;
        //Move right
        if( solveMazeUntil(maze, x+1, y, sol, endX, endY))
            return 1;
        
        sol->m[y][x] = 0;
        return 0;
    }
    return 0;
}

/* Check if x,y is a valid index for the maze */
int isSafe(Maze* maze, int x, int y) {
    if( x >= 0 && x < maze->nx && y >= 0 && y < maze->ny )
        return 1;
    else
        return 0;
}

void dbgMazeWithCurrentLocation(Maze *maze, int x, int y, Maze *sol) {
    int xx,yy;
    if( isSafe(maze, x,y) && maze->m[y][x] == 1 ) {
        if( sol->m[y][x] == 1 )
            printf("Current location: %d %d -- INVALID - previous path\n", x,y);
        else
            printf("Current location: %d %d\n", x,y);
        for (yy = 0; yy < maze->ny; ++yy) {
            for (xx = 0; xx < maze->nx; ++xx ) {
                if( xx == x && yy == y )
                    printf("+ ");
                else if( sol->m[yy][xx] == 1 )
                    printf(". ");
                else {
                    printf("%d ", maze->m[yy][xx]);
                }
            }
            printf("\n");
        }
    }
    else {
        printf("Current location: %d %d -- INVALID\n", x,y);
    }
}