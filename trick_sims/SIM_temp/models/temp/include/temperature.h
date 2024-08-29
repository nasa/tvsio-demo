/*************************************************************************
PURPOSE: (Do stuff)
**************************************************************************/
#ifndef TEMPERATURE_H
#define TEMPERATURE_H

typedef struct {

    double temp;    /*  degF Temperature */
    double speed;   /*  m/s */
    unsigned int reset_flag;

} TEMP ;

#define TEMP_MSG_SIZE 50
typedef struct {
    char message[TEMP_MSG_SIZE];
} MESSAGE;

#ifdef __cplusplus
extern "C" {
#endif
    int temp_init(TEMP*);
    int temp_process(TEMP*);
    void temp_display(TEMP*);

    void msg_init(MESSAGE*);
    void msg_process(MESSAGE*);
    void msg_display(MESSAGE*);
#ifdef __cplusplus
}
#endif

#endif