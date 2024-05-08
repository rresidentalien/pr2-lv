#include <stdio.h>
#include <stdlib.h>

typedef struct sllist {
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

int traverseSLList(SLLNODE* traverseNode) { //argument: pokazivac na cvor kojim cemo prolaziti kroz popis, tj. mora biti glava kako bismo prosli kroz sve cvorove
    int counter = 0; //brojac cvorova
    if (traverseNode == NULL) {
        return -1;
    } else {
        while (traverseNode) { //isto kao sto za cijele brojeve 0 = false, tako je za pokazivace NULL = false, dakle uvjet vrijedi sve do zadnjeg cvorista
            counter++;
            printf("Node number: %d\tnumber: %d\tcurrent node addr: %p\tnext node addr: %p\n", //ispis broja u cvoristu, trenutne adrese i adrese iduceg cvorista
                   counter, traverseNode->number, traverseNode, traverseNode->nextNode);
            traverseNode = traverseNode->nextNode; //pomak na sljedeci cvor
        }
    }
    return counter;
}

SLLNODE* searchSLList(SLLNODE* traverseNode, int criteria) { //pretraga popisa za nekim elementom (criteria), argumenti: cvor i broj koji trazimo
    while (traverseNode) { //dok ne dodjemo do zadnjeg cvorista
        if (traverseNode->number == criteria) {
            return traverseNode; //vraca cvor u kojem se nalazi broj koji trazimo
        }
        traverseNode = traverseNode->nextNode; //pomak na sljedeci cvor
    }
    return NULL; //vraca null ako se ne nadje criteria
}

int main(void) {
    SLLNODE *headNode = createSLList();
    if (headNode == NULL) {
        return 1;
    }

    headNode = insertNewNodeSLList(headNode);
    printf("Broj elemenata u jednostrukom povezanom popisu: %d\n", traverseSLList(headNode));
    SLLNODE *targetNode = searchSLList(headNode, 5);
    
    return 0;
}