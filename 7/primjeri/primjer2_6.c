//fscanf - cita iz dokumenta, vraca broj uspjesno procitanih vrijednosti/varijabli, EOF u slucaju pogreske ili ako dodje do kraja bez da ista procita

#include<stdio.h>

int main(void) {
    char ime[20] = {'\0'};
    char prezime[30] = {'\0'};
    int ocjena;
    int bodovi;
    int status;

    FILE* fp = NULL;
    fp = fopen("primjer2_6.txt", "r");
    if (fp == NULL) {
        printf("Datoteka se ne moze otvoriti.\n");
    }
    else {
        while ((status = fscanf(fp, "%s %s %d %d",ime, prezime, &ocjena, &bodovi)) != EOF) { //ime = prva rijec, prezime = druga rijec, ocjena = prvi broj, bodovi = drugi broj
            printf("Status je %d.\n", status);
            printf("Ime: %s Prezime: %s\tOcjena: %d Bodovi: %d.\n", ime, prezime, ocjena, bodovi);
        }
        printf("Status je %d.\n", status); //status ce biti ili broj od 1 do 4 (npr. status 4 = sve 4 vrijednosti su ispravno procitane) ili -1 kada dodje do kraja
        //ako se npr. stavi moja_datoteka.txt status ce biti 2 jer ce ispravno uzimati prvu i drugu rijec, ali ne i brojeve jer nema nijednog broja u datoteci
        fclose(fp);
    }
    return 0;
}