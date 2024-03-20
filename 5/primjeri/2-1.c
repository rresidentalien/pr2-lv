#include <stdio.h>

struct tocka { //struktura tocka
    int x;
    int y;
    int z;
};

struct tocka add(struct tocka p1, struct tocka p2) { //funkcija tipa struct tocka imena add
    struct tocka res; //varijabla res tipa struct tocka
    res.x = p1.x + p2.x; //zbroj x komponenata tocke
    res.y = p1.y + p2.y; //zbroj y komponenata tocke
    res.z = p1.z + p2.z; //zbroj z komponenata tocke
    
    return res;
}
int main(void) {
    struct tocka a={1,2,3}, b={2,3,4}; //dve toke
    struct tocka p;
    p = add(a, b); //u p se sprema zbroj tocaka a i b
    printf("zbroj je: %d, %d, %d", p.x, p.y, p.z);

    return 0;
}