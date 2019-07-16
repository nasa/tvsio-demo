#include <queue>

#include "test_stubs.h"

namespace 
{
    std::queue<uint16_t> cmdCodes;
}

void ClearCmdCodeQueue()
{
    cmdCodes = std::queue<uint16_t>();
}

void PushCommandCode(uint16_t cmdCode)
{
    cmdCodes.push(cmdCode);
}

uint16_t CFE_SB_GetCmdCode(CFE_SB_Msg_t *msg)
{
    if (!cmdCodes.empty())
    {
        uint16_t value = cmdCodes.front();
        cmdCodes.pop();

        return value;
    }

    return 0;
}
