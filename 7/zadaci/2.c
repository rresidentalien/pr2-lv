#include <stdio.h>

int main() {
    int m, n;
    int i, j;
    FILE *in = fopen("in.txt", "r");
    if (in == NULL) {
        printf("Datoteka se ne moze otvoriti.\n");
        return 1;
    }

    fscanf(in, "%d %d", &m, &n);
    float matrica[m][n];

    for (i = 0; i < m; ++i) {
        for (j = 0; j < n; ++j) {
            printf("Upisi broj:");
            scanf("%f", &matrica[i][j]);
        }
    }

    printf("REZULTATI:\n");

    FILE *out = fopen("out.txt", "w");
    if (out == NULL) {
        printf("Datoteka se ne moze otvoriti.\n");
        return 1;
    }
    for (i = 0; i < m-1; ++i) {
        for (j = 1; j < n; ++j) {
            fprintf(out, "%.2f\t", matrica[i][j]);
            printf("%.2f\t", matrica[i][j]);
        }
        fprintf(out, "\n");
        printf("\n");
    }
    fclose(in);
    fclose(out);

    return 0;
}
