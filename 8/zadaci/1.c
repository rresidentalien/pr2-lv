#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct clan {
    char prezime[20];
    char ime[20];
    int sifra;
    char adresa[50];
    int broj;
}CLAN;

int kreiranje() {
    FILE* clanovi = fopen("Clanovi.txt", "wb");
        if (clanovi == NULL) {
            perror("Greska");
            exit(EXIT_FAILURE);
        }

        printf("Datoteka je kreirana.\n");
        fclose(clanovi);
        return 0;
}

int citanje() {
    int brojClanova, i;
    CLAN cl[50];

    FILE* clanovi = fopen("Clanovi.txt", "rb");
    if (clanovi == NULL) {
        perror("Greska");
        exit(EXIT_FAILURE);
    }
    brojClanova = fread(cl, sizeof(CLAN), 50, clanovi); //fread vraca broj uspjesno procitanih elemenata
    
    for (i = 0; i < brojClanova; ++i) {
        printf("%s %s %d %s %d", cl[i].prezime, cl[i].ime, cl[i].sifra, cl[i].adresa, cl[i].broj);
    }

    fclose(clanovi);
    return 0;
}

int dodavanje() {
    FILE* clanovi = fopen("Clanovi.txt", "ab");
    if (clanovi == NULL) {
        perror("Greska");
        exit(EXIT_FAILURE);
    }
    CLAN clan;

    printf("Unesite prezime clana:\n");
    scanf(" %s", clan.prezime);
    
    printf("Unesite ime clana:\n");
    scanf(" %s", clan.ime);

    printf("Unesite sifru clana:\n");
    scanf("%d", &clan.sifra);

    getchar();
    printf("Unesite adresu clana:\n");
    fgets(clan.adresa, sizeof(clan.adresa), stdin);

    printf("Unesite broj telefona:\n");
    scanf("%d", &clan.broj);

    fwrite(&clan, sizeof(CLAN), 1, clanovi);
    fclose(clanovi);
    return 0;
}

int main() {
    int radnja;

    printf("Izbornik:\n 1 - kreiranje datoteke\n 2 - citanje iz datoteke Clanovi.txt\n 3 - dodavanje novih clanova\n 4 - zavrsetak programa\n");
    scanf("%d", &radnja);
    switch (radnja) {
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
        default:
            printf("Unesite broj od 1 do 4!\n");
    }

    return 0;
}