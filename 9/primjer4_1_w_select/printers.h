#ifndef PRINTERS_MAZE_H
#define PRINTERS_MAZE_H 1
#include <stdio.h>
#include "types.h"

extern void (*_maze_printer)(Maze* maze, Maze* solution);
extern void (*_maze_writer)(Maze* maze, Maze* solution);
extern const char* _maze_write_path;

int init_maze_printer(void (*printer)(Maze* maze, Maze* solution));
int init_maze_writer(void (*writer)(Maze* maze, Maze* solution), const char* maze_write_path);
int printMazeSolution(Maze* maze, Maze* solution);

//Printer functions
void printMaze(Maze* maze);
void printSimpleMaze(Maze* maze, Maze* solution);
void printPrettyMaze(Maze* maze, Maze* solution);

//Writer functions
void writeSimpleMaze(Maze* maze, Maze* solution);
void writePrettyMaze(Maze* maze, Maze* solution);
int writeMazeSolution(Maze* maze, Maze* solution);

#endif