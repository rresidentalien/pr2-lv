#include <stdio.h>

typedef struct {
    float realni;
    float imaginarni;
} KOMPLEKSNI;

int main() {
    KOMPLEKSNI broj1, broj2, zbroj, razlika;

    printf("Unesi prvi kompleksni broj: ");
    scanf("%f %f", &broj1.realni, &broj1.imaginarni);
    printf("Unesi drugi kompleksni broj: ");
    scanf("%f %f", &broj2.realni, &broj2.imaginarni);

    zbroj.realni = broj1.realni + broj2.realni;
    zbroj.imaginarni = broj1.imaginarni + broj2.imaginarni;

    razlika.realni = broj1.realni - broj2.realni;
    razlika.imaginarni = broj1.imaginarni - broj2.imaginarni;

    printf("REZULTATI:\n");
    printf("Zbroj: %.3f, %.3f*i\n", zbroj.realni, zbroj.imaginarni);
    printf("Razlika: %.3f, %.3f*i\n", razlika.realni, razlika.imaginarni);

    return 0;
}