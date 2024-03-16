#include <stdio.h>
#include <math.h>
#define N 10


int pr1() {
    struct tocka {
        int x;
        int y;
        int z;
    };
    struct trokut {
        struct tocka toc[3]; //trokut se sastoji od tri tocke i svaka tocka ima x,y,z koordinatu
    };

    struct trokut T[20]; //polje od 20 trokuta
    struct trokut *pT; //pokazivac tipa struct trokut
    pT = &T[0]; // pokazivac je usmjeren na prvi element polja trokuta (prvi trokut)

    T[0].toc[0].x = 2; //pT->toc[0].x = 2;      (*pT).toc[0].x = 2;
    T[0].toc[0].y = 3; //pT->toc[0].y = 3;      (*pT).toc[0].y = 3;
    T[0].toc[0].z = 4; //pT->toc[0].z = 4;      (*pT).toc[0].z = 4;

    printf("\nKoordinate jedne tocke prvog trokuta polja trokuta: %d,%d,%d\n", pT->toc[0].x, pT->toc[0].y, pT->toc[0].z);

    /*  pT = &T[0];         postavlja pokazivač na adresu prvog elementa polja T
        pT                  adresa prvog elementa polja T - adresa prve strukture trokut (od njih 20)
        *pT                 podatak na adresi pokazivača, tj. prvi element polja T - prva struktura trokut. ne mozemo ovako printati jer u C nema nacina da se odjednom isprinta cijela struktura
        (*pT).toc           adresa prvog elementa polja toc, što je zapravo varijabla tipa tocka - prva tocka prvog trokuta. takodjer ne mozemo samo ovako isprintati jer je tocka struktura
        pT->toc             ekvivalent gornjoj liniji
        (*pT).toc[0].x      koordinata x prvog elementa polja toc
        pt->toc[0].x        ekvivalent gornjoj liniji
    */
}



int pr2 () {
    //paziti na prioritet operatora!
    struct str {
        int x;
        int *p; //pokazivac na int koji je clan strukture
    };

    struct str a, *pstr; //varijabla i pokazivac tipa struct str
    pstr = &a; //pokazivac tipa str usmjeren na varijablu tipa str

    int podatak = 20;
    a.x = 19;
    a.p = &podatak; //pokazivac strukture pokazuje na varijablu podatak

    printf("a.x = (*pstr).x = %d\n", (*pstr).x);
    printf("*a.p = *(*pstr).p = *pstr->p = podatak = %d\n", *pstr->p); //svi izrazi su dereferencirani kako bi ispisivali podatak na koji pokazuje p
    printf("a.p = (*pstr).p = pstr->p = &podatak = %p\n", a.p); //pstr dereferenciramo kako bismo dobili vrijednosti iz strukture, a vrijednost na a.p je adresa varijable podatak
}



int pr3() {
    struct tocka {
        float x;
        float y;
        float z;
    };
    struct trokut {
        //koristimo se pokazivacima kako bismo lakse mogli mijenjati vrijednosti tocki
        struct tocka *t1;
        struct tocka *t2;
        struct tocka *t3;
    };
    struct tocka tocke[100];
    struct trokut trokuti[100];

    //koordinate prve cetiri tocke polja tocke[100]
    tocke[0].x = 0;
    tocke[0].y = 0;
    tocke[0].z = 0;

    tocke[1].x = 1;
    tocke[1].y = 1;
    tocke[1].z = 0;

    tocke[2].x = 0;
    tocke[2].y = 2;
    tocke[2].z = 0;

    tocke[3].x = 1;
    tocke[3].y = 1;
    tocke[3].z = 1;

    //uz pomnoc pokazivaca postavljamo koordinate tocki trokuta - brze je, zauzima manje memorije i pojednostavljuje sintaksu
    trokuti[0].t1 = &tocke[0]; //trokuti[0].t1.x = tocke[0].x;      sintaksa bez pokazivaca, bile bi nam potrebne tri linije koda za svaku tocku. ovdje imamo samo jednu
    trokuti[0].t2 = &tocke[1];
    trokuti[0].t3 = &tocke[2];

    trokuti[1].t1 = &tocke[0];
    trokuti[1].t2 = &tocke[1];
    trokuti[1].t3 = &tocke[3];

    trokuti[2].t1 = &tocke[0];
    trokuti[2].t2 = &tocke[2];
    trokuti[2].t3 = &tocke[3];

    trokuti[3].t1 = &tocke[1];
    trokuti[3].t2 = &tocke[2];
    trokuti[3].t3 = &tocke[3];

    printf("\nPrvi trokut: (%.2f,%.2f,%.2f), (%.2f,%.2f,%.2f), (%.2f,%.2f,%.2f)\n", trokuti[0].t1->x, trokuti[0].t1->y, trokuti[0].t1->z, trokuti[0].t2->x, trokuti[0].t2->y, trokuti[0].t2->z, trokuti[0].t3->x, trokuti[0].t3->y, trokuti[0].t3->z);
}



