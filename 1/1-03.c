#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main() {
    srand(time(NULL));

    int polje[32];
    int i, n = 0;

    for (int i = 0; i < 32; ++i) {
        polje[i] = rand() % 2;
    }

    for (i=32, i>=0; --i) {
        polje[i] = polje[i] * pow(2, 32-i);
    }
}