/*#include<stdio.h>
int main(void) {
int polje[] = { 1, 2, 3, 4, 5 };
int *pok = polje;
int n = sizeof(polje)/sizeof(int);
//izraz je ispravan samo ako je polje statički zauzeto
int i;
for (i = 0; i < n; i++)
{
printf("%3d", polje[i]);
//printf("%3d", *(polje + i));
}
for (i = 0; i < n; i++)
{
printf("%3d", *(pok + i));
//printf("%3d", pok[i]);
}
return 0;
}*/

#include<stdio.h>
int main(void) {
int a = 5;
int *jedPok = &a;
int **dvoPok = &jedPok;
printf("a == %d\n", a);
printf("a == *jedPok == %d\n", *jedPok);
printf("a == **dvoPok == %d\n", **dvoPok);
printf("&a == %ul\n", &a);
printf("&a == jedPok == %ul\n", jedPok);
printf("&a == *dvoPok == %ul\n", *dvoPok);
printf("&jedPok == dvoPok == %ul\n", dvoPok);
return 0;
}