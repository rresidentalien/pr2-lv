#include "myheader.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int **M = NULL;
    int m, n, K;
    
    printf("Unesi n i m: ");
    scanf("%d%d", &n, &m);
    
    printf("Unesi k: ");
    scanf("%d", &K);
    
    M = allocateMatrix(n, m);
    inputMatrix(M, n, m);
    matrixTimesK(M, n, m, K);
    
    printf("REZULTATI:\n");
    printMatrix(M, n, m);
    
    return 0;
}