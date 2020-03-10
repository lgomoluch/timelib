/**
* Timelib - timelib.h
*
* Header-Datei, welche die Funktionsprototypen sowie die Struktur, welche von diesen
* Funktionen genutzt wird
*
* Autor: Lothar Gomoluch
* Last Edited: 10.03.2020
*/
#ifndef TIMELIB_H_INCLUDED
#define TIMELIB_H_INCLUDED

/**
* Struktur, welche bereits den Datentyp für die Funktionen vorgibt.
* Fasst die einzelnen Datum-Teildatentypen zusammen
*/
struct date{
    int day;
    int month;
    int year;
};

/**
* Funktion zum zurückgeben, ob ein gegebenes Jahr ein Schaltjahr ist
* @param year: Integer, der das Jahr repräsentiert
* @return 1: Wenn übergebenes Jahr ein Schaltjahr ist
* @return 0: Wenn übergebenes Jahr kein Schaltjahr ist
* @return -1: Wenn ein ungültiges Jahr übergeben wurde
*
*/
int is_leapyear(struct date curdate);

/**
* Funktion, welche die Anzahl an Tagen in einem Monat zurückgibt
* @param month: Integer, der den Monat repräsentiert
* @param year: Integer, der das Jahr repräsentiert
* @return -1: Wenn ein ungültiges Jahr oder ein ungültiger Monat übergeben wurde
* @return 1-31: Wenn ein gültiger Monar eingegeben wurde
*/
int get_days_for_month(struct date curdate);

/**
* Funktion, welche prüft, ob ein Datum existiert im gregorianischen Kalender
* @param day: Integer, der den Tag repräsentiert
* @param month: Integer, der den Monat repräsentiert
* @param year: Integer, der das Jahr repräsentiert
* @return 1: Wenn das Datum existiert
* @return 0: Wenn das Datum nicht existiert
*/
int exists_date(struct date curdate);

/**
* Funktion, welche die Nummer des Tages gezählt vom Jahresbegin
* @param day: Integer, der den Tag repräsentiert
* @param month: Integer, der den Monat repräsentiert
* @param year: Integer, der das Jahr repräsentiert
* @return -1: Bei nicht gültig eingegebenen Datum
* @return number: Die Nummer, welche die des Tages des eingegebenen Datums ist
**/
int day_of_the_year(struct date curdate);

/**
* Funktion zum Eingeben des Datums
* @param *day: Pointer auf die übergebene Variable des Tages
* @param *month: Pointer auf die übergebene Variable des Monats
* @param *year: Pointer auf die übergebene Variable des Jahres
*/
struct date input_date();

/**
* Funktion, welche den Output der Weekday_as_number Funktion übernimmt
* @param weekdayno: Eine Nummer von 0-6, 0 entspricht Sonntag
* @return int: Gibt 0 bei erfolgreichem ausführen zurück, sonst -1
*/
int return_weekday(int weekdayno);

/**
* Funktion, welche den Wochentag eines Datums des gregoreanischen Kalenders ausgibt
* @param day: Integer, der den Tag repräsentiert
* @param month: Integer, der den Monat repräsentiert
* @param year: Integer, der das Jahr repräsentiert
*/
void weekday_as_number(struct date curdate);
#endif // TIMELIB_H_INCLUDED
