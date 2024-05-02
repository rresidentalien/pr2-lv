#include <stdio.h>

int main() {
    int polje[] = {-2, 4, 1, 5, 3};
    int a = 5;
    int n, pronadjen = 0, br = 0;

    n = sizeof(polje) / sizeof(int);

    while(!pronadjen && br<n) { 
        if (polje[br] == a) 
            pronadjen = 1; 
        br++;
    }
    if (pronadjen) printf ("Element je pronadjen na %d. mjestu.\n", br);
    else printf ("Element nije pronadjen.\n");

    printf ("\n\n");

    return 0;
}