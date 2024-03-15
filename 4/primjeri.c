#include <stdio.h>

struct tocka {
    float x;
    float y;
    float z;
};
struct trokut {
    struct tocka toc[3];
};

int main() {
    struct trokut T[20];
    struct trokut *pT;
    pT = &T[0];

    T[0].toc[0].x = 2;
    T[0].toc[0].y = 3;
    T[0].toc[0].z = 4;

    pT->toc[0].x = 2;
    pT->toc[0].y = 3;
    pT->toc[0].z = 4;
}