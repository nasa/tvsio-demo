/******************************* TRICK HEADER ****************************
PURPOSE: (Set the initial data values)
*************************************************************************/

/* Model Include files */
#include "../include/temperature.h"

/* initialization job */
int temp_init( TEMP* T) {
   
    T->temp = 0.0;
    T->reset_flag = 0;
    return 0 ; 
}