int pr4() {
    struct tocka {
        float x;
        float y;
        float z;
    };

    struct tocka tocke[100]; //polje od 100 tocaka
    struct tocka *max; //koristimo pokazivac umjesto da upisujemo vrijednosti x,y,z u strukturu max - optimiziranije
    int i;

    for (i = 0; i < N; i++) { //N je definiran kao 10 pretprocesorskom naredbom
    printf("\nUpisi x, y i z za %d tocku: ", i+1); //i+1 jer indeksiranje krece od 0
    scanf("%f%f%f", &tocke[i].x, &tocke[i].y, &tocke[i].z);
    }

    max = &tocke[0]; //max usmjeren na prvu tocku polja tocke
    for (i = 1; i < N; i++) {
    if(max->z < tocke[i].z) //ako je z koordinata trenutne tocke veca od z koordinate max tocke - dereferencirano: max->z == (*max).z
    max = &tocke[i]; //u max upisujemo adresu trenutne tocke
    }

    printf("Koordinate najviše točke su :\n");
    printf("(%.2f, %.2f, %.2f)\n", max->x, max->y, max->z);
}



float len3d(float x, float y, float z) {
        return sqrt( x*x + y*y + z*z); //formula za udaljenost tocke od ishodista potrebna za iduci zadatak
}
int pr5() {
    struct tocka { //struktura tocka s koordinatama x,y,z
        float x;
        float y;
        float z;
    };
    struct trokut { //struktura trokut s pokazivacima na tri tocke
        struct tocka *t1;
        struct tocka *t2;
        struct tocka *t3;
    };

    struct tocka tocke[100]; //polje od 100 tocaka
    struct trokut trokuti[100]; //polje od 100 trokuta
    struct trokut *max; //pokazivac na strukturu trokut, koristit ce se za usmjeravanje na najudaljeniji trokut
    int i;
    int ind1, ind2, ind3; //indeksi tocaka koje definiraju trokut
    float Dtrenutni=0, Dmax=0; //Dmax = najveca udaljenost trokuta od ishodista, Dtrenutni = trenutna udaljenost trokuta od ishodista

    for (i = 0; i < N; i++) { //upis 10 tocaka u polje tocke
        printf("Upisi x, y i z za %d tocku: ", i+1);
        scanf("%f%f%f", &tocke[i].x, &tocke[i].y, &tocke[i].z);
    }

    for (i = 0; i < N; i++) { //upis 10 trokuta definiranih tim tockama u polje trokuti
        printf("Upisi indexe tocaka za %d trokut: ", i+1);
        scanf("%d%d%d", &ind1, &ind2, &ind3);
        trokuti[i].t1 = &tocke[ind1];
        trokuti[i].t2 = &tocke[ind2];
        trokuti[i].t3 = &tocke[ind3];
    }

    for (i = 0; i < N; i++) {
        Dtrenutni = 0; //resetiranje trenutne udaljenosti
        Dtrenutni += len3d(trokuti[i].t1->x, trokuti[i].t1->y, trokuti[i].t1->z); //poziv funkcije za izracun udaljenosti tocke od ishodista
        Dtrenutni += len3d(trokuti[i].t2->x, trokuti[i].t2->y, trokuti[i].t2->z); 
        Dtrenutni += len3d(trokuti[i].t3->x, trokuti[i].t3->y, trokuti[i].t3->z);
        Dtrenutni /= 3; //srednja vrijednost udaljenosti tocka trokuta od ishodista
        if (Dtrenutni > Dmax) { //ako je trenutna udaljenost veca od najvece dosad
            Dmax = Dtrenutni; //najveca udaljenost postaje trenutna udaljenost
            max = &trokuti[i]; //pokazivac max usmjeravamo na trenutni trokut
        }
    }

    printf("Najudaljeniji trokut je udaljen %.2f od ishodišta,\n", Dmax);
    printf("a njegove koordinate su:\n");
    printf("(%.2f, %.2f, %.2f)\n", max->t1->x, max->t1->y, max->t1->z);
    printf("(%.2f, %.2f, %.2f)\n", max->t2->x, max->t2->y, max->t2->z);
    printf("(%.2f, %.2f, %.2f)\n", max->t3->x, max->t3->y, max->t3->z);
}



int main() {
    printf("\nPrvi primjer - pokazivac na strukturu");
    pr1();

    printf("\nDrugi primjer - pokazivac kao clan strukture");
    pr2();

    printf("\nTreci primjer - struktura s pokazivacima na drugu strukturu");
    pr3();

    printf("\nCetvrti primjer - ucitavanje 10 tocaka u 3D prostoru i ispis najvise tocke");
    pr4();

    printf("\nPeti primjer - ucitavanje 10 tocaka i 10 trokuta u 3D prostoru i ispis najudaljenijeg trokuta");
    pr5();

    return 0;
}