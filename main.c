/**
 * Timelib - main.c
 *
 * Die "main.c" der timelib-Bibliothek, welche die Tagesnummer eines Datums berechnet
 * sowie den Wochentag dieses Datums
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
    struct date curdate;
    curdate = input_date();

    printf("Tag des Jahres: %i\n", day_of_the_year(curdate));
    weekday_as_number(curdate);
    return 0;
}
