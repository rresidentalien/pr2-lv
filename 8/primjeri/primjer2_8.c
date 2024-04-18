#include<stdio.h>

//size_t fwrite(const void *pok, size t vel, size t br, FILE *fp);
//upisivanje raw podatka u datoteku (najcesce binarnu), vraca broj uspjesno zapisanih elemenata (0-4)
//parametri: adresa varijable koja ce se zapisati, velicina vrste varijable, broj varijabli, pokazivac na datoteku
//fwrite upisuje raw binarne podatke, fprintf upisuje formatirane podatke

int main(void) {
    int m = 5;
    FILE* fp = NULL;
    fp = fopen("binarna.bin", "wb");

    if (fp == NULL) {
        perror("Otvaranje");
    }else{
        fwrite(&m, sizeof(int), 1, fp);
        fclose(fp);
    }

    return 0;
}