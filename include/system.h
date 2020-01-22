#ifndef LIB_TP_SYSTEM
#define LIB_TP_SYSTEM

#include <stdint.h>
#include "addrs.h"

typedef void* (*tp_memalign_t)(int32_t align, uint32_t size);
typedef void (*tp_free_t)(void* addr);
typedef uint32_t (*tp_strlen_t)(const char* string);
typedef void (*tp_osReport_t)(const char* string);

#define tp_memalign ((tp_memalign_t) tp_memalign_addr)
#define tp_free ((tp_free_t) tp_free_addr)
#define tp_strlen ((tp_strlen_t) tp_strlen_addr)

#define malloc(x) tp_memalign(-4, x)
#define free tp_free
#define strlen tp_strlen

#define tp_osReport ((tp_osReport_t) tp_osReport_addr)

#endif // LIB_TP_SYSTEM