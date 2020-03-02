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
    struct date curdate;
    curdate = input_date();

    weekday_as_number(curdate);
    printf("Tag des Jahres: %i\n", day_of_the_year(curdate));
    return 0;
}
