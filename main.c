/**
 * Timelib
 *
 * Eine Bibliothek mit verschiedenen Zeitfunktionen
 *
 * Autor: Lothar Gomoluch
 * Last Edited: 11.02.2020
 **/

#include <stdio.h>
#include <stdlib.h>


/**
* Funktion zum zurückgeben, ob ein gegebenes Jahr ein Schaltjahr ist
* @param year: Integer, der das Jahr repräsentiert
* @return 1: Wenn übergebenes Jahr ein Schaltjahr ist
* @return 0: Wenn übergebenes Jahr kein Schaltjahr ist
* @return -1: Wenn ein ungültiges Jahr übergeben wurde
*
*/
int is_leapyear(int year)
{
    //Einlesen und definieren der vom User eingegebenen Wert in die Variabl

    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
    {
        return(1);
    }
    if (year < 1582)
    {
        return(-1);
    }
    return 0;
    //Ausgabe, falls keine Zahl angegeben wurde
}

/**
* Funktion, welche die Anzahl an Tagen in einem Monat zurückgibt
* @param month: Integer, der den Monat repräsentiert
* @param year: Integer, der das Jahr repräsentiert
* @return -1: Wenn ein ungültiges Jahr oder ein ungültiger Monat übergeben wurde
* @return 1-31: Wenn ein gültiger Monar eingegeben wurde
*/
int get_days_for_month(int month, int year)
{
    int dayInMonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

    int leapyearresult = is_leapyear(year);

    if (leapyearresult == -1 || month < 0 || month > 13)
    {
        return -1;
    }

    if (leapyearresult == 1)
    {
        dayInMonth[1] = 29;
    }

    return dayInMonth[month];

}

/**
* Funktion, welche prüft, ob ein Datum existiert im gregorianischen Kalender
* @param day: Integer, der den Tag repräsentiert
* @param month: Integer, der den Monat repräsentiert
* @param year: Integer, der das Jahr repräsentiert
* @return 1: Wenn das Datum existiert
* @return 0: Wenn das Datum nicht existiert
*/
int exists_date(int day, int month, int year)
{
    if ((year > 1582 && year < 2400) &&
        (month > 0 && month < 13) &&
        (day > 0 || day <= get_days_for_month(month-1, year)))
    {
        return 1;
    }
    return 0;

}

/**
* Funktion, welche die Nummer des Tages gezählt vom Jahresbegin
* @param day: Integer, der den Tag repräsentiert
* @param month: Integer, der den Monat repräsentiert
* @param year: Integer, der das Jahr repräsentiert
* @return -1: Bei nicht gültig eingegebenen Datum
* @return number: Die Nummer, welche die des Tages des eingegebenen Datums ist
**/
int day_of_the_year(int day, int month, int year)
{

    int i = 0, number = 0;

    if(exists_date(day, month, year) == 0)
    {
        return -1;
    }
    else
    {
        for(i=0; i<month-1; i++)
        {
            number += get_days_for_month(i,year);
        }
        number+=day;
        return number;
    }

}

/**
*
*
*
*/
int main()
{
    int month=0,year=0,day=0;

    printf("Geben sie den Tag des Datums ein:");
    scanf("%d",&day);
    fflush(stdin);

    printf("Geben sie den Monat des Datums ein:");
    scanf("%d",&month);
    fflush(stdin);

    printf("Geben sie den Jahr des Datums ein:");
    scanf("%d",&year);
    fflush(stdin);

    printf("Tag des Jahres: %i\n", day_of_the_year(day, month, year));
    return 0;
}
