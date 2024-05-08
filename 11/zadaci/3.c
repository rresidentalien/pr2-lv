#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int arr[], int n, int uzlazno) {
    int i, j, temp;
    for (i = 0; i < n-1; ++i) {
        for (j = 0; j < n-i-1; ++j) {
            if (uzlazno) {
                if (arr[j] > arr[j+1]) {
                    temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
            } else {
                if (arr[j] < arr[j+1]) {
                    temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
            }
        }
    }
}

void selectionSort(int arr[], int n, int uzlazno) {
    int i, j, min_idx, temp;
    for (i = 0; i < n-1; i++) {
        min_idx = i;
        for (j = i+1; j < n; j++) {
            if (uzlazno) {
                if (arr[j] < arr[min_idx]) {
                    min_idx = j;
                }
            } else {
                if (arr[j] > arr[min_idx]) {
                    min_idx = j;
                }
            }
        }
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

int main() {
    int i;

    FILE *ulaz = fopen("ulaz.txt", "r");
    FILE *izlaz = fopen("izlaz.txt", "w");

    int n;
    fscanf(ulaz, "%d", &n);

    int ulazPolje[n];
    for (i = 0; i < n; ++i) {
        fscanf(ulaz, "%d", &ulazPolje[i]);
    }

    int izbor;
    do {
        printf("\nIzbornik:\n1. Ispis ucitanog polja\n2. Sortiranje - bubble sort uzlazno\n3. Sortiranje - bubble sort silazno\n4. Sortiranje - selection sort uzlazno\n");
        printf("5. Sortiranje - selection sort silazno\n6. Zapisivanje polja u izlaz.txt\n7. Kraj\n");

        scanf("%d", &izbor);

        switch(izbor) {
            case 1:
                for (i = 0; i < n; ++i) {
                    printf("%d ", ulazPolje[i]);
                }
                break;
            case 2:
                bubbleSort(ulazPolje, n, 1);
                break;
            case 3:
                bubbleSort(ulazPolje, n, 0);
                break;
            case 4:
                selectionSort(ulazPolje, n, 1);
                break;
            case 5:
                selectionSort(ulazPolje, n, 0);
                break;
            case 6:
                for (i = 0; i < n; ++i) {
                    fprintf(izlaz, "%d ", ulazPolje[i]);
                }
                break;
        }
    }while (izbor != 7);

    fclose(ulaz);
    fclose(izlaz);
    return 0;
}