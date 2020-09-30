/*****************************************************************************
PURPOSE:    ( Process Temperature )
*****************************************************************************/
#include <stdio.h>
#include "../include/temperature.h"

int temp_process( TEMP* T ) {

    T->temp += 0.1;
    if (T->temp > 100) {
        T->temp = 0.0;
        fprintf(stderr,"temp check\n");
    }
    return 0;
}