#ifndef FUNCTIONS_MAZE_H
#define FUNCTIONS_MAZE_H value

#include <stdio.h>
#include "types.h"
#include "printers.h"

int solveMaze(Maze* maze, Maze* sol, int startX, int startY, int endX, int endY);
int solveMazeUntil(Maze* maze, int x, int y, Maze* sol, int endX, int endY);
int isSafe(Maze* maze, int x, int y);
int** allocateMaze(int rows, int columns);
int loadMaze(const char* filename, Maze* maze, Maze* sol);
void dbgMazeWithCurrentLocation(Maze *maze, int x, int y, Maze *sol);

#endif