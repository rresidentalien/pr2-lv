#include <stdio.h>
#include <stdlib.h>

void ispis2D(int **p, int m, int n) {
    int i, j;
    for (i = 0; i < m; ++i) {
        for (j = 0; j < n; ++j) {
            printf("%d " , p[i][j]); //*(*(p+i)+j)
        }
        printf("\n");
    }
}

int main() {
    int polje2D[4][3] = { {1, 2, 3},
                         {4, 5, 6},
                         {7, 8, 9},
                         {10, 11, 12} };
    int *pok[4] = {NULL};
    int i;

    for (i = 0; i < 4; ++i) {
        pok[i] = polje2D[i];
    }

    ispis2D(pok, 4, 3);

    return 0;
}