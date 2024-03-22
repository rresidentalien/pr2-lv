#include <stdio.h>
#include <string.h>

struct podaci {
    char naziv[50];
    float cijena;
    int kolicina;
};

void unesiPodatkeRacuna(struct podaci *racun, int n) {
    int i;

    for (i = 0; i < n; ++i) {
        scanf(" %[^\n]s", racun[i].naziv);
        scanf("%f", &racun[i].cijena);
        scanf("%d", &racun[i].kolicina);
    }
}

void ispisRacuna(char *kupac, char *prodavac, struct podaci *racun, int n) {
    int i;
    float ukupno = 0;

    printf("Kupac: %s", kupac);
    printf("\nProdavac: %s", prodavac);
    printf("\n-----------------------------");
    printf("\nArtikli:");
    printf("\n%-4s %-20s %-10s %-10s %-10s", "rb", "naziv", "kolicina", "cijena", "ukupno");

    for (i = 0; i < n; ++i) {
        printf("\n");
        printf("%-4d %-20s %-10d %-10.2f %-10.2f", i+1, racun[i].naziv, racun[i].kolicina, racun[i].cijena, (float)racun[i].kolicina * racun[i].cijena);

        ukupno += (float)racun[i].kolicina * racun[i].cijena;
    }

    printf("\nUkupan iznos racuna: %.2f", ukupno);
}

int main() {
    char kupac[50], prodavac[50];
    scanf(" %[^\n]s", kupac);
    scanf(" %[^\n]s", prodavac);

    int n;
    scanf("%d", &n);
    getchar();
    if (n <= 0 || n >= 10) {
        return 0;
    }

    struct podaci racun[n];
    unesiPodatkeRacuna(racun, n);

    printf("REZULTATI:\n");
    ispisRacuna(kupac, prodavac, racun, n);

    return 0;
}