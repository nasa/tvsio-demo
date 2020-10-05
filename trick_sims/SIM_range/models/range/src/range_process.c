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