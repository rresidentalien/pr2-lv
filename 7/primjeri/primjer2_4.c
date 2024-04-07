//fgets - unos stringa, moze biti s tipkovnice (stdin) ili pokazivaca (ovdje fp)

#include <stdio.h>
#include <string.h>

void provjeraStringa(char*);

int main(void) {
    char stringPolje[100] = { '\0' };
    FILE* fp = NULL;
    fp = fopen("moja_datoteka.txt", "r"); //otvara datoteku za citanje

    if (fp == NULL) {
        printf("Datoteka ne postoji na disku.\n");
    }
    else {
        while (fgets(stringPolje, 100, fp) != NULL) { //fgets vraca NULL nakon sto dodje do EOF znaka ili \n znaka u moja_datoteka: printa moja_datoteka red po red dok ne dodje do kraja
            //fgets "mice kursor" za jedan znak naprijed nakon sto ocita EOF ili \n i zato kod printa cijelu moja_datoteka, a ne samo prvi red
            puts(stringPolje); //printa string
            provjeraStringa(stringPolje); //radi zamjenu
            puts(stringPolje); //printa string ponovno - komentirajte jedan po jedan puts i usporedite
        }
        fclose(fp);
    }
    return 0;
}

void provjeraStringa(char *polje) { //mijenja znak za novi red s nul znakom
    int n = strlen(polje);
    if (polje[n - 1] == '\n') {
        polje[n - 1] = '\0';
    }
}