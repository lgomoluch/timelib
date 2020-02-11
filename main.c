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
#include "timelib.h"

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
