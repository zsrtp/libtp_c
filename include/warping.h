#ifndef LIB_TP_WARPING
#define LIB_TP_WARPING

#include <stdint.h>
#include <stdbool.h>

typedef struct {
    uint8_t stage[8];
    uint8_t _p0;
    uint8_t spawn;
    uint8_t room;
    uint8_t state;
} Entrance;

typedef struct {
    Entrance entrance;
    uint8_t _p0[2];
    bool enabled;
} Warp;

#endif // LIB_TP_WARPING