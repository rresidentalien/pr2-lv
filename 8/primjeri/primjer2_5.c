#include <stdio.h>

//void perror(const char *str);
//ispisuje korisnicki definiriani string i na njega dodati dvotocku i tekst greske iz errno. perror() == strerror(errno)

int main (){
    FILE *fp = NULL;
    int c;

    fp = fopen("file.txt","r");
    if(fp == NULL) {
        perror("Greska"); //Greska: No such file or directory
        return -1;
    }

    while(1) { //cita i ispisuje datoteku file.txt slovo po slovo
        c = fgetc(fp);
        if(feof(fp)) break;
        printf("%c", c);
    }

    fclose(fp);
    return 0;
}