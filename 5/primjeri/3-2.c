#include <stdio.h>
#include <math.h>

typedef struct tocka {
    float x;
    float y;
    float z;
} Tocka;

int inputData(Tocka *p) {
    int i, n;
    printf("Upisi broj tocaka: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Upisi x, y i z za %d tocku: ", i+1);
        scanf("%f%f%f", &p[i].x, &p[i].y, &p[i].z);
    }

    return n;
}

void findTopTwo(Tocka *p, int n, Tocka *max[]) {
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

float len3d(Tocka *p1, Tocka *p2) {
    return sqrt( pow(p2->x - p1->x, 2) + pow(p2->y - p1->y,2) + pow(p2->z - p1->z, 2));
}

void printTocka(Tocka *p) {
    printf("%.2f, %.2f, %.2f \n", p->x, p->y, p->z);
}

int main(void) {
    Tocka tocke[40];
    Tocka *max[2];
    int n;
    float D;

    n = inputData(tocke);
    findTopTwo(tocke, n, max);

    D = len3d(max[0], max[1]);

    printf("Udaljenost najvisih vrhova je %.2f\n", D);
    printf("a njihove koordinate su:\n");
    printTocka(max[0]);
    printTocka(max[1]);
    
    return 0;
}