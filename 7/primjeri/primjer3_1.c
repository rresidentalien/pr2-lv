//skenira ime datoteke s tipkovnice, otvara ju ako postoji

#include <stdio.h>

void cpy(FILE *, FILE *);

int main() {
    FILE *fpt = NULL;
    char argv[10];

    printf("Unesite ime datoteke:\n"); //upisati i ekstenziju
    scanf("%s",argv);
    
    if((fpt=fopen(argv,"r"))==NULL){
        printf("ne mogu otvoriti datoteku %s\n",argv);
    return 1;
    }
    else {
        cpy(fpt,stdout);
        fclose(fpt);
    }

    return 0;
}

void cpy(FILE *fpulaz, FILE *fpizlaz) { //kopira sadrzaj jedne datoteke i ispisuje na izlaz (u nasem slucaju na stdout)
    int c;
    while((c=getc(fpulaz))!=EOF)
    putc(c,fpizlaz);
}