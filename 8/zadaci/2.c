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

typedef struct film {
    char ime[50];
    int datum;
    int sifra;
}FILM;

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

int posudba() {
    FILE* filmovi = fopen("posudbe.txt", "ab");
    if (filmovi == NULL) {
        perror("Greska");
        return -1;
    }

    int brojFilmova, i, j, brojPosudbiClana;
    do{
        printf("Koliko filmova zelite posuditi?\n");
        scanf("%d", &brojFilmova);
    }while (brojFilmova > 4);
    FILM film[brojFilmova];

    for (i = 0; i < brojFilmova; ++i) {
        getchar();
        printf("Unesi ime filma:");
        fgets(film[i].ime, sizeof(film[i].ime), stdin);

        printf("Unesi datum posudbe:");
        scanf("%d", &film[i].datum);

        printf("Unesi sifru clana:");
        scanf("%d", &film[i].sifra);

        FILE* provjera = fopen("posudbe.txt", "rb");
        FILM posudbe[50];
        int brojPosudbi = fread(posudbe, sizeof(FILM), 50, provjera);
        brojPosudbiClana = 0;
        for (j = 0; j < brojPosudbi; ++j) {
            if (posudbe[j].sifra == film[i].sifra) {
                ++brojPosudbiClana;
            }
        }
        fclose(provjera);

        if (brojPosudbiClana >= 4) {
            printf("Clan ne moze posuditi vise filmova!");
            return 0;
        }

        fwrite(&film, sizeof(FILM), 1, filmovi);
    }
    fclose(filmovi);
    return 0;
}

int main() {
    int radnja;

    printf("Izbornik:\n 1 - kreiranje datoteke\n 2 - citanje iz datoteke Clanovi.txt\n 3 - dodavanje novih clanova\n 4 - posudba filma\n 5- zavrsetak programa\n");
    scanf("%d", &radnja);
    if (radnja == 1) {
        kreiranje();
    }else if (radnja == 2) {
        citanje();
    }else if (radnja == 3) {
        dodavanje();
    }else if(radnja == 4) {
        posudba();
    }else if (radnja == 5) {
        exit(EXIT_SUCCESS);
    }else {
        printf("Unesite broj od 1 do 4!");
    }

    return 0;
}