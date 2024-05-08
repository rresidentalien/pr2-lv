#include <stdio.h>
#include <stdlib.h>

typedef struct sllist { //definiranje strukture cvorista popisa
    int number;
    struct sllist *nextNode;
} SLLNODE;

SLLNODE* createSLList() { //funkcija createSLList tipa SLLNODE
    SLLNODE *headNode = (SLLNODE*)calloc(1, sizeof(SLLNODE)); //dinamicko zauzimanje memorije za glavu popisa
    if (headNode == NULL) {
        perror("Kreiranje");
        return NULL;
    } else {
        printf("Unesite cijeli broj!\n");
        scanf("%d", &headNode->number); //vrijednost n sprema se u podatak glave
        headNode->nextNode = NULL; //sljedeceg cvora nema, pa glava pokazuje na NULL
    }
    return headNode;
}

int main() {
    SLLNODE *headNode = createSLList();
    if (headNode == NULL) {
        return 1;
    }
    return 0;
}