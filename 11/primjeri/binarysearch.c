#include <stdio.h>
int main(void){
    int V[] = { 1, 2, 5, 7, 8, 9, 11, 14, 17, 19,
                21, 23, 27, 28, 29, 30, 32, 34, 35, 36,
                38, 40, 41, 43, 44, 45, 46, 48, 49, 50};
    int n, x, brk=0;
    int dg, gg, s;
    n = sizeof(V)/sizeof(int);

    printf ("Unesi broj koji zelis pronaci u intervalu 1-50: ");
    scanf("%d", &x);

    dg = 0; //donja granica
    gg = n-1; //gornja granica
    while (dg<=gg) {
        s = (dg+gg)/2;
        if (x == V[s]) {
            printf ("Broj je pronadjen na %d. mjestu u %d koraka!", s, brk);
            break;
        }
        else if (x>V[s]) {
            dg = s+1;
            brk++;
        }
        else if (x<V[s]) {
            gg = s-1; 
            brk++;
        }
    }
    if (dg>gg) printf ("\nBroj nije pronadjen!");
    printf ("\n\n");
    return 0;
}