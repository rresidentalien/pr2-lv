#include <stdio.h>

int main() {
    char znakovi[10], znak;
    int brojac = 0, i;

    for(i=0; i<10; i++) {
        printf("\nUcitaj %d. znak: ", i+1);
        scanf(" %c", &znakovi[i]);
    }

    printf("\nUcitaj znak koji trazimo:");
    scanf(" %c", &znak);

    for(i=0; i<10; i++) {
        if(znakovi[i] == znak)
            brojac++;
    }
    if(brojac == 0)
        printf("\nZnak %c se ne nalazi u polju", znak);
    else
        printf("\nZnak %c se pojavljuje %d puta", znak, brojac);

    printf("\n\n");

    return 0;
}