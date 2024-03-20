#include <stdio.h>
#include <math.h> //za sqrt i pow

typedef struct tocka {
    float x;
    float y;
    float z;
} TOCKA;

int inputData(TOCKA *p) { //funkcija prima pokazivac tipa tocka
    int i, n;
    printf("Upiši broj točaka: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Upiši x, y i z za %d. točku: ", i+1);
        scanf("%f%f%f", &p[i].x, &p[i].y, &p[i].z);
    }

    return n; //vraca broj unesenih tocaka, sto nam kasnije treba kao argument za findTopTwo
}

void findTopTwo(TOCKA *p, int n, TOCKA *max[]) { //funkcija koja trazi dvije tocke s najvecom z koordinatom
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

float len3d(TOCKA *p1, TOCKA *p2) { //izracun udaljenost izmedju dvije tocke
    return sqrt(pow(p2->x - p1->x, 2) + pow(p2->y - p1->y, 2) + pow(p2->z - p1->z, 2));
}

void printTocka(TOCKA *p) { //ispis koordinata jedne tocke
    printf("%.2f, %.2f, %.2f \n", p->x, p->y, p->z);
}

int main(void) {
    TOCKA tocke[40]; //polje od 40 tocki
    TOCKA *max[2]; //dva pokazivaca na tocku
    int n;
    float D;

    n = inputData(tocke);
    findTopTwo(tocke, n, max);

    D = len3d(max[0], max[1]);

    printf("Udaljenost najviših vrhova je %.2f\n", D);
    printf("a njihove koordinate su:\n");
    printTocka(max[0]);
    printTocka(max[1]);
    
    return 0;
}