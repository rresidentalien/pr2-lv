#include <stdio.h>

extern int br2;
extern int drugaIspis(int);
// int br2;
// int drugaIspis(int);

void prvaIspis(void) {
    char p[] = "Ovo je prva datoteka";
    int br = 1;
    printf("p: %s\n", p);
    printf("br: %d\n", br);
    printf("br2: %d\n", br2);
    printf("extern: %d\n", drugaIspis(br));
}