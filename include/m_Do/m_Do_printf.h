#ifndef M_DO_M_DO_PRINTF_H
#define M_DO_M_DO_PRINTF_H

#include <stdint.h>

#include "../addrs.h"

typedef void (*tp_osReport_t)(const char *string, ...);
#define tp_osReport ((tp_osReport_t)tp_osReport_addr)

#endif