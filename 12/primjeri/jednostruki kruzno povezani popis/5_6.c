#include <stdio.h>
#include <stdlib.h>

typedef struct cllist {
    int number;
    struct cllist *nextNode;
} CLLNODE;

CLLNODE* createCLList() {
    CLLNODE *headNode = (CLLNODE*)calloc(1, sizeof(CLLNODE));
    if (headNode == NULL) {
        perror("Kreiranje");
        return NULL;
    }
    else {
        printf("Unesite cijeli broj!\n");
        scanf("%d", &headNode->number);
        headNode->nextNode = headNode; //popis od jednog cvora pokazuje na samog sebe kao iduci cvor
    }
    return headNode;
}

CLLNODE* insertNewNodeCLList(CLLNODE* headNode) {
    CLLNODE *newHeadNode = (CLLNODE*)calloc(1, sizeof(CLLNODE));
    if (newHeadNode == NULL) {
        perror("Kreiranje");
        return headNode;
    }
    else {
        printf("Unesite cijeli broj!\n");
        scanf("%d", &newHeadNode->number);
        newHeadNode->nextNode = headNode;
        CLLNODE* traverseNode = headNode;
        while (headNode != traverseNode->nextNode) { //dok glava nije iduci cvor
            traverseNode = traverseNode->nextNode;
        }
        traverseNode->nextNode = newHeadNode; //nakon prolaska kroz sve cvorove, onaj nakon zadnjega je glava
    }
    return newHeadNode;
}

//ostatak koda je zapravo isti, jedina razlika je iznad i ostatak koda ne treba promjene da bi radio za kruzni povezani popis
int traverseCLList(CLLNODE* traverseNode) {
    int counter = 1;
    if (traverseNode == NULL) {
        return -1;
    }
    else {
        CLLNODE *tempHeadNode = traverseNode;
        traverseNode = traverseNode->nextNode;
        printf("Node number: %d\tnumber: %d\tcurrent node addr: %p\tnext node addr: %p\n", counter, tempHeadNode->number, tempHeadNode, tempHeadNode->nextNode);
        while (tempHeadNode != traverseNode) {
            counter++;
            printf("Node number: %d\tnumber: %d\tcurrent node addr: %p\tnext node addr: %p\n", counter, traverseNode->number, traverseNode, traverseNode->nextNode);
            traverseNode = traverseNode->nextNode;
        }
        return counter;
    }
}

CLLNODE* searchCLList(CLLNODE* traverseNode, int criteria) {
    CLLNODE* tempHeadNode = traverseNode;
    if (tempHeadNode->number == criteria) {
        return tempHeadNode;
    }
    else {
        traverseNode = traverseNode->nextNode;
        while (tempHeadNode != traverseNode) {
            if (traverseNode->number == criteria) {
                return traverseNode;
            }
            traverseNode = traverseNode->nextNode;
        }
    }
    return NULL;
}

void deleteNodeCLList(CLLNODE** headNode, CLLNODE* targetNode) {
    if (targetNode == NULL) {
        printf("Ne postoji cvor za brisanje: %p\n", targetNode);
        return;
    }
    CLLNODE *traverseNode = *headNode;
    if (*headNode == targetNode) {
        while (*headNode != traverseNode->nextNode) {
            traverseNode = traverseNode->nextNode;
        }
        traverseNode->nextNode = (*headNode)->nextNode;
        *headNode = traverseNode->nextNode;
        free(targetNode);
        printf("Oslobodjen cvor: %p\n", targetNode);
    }
    else if (*headNode == targetNode->nextNode) {
        while (traverseNode->nextNode != targetNode) {
            traverseNode = traverseNode->nextNode;
        }
        traverseNode->nextNode = targetNode->nextNode;
        free(targetNode);
        printf("Oslobodjen cvor: %p\n", targetNode);
    }
    else {
        while (*headNode != traverseNode->nextNode) {
            if (targetNode == traverseNode->nextNode) {
                traverseNode->nextNode = targetNode->nextNode;
                free(targetNode);
                break;
            }
            traverseNode = traverseNode->nextNode;
        }
    }
}

int main() {
    CLLNODE *headNode = createCLList();
    if (headNode == NULL) {
        return 1;
    }
    headNode = insertNewNodeCLList(headNode);
    printf("Broj elemenata u jednostrukom povezanom popisu: %d\n", traverseCLList(headNode));
    CLLNODE *targetNode = searchCLList(headNode, 5);
    deleteNodeCLList(&headNode, targetNode);
    return 0;
}