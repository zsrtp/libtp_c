#ifndef LIB_TP_TIME
#define LIB_TP_TIME

#include <stdint.h>

#include "addrs.h"

typedef void (*tp_setTimePass)(uint8_t flag);
#define tp_setTimePass ((tp_setTimePass)tp_setTimePass_addr)

#endif  // LIB_TP_TIME