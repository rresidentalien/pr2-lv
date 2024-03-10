#include <stdio.h>
int polje1d() {
    int polje[] = { 1, 2, 3, 4, 5 };
    int *pok[sizeof(polje)] = { NULL };
    int n = sizeof(polje)/sizeof(int);
    //izraz je ispravan samo ako je polje statički zauzeto - pri dinamickom zauzimanju memorije memorija se ne alocira pri kompajliranju, vec pri izvodenju programa; sizeof(polje) ce vratiti velicinu pokazivaca na prvi element polja
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
    //da smo samo jednom dereferencirali pok u drugoj for petlji npr *(pok+i), dobili bismo vrijednost na pok[i] (adresu i-tog elementa pok), a ne vrijednost na adresi na koju pok[i] pokazuje.
    //pok[i][0] i *(*(pok+i)+0) - 0 referira na prvi element i-tog "podpolja"
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
    //ako imamo 1D polje int array[5], onda je array ekvivalentno &array[0], tj. polje je jednako adresi svog prvog elementa.
    //ako negdje dalje u kodu upisemo array, "maknuli" smo mu jednu dimenziju i tada on postaje pokazivac.
    //to se zove iscezavanje (decay): micanjem jedne dimenzije iz polja ono postaje pokazivac, tj. iscezava u pokazivac.

    //sada cemo lakse razumijeti 34. i 35. liniju koda:
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

int pokNaPolje() {
    int polje[] = { 1, 2, 3, 4, 5 };
    int *p = polje;
    int (*pPolje)[5] = &polje;

    printf("Adresa prije inkrementa\n");
    printf("p = %p\n", p);
    printf("pPolje = %p\n", pPolje);
    printf("*pPolje = %p\n", *pPolje);

    printf("Vrijednost prije inkrementa\n");
    printf("*p = %d\n", *p);
    printf("**pPolje = %d\n", **pPolje);

    p++;
    pPolje++; //ovdje se pPolje povecava za 5 * sizeof(int), a ne za jedan element, pa vam zato ispise nesto bezveze

    printf("Adresa poslije inkrementa\n");
    printf("p = %p\n", p);
    printf("pPolje = %p\n", pPolje);
    printf("*pPolje = %p\n", *pPolje);
    printf("Vrijednost poslije inkrementa\n");
    printf("*p = %d\n", *p);
    printf("**pPolje = %d\n", **pPolje);
}

int ispisAdrese() {
    int polje2D[][3] = { { 1, 2, 3 },
                        { 4, 5, 6 },
                        { 7, 8, 9 },
                        { 10, 11, 12 } };
    int i;
    printf("Ispis memorijske adrese pojedinog podpolja\n"); //svako podpolje zauzima 3 * sizeof(int) -> 3*4 bajtova pa je adresa svakog podpolja udaljena za 12 bajtova od prethodnog
    for (i = 0; i < 4; i++)
    {
        printf("polje2D[%d]\t%p\n", i, polje2D + i);
    }
        printf("\nIspis memorijske adrese prvog elementa podpolja\n"); //svaki prvi element podpolja je udaljen od iduceg za 12 bajtova
    for (i = 0; i < 4; i++)
    {
        printf("polje2D[%d]\t%p\n", i, *(polje2D + i));
        //printf("polje2D[%d]\t%lu\n“, i, polje2D[i]);
    }
}

int ispisPolja() {
    int polje2D[][3] = { {1, 2, 3},
                        {4, 5, 6},
                        {7, 8, 9},
                        {10, 11, 12} };
    int i, j;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 3; j++) {
            printf("polje2D[%d][%d]\t%d\n", i, j, *(*(polje2D + i) + j)); //pokazivacka notacija za pristup elementima 2D polja
        //printf("polje2D[%d][%d]\t%d\n", i, j, polje2D[i][j]);
        }
    printf("\n");
    }
}

int pokNa2DPolje () {
    int polje2D[][3] = { { 1, 2, 3 },
                        { 4, 5, 6 },
                        { 7, 8, 9 },
                        { 10, 11, 12 } };
    int i, j;
    int(*p)[3] = polje2D;
    //p = polje2D;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 3; j++) {
            printf("polje2D[%d][%d]\t%d\t", i, j, *(*(p + i) + j));
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
    printf("Pokazivac na polje:\n");
    pokNaPolje();
    printf("Ispis adrese:\n");
    ispisAdrese();
    printf("Ispis polja:\n");
    ispisPolja();
    printf("Pokazivac na 2D polje:\n");
    pokNa2DPolje();

    return 0;
}