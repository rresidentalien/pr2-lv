#include <stdio.h>

struct tocka {
    int x;
    int y;
    int z;
};

struct tocka add(struct tocka *p1, struct tocka *p2) {
    struct tocka res;

    res.x = p1->x + p2->x;
    res.y = p1->y + p2->y;
    res.z = p1->z + p2->z;

    printf("add: p1= %p, p2= %p, res= %p\n", p1, p2, &res);

    return res;
}
int main(void) {
    struct tocka a={1,2,3}, b={2,3,4};
    struct tocka p;

    printf("main: a = %p, b = %p, p = %p\n", &a, &b, &p);
    p = add(&a, &b);
    printf("rezultat: %d, %d, %d", p.x, p.y, p.z);

    return 0;
}

//ovaj put a ima jednaku adresu kao i p1, a b ima jednaku adresu kao i p2
//funkcija add prenosi vrijednost po adresi, a p1 i p2 su pokazivaci na a i b
//zato su adrese a i b jednake adresama p1 i p2

//kada se program pokrene, rezultat zbrajanja p1 i p2 se upisuje u res
//povratne vrijednosti u C se prenose po kopiji, dakle funkcija add vraca kopiju vrijednosti koja se upisuje u p
//zato res i p imaju razlicite adrese