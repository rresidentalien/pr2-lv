#include <stdio.h>
#include <stdlib.h>

typedef struct dllist {
    int number;
    struct dllist *previousNode;
    struct dllist *nextNode;
} DLLNODE;

DLLNODE* createDLList(void) { //funkcija za kreiranje dvostruko povezanog popisa
    DLLNODE *headNode = (DLLNODE*)calloc(1, sizeof(DLLNODE)); //dinamicko zauzimanje memorije za jedan cvor
    if (headNode == NULL) {
        perror("Kreiranje");
        return NULL;
    } else {
        printf("Unesite cijeli broj!\n");
        scanf("%d", &headNode->number); //postavljanje vrijednosti za glavu popisa
        headNode->nextNode = NULL;
        headNode->previousNode = NULL; //imamo samo jedan cvor, pa pokazivaci na prosli i iduci pokazuju na NULL
    }
    return headNode;
}

int main(void) {
    DLLNODE *headNode = createDLList();
    if (headNode == NULL) {
        return 1;
    }
    return 0;
}