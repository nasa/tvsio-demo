/*************************************************************************
PURPOSE: (Do stuff)
**************************************************************************/
#ifndef RANGE_H
#define RANGE_H

typedef struct {

    double range;      /*  ft range */
    double range_rate; /*  ft/s range rate */

} CONTROL ;

typedef struct {

    double temp;    /*  degF Temperature */
    double speed;   /*  m/s  */

} TEMP ;

#ifdef __cplusplus
extern "C" {
#endif
    int range_init(CONTROL*, TEMP*);
    int range_process(CONTROL*);
    int temp_process(TEMP*);
#ifdef __cplusplus
}
#endif

#endif