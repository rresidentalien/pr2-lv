#include <stdio.h>

//int rename(const char *oldname, const char *newname);
//prima dva parametra, staro ime i novo ime; mijenja ime datoteke na disku

int main() {
    FILE* fp = NULL;
    char* staro_ime = "Programiranje 1.txt";
    char* novo_ime = "Programiranje 2.txt";
    int status = 0;
    
    fp = fopen(staro_ime, "r");
    if (fp == NULL) {
        printf("Datoteka %s ne postoji na disku.\n", staro_ime);
        return -1;
    }
    else {
        fclose(fp);
    } //datoteka mora biti zatvorena kako bi se funkcija rename mogla izvrsiti

    status = rename(staro_ime, novo_ime);
    if (status == 0) { //funkcija rename vraca vrijednost 0 ako je ime uspjesno promijenjeno
        printf("Uspjesno promijenjeno ime datoteci!\n");
    }
    else { //funkcija rename vraca neku drugu vrijednost ako ime nije uspjesno promijenjeno
    printf("Nemogucnost promijene imena datoteci!\n");
    }

    return 0;
}