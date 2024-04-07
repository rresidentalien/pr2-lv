//fgetc - citanje jednog znaka u datoteku i pomak za jedan znak naprijed nakon citanja

#include <stdio.h>
#include <stdlib.h>
int main(){
    int ch,brojac=0;
    FILE *pFile = NULL;
    const char *imeDatoteke = "moja_datoteka.txt";
    
    if((pFile=fopen(imeDatoteke,"r"))==NULL){
        printf("Ne mogu otvoriti datoteku myfile.txt\n");
    return 1;
    }

    while((ch=fgetc(pFile))!=EOF){ //ovaj while funkcionira zato jer funkcija fgetc procita znak i pomakne "kursor" za jedno mjesto naprijed
        brojac++;
    }

    fclose(pFile);
    printf("\nBroj znakova = %d\n", brojac);
    return 0;
}