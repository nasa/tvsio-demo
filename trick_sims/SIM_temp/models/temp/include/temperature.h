/*************************************************************************
PURPOSE: (Do stuff)
**************************************************************************/
#ifndef TEMPERATURE_H
#define TEMPERATURE_H

typedef struct {

    double temp;    /*  degF Temperature */
    unsigned int reset_flag;

} TEMP ;

#ifdef __cplusplus
extern "C" {
#endif
    int temp_init(TEMP*);
    int temp_process(TEMP*);
    void temp_display(TEMP*);
#ifdef __cplusplus
}
#endif

#endif