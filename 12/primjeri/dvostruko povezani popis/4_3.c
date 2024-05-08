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

DLLNODE* insertNewNodeDLList(DLLNODE* headNode) { //argument: glava popisa
    DLLNODE *newHeadNode = (DLLNODE*)calloc(1, sizeof(DLLNODE)); //zauzimanje prostora za novi cvor
    if (newHeadNode == NULL) {
        perror("Kreiranje");
        return headNode;
    } else {
        printf("Unesite cijeli broj!\n");
        scanf("%d", &newHeadNode->number);
        newHeadNode->nextNode = headNode; //glava se premjesta na drugi cvor
        newHeadNode->previousNode = NULL;
        headNode->previousNode = newHeadNode; //na novu glavu pokazuje pokazivac stare glave za prijasnji cvor
    }
    return newHeadNode;
}

int main(void) {
    DLLNODE *headNode = createDLList();
    if (headNode == NULL) {
        return 1;
    }
    headNode = insertNewNodeDLList(headNode);
    return 0;
}