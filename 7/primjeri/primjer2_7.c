//fprintf - upisivanje sadrzaja u datoteku ili standardni izlaz (stdout), vraca broj upisanih znakova

#include<stdio.h>

int main(void) {
    char ime[20] = { '\0' };
    char prezime[30] = { '\0' };
    int ocjena = 0;
    int bodovi = 0;
    int status = 0;
    int n = 0;

    FILE* fp = NULL;
    fp = fopen("moja_datoteka.txt", "a+");
    if (fp == NULL) {
        printf("Datoteka se ne moze otvoriti.\n");
    }

    else {
        printf("Unesite broj zapisa koje zelite zapisati:"); //aka broj studenata
        scanf("%d", &n);
        for (int i = 0; i < n; i++){
            printf("Unesite ime za %d. studenta\n", i + 1);
            scanf("%19s", ime);
            printf("Unesite prezime za %d. studenta\n", i + 1);
            scanf("%29s", prezime);
            printf("Unesite ocjenu za %d. studenta\n", i + 1);
            scanf("%d", &ocjena);
            printf("Unesite bodove za %d. studenta\n", i + 1);
            scanf("%d", &bodovi);
            status = fprintf(fp, "Student br: %d\tIme: %s Prezime: %s\tOcjena: %d Bodovi: %d\n", i + 1, ime, prezime, ocjena, bodovi);
            printf("Status je %d.\n", status); //ispisuje broj znakova po unosu studenta
        }
        fclose(fp);
    }

    return 0;
}