#ifndef PLATFORM_H_
#define PLATFORM_H_

#include <string.h>

#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

uint32_t otPlatRandomGet(otInstance *aInstance);

#ifdef __cplusplus
}  // extern "C"
#endif

#endif // PLATFORM_H_
