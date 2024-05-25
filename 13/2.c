#include <stdio.h>
#include <stdlib.h>
#define indeks(s, dg, gg) s = (dg+gg)/2

void swap (int *x, int *y) {
    int aux;
    aux = *x;
    *x = *y;
    *y = aux;
}

void selectionSort (int a[], int n) {
    int i, j, min;
    for (i = 0; i < n-1; i++) {
        min = i;
        for (j = i+1; j < n; j++)
            if (a[j] < a[min]) 
                min = j;
        swap(&a[i], &a[min]);
    }
}

void binarySearch(int *V, int x) {
    int dg=0, gg=499, s;
    while (dg<=gg) {
        indeks(s, dg, gg);
        if (x == V[s]) {
            printf("Broj je nadjen.");
            break;
        }
        else if (x>V[s]) {
            dg = s+1;
        }
        else if (x<V[s]) {
            gg = s-1;
        }
    }
    if (dg>gg) 
        printf ("Broj nije nadjen.");
}

int main() {
    int i;

    FILE *in = fopen("in.txt", "r");
    if (in == NULL) return 1;

    int polje[500];
    for (i = 0; i < 500; ++i) {
        fscanf(in, "%d", &polje[i]);
    }

    int x;
    scanf("%d", &x);

    selectionSort(polje, 500);

    printf("REZULTATI:\n");
    binarySearch(polje, x);

    fclose(in);
    return 0;
}