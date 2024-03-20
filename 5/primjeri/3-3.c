#include <stdio.h>
#include <math.h>

#define N 4
typedef struct tocka {
float x;
float y;
float z;
}Tocka;
typedef struct trokut {
    struct tocka *t1;
    struct tocka *t2;
    struct tocka *t3;
} Trokut;

void inputData(Tocka *p, Trokut *t, int n) {
    int i;
    int ind1, ind2, ind3;

    for (i = 0; i < n; i++) {
        printf("Upisi x, y i z za %d tocku: ", i);
        scanf("%f%f%f", &p[i].x, &p[i].y, &p[i].z);
    }
    for (i = 0;
         i < n;
         i++) {
        printf("Upisi indexe tocaka za %d trokut: ", i);
        scanf("%d%d%d", &ind1, &ind2, &ind3);
        t[i].t1 = &p[ind1];
        t[i].t2 = &p[ind2];
        t[i].t3 = &p[ind3];
    }
}

float len3d(Tocka p) {
    return sqrt(p.x * p.x + p.y * p.y + p.z * p.z);
}

float distTrokut(Trokut t) {
    float D = 0.0;
    D = len3d(*t.t1) + len3d(*t.t2) + len3d(*t.t3);
    D /= 3;
    return D;
}

int main(void) {
    Tocka tocke[100];
    Trokut trokuti[100];
    Trokut *max;
    int i;
    float Dtrenutni = 0, Dmax = 0;

    inputData(tocke, trokuti, N);

        for (i = 0; i < N; i++) {
                Dtrenutni = distTrokut(trokuti[i]);
                if (Dtrenutni > Dmax) {
                    Dmax = Dtrenutni;
                    max = &trokuti[i];
                }
            }

            printf("Najudaljeniji trokut je udaljen %.2f od ishodišta,\n", Dmax);
            printf("a njegove koordinate su:\n");
            printf("(%.2f, %.2f, %.2f)\n", max->t1->x, max->t1->y, max->t1->z);
            printf("(%.2f, %.2f, %.2f)\n", max->t2->x, max->t2->y, max->t2->z);
            printf("(%.2f, %.2f, %.2f)\n", max->t3->x, max->t3->y, max->t3->z);

            return 0;
}