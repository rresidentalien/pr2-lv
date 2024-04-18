#include<stdio.h>

//size_t fread(void* pok, size_t vel, size_t br, FILE* fp);
//cita podatak iz datoteke (najcesce binarne), vraca broj uspjesno procitanih elemenata

int main(void) {
    int n = 0;
    FILE* fp = NULL;

    fp = fopen("binarna.bin", "rb");
    if (fp == NULL) {
        perror("Otvaranje");
    }else {
        fprintf(stdout, "Datoteka postoji na disku.\n");
        fread(&n, sizeof(int), 1, fp);
        fprintf(stdout, "n = %d\n", n);
        fclose(fp);
    }
    return 0;
}