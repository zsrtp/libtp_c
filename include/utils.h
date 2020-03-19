#ifndef LIB_TP_UTIL
#define LIB_TP_UTIL

struct Vec3 {
    float x, y, z;
};
static_assert(sizeof(Vec3) == 0xC);

struct CameraMatrix {
    float c0, c1, c2, c3, c4, c5, c6, c7;
};
static_assert(sizeof(CameraMatrix) == 0x20);

#endif  // LIB_TP_UTIL