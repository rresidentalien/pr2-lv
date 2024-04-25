#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct tocka {
    float x;
    float y;
    float z;
}TOCKA;

typedef struct trokut {
    TOCKA t1;
    TOCKA t2;
    TOCKA t3;
}TROKUT;

float udaljenostTocaka(TOCKA *p1, TOCKA *p2) {
    return sqrt( pow(p2->x - p1->x, 2) + pow(p2->y - p1->y,2) + pow(p2->z - p1->z, 2));
}

float opseg(TROKUT *trokut) {
    float a = udaljenostTocaka(&trokut->t1, &trokut->t2);
    float b = udaljenostTocaka(&trokut->t1, &trokut->t3);
    float c = udaljenostTocaka(&trokut->t2, &trokut->t3);

    return a + b + c;
}

float najveciOpseg(TROKUT *trokuti, int m) {
    int i;
    float max = 0.0;

    for (i = 0; i < m; ++i) {
        if (opseg(&trokuti[i]) > max) {
            max = opseg(&trokuti[i]);
        }
    }

    return max;
}

int main() {
    FILE *model = fopen("model.txt", "r");
    TOCKA *tocke = NULL;
    TROKUT *trokuti = NULL;
    int n, m;
    int i;

    fscanf(model, "%d", &n);
    tocke = (TOCKA*)malloc(n * sizeof(TOCKA));
    if (tocke == NULL) {
        perror("Greska");
        return 1;
    }

    fscanf(model, "%d", &m);
    trokuti = (TROKUT*)malloc(m * sizeof(TROKUT));
    if (trokuti == NULL) {
        perror("Greska");
        return 1;
    }

    for (i = 0; i < n; ++i) {
        fscanf(model, "%f %f %f", &tocke[i].x, &tocke[i].y, &tocke[i].z);
    }
    for (i = 0; i < m; ++i) {
        int ind1, ind2, ind3;
        fscanf(model, "%d %d %d", &ind1, &ind2, &ind3);
        trokuti[i].t1 = tocke[ind1];
        trokuti[i].t2 = tocke[ind2];
        trokuti[i].t3 = tocke[ind3];
    }

    float max = najveciOpseg(trokuti, m);
    
    printf("REZULTATI:\n");
    printf("%f", max);

    free(tocke);
    free(trokuti);
    return 0;
}