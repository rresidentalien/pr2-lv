#include <stdio.h>

int sekvencijalnaPretraga(int K[], int x, int length, int *brk) { //argumenti: niz brojeva, broj koji trazimo, velicina niza(broj brojeva?), broj koraka
    int i;
    for (i = 0; i < length; i++) {
        (*brk)++; //inkrementira se za svaki korak u kojem ne pronadjemo trazeni broj
        if (K[i] == x)
            return i;
    }
    return -1;
}

int binarnaPretraga(int K[], int x, int length, int *brk) { //argumenti: niz brojeva, broj koji trazimo, velicina niza, broj koraka
    int dg, gg, s;

    dg = 0; //donja granica = 0
    gg = length - 1; //gornja granica = indeks posljednjeg elementa

    while (dg <= gg) {
        s = (dg + gg) / 2; //srednji element
        (*brk)++;
        if (x == K[s]) //ako je srednji element trazeni element, vracamo srednji element
            return s;
        else if (x > K[s]) //ako je trazeni element veci od srednjeg
            dg = s + 1; //donja granica se pomice na jedan desno od srednjeg elementa (skratili smo si "vidno polje" za pola+1 jer nam cijela lijeva strana ne treba)
        else if (x < K[s]) //ako je trazeni element manji od srednjeg
            gg = s - 1; //gornja granica se pomice na jedan lijevo od srednjeg elementa
    }
    if (dg > gg) //nemoguc slucaj, tj. ako se dogodi imamo gresku
        return -1;
}

int main(void) {
    int niz[30] = {1, 2, 5, 7, 8, 9, 11, 14, 17, 19, 21, 23, 27, 28, 29, 30, 32, 34, 35, 36, 38, 40, 41, 43, 44, 45, 46, 48, 49, 50};
    int n, x, brks = 0, brkb = 0, brki = 0;
    int sp, bp, ip;

    n = sizeof(niz) / sizeof(int);
    printf("Unesi broj koji zelis pronaci u intervalu 1-50: ");
    scanf("%d", &x);

    sp = sekvencijalnaPretraga(niz, x, n, &brks);
    bp = binarnaPretraga(niz, x, n, &brkb);

    if (sp != -1)
        printf("\nSekvencijalno: broj je pronadjen na %d. mjestu u %d koraka!", sp, brks);
    else
        printf("\nBroj nije pronadjen!");

    if (bp != -1)
        printf("\nBinarno: broj je pronadjen na %d. mjestu u %d koraka!", bp, brkb);
    else
        printf("\nBroj nije pronadjen!");

    printf("\n\n");
    return 0;
}