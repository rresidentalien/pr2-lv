#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct tocka {
    float x;
    float y;
    float z;
}TOCKA;

void inputData(TOCKA *tocke, int n) { //funkcija za upis n tocaka u polje struktura tocka
    int i;
    for (i = 0; i < n; i++) {
        printf("Upisi x, y i z za %d tocku: ", i+1);
        scanf("%f%f%f", &tocke[i].x, &tocke[i].y, &tocke[i].z);
    }
}

void findTopTwo(TOCKA *p, int n, TOCKA *max[]) { //funkcija koja pronalazi dvije tocke s najvecim z koordinatama
    int i;

    max[0] = &p[0];
    max[1] = &p[1];

    for (i = 2; i < n; i++) {
        if(max[0]->z < p[i].z || max[1]->z < p[i].z) {
            if(max[0]->z < max[1]->z)
                max[0] = &p[i];
            else
                max[1] = &p[i];
        }
    }
}

float len3d(TOCKA *p1, TOCKA *p2) { //funkcija koja racuna udaljenost dvije tocke u 3D prostoru
    return sqrt( pow(p2->x - p1->x, 2) + pow(p2->y - p1->y,2) + pow(p2->z - p1->z, 2));
}

void printTocka(TOCKA *p) { //prima adresu tocke i ispisuje ju na ekran
    printf("%.2f, %.2f, %.2f \n", p->x, p->y, p->z);
}

int main() {
    TOCKA *tocke;
    TOCKA *max[2];
    int n;
    float D;

    printf("Upisi broj tocaka: ");
    scanf("%d", &n);

    tocke = (TOCKA *) malloc ( n * sizeof(TOCKA)); //dinamicko zauzimanje memorije za n tocaka
    if (tocke == NULL){
        printf("Greska kod zauzimanja memorije ");
        return 1;
    }

    inputData(tocke, n); //unos tocaka u memoriju tocke

    for (int i = 0; i < n; i++) { //ispis svih tocaka
        printf("%.2f %.2f %.2f\n", tocke[i].x, tocke[i].y, tocke[i].z);
    }

    findTopTwo(tocke, n, max);

    D = len3d(max[0], max[1]);

    printf("Udaljenost najvisih vrhova je %.2f\n", D);
    printf("a njihove koordinate su:\n");
    printTocka(max[0]);
    printTocka(max[1]);

    free(tocke);
    tocke = NULL;
    return 0;
}