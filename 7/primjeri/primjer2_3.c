//fputc - pisanje jednoga znaka u datoteku

#include<stdio.h>
    int main(void) {
    int znak;
    FILE *fp = NULL;
    int br = 0;

    fp = fopen("moja_datoteka.txt", "a+"); //otvara datoteku moja_datoteka za dodavanje

    if (fp == NULL){
        printf("Datoteka se ne moze kreirati.\n");
    }
    else {
        while ((znak = getchar()) != EOF){
            printf("Upisani znak u datoteku %c\n", fputc(znak, fp));
            br++;
            if (br == 5) { //nakon 5 upisanih znakova (ukljucujuci enter) javlja se obavijest da mozemo prekinuti upis
                printf("Pritisnite Ctrl+Z u DOS-u ili Ctrl+D u Linux-u kako bi se onemogucilo daljnje ucitavanje znakova\n\n"); //ctrl+Z = EOF znak
                br = 0;
            }
        }
        fclose(fp);
    }
    return 0;
}