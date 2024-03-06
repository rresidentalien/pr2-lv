#include <stdio.h>

int main() {
    int n;
    do {
        printf("\nUnesite broj mjeseca: ");
        scanf("%d", &n);
        if (n < 1 || n > 12) {
            printf("Nekorektan broj mjeseca");
        }
    }while (n < 1 || n > 12);

    char *mjeseci[] = { "sijecanj", "veljaca", "ozujak", "travanj", "svibanj", "lipanj", "srpanj", "kolovoz", "rujan", "listopad", "studeni", "prosinac" };
    printf("REZULTATI:\n");
    printf("%s", mjeseci[n-1]);

    return 0;
}