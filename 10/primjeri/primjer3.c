#include <stdio.h>
#include <stdlib.h>

typedef struct tocka {
    float x;
    float y;
    float z;
}TOCKA;

int main() {
    int n=10;

    TOCKA *polje = NULL;
    polje = (TOCKA*)malloc(n * sizeof(TOCKA)); //pokazivac tipa tocka na memoriju za n(10) tocaka
    if (polje == NULL){
        printf("Greska kod zauzimanja memorije");
        return 1;
    }

    for (int i = 0; i < n; ++i) {
        scanf("%f%f%f", &(polje+i)->x, &(polje+i)->y, &(polje+i)->z); //unos jedne tocke (tri broja)
        printf("-->%f %f %f<--\n", polje[i].x, polje[i].y, polje[i].z); //ispis jedne tocke
    }

    free(polje);
    polje = NULL;
    return 0;
}