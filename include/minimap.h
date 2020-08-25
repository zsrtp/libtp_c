#ifndef LIB_TP_MINIMAP
#define LIB_TP_MINIMAP

#include <stdint.h>

namespace Minimap {
    struct Region {
        uint8_t area_unlocked;                      // 8040623D // bits - 0: n/a, 1: ordon, 2: faron, 3: eldin, 4: lanayru, 5: gerudo, 6: snowpeak, 7: n/a   
    }; // struct Region

    static_assert(sizeof(Region) == 0x01);
};

#endif // LIB_TP_MINIMAP