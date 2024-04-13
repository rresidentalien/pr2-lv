#include "lv6-2-header.h"
#include <stdio.h>

void ucitavanje(ARTIKL *artikli, int n) {
    for (int i = 0; i < n; i++) {
        printf("Unesite ime artikla: ");
        scanf("%s", artikli[i].ime);
        printf("Unesite količinu artikla: ");
        scanf("%d", &artikli[i].kolicina);
        printf("Unesite cijenu artikla: ");
        scanf("%f", &artikli[i].cijena);
    }
}

ARTIKL *najveci(ARTIKL *artikli, int n) {
    ARTIKL *max = &artikli[0];
    for (int i = 1; i < n; i++) {
        if (artikli[i].cijena > max->cijena) {
            max = &artikli[i];
        }
    }
    return max;
}

//ovog zadatka iz nekog razloga nema na dokumentu za lv. vise manje po treci put onaj zadatak s artiklima, opet na drugaciji nacin