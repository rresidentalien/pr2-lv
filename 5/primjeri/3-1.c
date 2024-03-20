#include <stdio.h>
#include <math.h>

#define N 10

typedef struct tocka {
    float x;
    float y;
    float z;
} TOCKA; //dogovorno se aliasi struktura pisu velikim slovima

void inputData(TOCKA *p, int n) { //unos n tocaka
    int i;

    for (i = 0; i < n; i++) {
        printf("Upisi x, y i z za %d tocku: ", i+1);
        scanf("%f%f%f", &p[i].x, &p[i].y, &p[i].z);
    }
}

TOCKA* findMax(TOCKA *p, int n) { //pronalazenje najvece z koordinate svake tocke
    int i;
    TOCKA *max;

    max = &p[0];
    for (i = 0; i < n; i++) {
        if (max->z < p[i].z) {
            max = &p[i];
        }
    }

    return max;
}

//iskreno koja je poanta ove funkcije
//valjda da predamo pokazivac tipa tocka funkciji? kao jer zasto ne?
void printTocka(TOCKA *p) { //ispisuje koordinate tocke s najvecom z koordinatom
    printf("Koordinate tocke su: %.2f, %.2f, %.2f \n", p->x, p->y, p->z);
}

int main(void) {
    TOCKA tocke[100]; //polje od 100 tocaka
    TOCKA *max; //pokazivac max tipa tocka

    inputData(tocke, N); //unosimo N(10) tocaka
    max = findMax(tocke, N); //trazimo tocku s najvecom z koordinatom
    printTocka(max); //predajemo pokazivac max funkciji printTocka koja ispisuje koordinate

    return 0;
}