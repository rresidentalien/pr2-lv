#include <stdio.h>
#include <stdlib.h>

typedef struct tocka { //struktura za tocku u 3D prostoru
float x;
float y;
float z;
} TOCKA;

int main() {
    TOCKA t = {3.0, 2.0, 1.0};
    TOCKA *d = NULL;

    d = (TOCKA *)malloc(sizeof(TOCKA)); //zauzimanje memorije - d je pokazivac na memoriju
    if (d == NULL) {
        printf("Greska kod zauzimanja memorije");
        return 1;
    }

    d->x = t.x; //(*d).x = t.x
    d->y = t.y; //pridajemo vrijednost t.y adresi na koju pokazivac d.y pokazuje
    d->z = t.z;

    printf("%.2f %.2f %.2f", d->x, d->y, d->z);

    free(d);
    d=NULL;
    return 0;
}