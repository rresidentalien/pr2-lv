#include <stdio.h>
#include <stdlib.h>

typedef struct sllist { //definiranje cvora povezanog popisa
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

SLLNODE* insertNewNodeSLList(SLLNODE* headNode) { //funkcija za umetanje novog cvora
    SLLNODE *newHeadNode = (SLLNODE*)calloc(1, sizeof(SLLNODE)); //dinamicko zauzimanje memorije za novi cvor
    if (newHeadNode == NULL) {
        perror("Kreiranje");
        return headNode;
    } else {
        printf("Unesite cijeli broj!\n");
        scanf("%d", &newHeadNode->number); //vrijednost n sprema se u podatak novog cvora
        newHeadNode->nextNode = headNode; //novi cvor pokazuje na prijasnju glavu, sto cini novi cvor glavom
    }
    return newHeadNode;
}

int main(void) {
    SLLNODE *headNode = createSLList();
    if (headNode == NULL) {
        return 1;
    }
    headNode = insertNewNodeSLList(headNode);
    return 0;
}