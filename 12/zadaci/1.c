#include <stdio.h>
#include <stdlib.h>

typedef struct student{
    int id;
    char *ime;
    char *prezime;
    float prosjek;
    struct student *nextNode;
}STUDENT;

STUDENT* kreiraj(void) {
    STUDENT *headNode = (STUDENT*)calloc(1, sizeof(STUDENT));
    if (headNode == NULL) {
        perror("Kreiranje");
        return NULL;
    }
    else {
        headNode->nextNode = NULL;
    }
    return headNode;
}

STUDENT* umetni(STUDENT* headNode) {
    STUDENT *newHeadNode = (STUDENT*)calloc(1, sizeof(STUDENT));
    if (newHeadNode == NULL) {
        perror("Kreiranje");
        return headNode;
    }
    else {
        scanf("%d", &newHeadNode->id);
        newHeadNode->nextNode = headNode;
    }
    return newHeadNode;
}

STUDENT* pretrazi(STUDENT* traverseNode, int criteria) {
    while (traverseNode) {
        if (traverseNode->id == criteria) {
            return traverseNode;
        }
        traverseNode = traverseNode->nextNode;
    }
    return NULL;
}

void obrisiCvor(STUDENT** headNode, STUDENT* targetNode) {
    if (*headNode == targetNode) {
        *headNode = (*headNode)->nextNode;
        free(targetNode);
    }
    else {
        STUDENT* traverseNode = *headNode;
        while (traverseNode->nextNode) {
            if (traverseNode->nextNode == targetNode) {
                traverseNode->nextNode = targetNode->nextNode;
                free(targetNode);
                break;
            }
            traverseNode = traverseNode->nextNode;
        }
    }
}

STUDENT* obrisiPopis(STUDENT* traverseNode) {
    STUDENT* deleteNode = NULL;
    while (traverseNode) {
        deleteNode = traverseNode;
        traverseNode = traverseNode->nextNode;
        free(deleteNode);
    }
    return NULL;
}

void unosPodataka(STUDENT *node) {
    node->ime = malloc(50 * sizeof(char));
    node->prezime = malloc(50 * sizeof(char));

    scanf("%d", &node->id);
    scanf("%s", node->ime);
    scanf("%s", node->prezime);
    scanf("%f", &node->prosjek);
}

float prosjekSvihStudenata(STUDENT *headNode, int n) {
    float sum = 0;
    STUDENT *currentNode = headNode;

    while (currentNode != NULL) {
        sum += currentNode->prosjek;
        currentNode = currentNode->nextNode;
    }

    return sum / n;
}

int main() {
    int n, i, id;
    STUDENT *head = NULL, *foundNode = NULL;

    scanf("%d", &n);

    for (i = 0; i < n; ++i) {
        if (head == NULL) {
            head = kreiraj();
            unosPodataka(head);
        } else {
            head = umetni(head);
            unosPodataka(head);
        }
    }

    STUDENT *currentNode = head;
    while (currentNode != NULL) {
        printf("ID: %d - %s %s, prosjek: %.2f\n", currentNode->id, currentNode->ime, currentNode->prezime, currentNode->prosjek);
        currentNode = currentNode->nextNode;
    }
    printf("Ukupan prosjek svih studenata je: %.2f\n", prosjekSvihStudenata(head, n));

    scanf("%d", &id);
    foundNode = pretrazi(head, id);
    if (foundNode != NULL) {
        obrisiCvor(&head, foundNode);
        printf("Student s ID-em %d je obrisan.\n", id);
    } else {
        printf("Student s trazenim ID-em nije pronadjen!\n");
    }

    // Print students again
    currentNode = head;
    while (currentNode != NULL) {
        printf("ID: %d - %s %s, prosjek: %.2f\n", currentNode->id, currentNode->ime, currentNode->prezime, currentNode->prosjek);
        currentNode = currentNode->nextNode;
    }

    printf("Ukupan prosjek svih studenata je: %.2f\n", prosjekSvihStudenata(head, n));

    head = obrisiPopis(head);

    return 0;
}