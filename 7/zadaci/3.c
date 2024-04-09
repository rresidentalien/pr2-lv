#include <stdio.h>
#include <ctype.h>

int main() {
    FILE *prva = fopen("prva.txt", "r");
    FILE *druga = fopen("druga.txt", "w");

    if (prva == NULL || druga == NULL) {
        printf("Datoteka se ne moze otvoriti.\n");
        return 1;
    }
    
    char c;
    while ((c = fgetc(prva)) != EOF) {
        if (islower(c)) {
            c = toupper(c);
        } else if (isupper(c)) {
            c = tolower(c);
        }
        fputc(c, druga);
    }
    
    fclose(prva);
    fclose(druga);

    return 0;
}