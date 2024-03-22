#include <stdio.h>

struct tocka {
    int x;
    int y;
    int z;
};

//vraca pokazivac na strukturu u kojoj je najvisa tocka
struct tocka* findMax(struct tocka *p, int n) { //p = pokazivac, mi cemo ovdje funkciji davati polje, pa ono iscezava u pokazivac na prvi element polja
    int i;
    struct tocka *max; //max je pokazivac tipa struct tocka

    max = &p[0]; //vrijednost varijable max = adresa prvog elementa polja pokazivaca na tocku. mozemo pisati i max = p (p je pokazivac i s &p[0] ga referenciramo, zatim dereferenciramo)

    for (i = 0; i < n; i++) {//n = broj elemenata polja pokazivaca
        if (max->z < p[i].z) { //(*max).z < p[i].z - za p[i].z koristimo tocku umjesto strelice jer uglatim zagradama [] vec vrsimo dereferenciranje, dakle s -> bi radili dva dereferenciranja
            max = &p[i]; //ako je vrijednost na max.z manja od vrijednosti trenutnog elementa p[i].z, max postaje pokazivac na taj p[i] (trazimo najvecu z koordinatu u zadatku)
        }
    }

    return max;
}

int main(void) {
    struct tocka *najveci; //pokazivac najveci tipa struct tocka
    int n=4; //4 jer imamo 4 elementa - 4 skupine po tri broja - 4 tocke
    struct tocka polje[]={1,2,3, //prva tocka
                        10,11,12, //druga tocka
                        7,8,9, //treca tocka
                        4,5,6}; //cetvrta tocka

    najveci = findMax(polje, n);
    printf("najveci Z je %d", najveci->z);

    return 0;
}
