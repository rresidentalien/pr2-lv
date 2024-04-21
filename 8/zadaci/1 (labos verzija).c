#include <stdio.h>
#include <stdlib.h>

//drugacije (vjerojatno) nece raditi :))

typedef struct podaci
{		
	char prezime[20];
	char ime[20];
	int sifra;
	char adresa[100];
	int br_tel;
}PODACI;

FILE* clanovi;

void kreiranje() {
    clanovi = fopen("clanovi.txt", "ab+");
    if (clanovi == NULL) {
        perror("Greska");
        exit(EXIT_FAILURE);
    }else {
        printf("Datoteka clanovi.txt je kreirana\n");
    }
}

void citanje() {
    PODACI p[100];
    int brojClanova, i;
    
    fseek(clanovi, 0L, SEEK_SET);
    brojClanova = fread(p, sizeof(PODACI), 100, clanovi);
    rewind(clanovi);
    for (i = 0; i < brojClanova; ++i) {
        printf("%s %s %d %s %d", p[i].prezime, p[i].ime, p[i].sifra, p[i].adresa, p[i].br_tel);
    }
}

void dodavanje() {
    PODACI p = {};
    printf("Unesite prezime clana:\n");
    scanf(" %s", p.prezime);
    
    printf("Unesite ime clana:\n");
    scanf(" %s", p.ime);

    printf("Unesite sifru clana:\n");
    scanf("%d", &p.sifra);

    getchar();
    printf("Unesite adresu clana:\n");
    scanf(" %99[^\n]", p.adresa);

    printf("Unesite broj telefona:\n");
    scanf("%d", &p.br_tel);

    fwrite(&p, sizeof(PODACI), 1, clanovi);
}

int main() {
    int radnja;
    
    do{
        printf(" 1 - kreiranje datoteke clanovi.txt\n 2 - citanje iz datoteke clanovi.txt\n 3 - dodavanje novih clanova\n 4 - zavrsetak programa\n");
        scanf("%d", &radnja);
        switch(radnja) {
            case 1: 
                kreiranje();
                break;
            case 2:
                citanje();
                break;
            case 3:
                dodavanje();
                break;
            case 4:
                exit(EXIT_SUCCESS);
        }
    }while(radnja != 4);
}