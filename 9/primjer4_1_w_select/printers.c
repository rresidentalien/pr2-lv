#include "printers.h"

//write = ispis na datoteku
//print = ispis na ekran

void (*_maze_printer)(Maze* maze, Maze* solution) = NULL;
void (*_maze_writer)(Maze* maze, Maze* solution) = NULL;
const char* _maze_write_path;

int init_maze_printer(void (*printer)(Maze* maze, Maze* solution)) { //definira globalnu varijablu _maze_printer kao pokazivac na labirint i rjesenje
    _maze_printer = printer;
    return 0;
}

int init_maze_writer(void (*writer)(Maze* maze, Maze* solution), const char* maze_write_path) {
    _maze_writer = writer; //definira globalnu varijablu _maze_writer kao pokazivac na labirint i rjesenje
    _maze_write_path = maze_write_path; //ovdje ce se unositi ime datoteke na koju zelimo ispisati rjesenje
    return 0;
}

int printMazeSolution(Maze* maze, Maze* solution) {
    if(_maze_printer == NULL) {
        printf("ERROR: Maze printer not initialized!");
        exit(1);
    }
    _maze_printer(maze, solution); //ispis rjesenja na ekran
    return 0;
}

int writeMazeSolution(Maze* maze, Maze* solution) {
    if(_maze_writer == NULL) {
        printf("ERROR: Maze writer not initialized!");
        exit(1);
    }
    if(_maze_write_path == NULL) {
        printf("ERROR: Maze write path not set!");
        exit(1);
    }
    _maze_writer(maze, solution); //ispis rjesenja na datoteku
    return 0;
}

void printMaze(Maze* maze) { //ispisuje labirint na konzolu
    int xx,yy;
    for (yy = 0; yy < maze->ny; ++yy) {
        for (xx = 0; xx < maze->nx; ++xx ) {
            printf("%d ", maze->m[yy][xx]);
        }
        printf("\n");
    }
}

void printSimpleMaze(Maze* maze, Maze* solution) { //ispisuje labirint na konzolu, s trenutnim rjesenjem (. ako je pozicija dio rjesenja)
    int xx,yy;
    for (yy = 0; yy < maze->ny; ++yy) {
        for (xx = 0; xx < maze->nx; ++xx ) {
            if( solution->m[yy][xx] == 1 )
                printf(". ");
            else if( maze->m[yy][xx] == 1 )
                printf("1 ");
            else
                printf("0 ");
        }
        printf("\n");
    }
}

void printPrettyMaze(Maze* maze, Maze* solution) { //ispisuje rjesenje na ekran tako da dodaje ## oko labirinta kao ogradu, . za rjesenje, prazninu za moguci put koji nije dio rjesenja i # za zid
    int xx,yy;

    for (yy = -1; yy <= maze->ny; ++yy) {
        for (xx = -1; xx <= maze->nx; ++xx ) {
            //print border
            if( yy == -1 || yy == maze->ny || xx == -1 || xx == maze->nx) {
                printf("##");
                continue;
            }
            //print maze
            if( solution->m[yy][xx] == 1 )
                printf(". ");
            else if( maze->m[yy][xx] == 1 )
                printf(" ");
            else
                printf("# ");
        }
        printf("\n");
    }
}

void writeSimpleMaze(Maze* maze, Maze* solution) { //ispisuje rjesenje labirinta na datoteku
    int xx,yy;
    FILE *f = fopen(_maze_write_path, "w");
    if( f == NULL )
        printf("Error opening file for writing!");
    for (yy = 0; yy < maze->ny; ++yy) {
        for (xx = 0; xx < maze->nx; ++xx ) {
            if( solution->m[yy][xx] == 1 )
                fprintf(f, ". ");
            else if( maze->m[yy][xx] == 1 )
                fprintf(f, "1 ");
            else
                fprintf(f, "0 ");
        }
        fprintf(f, "\n");
    }
}

void writePrettyMaze(Maze* maze, Maze* solution) { //ispisuje  "lijepo" rjesenje labirinta na datoteku
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
                fprintf(f, ". ");
            else if( maze->m[yy][xx] == 1 )
                fprintf(f, " ");
            else
                fprintf(f, "##");
        }
        fprintf(f, "\n");
    }
}