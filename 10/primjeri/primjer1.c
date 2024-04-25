#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n = 100; //maksimalna velicina stringa
    char orig[] = "Ovo je string koji cemo kopirati u dinamicki zauzeti";
    char *p = NULL;

    p = (char*)malloc(n*sizeof(char)); //pokazivac na dinamicki zauzet blok memorije castan u tip char u koji cemo smjestiti nas string (velicine 100 bajtova)
    if (p == NULL) {
        printf("Greska kod zauzimanja memorije");
        return 1;
    }

    strcpy(p,orig); //kopiramo string u dinamicki zauzetu memoriju
    puts(orig); //ispis na ekran iz originalnog stringa
    puts(p); //ispis na ekran iz dinamicki zauzete memorije

    free(p);
    p = NULL;
    return 0;
}