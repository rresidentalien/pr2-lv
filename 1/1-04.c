#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    
    int broj, i;
    broj = (rand() % 65535) - 32767;
    
    int bitovi[32] = {0};
    
    if (broj < 0) {
        printf("1");
        broj = -broj;

        for (i=31; i>0; --i) { 
            bitovi[i] = broj % 2;
            broj = broj / 2;
        }

        for (i = 0; i < 32; ++i) {
            bitovi[i] = (bitovi[i] == 0) ? 1 : 0;
        }
        for (i = 0; i < 32; ++i) {
            if (bitovi[i] == 0) {
                bitovi[i] = 1;
            } else {
                bitovi[i] = 0;
            }
        }
    } else {
        printf("0");

        for (i=31; i>=0; --i) {
            bitovi[i] = broj % 2;
            broj = broj / 2;
        }
    }

    for (i=0; i<32; ++i) {
        printf("%d", bitovi[i]);
    }

    return 0;
}
