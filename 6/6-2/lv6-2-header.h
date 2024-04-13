#ifndef LV6_2_HEADER_H //nekima je radilo jedino ako se stavi #pragma once
#define LV6_2_HEADER_H

typedef struct {
    char ime[50];
    int kolicina;
    float cijena;
} ARTIKL;

void ucitavanje(ARTIKL *artikli, int n);
ARTIKL *najveci(ARTIKL *artikli, int n);

#endif