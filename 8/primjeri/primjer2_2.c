#include <stdio.h>

int main() {
    FILE* fp = NULL;
    char* ime_datoteke = "Programiranje 1.txt";
    int status = 0;

    fp = fopen(ime_datoteke, "r");
    if (fp == NULL) {
        printf("Datoteka %s ne postoji na disku\n", ime_datoteke);
        return -1;
    }
    else {
        fclose(fp);
    } //datoteka mora biti zatvorena kako bi se funkcija remove mogla izvrsiti

    status = remove(ime_datoteke); //funkcija remove vraca 0 ako je datoteka uspjesno obrisana
    if (status == 0) {
        printf("Uspjesno obrisana datoteka!\n");
    }
    else {
        printf("Nemogucnost brisanja datoteke!\n");
    }
    return 0;
}