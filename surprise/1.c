/*
Napisite rekurzivnu funkciju koja za broj n racuna sumu njegovih znamenki. U main() funkciji zatrazite unos broja,
pozovite funkciju i zatim rezultat ispisite u datoteku posudbe.txt i na ekran.
*/

#include <stdio.h>
#include <stdlib.h>

int sumaZnamenki(int x){
    //baza
    if (x < 10){ //ako je x jednoznamenkasti broj
        return x; //vrati x
    }

    //rekurzija
    else{
        return x % 10 + sumaZnamenki(x / 10); //vrati najdesniju znamenku + sumaZmamenki bez najdesnije znamenke
    }
}

int main(void){
    int n;
    FILE *suma = fopen("suma.txt", "w");
    if(suma == NULL){
        printf("Greska pri otvaranju datoteke.");
        exit(EXIT_FAILURE);
    }

    scanf("%d", &n);
    if (n < 0){ //ako je broj manji od 0
        n *= -1; //vrati apsolutnu vrijednost
    }

    fprintf(suma, "%d", sumaZnamenki(n)); //ispis na datoteku
    printf("%d", sumaZnamenki(n)); //ispis na ekran

    fclose(suma);
    return 0;
}