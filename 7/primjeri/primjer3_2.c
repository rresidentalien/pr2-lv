#include <stdio.h>
const int LENGTH = 80; //maksimalna duzina stringa

int main(void){
    char *proverbs[] ={ "Tko rano rani, dvije srece grabi.\n",
                        "Tko se zadnji smije, najsladje se smije.\n",
                        "Tko rano rani, taj je umoran.\n"};
    char nove[LENGTH]; // string za unos nove poslovice
    int i;

    FILE *pfile = NULL; // pokazivac na datoteku 
    char *filename = "myfile.txt";
    
    // kreiraj novu datoteku (ako myfile.txt ne postoji) 
    if(!(pfile = fopen(filename, "w"))) {// otvori datoteku za pisanje 
        printf("Greska pri otvaranju %s za pisanje. Zavrsavam program.",
        filename);
        return 1;
    }

    //zapisi prve tri poslovice u datoteku
    int count = sizeof proverbs/sizeof proverbs[0];
    for(i = 0 ; i < count ; i++)
        fputs(proverbs[i], pfile);
    fclose(pfile); //zatvori datoteku 

    //otvori datoteku za dopisivanje novih poslovica
    if(!(pfile = fopen(filename, "a"))){
        printf("Greska pri otvaranju %s za pisanje. Zavrsavam program.", filename);
        return 1;
    }
    printf("Unesite poslovicu koja nije duza od 80 znakova ili pritisnite Enter za kraj:\n");
    while(1){
        fgets(nove, LENGTH, stdin); //ucitaj poslovicu 
        if(nove[0] == '\n') //ako je ucitan novi red - enter 
            break; // zavrsi operaciju upisaivanja novih poslovica 
        fputs(nove, pfile); // zapisi poslovicu u datoteku 
    }
    fclose(pfile); // zatvori datoteku 
    if(!(pfile = fopen(filename, "r"))) { // otvori datoteku za citanje 
        printf("Greska pri otvaranju %s za pisanje. Zavrsavam program.", filename);
        return 1;
    }

    //procitaj i ispisi na ekran procitano iz datoteke 
    printf("Poslovice u datoteci su:\n\n");
    while(fgets(nove, LENGTH, pfile)) //ucitaj poslovicu 
        printf("%s", nove); //ispisi je na ekranu 
    fclose(pfile); //zatvori datoteku

    return 0;
}