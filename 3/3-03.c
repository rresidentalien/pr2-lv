#include <stdio.h>
#include <stdlib.h>

int mnozenjeMatrice(int **matrica, int m, int n, int k) {
    int i, j;
    for (i = 0; i < m; ++i) {
        for (j = 0; j < n; ++j) {
            printf("%d ", *(*(matrica+i)+j) *= k);
        }
        printf("\n");
    }
}

int main() {
    int m, n, k;
    int i, j;

    do{
        printf("Unesi broj redaka: ");
        scanf("%d", &m);
    }while(m < 2 || m > 10);
    do{
        printf("Unesi broj stupaca: ");
        scanf("%d", &n);
    }while(n < 2 || n > 10);

    printf("Unesi broj s kojim zelis mnoziti matricu: ");
    scanf("%d", &k);

    int **matrica = (int **)malloc(m * sizeof(int *));
    if (matrica == NULL) {
        return 1;
    }
    for (i = 0; i < m; ++i) {
        *(matrica+i) = (int *)calloc(n, sizeof(int));
        if (*(matrica+i) == NULL) {
            return 1;
        }
    }

    for (i = 0; i < m; ++i) {
        for (j = 0; j < n; ++j) {
            scanf("%d", &*(*(matrica+i)+j));
        }
    }

    printf("REZULTATI:\n");
    mnozenjeMatrice(matrica, m, n, k);

    for (i = 0; i < m; ++i) {
        free(*(matrica+i));
    }
    free(matrica);

    return 0;
}