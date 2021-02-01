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
static_assert(sizeof(Entrance) == 0x0C);

#ifdef GCN_PLATFORM
struct Warp {
    Entrance entrance;  // 8040AFCE
    uint8_t _p0[2];     // 8040AFDA
    bool enabled;       // 8040AFDC
};
static_assert(sizeof(Warp) == 0x0F);
#endif
#ifdef WII_PLATFORM
struct Warp {
    Entrance entrance;  // 8040AFCE
    uint8_t _p0;        // 8040AFDA -> 80497742
    bool enabled;       // 8040AFDC -> 80497743
    uint8_t _p1;        // 8040AFDA -> 80497742
};
static_assert(sizeof(Warp) == 0x0F);
#endif

// void set_next_stage(uint8_t new_stage[8]) {
//     Entrance.stage = new_stage;
// }

// void set_next_spawn(uint8_t new_spawn) {
//     Entrance.spawn = new_spawn;
// }

// void set_next_room(uint8_t new_room) {
//     Entrance.room = new_room;
// }
#endif  // LIB_TP_WARPING