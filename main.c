/**
 * Timelib
 *
 * Eine Bibliothek mit verschiedenen Zeitfunktionen
 *
 * Autor: Lothar Gomoluch
 * Last Edited: 25.02.2020
 **/

#include <stdio.h>
#include <stdlib.h>
#include "timelib.h"

/**
* Main Funktion, welche am Anfang des Programmes aufgerufen wird.
* @return int: 0 wenn alles richtig ist, sonst -1
*/
int main()
{
    int month=0,year=0,day=0;

    input_date(&day, &month, &year);

    printf("Tag des Jahres: %i\n", weekday_as_number(day, month, year));
    return 0;
}
