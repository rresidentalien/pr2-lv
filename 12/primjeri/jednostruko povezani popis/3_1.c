#include <stdio.h>

//jednostruki povezani popis u C-u se definira kao struktura od dva clana - podatka i pokazivaca na sljedeci podatak
typedef struct sllist {
    int number;
    struct sllist *nextNode; //pokazivac na sljedece cvoriste tipa sllist
}SLLNODE;

int main(void) {
    SLLNODE *headNode = NULL; //deklaracija i inicijalizacija prvog elementa povezanog popisa - glave. s obzirom da je samo jedan, on je i zadnji, pa pokazuje na vrijednost NULL

    return 0;
}