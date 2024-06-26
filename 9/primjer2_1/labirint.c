#include <stdio.h>

//program koji rjesava labirint u obliku 2D polja gdje su 1 prolazi, a 0 zidovi
//pronalazi put i vraca sol - 2D polje gdje su 1 prolaz, a svi ostali elementi su 0
//program je hard-coded da pocinje u gornjem lijevom kutu (0,0), a zavrsava u donjem desnom (3,3)

int isSafe(int x, int y) { //provjerava je li x,y validan indeks za labirint - je li 2D polje odgovarajucih dimenzija od 1x1 do 4x4; potrebno da nam funkcija ne "izleti" van matrice
    if( x >= 0 && x < 4 && y >= 0 && y < 4 )
        return 1;
    else
        return 0;
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
    int maze[4][4] = {  { 1, 0, 1, 0 }, //prvi y i cetiri x-a: (0, 0), (0, 1), (0, 2), (0, 3)
                        { 1, 1, 1, 1 }, //drugi y i cetiri x-a (1, 0), (1, 1), (1, 2), (1, 3)
                        { 1, 0, 1, 0 }, //treci y i cetiri x-a (2, 0), (2, 1), (2, 2), (2, 3)
                        { 1, 0, 1, 1 }}; //cetvrti y i cetiri x-a (3, 0), (3, 1), (3, 2), (3, 3)
    //x i y su svugdje u funkcijama "obrnuti" jer je y vertikalna koordinata, a x horizontalna koordinata
    //y je prvi kako bi brojevi isli "redom"
    int sol[4][4] = {0};
    solveMaze(maze, sol);
    return 0;
}