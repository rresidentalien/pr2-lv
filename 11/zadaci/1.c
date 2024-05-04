#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, koraci = 0;
    int flag = 0;
    int polje[500];

    FILE* in1txt = fopen("in1.txt", "r");
    if (in1txt == NULL) {
        perror("Greska");
    }

    for (i = 0; i < 500; ++i) {
        fscanf(in1txt, "%d", &polje[i]);
    }

    do {
        printf("Unesi broj: ");
        scanf("%d", &n);
    }while (n > 1000 || n < 0);

    for (i = 0; i < 500; ++i) {
        if (polje[i] == n) {
            flag = 1;
            break;
        }
        ++koraci;
    }

    printf("REZULTATI:\n");
    if (flag)
        printf("Broj %d je pronadjen nakon %d koraka.", n, koraci);
    else
        printf("Broj %d nije pronadjen.", n);

    fclose(in1txt);
    return 0;
}