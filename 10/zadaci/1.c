#include <stdio.h>
#include <stdlib.h>

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
        printf("%.2f %.2f %.2f \n", tocke[i].x, tocke[i].y, tocke[i].z);
    }

    free(tocke);
    free(trokuti);
    return 0;
}