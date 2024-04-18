#include <stdio.h>
#include <errno.h>
#include <string.h>

//char* strerror (int error_num);
//vraca string koji opisuje pogresku

int main() {
    FILE* fp = NULL;
    fp = fopen("datoteka.txt", "r");

    if (fp == NULL) {
        fprintf(stderr, "Vrijednost pogreske je: %d.\n", errno); //svaka pogreska ima neki broj, npr. errno 2 = ENOENT (no such file or directory)
        fprintf(stderr, "Pogreska: %s.\n", strerror(errno)); // no such file or directory
        return -1;
    }
    else {
        fclose(fp);
    }
    
    return 0;
}