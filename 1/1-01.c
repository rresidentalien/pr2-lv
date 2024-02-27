#include <stdio.h>

int main() {
    int broj, i;
    int bitovi[8] = {0};

    do{
        scanf("%d", &broj);
    }while (broj < -128 || broj > 127);

    if (broj < 0) {
        printf("1");
        broj = -broj;

        for (i=7; i>0; --i) { 
            bitovi[i] = broj % 2;
            broj = broj / 2;
        }

        for (i = 0; i < 8; ++i) {
            bitovi[i] = (bitovi[i] == 0) ? 1 : 0;
        }
        for (i = 0; i < 8; ++i) {
            if (bitovi[i] == 0) {
                bitovi[i] = 1;
            } else {
                bitovi[i] = 0;
            }
        }
    } else {
        printf("0");

        for (i=7; i>=0; --i) {
            bitovi[i] = broj % 2;
            broj = broj / 2;
        }
    }

    for (i=0; i<8; ++i) {
        printf("%d", bitovi[i]);
    }

    return 0;
}