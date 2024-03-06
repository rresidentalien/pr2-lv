#include <stdio.h>
#include <string.h>

typedef struct{
    unsigned short dan;
    unsigned short mjesec;
    unsigned short godina;
}DATUM;

 struct podaci{
    char ime[20];
    char prezime[20];
    int maticniBroj;
    float prosjek;
    DATUM datumRodjenja; //= struct datum datumRodjenja;
}student[40];

int main() {
    int n, i;
    int max = 0;
    char ime[20], prezime[20];
    scanf("%d", &n);

    for (i=0; i<n; ++i) {
        printf("Unesite ime:");
        scanf(" %s", student[i].ime);

        printf("Unesite prezime:");
        scanf(" %s", student[i].prezime);

        printf("Unesite maticni broj:");
        scanf("%d", &student[i].maticniBroj);

        printf("Unesite prosjek:");
        scanf("%f", &student[i].prosjek);

        printf("Unesite datum rodjenja:");
        scanf("%hu.%hu.%hu.", &student[i].datumRodjenja.dan, &student[i].datumRodjenja.mjesec, &student[i].datumRodjenja.godina);

        if (student[i].prosjek > max) {
            max = student[i].prosjek;
            strcpy(ime, student[i].ime);
            strcpy(prezime, student[i].prezime);
        }
    }

    printf("REZULTATI:\n");
    printf("%s %s", ime, prezime);

    return 0;
}