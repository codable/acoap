#ifndef TYPES_H_
#define TYPES_H_

#include "platform/types.h"

#ifndef CONTAINING_RECORD
#define CONTAINING_RECORD(address, type, field) \
    ((type *)((uint8_t*)(address) - (((size_t)&(((type*)0x01)->field))-0x01)))
#endif /* CONTAINING_RECORD */

struct SockAddr {
    uint16_t mPort;
    otIp6Address mAddr;
};

typedef enum otError
{
    OT_ERROR_NONE,
    OT_ERROR_INVALID_ARGS,
    OT_ERROR_ABORT,
    OT_ERROR_ALREADY,
    OT_ERROR_NO_BUFS,
    OT_ERROR_RESPONSE_TIMEOUT,
    OT_ERROR_NOT_FOUND,
    OT_ERROR_PARSE,
} otError;

#endif //  TYPES_H_
