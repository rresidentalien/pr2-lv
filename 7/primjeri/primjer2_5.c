//fputs - zapisivanje stringa u datoteku ili na ekran (stdout)

#include <stdio.h>

int main (){
    FILE * pFile =NULL;
    char recenica[256] = { '\0' };

    printf ("Unesite recenicu koja ce se dopisati u datoteku: ");
    fgets (recenica, 255, stdin);
    
    pFile = fopen ("moja_datoteka.txt","a");
    if (pFile == NULL){
        printf("Datoteka se ne moze otvoriti.\n");
        return 1;
    }
    fputs (recenica, pFile);
    fclose (pFile);

    return 0;
}