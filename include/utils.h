#ifndef LIB_TP_UTIL
#define LIB_TP_UTIL

struct Vec3 {
    float x, y, z;
};
static_assert(sizeof(Vec3) == 0xC);

#endif  // LIB_TP_UTIL