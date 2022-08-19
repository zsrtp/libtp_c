#ifndef MSL_STRING_H_
#define MSL_STRING_H_

#include <stdint.h>
#include <cstddef>
#include <cstdarg>

#include "../addrs.h"
#include "../defines.h"

extern "C" {
void* memset(void* addr, int value, uint32_t size);
void* memcpy(void* dest, const void* src, uint32_t size);
int sprintf(char* string, const char* format, ...);
int vsnprintf(char* string, uint32_t n, const char* format, va_list);
char* strcpy(char* dst, const char* src);
size_t strlen(const char* str);
int strcmp(const char* lhs, const char* rhs);
}

#endif