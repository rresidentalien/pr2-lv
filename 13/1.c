#include <stdio.h>

enum TJEDAN {ponedjeljak = 1, utorak, srijeda, cetvrtak, petak, subota, nedjelja};

int main() {
    int dan;
    scanf("%d", &dan);

    if(dan == subota || dan == nedjelja) {
        printf("Vikeeeend!");
    }
    else {
        printf("Radis jos %d dana do vikenda.", petak-dan);
    }

    return 0;
}