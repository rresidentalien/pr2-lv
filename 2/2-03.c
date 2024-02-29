#include <stdio.h>

struct stan {
    float povrsina;
    int cijena;
    char adresa[50];
    char razred;
    int klima;
    int cijenaPoKvadratu;
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
        
        stan[i].cijenaPoKvadratu = stan[i].cijena / stan[i].povrsina;
    }
    
    int flag = 0;
    
    for (i = 0; i < n; ++i) {
        if ((stan[i].cijenaPoKvadratu < 900 || stan[i].cijenaPoKvadratu > 1100) & (!stan[i].klima)) {
            printf("%s, %d", stan[i].adresa, stan[i].cijena);
            flag = 1;
        }
    }
    
    if (!flag) {
        printf("Niti jedan stan ne odgovara kriterijima.");
    }
    
    return 0;
}
