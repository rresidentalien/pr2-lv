#include <stdio.h>

struct podaci {
    char naziv[50];
    float cijena;
    int kolicina;
};

int unesiPodatkeRacuna() {
    char kupac[50];
    char prodavac[50];

    fgets(kupac, 51, stdin);
    fgets(prodavac, 51, stdin);

    
}