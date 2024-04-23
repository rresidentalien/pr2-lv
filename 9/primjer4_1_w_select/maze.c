#include "functions.h"

int solveMaze(Maze* maze, Maze* sol, int startX, int startY, int endX, int endY) {
    if( solveMazeUntil(maze, startX, startY, sol, endX, endY) ){
        return 1;
    }
    return 0;
}

void myMazeWriter(Maze* maze, Maze* solution) { //ispisuje rjesenje labirinta u datoteku
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