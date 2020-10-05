/*************************************************************************
PURPOSE: (Do stuff)
**************************************************************************/
#ifndef RANGE_H
#define RANGE_H

typedef struct {

    double range;      /*  ft range */
    double range_rate; /*  ft/s range rate */

} CONTROL ;

#ifdef __cplusplus
extern "C" {
#endif
    int range_init(CONTROL*);
    int range_process(CONTROL*);
#ifdef __cplusplus
}
#endif

#endif