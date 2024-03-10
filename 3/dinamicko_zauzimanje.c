#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RED 4
#define STUPAC 3

int main() {
    srand((unsigned)time(NULL));

    int **polje2D = NULL; //dvodimenzionalno polje -> dvodimenzionalni pokazivac
    int i, j;

    polje2D = (int **)malloc(RED * sizeof(int *)); //dinamicka alokacija redova
    if (polje2D == NULL) {
        return 1;
    }//provjera uspjesnosti

    for (i = 0; i < RED; ++i) {
        polje2D[i] = (int *)calloc(STUPAC, sizeof(int)); //dinamicka alokacija stupaca za svaki red
        if (polje2D[i] == NULL) {
            return 1;//provjera uspjesnosti
        }
    }

    for (i = 0; i < RED; ++i) {
        for (j = 0; j < STUPAC; ++j) {
            polje2D[i][j] = (float)rand() / RAND_MAX * (10) + 1; //generiranje pseudo slucajnih brojeva od 1 do 11
        }
    }

    for (i = 0; i < RED; ++i) {
        for (j = 0; j < STUPAC; ++j) {
            printf("polje[%d][%d] = %d \n", i, j, polje2D[i][j]); //printanje 2D polja
        }
    }

    for (i = 0; i < RED; ++i) {
        free(polje2D[i]);
    } //moramo koristiti for petlju ovdje kako bismo oslobodili svaki element, a ne samo retke polja
    free(polje2D);
    polje2D = NULL; //dobra praksa

    return 0;
}