#include <stdio.h>
#include <math.h>

int main() {
    int polje[8] = {0};
    int i, n = 0;
    int broj = 0;

    for (i = 0; i < 8; ++i) {
        scanf("%d", &polje[i]);
    }

    for (i = 7; i >= 0; --i) {
        polje[i] = polje[i] * pow(2, n);
        ++n;
        broj += polje[i];
    }

    printf("%d", broj);

    return 0;
}