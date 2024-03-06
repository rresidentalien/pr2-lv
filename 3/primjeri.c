#include <stdio.h>
int polje1d() {
    int polje[] = { 1, 2, 3, 4, 5 };
    int *pok[sizeof(polje)] = { NULL };
    int n = sizeof(polje)/sizeof(int);
    //izraz je ispravan samo ako je polje statički zauzeto
    int i;
    for (i = 0; i < n; i++) {
        *(pok + i) = &polje[i];
        //pok[i] = (polje + i);
        }
    for (i = 0; i < n; i++) {
        printf("%3d", *(*(pok + i)));
        //printf("%3d", *pok[i]);
        //printf("%3d ", pok[i][0]);
        //printf("%3d", *(*(pok + i) + 0));
        }
    printf("\n");

    //u prvoj for petlji s *(pok + i) dereferenciramo pok, sto znaci da cemo na adresu pok[i] upisati neku vrijednost. ta vrijednost je &polje[i], tj. adresa i-tog elementa polja.
    //u drugoj for petlji s *(*(pok + i)) duplo dereferenciramo pok, cime printamo vrijednost na adresi koju pokazuje pok, tj. vrijednost i-tog elementa polja.
}

int polje2d() {
    int M[][3] = { { 1, 2, 3 },
    { 4, 5, 6 },
    { 7, 8, 9 },
    { 10, 11, 12 } };
    int *pok[4] = { NULL };
    int i, j;
    for (i = 0; i < 4; i++) {
        *(pok + i) = &M[i][0];
        //pok[i] = M[i];
        //*(pok + i) = M[i];
        //*(pok + i) = *(M + i);
    }
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 3; j++) {
            printf("%3d", *(*(pok + i) + j));
            //printf("%3d", pok[i][j]);
            //printf("%3d", *(pok[i] + j);
        }
    printf("\n");
    }

    //za lakse shvacanje ovog primjera pogledajte jednostavniji primjer s 1D poljem:
    //ako imamo 1D polje int array[5], onda je array ekvivalentno s &array[0], tj. polje je jednako adresi svog prvog elementa.
    //ako negdje dalje u kodu upisemo array, "maknuli" smo mu jednu dimenziju i tada on postaje pokazivac.
    //to se zove iscezavanje (decay): micanjem jedne dimenzije iz polja ono postaje pokazivac, tj. iscezava u pokazivac.

    //sada cemo lakse razumijeti 32. i 33. liniju koda:
    //&M[i][0] == M[i] jer &M[i][0] dohvaca adresu i-tog reda i 0-tog stupca, a M[i] iscezava u pokazivac na 0-ti indeks i-tog reda, sto je adresa M[i][0].
}

int mjeseci() {
    char *mjeseci[] = { "sijecanj", "veljaca", "ozujak", "travanj", "svibanj", "lipanj", "srpanj", "kolovoz", "rujan", "listopad", "studeni", "prosinac" };
    int i;
    for (i = 0; i < 12; i++) {
        printf("%d\t%s\n", i + 1, *(mjeseci + i));
        //printf("%d\t%s\n", i + i, mjeseci[i]);
    }

    //pri radu sa stringovima lakse je koristiti polje pokazivaca na stringove, jer time izbjegavamo 2D polje (gdje je prva dimenzija broj stringova, a druga dimenzija broj znakova u svakom stringu).
    //također, lakse je koristiti polje pokazivaca jer je svaki string zaseban element polja, a ne dio nekog veceg polja.
    //time izbjegavamo i potrebu za kopiranjem stringova, jer svaki string ima svoju adresu.
    //pokazivac smo dereferencirali kako bismo dobili vrijednost na adresi koju pokazuje, tj. string.
}

int elementiPolja() {
    int polje2D[][3] = { {1, 2, 3},
                        {4, 5, 6},
                        {7, 8, 9},
                        {10, 11, 12} };
    int *pokNa2D = *(polje2D + 0);
    //int *pokNa2D = *polje2D ili polje2D[0];
    int i, j;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 3; j++) {
            printf("polje2D[%d][%d]\t%d\n", i, j, polje2D[i][j]);
            //printf("*(*(polje2D + %d) + %d)\t%d\t", i, j, *(*(polje2D + i) + j));
            //printf("*(polje2D[%d] + %d)\t%d\t", i, j, *(polje2D[i] + j));
        }
    }
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 3; j++) {
            printf("*(pokNa2D + %d * %d + %d\t%d\t", i, 3, j, *(pokNa2D + i * 3 + j));
        }
    printf("\n");
    }
}

int main() {
    printf("1D polje:\n");
    polje1d();
    printf("2D polje:\n");
    polje2d();
    printf("Mjeseci:\n");
    mjeseci();
    printf("Elementi polja:\n");
    elementiPolja();

    return 0;
}