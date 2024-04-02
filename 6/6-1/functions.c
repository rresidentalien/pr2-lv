#include <stdio.h>
#include <stdlib.h>

int** allocateMatrix(int n, int m)
{
    int i;
    int **M;
    M = (int**)malloc(n * sizeof(int*));
    for (i = 0; i < n; i++) {
        M[i] = (int*)malloc(m * sizeof(int));
    }
    return M;
}

void inputMatrix(int **M, int n, int m)
{
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("Input M[%d][%d]: ", i, j);
            scanf("%d", (*(M + i) + j));
        }
    }
}

void printMatrix(int **M, int n, int m)
{
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("%d\t", M[i][j]);
        }
        printf("\n");
    }
}

void matrixTimesK(int **M, int n, int m, int k)
{
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            M[i][j] *= k;
        }
    }
}