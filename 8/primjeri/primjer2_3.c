#include <stdio.h>
#include <errno.h>

int main() {
    FILE* fp = NULL;
    fp = fopen("datoteka.txt", "r");

    if (fp == NULL) {
        fprintf(stderr, "Vrijednost pogreske je: %d.\n", errno);
        return -1;
    }
    else {
        fclose(fp);
    }
    
    return 0;
}