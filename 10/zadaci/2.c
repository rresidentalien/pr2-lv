#include <stdio.h>
#include <stdlib.h>

typedef struct artikl {
    char *naziv;
    float cijena;
    int kolicina;
}ARTIKL;

typedef struct racun {
    char *prodavac;
    char *kupac;
    ARTIKL *artikli;
    int  brojArtikala;
    float iznos;
}RACUN;

int main() {
    int i;
    FILE *racuntxt = fopen("racun.txt", "r");
    if (racuntxt == NULL) perror("Greska");
    RACUN *racun = (RACUN*)malloc(sizeof(RACUN));

    racun->prodavac = malloc(100 * sizeof(char));
    racun->kupac = malloc(100 * sizeof(char));

    fgets(racun->kupac, 100, racuntxt);
    fgets(racun->prodavac, 100, racuntxt);
    fscanf(racuntxt, "%d", &racun->brojArtikala);

    racun->artikli = malloc(racun->brojArtikala * sizeof(ARTIKL));
    racun->iznos = 0.0;

    for (i = 0; i < racun->brojArtikala; ++i) {
        racun->artikli[i].naziv = malloc(100 * sizeof(char));

        fgets(racun->artikli[i].naziv, 100, racuntxt);
        fscanf(racuntxt, "%f", &racun->artikli[i].cijena);
        fscanf(racuntxt, "%d", &racun->artikli[i].kolicina);

        racun->iznos += racun->artikli->kolicina;
    }

    printf("REZULTATI:\n");
    printf("%.2f", racun->iznos);


    for (i = 0; i < racun->brojArtikala; ++i) {
        free(racun->artikli[i].naziv);
    }
    free(racun->prodavac);
    free(racun->kupac);
    free(racun->artikli);
    free(racun);
    return 0;
}