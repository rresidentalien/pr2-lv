#include <stdio.h>

static char p[] = "Ovo je prva datoteka";
static int br = 1;

static void ispis(void) {
    printf("Funkcije ispis() iz prve datoteke\n");
}

void prvaIspis(void) {
    printf("p: %s\n", p);
    ispis();
    printf("br: %d\n", br);
}