#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    if (*(int*)a < *(int*)b)
        return -1;
    else if (*(int*)a > *(int*)b)
        return 1;
    else
        return 0;
};

int main() {
    int polje[] = {1, 2, 4, 9, 18, 324, 333, 335, 367, 368, 421, 422, 500, 505, 506, 800, 999, 1000, 1011, 2000};
    int *res, x;
    int n = sizeof(polje)/sizeof(int);
    printf("Koji broj zelite traziti: ");
    scanf("%d", &x);
    res = bsearch(&x, polje, n, sizeof(int), compare);
    if (res != NULL)
        printf ("Broj %d je pronadjen na adresi: %p!", *res, res);
    else
        printf ("Broj %d nije pronadjen!", x);
    return 0;
}