#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct tocka {
    float x;
    float y;
    float z;
} TOCKA;

typedef struct trokut {
    TOCKA *t1;
    TOCKA *t2;
    TOCKA *t3;
} TROKUT;

void inputData(TOCKA *p, TROKUT *t, int n, int m) { //upis n tocaka i m trokuta sastavljenih od prethodno unesenih tocaka
    int i;
    int ind1, ind2, ind3;

    for (i = 0; i < n; i++) {
        printf("Upisi x, y i z za %d tocku: ", i);
        scanf("%f%f%f", &p[i].x, &p[i].y, &p[i].z);
    }
    for (i = 0; i < m; i++) {
        printf("Upisi indexe tocaka za %d trokut: ", i);
        scanf("%d%d%d", &ind1, &ind2, &ind3);
        t[i].t1 = &p[ind1];
        t[i].t2 = &p[ind2];
        t[i].t3 = &p[ind3];
    }
}

float len3d(TOCKA p) { //udaljenost tocke od ishodista
    return sqrt(p.x*p.x + p.y*p.y + p.z*p.z);
}

float distTrokut(TROKUT t) { //udaljenost trokuta od ishodista (prosjecna udaljenost svake tocke od ishodista)
    float D = 0.0;
    D = len3d(*t.t1) + len3d(*t.t2) + len3d(*t.t3);
    D /= 3;

    return D;
}

int main() {
    TOCKA *tocke;
    TROKUT *trokuti;
    TROKUT *max;
    int i, n, m;
    float Dtrenutni=0, Dmax=0;

    printf("Upisi broj tocaka: ");
    scanf("%d", &n);
    tocke = (TOCKA *) malloc ( n * sizeof(TOCKA));
    if (tocke == NULL){
        printf("Greska kod zauzimanja memorije ");
        return 1;
    }


    printf("Upisi broj trokuta: ");
    scanf("%d", &m);
    trokuti = (TROKUT *) malloc ( n * sizeof(TROKUT));
    if (trokuti == NULL){
        printf("Greska kod zauzimanja memorije ");
        return 1;
    }


    inputData(tocke, trokuti, n, m);

    for (i = 0; i < m; i++) {
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


    free(tocke);
    free(trokuti);
    tocke = NULL;
    trokuti=NULL;
    return 0;
}