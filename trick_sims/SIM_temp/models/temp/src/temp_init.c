/******************************* TRICK HEADER ****************************
PURPOSE: (Set the initial data values)
*************************************************************************/

/* Model Include files */
#include "../include/temperature.h"

/* initialization job */
int temp_init( TEMP* T) {
   
    T->temp = 0.0;
    T->speed = 0.0;
    T->reset_flag = 0;
    return 0 ; 
}

void msg_init( MESSAGE* m) {
    for (int i = 0; i < TEMP_MSG_SIZE - 1; i++) {
        m->message[i] = 'A';
    }
    m->message[TEMP_MSG_SIZE] = '\0';
}
