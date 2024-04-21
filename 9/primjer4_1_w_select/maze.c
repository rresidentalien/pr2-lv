#include "functions.h"

int solveMaze(Maze* maze, Maze* sol, int startX, int startY, int endX, int endY) {
    if( solveMazeUntil(maze, startX, startY, sol, endX, endY) ){
        return 1;
    }
    return 0;
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

void myMazeWriter(Maze* maze, Maze* solution) {
    int xx,yy;
    FILE *f = fopen(_maze_write_path, "w");
    if( f == NULL )
        printf("Error opening file for writing!");
    //change limits in for to allow room for adding border around the maze
    for (yy = -1; yy <= maze->ny; ++yy) {
        for (xx = -1; xx <= maze->nx; ++xx ) {
            //print border
            if( yy == -1 || yy == maze->ny || xx == -1 || xx == maze->nx) {
                fprintf(f, "##");
                continue;
            }
            //print maze
            if( solution->m[yy][xx] == 1 )
                fprintf(f, "* ");
            else if( maze->m[yy][xx] == 1 )
                fprintf(f, " ");
            else
                fprintf(f, "##");
        }
        fprintf(f, "\n");
    }
    fclose(f);
}

int main(void) {
    Maze maze;
    Maze sol;
    int startX, startY, endX, endY;
    printf("Enter the start and end positions (startX startY endX endY): ");
    scanf("%d %d %d %d", &startX, &startY, &endX, &endY);
    int solved = 0;
    init_maze_printer(printPrettyMaze);
    init_maze_writer(myMazeWriter, "my-callback-maze.txt");
    if( loadMaze("maze.txt", &maze, &sol) ) {
        printf("Maze loaded:\n");
        printMaze(&maze);
    }
    else {
        printf("Error while loading maze! Exiting...\n");
        return 1;
    }
    printf("Solving maze...\n");
    solved = solveMaze(&maze, &sol, startX, startY, endX, endY);
    if(solved) {
        printf("Maze solved\n");
        printMazeSolution(&maze, &sol);
        writeMazeSolution(&maze, &sol);
    }
    else {
        printf("Maze cannot be solved!");
    }
    return 0;
}