/*#include <stdio.h>
int main(void) {
int polje[] = { 1, 2, 3, 4, 5 };
int *pok[5] = { NULL };
int n = sizeof(polje)/sizeof(int);
//izraz je ispravan samo ako je polje statički zauzeto
int i;
    for (i = 0; i < n; i++) {
    *(pok + i) = &polje[i];
    printf("%d", (*(pok + i)));
    printf("\n%d \n\n", &polje[i]);
    //pok[i] = (polje + i);
    }
for (i = 0; i < n; i++) {
    printf("%3d", *(*(pok + i)));
    printf("%3d", *pok[i]);
    printf("%3d ", pok[i][0]);
    printf("%3d", *(*(pok + i) + 0));
    }
}*/

#include<stdio.h>
int main(void) {
int M[][3] = { { 1, 2, 3 },
{ 4, 5, 6 },
{ 7, 8, 9 },
{ 10, 11, 12 } };
int *pok[4] = { NULL };
int i, j;
for (i = 0; i < 4; i++) {
*(pok + i) = &M[i][0];
//pok[i] = M[i];
//*(pok + i) = M[i];
//*(pok + i) = *(M + i);
}
for (i = 0; i < 4; i++) {
for (j = 0; j < 3; j++) {
printf("%3d", *(*(pok + i) + j));
//printf("%3d", pok[i][j]);
//printf("%3d", *(pok[i] + j);
}
printf("\n");
}
return 0;
}