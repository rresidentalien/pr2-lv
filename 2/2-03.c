#include <stdio.h>

struct stan {
    float povrsina;
    int cijena;
    char adresa[50];
    char razred;
    int klima;
}stan[20];

int main() {
    int n, i;
    do {
        scanf("%d", &n);
    }while (n < 2 || n > 20);
    
    for (i = 0; i < n; ++i) {
        printf("Unesite povrsinu: ");
        scanf("%f", &stan[i].povrsina);
        
        printf("Unesite cijenu: ");
        scanf("%d", &stan[i].cijena);
        
        printf("Unesite adresu: ");
        scanf("%s", stan[i].adresa);
        
        printf("Unesite energetski razred: ");
        scanf(" %c", &stan[i].razred);
        
        printf("Ima li stan klimu? ");
        scanf("%d", &stan[i].klima);
    }
    
    
    
    return 0;
}
