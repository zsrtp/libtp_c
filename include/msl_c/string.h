#ifndef MSL_STRING_H_
#define MSL_STRING_H_

#include <stdint.h>
#include <cstddef>

#include "../addrs.h"

typedef void (*tp_memset_t)(void *addr, int value, uint32_t size);
typedef void *(*tp_memalign_t)(int32_t align, uint32_t size);
typedef void *(*tp_memcpy_t)(void *dest, void *src, size_t size);
typedef void (*tp_free_t)(void *addr);
typedef int (*tp_sprintf_t)(const char* string, const char* format, ...);
typedef char* (*tp_strcpy_t)(char* dst, const char* src);
typedef size_t (*tp_strlen_t)(const char* str);
typedef int (*tp_strcmp_t)(const char* lhs, const char* rhs);

#define tp_memset ((tp_memset_t)tp_memset_addr)
#define tp_memalign ((tp_memalign_t)tp_memalign_addr)
#define tp_memcpy ((tp_memcpy_t)tp_memcpy_addr)
#define tp_free ((tp_free_t)tp_free_addr)
#define tp_sprintf ((tp_sprintf_t)tp_sprintf_addr)
#define tp_strcpy ((tp_strcpy_t)tp_strcpy_addr)
#define tp_strlen ((tp_strlen_t)tp_strlen_addr)
#define tp_strcmp ((tp_strcmp_t)tp_strcmp_addr)
#define malloc(x) tp_memalign(-4, x)
#define free tp_free

#endif