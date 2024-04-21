#include <stdio.h>
#define MAZE_N 6

//program obavlja isti zadatak kao i prethodna dva
//iako mu je velicina matrice tj. labirinta i dalje hard-coded, sada ju mozemo lako promijeniti jer se u kodu koristi konstanta MAZE_N umjesto broja 4 direktno

int isSafe(int x, int y) {
    if( x >= 0 && x < MAZE_N && y >= 0 && y < MAZE_N )
        return 1;
    else
        return 0;
}

void dbgMazeWithCurrentLocation(int maze[MAZE_N][MAZE_N], int x, int y, int sol[MAZE_N][MAZE_N]) {
    int i, j;

    if(isSafe(x,y) && maze[y][x] == 1) {
        if( sol[y][x] == 1 )
            printf("Current location: %d %d -- INVALID - previous path\n", x,y);
        else
            printf("Current location: %d %d\n", x,y);

        for (i = 0; i < MAZE_N; ++i) {
            for (j = 0; j < MAZE_N; ++j ) {
                if( j == x && i == y )
                    printf("+ "); //trenutna lokacija
                else if( sol[i][j] == 1 )
                    printf(". "); //dio rjesenja
                else
                    printf("%d ", maze[i][j]);
            }
            printf("\n");
        }
    }else {
        printf("Current location: %d %d -- INVALID\n", x,y);
    }
}
void printMaze(int maze[MAZE_N][MAZE_N]) {
    int i, j;

    for (i = 0; i < MAZE_N; ++i) {
        for (j = 0; j < MAZE_N; ++j ) {
            printf("%d ", maze[i][j]);
        }
    printf("\n");
    }
}

int solveMazeUntil(int maze[MAZE_N][MAZE_N], int x, int y, int sol[MAZE_N][MAZE_N]){
    dbgMazeWithCurrentLocation(maze, x, y, sol);

    int endX = MAZE_N-1, endY = MAZE_N-1;
    if(x == endX && y == endY && maze[y][x] == 1) {
        sol[y][x] = 1;
        return 1;
    }

    if(isSafe(x,y) && maze[y][x] == 1) {

    if( sol[y][x] == 1 ) {
        return 0;
    }
    
    sol[y][x] = 1;
    
    if( solveMazeUntil(maze, x, y+1, sol) )
    return 1;
    
    if( solveMazeUntil(maze, x-1, y, sol) )
    return 1;
    
    if( solveMazeUntil(maze, x, y-1, sol) )
    return 1;
    
    if( solveMazeUntil(maze, x+1, y, sol) )
    return 1;
    
    sol[y][x] = 0;
    return 0;
    }

    return 0;
}

int solveMaze(int maze[MAZE_N][MAZE_N], int sol[MAZE_N][MAZE_N]) {
    if( solveMazeUntil(maze, 0, 0, sol) == 0 ){
        printf("Maze cannot be solved\n");
        return 0;
    }

    printf("Maze solved successfully\n");
    printMaze(sol);
    return 0;
}

int main(void) {
    int maze[MAZE_N][MAZE_N] = {{ 1, 1, 1, 1, 1, 1},
                                { 1, 0, 0, 0, 1, 0},
                                { 1, 1, 1, 0, 1, 0},
                                { 1, 0, 1, 1, 1, 0},
                                { 1, 0, 1, 0, 1, 0},
                                { 1, 1, 1, 1, 1, 1}};
    int sol[MAZE_N][MAZE_N] = {0};
    solveMaze(maze, sol);

    return 0;
}