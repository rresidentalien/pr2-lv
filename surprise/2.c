/*
Rekurzija prima jednu cjelobrojnu vrijednost koja je visina piramide.
U datoteku piramida.txt koju cete kreirati iz programa, "nacrtati" piramidu od znakova '*'
koja moze imati maksimalnu visinu 30 redova. U main() dijelu ucitati visinu piramide te pozvati rekurziju.
Primjer: n = 5
    *
   * *
  * * *
 * * * *
* * * * *
*/

#include <stdio.h>
#include <stdlib.h>

FILE *file;
int maxVisina;

void Razmak(int visina, FILE* file) { //printa broj razmaka takav da je zbroj razmaka i zvjezdica uvijek jednak maxVisina
    //baza
    if (visina == 0) {
        return;
    }

    printf(" "); //ispis jednog razmaka na ekran
    fprintf(file, " "); //ispis jednog razmaka na datoteku

    //rekurzija
    Razmak(visina - 1, file); //printa visina znakova: svaki put se smanjuje za 1 dok ne dodje do 0
}

void Piramida(int visina){ //printa razmake uz pomoc Razmak i zatim zvjezdice
    int i, j;

    //baza
    if (visina == 0){
        return;
    }

    //rekurzija
    Piramida(visina - 1);
    for (i = 0; i < visina; ++i){
        if (i == 0){ //dok je i = 0, tj prije zvjezdica
            Razmak(maxVisina - visina, file); //isprintaj broj zvjezdica jednak maxVisina - visina
        }
        printf("* "); //razmak izmedju svake zvjezdice
        fprintf(file, "* ");
    }

    printf("\n");
    fprintf(file, "\n");
}

int main(){
    file = fopen("piramida.txt", "w");
    if (file == NULL)
        exit(EXIT_FAILURE);

    int visina;
    do{
        scanf("%d", &visina);
    }while (visina > 30);

    maxVisina = visina;
    Piramida(visina);

    fclose(file);
    return 0;
}