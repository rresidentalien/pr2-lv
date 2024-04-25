#include <stdio.h>
#include <stdlib.h>

typedef struct tocka {
    int x;
    int y;
    int z;
}TOCKA;

TOCKA static_add(TOCKA p1, TOCKA p2) { //zbrajanje staticki zauzetih tocaka; prijenos po kopiji 
    TOCKA res;

    res.x = p1.x + p2.x;
    res.y = p1.y + p2.y;
    res.z = p1.z + p2.z;

    return res; //vraca rezultat
}

TOCKA *dynamic_add(TOCKA p1, TOCKA p2) { //zbrajanje dinamicki zauzetih tocaka
    TOCKA *res = (TOCKA *)malloc(sizeof(TOCKA)); //dinamicki zauzeta memorija za tocke
    if (res == NULL) {
        printf("Greska kod zauzimanja memorije ");
        return NULL;
    }

    res->x = p1.x + p2.x;
    res->y = p1.y + p2.y;
    res->z = p1.z + p2.z;

    return res; //vraca adresu varijable koja sadrzi rezultat
}

int main() {
    TOCKA a={1,2,3}, b={2,3,4};
    TOCKA p;
    TOCKA *q;

    puts("static add: ");
    p = static_add(a, b);
    printf("rezultat: %d, %d, %d; adresa: %p \n", p.x, p.y, p.z, p);
    p = static_add(a, b);
    printf("rezultat: %d, %d, %d; adresa: %p \n", p.x, p.y, p.z, p);

    puts("dynamic add: ");
    q = dynamic_add(a, b);
    printf("rezultat: %d, %d, %d; adresa: %p \n", q->x, q->y, q->z, q);
    free(q); //zastita od curenja memorije - oslobadjamo memoriju koja se vise nece koristiti, ali vrijednost ostaje spremljena u njoj
    q = dynamic_add(a, b);
    printf("rezultat: %d, %d, %d; adresa: %p \n", q->x, q->y, q->z, q);
    free(q);

    return 0;
}