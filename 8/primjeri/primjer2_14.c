#include <stdio.h>

//int fseek(FILE *fp, long pomak, int od_pozicije);
//vraca 0 ako je promjena pozicije uspjesno izvrsena, !0 ako nije

int main (){
    FILE * fp=NULL;

    fp = fopen ("primjer.txt" ,"w+");
    if (fp == NULL) {
        perror("Otvaranje");
        return -1;
    }

    fputs ("This is an apple.",fp);
    fseek (fp,9,SEEK_SET); //pomak za 9 od pocetka (SEEK_SET - pocetak)
    fputs (" sam", fp); //mijenja an apple u a sample
    
    fclose (fp);
    return 0;
}