/*****************************************************************************
PURPOSE:    ( Process Temperature )
*****************************************************************************/
#include <stdio.h>
#include "../include/temperature.h"

int temp_process( TEMP* T ) {

    T->temp += 0.1;
    if (T->temp > 100) {
        T->temp = 0.0;
        fprintf(stderr, "temp check\n");
    }

    T->speed += 0.5;
    if (T->speed > 30) {
        T->speed = 0.0;
        fprintf(stderr, "speed check\n");
    }

    if (T->reset_flag) {
        fprintf(stderr,"temp reset\n");
        T->temp = 0.0;
    }
    return 0;
}

void temp_display( TEMP* T )
{
    printf("Temp: %.1f\n", T->temp );
    printf("Speed: %.1f\n", T->speed );
}