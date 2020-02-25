#ifndef TIMELIB_H_INCLUDED
#define TIMELIB_H_INCLUDED

/**
* Funktion zum zurückgeben, ob ein gegebenes Jahr ein Schaltjahr ist
* @param year: Integer, der das Jahr repräsentiert
* @return 1: Wenn übergebenes Jahr ein Schaltjahr ist
* @return 0: Wenn übergebenes Jahr kein Schaltjahr ist
* @return -1: Wenn ein ungültiges Jahr übergeben wurde
*
*/
int is_leapyear(int year);

/**
* Funktion, welche die Anzahl an Tagen in einem Monat zurückgibt
* @param month: Integer, der den Monat repräsentiert
* @param year: Integer, der das Jahr repräsentiert
* @return -1: Wenn ein ungültiges Jahr oder ein ungültiger Monat übergeben wurde
* @return 1-31: Wenn ein gültiger Monar eingegeben wurde
*/
int get_days_for_month(int month, int year);

/**
* Funktion, welche prüft, ob ein Datum existiert im gregorianischen Kalender
* @param day: Integer, der den Tag repräsentiert
* @param month: Integer, der den Monat repräsentiert
* @param year: Integer, der das Jahr repräsentiert
* @return 1: Wenn das Datum existiert
* @return 0: Wenn das Datum nicht existiert
*/
int exists_date(int day, int month, int year);

/**
* Funktion, welche die Nummer des Tages gezählt vom Jahresbegin
* @param day: Integer, der den Tag repräsentiert
* @param month: Integer, der den Monat repräsentiert
* @param year: Integer, der das Jahr repräsentiert
* @return -1: Bei nicht gültig eingegebenen Datum
* @return number: Die Nummer, welche die des Tages des eingegebenen Datums ist
**/
int day_of_the_year(int day, int month, int year);

/**
* Funktion zum Eingeben des Datums
* @param *day: Pointer auf die übergebene Variable des Tages
* @param *month: Pointer auf die übergebene Variable des Monats
* @param *year: Pointer auf die übergebene Variable des Jahres
*/
void input_date(int *day, int *month, int *year);

/**
* Funktion, welche den Wochentag eines Datums des gregoreanischen Kalenders ausgibt
* @param day: Integer, der den Tag repräsentiert
* @param month: Integer, der den Monat repräsentiert
* @param year: Integer, der das Jahr repräsentiert
*/
int weekday_as_number(int day, int month, int year);
#endif // TIMELIB_H_INCLUDED
