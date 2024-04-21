#include <stdio.h>

//program koji rjesava labirint u obliku 2D polja gdje su 1 prolazi, a 0 zidovi
//pronalazi put i vraca sol - 2D polje gdje su 1 prolaz, a svi ostali elementi su 0
//program je hard-coded da pocinje u gornjem lijevom kutu (0,0), a zavrsava u donjem desnom (3,3)
//program je isti kao iz primjera 2.1., ali ima dodatnu funkcionalnost ispisa svakog koraka za debugging ili lakse razumijevanje programa (funkcija dbgMazeWithCurrentLocation)

int isSafe(int x, int y) { //provjerava je li x,y validan indeks za labirint - je li 2D polje odgovarajucih dimenzija od 1x1 do 4x4; potrebno da nam funkcija ne "izleti" van matrice
    if( x >= 0 && x < 4 && y >= 0 && y < 4 )
        return 1;
    else
        return 0;
}

void dbgMazeWithCurrentLocation(int maze[4][4], int x, int y, int sol[4][4]) { //parametri: pocetni labirint, trenutni indeks x i y, matrica rjesenja
    int i, j;

    if( isSafe(x,y) && maze[y][x] == 1 ) { //ako je unos validan i vrijednost na poziciji je 1
        if( sol[y][x] == 1 ) //ako je vrijednost na poziciji 1 (tj ako je vec pronadjeno, u pocetku je matrica sol popunjena nulama pa ako je neka vrijednost vec 1 znaci da smo tamo bili)
            printf("Current location: %d %d -- INVALID - previous path\n", x,y);
        else
            printf("Current location: %d %d\n", x,y);

        for (i = 0; i < 4; ++i) {
            for (j = 0; j < 4; ++j ) {
                if(j == x && i == y) //ako su trenutne koordinate jednake zadanim koordinatama (mijenjaju se jer se ova funkcija poziva unutar solveMazeUntil - pomak lijevo desno gore dolje)
                    printf("X "); //trenutna lokacija
                else if( sol[i][j] == 1 )
                    printf("P "); //dio rjesenja
                else
                    printf("%d ", maze[i][j]);
            }
            printf("\n");
        }
    }else {
        printf("Current location: %d %d -- INVALID\n", x,y);
    }
}

void printMaze(int maze[4][4]) { //funkcija za ispis labirinta, koristit cemo ju u solveMaze za ispis rjesenja (sol)
    int i, j;
    for (i = 0; i < 4; ++i) {
        for (j = 0; j < 4; ++j ) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
}

//funkcija rekurzivno provjerava sve moguce smjerove
int solveMazeUntil(int maze[4][4], int x, int y, int sol[4][4]){ //argumenti: pocetni labirint, trenutne koordinate x i y, matrica s rjesenjem
    dbgMazeWithCurrentLocation(maze, x, y, sol);
    int endX = 3, endY = 3; //pozicija do koje program zeli doci, tj. donji desni kut (3,3)

    //baza (dio rekurzivnog programa koji zaustavlja rekurziju ako je uvjet tocan, sprjecava da se ponavlja beskonacno)
    if( x == endX && y == endY && maze[y][x] == 1 ) { //ako je trenutna pozicija jednaka zeljenoj poziciji (3,3) i ako je vrijednost na toj poziciji 1 (prolaz)
        sol[y][x] = 1; //vrijednost na poziciji (x,y) tj. (3,3) je 1
        return 1; //vrati 1 (rjesenje pronadjeno)
    }

    //rekurzija
    if(isSafe(x,y) && maze[y][x] == 1) { //ako je (x,y) validan indeks i vrijednost na toj poziciji je 1
        if( sol[y][x] == 1 ) { //ako je vrijednost na toj poziciji u matrici rjesenja jednaka 1 (zapravo provjerava je li nam ovaj indeks vec u rjesenju da ne zapnemo u beskonacnoj petlji)
            return 0; //vrati 0 (rjesenje nije pronadjeno, tj. rjesenje je vec uzeto u obzir)
        }
        
        sol[y][x] = 1; //postavi vrijednost ovog indeksa u matrici rjesenja na 1

        //sljedecim naredbama funkcija se "mice" po labirintu, tj. poziva samu sebe za poziciju za 1 udaljenu od sebe u svim smjerovima i  rekurzivno provjerava do kraja je li taj put moguc
        
        if(solveMazeUntil(maze, x, y+1, sol)) //pomak dolje
            return 1;
        
        if(solveMazeUntil(maze, x-1, y, sol)) //pomak lijevo
            return 1;
        
        if(solveMazeUntil(maze, x, y-1, sol)) //pomak gore
            return 1;

        if(solveMazeUntil(maze, x+1, y, sol)) //pomak desno
            return 1;

        sol[y][x] = 0; //ako rjesenje nije pronadjeno u bilo kojem smjeru od ove pozicije, ipak postavi tu poziciju na 0
        return 0;
    }

    return 0;
}

int solveMaze(int maze[4][4], int sol[4][4]) { //prima dva parametra - pocetni labirint i rjesenje
    if( solveMazeUntil(maze, 0, 0, sol) == 0 ){ //ako solveMazeUntil vraca 0, tj. ako nije moguce rjesiti labirint
        printf("Maze cannot be solved\n");
        return 0;
    }
    printf("Maze solved successfully\n");
    printMaze(sol); //ispis matrice rjesenja
    return 0;
}

int main(void) {
    int maze[4][4] = {  { 1, 0, 1, 0 },
                        { 1, 1, 1, 1 },
                        { 1, 0, 1, 0 },
                        { 1, 0, 1, 1 }};
    int sol[4][4] = {0};
    solveMaze(maze, sol);
    return 0;
}