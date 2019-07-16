#ifndef __CCDD_PROTOBETTER_TEST_STUBS_H__
#define __CCDD_PROTOBETTER_TEST_STUBS_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

typedef struct 
{
    char header[10];
} CFE_SB_Msg_t;

uint16_t CFE_SB_GetCmdCode(CFE_SB_Msg_t *msg);

void ClearCmdCodeQueue();
void PushCommandCode(uint16_t cmdCode);

#ifdef __cplusplus
}
#endif

#endif /* __CCDD_PROTOBETTER_TEST_STUBS_H__ */

