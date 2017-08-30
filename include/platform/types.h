#ifndef PLATFORM_TYPES_H_
#define PLATFORM_TYPES_H_

#include <arpa/inet.h>
#include <stdint.h>

typedef in6_addr otIp6Address;

typedef struct {
    uint8_t ok;
} otInstance;

#endif //  PLATFORM_TYPES_H_
