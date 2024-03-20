#include <stdio.h>

struct tocka { //struktura deklarirana izvan funkcije main -- globalna -- vidljiva u cijelom programu
    int x;
    int y;
    int z;
};

struct tocka add(struct tocka p1, struct tocka p2) { //funkcija add tipa struct tocka
    struct tocka res;
    printf("add: p1= %p, p2= %p, res= %p", &p1, &p2, &res); //ispis adresa tocki p1, p2 i res
    return res;
}

int main(void) {
    struct tocka a={1,2,3}, b={2,3,4}; //tocke a i b
    struct tocka p;
    p = add(a, b); //ispis adresa tocki a, b i res iz funkcije
    printf("main: a = %p, b = %p, p = %p\n", &a, &b, &p); //ispis adresa tocki a, b i p iz main

    return 0;
}

//u ovom primjeru vidimo da p1, p2 (iz funkcije) i a, b iz maina nisu spremljene na istom mjestu u memoriji
//davanje varijable funkciji koristi prijenos po vrijednosti/kopiji -> funkcija add dobija kopije vrijednosti a i b
//te kopije se pohranjuju na razlicitim mjestima u memoriji od originalnih varijabli