#include <stdio.h>

int main() {
    FILE *dat = fopen("Dat.txt", "r");
    FILE *studenti = fopen("Studenti.txt", "w");

    if (dat == NULL || studenti == NULL) {
        printf("Datoteka se ne moze otvoriti.\n");
        return 1;
    }

    int n;
    fscanf(dat, "%d", &n);

    for (int i = 0; i < n; i++) {
        char ime[50];
        char prezime[50];

        printf("Unesi ime i prezime: ");
        scanf("%s %s", ime, prezime);

        fprintf(studenti, "%s %s\n", ime, prezime);
    }

    fclose(dat);
    fclose(studenti);

    return 0;
}