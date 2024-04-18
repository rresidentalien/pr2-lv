#include <stdio.h>

//int feof(FILE *stream)
//kao argument prima pokazivac na datoteku, vraca !0 ako se pokusalo citati iz datoteke nakon EOF, 0 ako nije

int main () {
    FILE *fp;
    int c;

    fp = fopen("file.txt","r");
    if(fp == NULL) {
        perror("Error in opening file");
        return(-1);
    }

    while(1){
        c = fgetc(fp);
        if(feof(fp)) break;
        printf("%c", c);
    }

    fclose(fp);
    return(0);
}