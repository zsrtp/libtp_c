#ifndef LIB_TP_CAVE
#define LIB_TP_CAVE

#include <stdint.h>
#include "flag.h"

namespace Cave {
    struct CaveFlags {
        Flags::GlobalFlags cave_flags_1;  // 804066D0
        Flags::GlobalFlags cave_flags_2;  // 804066F0
        Flags::GlobalFlags grotto_flags;  // 80406710
    };
    static_assert(sizeof(CaveFlags) == 0x60);

    namespace CaveOfOrdeals {
        struct Floors {
            uint8_t floor_27_34;  // 80406B3C
            uint8_t floor_18_26;  // 80406B3D
            uint8_t floor_09_17;  // 80406B3E
            uint8_t floor_01_08;  // 80406B3F
        };
        static_assert(sizeof(Floors) == 0x04);
    };  // namespace CaveOfOrdeals
};      // namespace Cave

#endif
