/******************************* TRICK HEADER ****************************
PURPOSE: (Set the initial data values)
*************************************************************************/

/* Model Include files */
#include "../include/range.h"

/* initialization job */
int range_init( CONTROL* C) {
   
    C->range = 0.0;
    C->range_rate = 0.0;
    return 0 ; 
}