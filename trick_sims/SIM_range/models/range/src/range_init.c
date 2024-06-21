/******************************* TRICK HEADER ****************************
PURPOSE: (Set the initial data values)
*************************************************************************/

/* Model Include files */
#include "../include/range.h"

/* initialization job */
int range_init( CONTROL* C, TEMP* T) {
   
    C->range = 0.0;
    C->range_rate = 0.0;

    T->temp  = 0.0;
    T->speed = 0.0;
    return 0 ; 
}