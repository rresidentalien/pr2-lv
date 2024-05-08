#include <stdio.h>

//dvostruko povezani popis sadrzi podatak, te pokazivac na prethodni i sljedeci cvor
typedef struct dllist {
    int number;
    struct dllist *previousNode;
    struct dllist *nextNode;
} DLLNODE;

int main(void) {
    DLLNODE *headNode = NULL;
    return 0;
}