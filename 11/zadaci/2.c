#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y) {
    int aux;
    aux = *x;
    *x = *y;
    *y = aux;
}

void selectionSort(int *a, int n) {
    int i, j, min;
    for (i = 0; i < n-1; ++i) {
        min = i;
        for (j = i+1; j < n; j++)
            if (a[j] < a[min])
                min = j;
        swap(&a[i], &a[min]);
    }
}

int sekvencijalno(int *V, int x) {
    int i, flag = 0, sekkoraci = 0;

    for (i = 0; i < 500; ++i) {
        if (V[i] == x) {
            flag = 1;
            break;
        }
        ++sekkoraci;
    }
    if (flag) {
        printf("Broj %d je pronadjen nakon %d koraka.", x, sekkoraci);
        return sekkoraci;
    }
    else {
        printf("Broj %d nije pronadjen.", x);
        return 0;
    }
}

int binarno(int *V, int x) { //polje, trazeni element
    int dg=0;
    int gg= 499;
    int s;
    int binkoraci = 0;

    while (dg<=gg) {
        s = (dg+gg)/2;
        ++binkoraci;
        if (x == V[s]) {
            printf("Broj %d je pronadjen u %d koraka.", x, binkoraci);
            return binkoraci;
            break;
        }
        else if (x>V[s]) {
            dg = s+1;
        }
        else if (x<V[s]) {
            gg = s-1;
        }
    }
    if (dg>gg) {
        printf ("Broj %d nije pronadjen.", x);
        return 0;
    }
}

int main() {
    int i;
    int n[5];
    int polje[500];
    int uspjesniSek = 0, uspjesniBin = 0;
    int koraciSek = 0, koraciBin = 0;

    FILE* f = fopen("in1.txt", "r");
    if (f == NULL) 
        perror("Greska");

    for (i = 0; i < 500; ++i) {
        fscanf(f, "%d", &polje[i]);
    }

    selectionSort(polje, 500); //polje mora biti sortirano za binarnu pretragu

    for (i = 0; i < 5; ++i) {
        do {
            printf("Unesi %d. broj: ", i+1);
            scanf("%d", &n[i]);
        }while(n[i] < 0 || n[i] > 1000);
    }

    printf("REZULTATI:\n");
    printf("Sekvencijalno:\n");
    for (i = 0; i < 5; ++i) {
        printf("%d. ", i+1);
        int koraci = sekvencijalno(polje, n[i]);
        printf("\n");

        if (koraci > 0) {
            koraciSek += koraci;
            ++uspjesniSek;
        }
    }

    printf("Binarno:\n");
    for (i = 0; i < 5; ++i) {
        printf("%d. ", i+1);
        int koraci = binarno(polje, n[i]);
        printf("\n");

        if (koraci > 0) {
            koraciBin += koraci;
            ++uspjesniBin;
        }
    }

    printf("\nSrednji broj koraka za sekvencijalno pretrazivanje je: %d", koraciSek/uspjesniSek);
    printf("\nSrednji broj koraka za binarno pretrazivanje je: %d", koraciBin/uspjesniBin);

    fclose(f);
    return 0;
}