#include <stdio.h>
#include <stdlib.h> //za malloc
#include <string.h> //za memcpy

int *bubble_sort(int *numbers, int count, int (*cmp)(int,int)) {
    int temp = 0;
    int i = 0;
    int j = 0;
    
    int *target = (int*)malloc(count * sizeof(int)); //polje cijelih brojeva u koje cemo spremiti sortirano polje
    if (target == NULL){
        printf("Greska kod alokacije");
        return NULL;
    }

    memcpy(target, numbers, count * sizeof(int)); //kopiramo polje brojeva iz funkcije main u polje target na kojem cemo izvrsiti sortiranje (originalni niz ostaje nepromijenjen)

    for(i = 0; i < count; i++) {
        for(j = 0; j < count - 1; j++) {
            if(cmp(target[j], target[j+1]) > 0) { //ako je trenutni clan veci od sljedeceg (sorted_order) / ako je sljedeci clan veci od trenutnog (reverse_order)
                temp = target[j+1]; //zamjena znakova
                target[j+1] = target[j];
                target[j] = temp;
            }
        }
    }
    return target;
}

int sorted_order(int a, int b) {
    return a - b;
}

int reverse_order(int a, int b) {
    return b - a;
}

void print_sorting(int *numbers, int count, int (*cmp)(int,int)){ //argumenti: polje brojeva, broj clanova polja, funkcija koja prima dva cijela broja (sorted_order ili reverse_order)
    int i = 0;
    int *sorted = bubble_sort(numbers, count, cmp); //sortirano polje
    if(!sorted) printf("Sortiranje nije uspjelo.");
    for(i = 0; i < count; i++) {
        printf("%d ", sorted[i]);
    }

    printf("\n");
    free(sorted);
}

int main() {
    int count = 0, i = 0;

    printf("Koliko brojeva zelite sortirati?\n");
    scanf("%d", &count); //velicina niza brojeva koji sortiramo

    int *numbers = (int*) malloc(count * sizeof(int)); //dinamicki zauzeto polje brojeva
    if (numbers == NULL){
        printf("Greska kod alokacije");
        return 1;
    }

    printf("Unesite brojeve za sortiranje?\n");
    for(i = 0; i < count; i++) {
        scanf("%d", &numbers[i]); //unos brojeva u niz
    }

    print_sorting(numbers, count, sorted_order);
    print_sorting(numbers, count, reverse_order);

    free(numbers);
    return 0;
}