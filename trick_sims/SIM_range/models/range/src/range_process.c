/*****************************************************************************
PURPOSE:    ( Process range )
*****************************************************************************/
#include <stdio.h>
#include "../include/range.h"

int range_process( CONTROL* C ) {

    C->range += 0.1;
    C->range_rate += 0.97;
    if (C->range > 100) {
        C->range = 0.0;
        C->range_rate = 0.0;
        fprintf(stderr,"still running\n");
    }
    return 0;
}

int temp_process( TEMP* T )
{
    printf( "Received temp: %5.2f\n", T->temp );
    printf( "Received speed: %5.2f\n", T->speed );
    return 0;
}