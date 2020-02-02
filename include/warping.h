#ifndef LIB_TP_WARPING
#define LIB_TP_WARPING

#include <stdint.h>

struct Entrance {
    uint8_t stage[8];   // 8040AFCE
    uint8_t void_flag;  // 8040AFD6
    uint8_t spawn;      // 8040AFD7
    uint8_t room;       // 8040AFD8
    uint8_t state;      // 8040AFD9
};
static_assert(sizeof(Entrance) == 12);

struct Warp {
    Entrance entrance;  // 8040AFCE
    uint8_t _p0[2];     // 8040AFDA
    bool enabled;       // 8040AFDC
};
static_assert(sizeof(Warp) == 15);

#endif  // LIB_TP_WARPING