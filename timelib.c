#include <stdio.h>
#include <stdlib.h>
#include "timelib.h"

/**
* Funktion zum zurückgeben, ob ein gegebenes Jahr ein Schaltjahr ist
* @param year: Integer, der das Jahr repräsentiert
* @return 1: Wenn übergebenes Jahr ein Schaltjahr ist
* @return 0: Wenn übergebenes Jahr kein Schaltjahr ist
* @return -1: Wenn ein ungültiges Jahr übergeben wurde
*
*/
int is_leapyear(struct date curdate)
{
    //Schaltjahre: Alle 4 Jahre außer, wenn es durch 100 restlos teilbar,
    //Alle 400 Jahre eine ausnahme
    if (((curdate.year % 4 == 0) && (curdate.year % 100 != 0)) || (curdate.year % 400 == 0))
    {
        return(1);
    }
    if (curdate.year < 1582)
    {
        return(-1);
    }
    return 0;
}

/**
* Funktion, welche die Anzahl an Tagen in einem Monat zurückgibt
* @param month: Integer, der den Monat repräsentiert
* @param year: Integer, der das Jahr repräsentiert
* @return -1: Wenn ein ungültiges Jahr oder ein ungültiger Monat übergeben wurde
* @return 1-31: Wenn ein gültiger Monar eingegeben wurde
*/
int get_days_for_month(struct date curdate)
{
    int dayInMonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

    int leapyearresult = is_leapyear(curdate);

    //Abfrage, ob Schaltjahr-Rückgabe ungültig oder Monat ungültig
    if (leapyearresult == -1 || curdate.month < 0 || curdate.month > 13)
    {
        return -1;
    }

    if (leapyearresult == 1)
    {
        dayInMonth[1] = 29;
    }

    return dayInMonth[curdate.month];

}

/**
* Funktion, welche prüft, ob ein Datum existiert im gregorianischen Kalender
* @param day: Integer, der den Tag repräsentiert
* @param month: Integer, der den Monat repräsentiert
* @param year: Integer, der das Jahr repräsentiert
* @return 1: Wenn das Datum existiert
* @return 0: Wenn das Datum nicht existiert
*/
//int exists_date(int day, int month, int year)
int exists_date(struct date curdate)
{
    //Jahr zwischen 1582 und 2400 sind gültig
    //Monat zwischen 1 und 12 sind gültig
    //Tag holen und überprüfen, ob es richtig ist
    if ((curdate.year >= 1582 && curdate.year <= 2400) &&
            (curdate.month > 0 && curdate.month < 13) &&
            (curdate.day > 0 || curdate.day <= get_days_for_month(curdate)))
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
//int day_of_the_year(int day, int month, int year)
int day_of_the_year(struct date curdate)
{

    int i = 0, number = 0, realmonth = curdate.month;

    if(exists_date(curdate) == 0)
    {
        return -1;
    }
    else
    {
        for(i=0; i<realmonth-1; i++)
        {
            curdate.month = i;
            number += get_days_for_month(curdate);
        }
        number+=curdate.day;
        curdate.month = realmonth;
        return number;
    }

}


/**
* Funktion zum Eingeben des Datums
* @param *day: Pointer auf die übergebene Variable des Tages
* @param *month: Pointer auf die übergebene Variable des Monats
* @param *year: Pointer auf die übergebene Variable des Jahres
* @return inputdate: Die Struktur mit den eingegebenen Daten
*/
//void input_date(int *day, int *month, int *year)
struct date input_date()
{
    struct date inputdate;
    do
    {
        printf("Geben sie den Tag des Datums ein: ");
        scanf("%d",&inputdate.day);
        fflush(stdin);

        printf("Geben sie den Monat des Datums ein: ");
        scanf("%d",&inputdate.month);
        fflush(stdin);

        printf("Geben sie den Jahr des Datums ein: ");
        scanf("%d",&inputdate.year);
        fflush(stdin);

        printf("\n");
    }
    while (!(exists_date(inputdate)));

    return inputdate;
}



/**
* Funktion, welche den Wochentag eines Datums des gregoreanischen Kalenders ausgibt
* @param day: Integer, der den Tag repräsentiert
* @param month: Integer, der den Monat repräsentiert
* @param year: Integer, der das Jahr repräsentiert
*/
int weekday_as_number(struct date curdate)
{
    int yearfisthalf = 0, yearsecondhalf = 0, dayno = 0, monthno = 0;
    int yearno = 0, centuryno = 0, leapyearcorection = 0, weekdayno = 0;
    //Der erste Monat fängt mit 0 an. Danach kommen die Reste des Vormonats
    //Modulo 7, da 7 Wochentage
    int allmonthnos[12] = {0,3,3,6,1,4,6,2,5,0,3,5};
    //Es fängt bei 0 an, um 1 hochzählen bei normalen Jahren, bei Schaltjahr 2
    //Modulo 7, da 7 Wochentage
    int allyearnos[29] = {0,1,2,3,5,6,0,1,3,4,5,6,1,2,3,4,6,0,1,2,4,5,6,0,2,3,4,5,0};

    //Herausholen der ersten beiden und letzten beiden Ziffern des Jahres
    yearsecondhalf = (curdate.year % 10) + (((curdate.year /10) % 10) * 10);
    yearfisthalf = ((curdate.year / 100) % 10) + (((curdate.year /1000) % 10) * 10);

    dayno = curdate.day % 7;
    monthno = allmonthnos[curdate.month-1];

    //es gibt nur 28 Iterationen bei der Zählung, danach wiederholt es sich
    while (yearsecondhalf > 28)
    {
        yearsecondhalf -= 28;
    }
    yearno = allyearnos[yearsecondhalf];

    //Zuordnungssummant je nach Jahrhundert. Wiederholt sich all 400 Jahre
    centuryno = (3-(yearfisthalf % 4)) *2;

    if ((is_leapyear(curdate) == 1) && (curdate.month < 3))
    {
        leapyearcorection = -1;
    }

    weekdayno = (dayno + monthno + yearno + centuryno + leapyearcorection) % 7;

    switch(weekdayno)
    {
    case 0:
        printf("Sonntag\n");
        break;

    case 1:
        printf("Montag\n");
        break;

    case 2:
        printf("Dienstag\n");
        break;

    case 3:
        printf("Mittwoch\n");
        break;

    case 4:
        printf("Donnerstag\n");
        break;

    case 5:
        printf("Freitag\n");
        break;

    case 6:
        printf("Samstag\n");
        break;

    default:
        return -1;
    }

    return 0;
}
