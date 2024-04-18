#include <stdio.h>
#include <stdlib.h>

//void exit(int status);
//ne vraca vrijednost, parametri su joj EXIT_FAILURE ili EXIT_SUCCESS, iznenadno prekida program

int main(void){
    FILE *fp = NULL;

    if ( (fp = fopen ("dat.txt", "r")) == NULL ) {
        perror("Greska");
        exit (EXIT_FAILURE); //prekida cijeli program
    }

    fclose (fp);
    return 0;
}