#include <stdio.h>
#include <stdlib.h>

//ovaj program koristi istu logiku za rjesavanje labirinta kao i prosli, ali ovaj put se memorija zauzima dinamicki i labirint se ucitava iz datoteke maze.txt
//dvije nove funkcije: loadMaze i allocateMaze

typedef struct _MAZE {
    int **m; //pokazivac na 2D polje
    int nx; //broj stupaca
    int ny; //broj redaka
} Maze;

int isSafe(Maze* maze, int x, int y) { //tri parametra - pokazivac na varijablu maze tipa Maze, x i y velicine labirinta
    if( x >= 0 && x < maze->nx && y >= 0 && y < maze->ny ) //ako su x i y koordinate pozitivne i manje od velicine labirinta
        return 1;
    else
        return 0;
}

void dbgMazeWithCurrentLocation(Maze *maze, int x, int y, Maze *sol) { //cetiri parametra - pokazivac na pocetnu varijablu tipa Maze, x i y koordinate, pokazivac na varijablu tipa Maze za rjesenje
    int j, i;
    if( isSafe(maze, x,y) && maze->m[y][x] == 1 ) { //ako je labirint odgovarajucih dimenzija i ako je vrijednost matrice labirinta na poziciji x,y jednaka 1
        if( sol->m[y][x] == 1 ) //ako je u rjesenje vec upisano 1 na tom mjestu
            printf("Current location: %d %d -- INVALID - previous path\n", y,x);
        else
            printf("Current location: %d %d\n", y,x);
        for (i = 0; i < maze->ny; ++i) {
            for (j = 0; j < maze->nx; ++j ) {
                if( j == x && i == y )
                    printf("+ "); //trenutna pozicija
                else if( sol->m[i][j] == 1 )
                    printf(". "); //dio rjesenja
                else {
                    printf("%d ", maze->m[i][j]);
                }
            }
            printf("\n");
        }
    }
    else {
        printf("Current location: %d %d -- INVALID\n", y,x);
    }
}

void printMaze(Maze* maze) { //jedan parametar - pokazivac na maze tipa Maze
    int j, i;
    for (i = 0; i < maze->ny; ++i) { //od 0 do broja redaka
        for (j = 0; j < maze->nx; ++j ) { //od 0 do broja stupaca
            printf("%d ", maze->m[i][j]);
        }
        printf("\n");
    }
}

int solveMazeUntil(Maze* maze, int x, int y, Maze* sol) { //ista funkcionalnost, samo je broj 4 (ili MAZE_N) zamijenjen pokazivacem na dimenziju matrica maze i sol, te matrice pokazivacem na matrice maze i sol
    dbgMazeWithCurrentLocation(maze, x, y, sol);

    int endX = maze->nx - 1; //-1 ide tamo gdje smo pisali 3, tj. 4-1 jer kod polja brojimo od 0
    int endY = maze->ny - 1;

    if( x == endX && y == endY && maze->m[y][x] == 1 ) {
        sol->m[y][x] = 1;
        return 1;
    }

    if( isSafe(maze,x,y) && maze->m[y][x] == 1 ) {
        if( sol->m[y][x] == 1 ) {
            return 0;
        }
        
        sol->m[y][x] = 1;
        
        if( solveMazeUntil(maze, x, y+1, sol) )
            return 1;
        
        if( solveMazeUntil(maze, x-1, y, sol) )
            return 1;
        
        if( solveMazeUntil(maze, x, y-1, sol) )
            return 1;
        
        if( solveMazeUntil(maze, x+1, y, sol) )
            return 1;

        sol->m[y][x] = 0;
        return 0;
    }
    return 0;
}

int solveMaze(Maze* maze, Maze* sol) {
    if(solveMazeUntil(maze, 0, 0, sol) == 0){
        printf("Maze cannot be solved\n");
        return 0;
    }
    printf("Maze solved successfully\n");
    printMaze(sol);
    return 0;
}

//nove funkcije:

int** allocateMaze(int rows, int columns) { //dinamicka alokacija prostora za matricu
    int **maze;
    int i;
    maze = (int**)malloc(sizeof(int*) * rows);
    for (i = 0; i < rows; i++) {
        maze[i] = (int*)malloc(sizeof(int) * columns);
    }
    return maze;
}

int loadMaze(const char* filename, Maze* maze, Maze* sol) { //cita elemente labirinta iz dokumenta i upisuje u dinamicki zauzetu memoriju
    int i,j;
    FILE *f = fopen(filename, "r"); //otvara datoteku za citanje
    if( f == NULL )
        return 0;
    
    int nx, ny;
    int **maze_array;
    int **sol_array;
    char maze_row[255];

    fscanf(f, "%d", &ny); //citanje velicine matrice iz datoteke
    fscanf(f, "%d", &nx);
    fgetc(f); //uzima znak razmaka izmedju dimenzija i labirinta

    maze_array = allocateMaze(ny, nx); //alokacija prostora za labirint i matricu s rjesenjem 
    sol_array = allocateMaze(ny, nx);

    for (i = 0; i < ny; ++i) {
        fgets(maze_row, 255, f); //citanje jednog reda labirinta iz datoteke

        for (j = 0; j < nx ; ++j) { //za sve znakove u jednom redu
            if( maze_row[j] == '1') //ako je znak 1, upisuje se vrijednost 1 u taj indeks labirinta
                maze_array[i][j] = 1;
            else //u suprotnom upisuje se 0
                maze_array[i][j] = 0;
            
            sol_array[i][j] = 0; //inicijalizacija polja rjesenja na 0
        }
    }

    maze->nx = nx; //broj stupaca labirinta jednak je drugom broju upisanom u datoteku
    maze->ny = ny; //broj redova labirinta jednak je prvom broju upisanom u datoteku
    maze->m = maze_array; //matrica labirinta jednaka je iscitanoj matrici

    sol->nx = nx;
    sol->ny = ny;
    sol->m = sol_array; //matrica rjesenja jednaka je ranijoj matrici koju smo postavili na 0

    return 1;
}

int main(void) {
    Maze maze;
    Maze sol;
    if(loadMaze("maze.txt", &maze, &sol)) {
        printf("Maze loaded:\n");
        printMaze(&maze);
    }else {
        printf("Error while loading maze! Exiting...\n");
        return 1;
    }

    printf("Solving maze...\n");
    solveMaze(&maze, &sol);
    return 0;
}