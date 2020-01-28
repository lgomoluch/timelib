/**
 * Timelib
 *
 * Eine Bibliothek mit verschiedenen Zeitfunktionen
 *
 * Autor: Lothar Gomoluch
 * Last Edited: 28.01.2020
 **/

#include <stdio.h>
#include <stdlib.h>

int schaltjahr(int jahr);
/**
 *
 *
 **/
int day_of_the_year(int day, int month, int year)
{
    int dayInMonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int i, number = 0;

    if (schaltjahr(year) == 1)
    {
        dayInMonth[1] =29;
    }

    if(!(day <= dayInMonth[month-1]))
    {
        return -1;

    }
    else
    {

        for(i=0; i<month-1; i++)
        {
            number += dayInMonth[i];
        }
        number+=day;
        return number;
    }
}


int schaltjahr(int jahr)
{

    //Einlesen und definieren der vom User eingegebenen Wert in die Variable
    if (jahr % 4 == 0 && jahr % 100 != 0 || jahr % 400 == 0)
    {
        return(1);
    }
    else
    {
        return(0);
    }
    //Ausgabe, falls keine Zahl angegeben wurde

}


int main()
{
    int month=0,year=0,day=0;


    do
    {
        printf("Geben sie den Tag des Datums ein:");
        scanf("%d",&day);
        fflush(stdin);
    }
    while(day>31 || day < 1);

    do
    {
        printf("Geben sie den Monat des Datums ein:");
        scanf("%d",&month);
        fflush(stdin);
    }
    while(month > 12 || month < 1);

    do
    {
        printf("Geben sie den Jahr des Datums ein:");
        scanf("%d",&year);
        fflush(stdin);
    }
    while(year < 0);
    printf("Tag des Jahres: %i\n", day_of_the_year(day, month, year));
    return 0;
}
