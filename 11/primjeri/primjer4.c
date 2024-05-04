#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void swap(int *x, int *y) { //zamjena dvije vrijednosti
    int aux;
    aux = *x;
    *x = *y;
    *y = aux;
}

void generiranjePolja(int A[]) { //generira polje od 30 tisuca pseudo slucajnih brojeva i sprema ih u polje.txt
    int i;
    FILE *f;
    f = fopen("polje.txt", "w");
    if (f == NULL) {
        printf("Greska prilikom otvaranja datoteke!");
        return;
    }
    for (i = 0; i < 30000; i++) {
        A[i] = (rand() % 30000) + 1;
        fprintf(f, "%d ", A[i]);
    }
    fclose(f);
}

void ucitavanjePolja(int A[]) { //otvara polje.txt, cita sve elemente iz njega i sprema ih u predano polje
    int i;
    FILE *f;
    f = fopen("polje.txt", "r");
    for (i = 0; i < 30000; i++) {
        fscanf(f, "%d", &A[i]);
    }
    fclose(f);
}

void spremanjePolja(int A[], int n) { //sprema polje u spolje.txt iz predanog polja duljine n
    int i;
    FILE *f;
    f = fopen("spolje.txt", "w");
    for (i = 0; i < n; i++) {
        fprintf(f, "%d ", A[i]);
    }
    fclose(f);
}

void ispisPolja(int A[], int n) { //ispis predanog polja duljine n na ekran
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
}

void selectionSort(int a[], int n) {
    int i, j, min;
    for (i = 0; i < n; i++) {
        min = i;
        for (j = i + 1; j < n; j++)
            if (a[j] < a[min])
                min = j;
        swap(&a[i], &a[min]);
    }
}

void bubbleSort(int a[], int n) {
    int i, j, chg;
    for (i = 0, chg = 1; chg; i++) {
        chg = 0;
        for (j = 0; j < n - 1 - i; j++)
            if (a[j + 1] < a[j]) {
                swap(&a[j], &a[j + 1]);
                chg = 1;
            }
    }
}

void quickSort(int a[], int low, int high) {
    int i = low, j = high;
    int s = a[(low + high) / 2];
    while (i <= j) {
        while (a[i] < s) {
            i++;
        }
        while (a[j] > s) {
            j--;
        }
        if (i <= j) {
            swap(&a[i], &a[j]);
            i++;
            j--;
        }
    }
    if (low < j)
        quickSort(a, low, j);
    if (i < high)
        quickSort(a, i, high);
}

int main() {
    srand(time(NULL));
    int niz[30000];
    int izbor, n = 30000;
    float seconds;
    clock_t start, end;
    do {
        printf("\nIzaberite broj 1-8:\n");
        printf("1. Generiranje polja i spremanje u polje.txt\n");
        printf("2. Ucitavanje polja iz datoteke polje.txt u spremanje u polje podataka\n");
        printf("3. Bubble Sort\n");
        printf("4. Selection sort\n");
        printf("5. Quick Sort\n");
        printf("6. Ispis polja\n");
        printf("7. Spremanje polja iz memorije u datoteku spolje.txt\n");
        printf("8. Kraj\n");
        scanf("%d", &izbor);
        switch (izbor) {
            case 1:
                generiranjePolja(niz);
                break;
            case 2:
                ucitavanjePolja(niz);
                break;
            case 3:
                start = clock();
                bubbleSort(niz, n);
                end = clock();
                seconds = (float)(end - start) / CLOCKS_PER_SEC;
                printf("Vrijeme izvođenja: %.8lfs.\n", seconds);
                break;
            case 4:
                start = clock();
                selectionSort(niz, n);
                end = clock();
                seconds = (float)(end - start) / CLOCKS_PER_SEC;
                printf("Vrijeme izvođenja: %.8lfs\n", seconds);
                break;
            case 5:
                start = clock();
                quickSort(niz, 0, n - 1);
                end = clock();
                seconds = (float)(end - start) / CLOCKS_PER_SEC;
                printf("Vrijeme izvođenja: %.8lfs.\n", seconds);
                break;
            case 6:
                ispisPolja(niz, n);
                break;
            case 7:
                spremanjePolja(niz, n);
                break;
            case 8:
                break;
        }
    } while (izbor != 8);
    printf("\n\n");
    return 0;
}