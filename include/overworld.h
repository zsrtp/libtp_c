#ifndef LIB_TP_OVERWORLD
#define LIB_TP_OVERWORLD

#include <stdint.h>
#include "flag.h"

namespace Overworld {
    struct OverworldFlags {
        Flags::GlobalFlags ordon_flags;         // 804063B0
        Flags::GlobalFlags sewers_flags;        // 804063D0
        Flags::GlobalFlags faron_flags;         // 804063F0
        Flags::GlobalFlags eldin_flags;         // 80406410
        Flags::GlobalFlags lanayru_flags;       // 80406430
        uint8_t _p01[0x20];                     // 80406450
        Flags::GlobalFlags hyrule_field_flags;  // 80406470
        Flags::GlobalFlags grove_flags;         // 80406490
        Flags::GlobalFlags snowpeak_flags;      // 804064B0
        Flags::GlobalFlags castle_town_flags;   // 804064D0
        Flags::GlobalFlags desert_flags;        // 804064F0
        Flags::GlobalFlags pond_flags;          // 80406510
    };
    static_assert(sizeof(OverworldFlags) == 0x180);
};      // namespace Overworld

#endif
