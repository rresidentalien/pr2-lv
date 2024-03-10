#include <stdio.h>
#include <stdlib.h>

int najveciElementMatrice(int **a, int m, int n) {
    int i, j, max = **a;

    for (i = 0; i < m; ++i) {
        for (j = 0; j < n; ++j) {
            if (*(*(a + i) + j) > max) {
                max = *(*(a + i) + j);
            }
        }
    }

    return max;
}

int main() {
    int m, n, **a;
    int i, j;
    do{
        printf("Unesi broj redaka: ");
        scanf("%d", &m);
    }while (m < 2 || m > 10);
    do{
        printf("Unesi broj stupaca: ");
        scanf("%d", &n);
    }while (n < 2 || n > 10);

    a = (int **)malloc(m * sizeof(int *));
    if (a == NULL) {
        return 1;
    }
    for (i = 0; i < m; ++i) {
        *(a + i) = (int *)calloc(n, sizeof(int));
        if (*(a + i) == NULL) {
            return 1;
        }
    }

    for (i = 0; i < m; ++i) {
        for (j = 0; j < n; ++j) {
            scanf("%d", &*(*(a+i)+j));
        }
    }

    printf("REZULTATI:\n");
    printf("%d", najveciElementMatrice(a, m, n));

    return 0;
}