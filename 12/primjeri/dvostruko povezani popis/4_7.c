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

int traverseDLList(DLLNODE* traverseNode) { //funkcija racuna broj elemenata, pocinje od glave
    int counter = 0;
    if (traverseNode == NULL) {
        return -1;
    } else {
        while (traverseNode) { //dok postoji cvor
            counter++;
            printf("Node number: %d\tnumber: %d\tcurrent node addr: %p\tnext node addr: %p\n",
                   counter, traverseNode->number, traverseNode, traverseNode->nextNode); //ispis broja, trenutnog cvora i iduceg cvora
            traverseNode = traverseNode->nextNode; //pomak prema naprijed
        }
    }
    return counter;
}

DLLNODE* searchDLList(DLLNODE* traverseNode, int criteria) { //argumenti: povezani popis i broj koji trazimo
    while (traverseNode) { //dok postoji cvor
        if (traverseNode->number == criteria) {
            return traverseNode; //vraca cvor ako sadrzi broj koji trazimo
        }
        traverseNode = traverseNode->nextNode; //pomak prema naprijed
    }
    return NULL;
}

void deleteNodeDLList(DLLNODE** headNode, DLLNODE* targetNode) { //argumenti: glava popisa, cvor koji zelimo obrisati
    if (targetNode == NULL) { //ako cvor koji zelimo obrisati ne postoji
        printf("Ne postoji cvor za brisanje: %p\n", targetNode);
        return;
    }
    if ((*headNode) == targetNode) { //ako je glava cvor koji zelimo obrisati
        *headNode = (*headNode)->nextNode; //glava se premjesta na iduci cvor
        (*headNode)->previousNode = NULL; //veza prema prijasnjem cvoru nove glave se brise
        free(targetNode); //prijasnji cvor se brise
        printf("Oslobodjen cvor: %p\n", targetNode);
    }
    else if (targetNode->nextNode == NULL) { //ako je rep (zadnji cvor) cvor koji zelimo obrisati
        targetNode = targetNode->previousNode; //vracamo se na prijasnji cvor
        free(targetNode->nextNode); //brisemo cvor nakon njega
        printf("Oslobodjen cvor: %p\n", targetNode);
        targetNode->nextNode = NULL;
    }
    else { //ako je cvor koji zelimo obrisati bilo koji drugi cvor
        targetNode->previousNode->nextNode = targetNode->nextNode; //sljedeci cvor prethodnog cvora = sljedeci cvor
        targetNode->nextNode->previousNode = targetNode->previousNode; //prethodni cvor sljedeceg cvora = prethodni cvor
        free(targetNode);
        printf("Oslobodjen cvor: %p\n", targetNode);
    }
}

DLLNODE* deleteWholeDLList(DLLNODE* traverseNode) { //brisanje cijelog popisa. argument: glava popisa
    while (traverseNode->nextNode != NULL) { //sve dok postoji iduci cvor
        traverseNode = traverseNode->nextNode; //pomak prema naprijed
        free(traverseNode->previousNode); //brisanje cvora
        printf("Oslobodjen cvor: %p\n", traverseNode->previousNode);
    }
    free(traverseNode); //brisanje repa
    printf("Oslobodjen cvor: %p\n", traverseNode);
    return NULL;
}

int main(void) {
    DLLNODE *headNode = createDLList();
    if (headNode == NULL) {
        return 1;
    }
    headNode = insertNewNodeDLList(headNode);
    printf("Broj elemenata u dvostrukog povezanom popisu: %d\n", traverseDLList(headNode));
    DLLNODE *targetNode = searchDLList(headNode, 5);
    deleteNodeDLList(&headNode, targetNode);
    headNode = deleteWholeDLList(headNode);
    return 0;
}