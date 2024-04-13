#include <stdio.h>

static char p[] = "Ovo je druga datoteka";
static int br = 2;

static void ispis(void) {
    printf("Funkcije ispis() iz druge datoteke \n");
}

void drugaIspis(void) {
    printf("p: %s\n", p);
    ispis();
    printf("br: %d\n", br);
}