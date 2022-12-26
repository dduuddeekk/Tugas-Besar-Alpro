#include <stdio.h>
#include "apartment.h"
void perkenalan()
{
    printf("\t\t\t\t |= ==================================================================== =|\n");
    printf("\t\t\t\t ||                      THIS PROGRAM WAS CREATED BY:                    ||\n");
    printf("\t\t\t\t || ,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,, ||\n");
    printf("\t\t\t\t ||                      I Kadek Indra Agusta Pratama                    ||\n");
    printf("\t\t\t\t ||                              2205551056                              ||\n");
    printf("\t\t\t\t || ==================================================================== ||\n");
    printf("\t\t\t\t ||                       Ni Komang Vaniya Apriandani                    ||\n");
    printf("\t\t\t\t ||                              2205551019                              ||\n");
    printf("\t\t\t\t |= ==================================================================== =|\n");
    system("pause");
    system("cls");
}
void selamat_datang()
{
    printf("\t\t\t\t|| =============================== ||\n");
    printf("\t\t\t\t||                                 ||\n");
    printf("\t\t\t\t||   Selamat Datang di Apartemen   ||\n");
    printf("\t\t\t\t||        J U N E K A R T A        ||\n");
    printf("\t\t\t\t||                                 ||\n");
    printf("\t\t\t\t|| =============================== ||\n");
    system("pause");
    system("cls");
}
int main()
{
    perkenalan();
    selamat_datang();
    mainmenu();
    return 0;
}