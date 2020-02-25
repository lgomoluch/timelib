#include <stdio.h>
#include <stdlib.h>


/**
* Funktion zum zur�ckgeben, ob ein gegebenes Jahr ein Schaltjahr ist
* @param year: Integer, der das Jahr repr�sentiert
* @return 1: Wenn �bergebenes Jahr ein Schaltjahr ist
* @return 0: Wenn �bergebenes Jahr kein Schaltjahr ist
* @return -1: Wenn ein ung�ltiges Jahr �bergeben wurde
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
* Funktion, welche die Anzahl an Tagen in einem Monat zur�ckgibt
* @param month: Integer, der den Monat repr�sentiert
* @param year: Integer, der das Jahr repr�sentiert
* @return -1: Wenn ein ung�ltiges Jahr oder ein ung�ltiger Monat �bergeben wurde
* @return 1-31: Wenn ein g�ltiger Monar eingegeben wurde
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
* Funktion, welche pr�ft, ob ein Datum existiert im gregorianischen Kalender
* @param day: Integer, der den Tag repr�sentiert
* @param month: Integer, der den Monat repr�sentiert
* @param year: Integer, der das Jahr repr�sentiert
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
* Funktion, welche die Nummer des Tages gez�hlt vom Jahresbegin
* @param day: Integer, der den Tag repr�sentiert
* @param month: Integer, der den Monat repr�sentiert
* @param year: Integer, der das Jahr repr�sentiert
* @return -1: Bei nicht g�ltig eingegebenen Datum
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

int weekday_as_number(int day, int month, int year)
{
    int yearfisthalf = 0, yearsecondhalf = 0, dayno = 0, centuryno = 0, leapyearcorection = 0;
    int allmonthnos[12] = {0,3,3,6,1,4,6,2,5,0,3,5};
    int allyearnos[28] = {0,1,2,3,5,6,0,1,3,4,5,6,1,2,3,4,6,0,1,2,4,5,6,0,2,3,4,5,0};

    yearsecondhalf = (year % 10) + (((year /10) % 10) * 10);
    yearfisthalf = (year / 100) % 10)) + (((year /1000) % 10) * 10);

    dayno = day % 7;

}
