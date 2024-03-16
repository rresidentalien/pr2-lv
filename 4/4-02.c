#include <stdio.h>

struct artikl {
    char ime[20];
    float cijena;
    int kolicina;
};

int main() {
    
    int n, i;
    scanf("%d", &n);
    if (n < 0 || n > 10) {
        return 0;
    }

    struct artikl artikli[n];
    for (i = 0; i < n; ++i) {
        scanf(" %s", artikli[i].ime);
        scanf("%d", &artikli[i].kolicina);
        scanf("%f", &artikli[i].cijena);
    }

    struct artikl *max = &artikli[0];
    for (i = 1; i < n; ++i) {
        if (artikli[i].cijena > max->cijena) {
            max = &artikli[i];
        }
    }

    printf("REZULTATI:\n");
    printf("cijena: %.2f, kolicina: %d", max->cijena, max->kolicina);

    return 0;
}