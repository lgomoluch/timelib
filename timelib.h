#ifndef TIMELIB_H_INCLUDED
#define TIMELIB_H_INCLUDED

struct date{
    int day;
    int month;
    int year;
};

/**
* Funktion zum zur�ckgeben, ob ein gegebenes Jahr ein Schaltjahr ist
* @param year: Integer, der das Jahr repr�sentiert
* @return 1: Wenn �bergebenes Jahr ein Schaltjahr ist
* @return 0: Wenn �bergebenes Jahr kein Schaltjahr ist
* @return -1: Wenn ein ung�ltiges Jahr �bergeben wurde
*
*/
int is_leapyear(struct date curdate);

/**
* Funktion, welche die Anzahl an Tagen in einem Monat zur�ckgibt
* @param month: Integer, der den Monat repr�sentiert
* @param year: Integer, der das Jahr repr�sentiert
* @return -1: Wenn ein ung�ltiges Jahr oder ein ung�ltiger Monat �bergeben wurde
* @return 1-31: Wenn ein g�ltiger Monar eingegeben wurde
*/
int get_days_for_month(struct date curdate);

/**
* Funktion, welche pr�ft, ob ein Datum existiert im gregorianischen Kalender
* @param day: Integer, der den Tag repr�sentiert
* @param month: Integer, der den Monat repr�sentiert
* @param year: Integer, der das Jahr repr�sentiert
* @return 1: Wenn das Datum existiert
* @return 0: Wenn das Datum nicht existiert
*/
int exists_date(struct date curdate);

/**
* Funktion, welche die Nummer des Tages gez�hlt vom Jahresbegin
* @param day: Integer, der den Tag repr�sentiert
* @param month: Integer, der den Monat repr�sentiert
* @param year: Integer, der das Jahr repr�sentiert
* @return -1: Bei nicht g�ltig eingegebenen Datum
* @return number: Die Nummer, welche die des Tages des eingegebenen Datums ist
**/
int day_of_the_year(struct date curdate);

/**
* Funktion zum Eingeben des Datums
* @param *day: Pointer auf die �bergebene Variable des Tages
* @param *month: Pointer auf die �bergebene Variable des Monats
* @param *year: Pointer auf die �bergebene Variable des Jahres
*/
struct date input_date();

/**
* Funktion, welche den Wochentag eines Datums des gregoreanischen Kalenders ausgibt
* @param day: Integer, der den Tag repr�sentiert
* @param month: Integer, der den Monat repr�sentiert
* @param year: Integer, der das Jahr repr�sentiert
*/
int weekday_as_number(struct date curdate);
#endif // TIMELIB_H_INCLUDED
