#ifndef LIB_TP_DUNGEON
#define LIB_TP_DUNGEON

#include <stdint.h>
#include "flag.h"

namespace Dungeon {
    struct DungeonFlags {
        Flags::GlobalFlags forest_temple_flags;
        Flags::GlobalFlags goron_mines_flags;
        Flags::GlobalFlags lakebed_flags;
        Flags::GlobalFlags arbiters_flags;
        Flags::GlobalFlags snowpeak_ruins_flags;
        Flags::GlobalFlags temple_of_time_flags;
        Flags::GlobalFlags cits_flags;
        Flags::GlobalFlags palace_flags;
        Flags::GlobalFlags hyrule_castle_flags;
    };
    static_assert(sizeof(DungeonFlags) == 0x120);

    struct danBit {
        /* 0x00 */ int8_t mStageNum;
        /* 0x01 */ uint8_t unk1;
        /* 0x02 */ uint8_t unk2[2];
        /* 0x04 */ uint32_t switch_bitfield[2];
        /* 0x0C */ uint32_t item_bitfield[4];
        /* 0x1C */ int16_t unk28[16];
    }; // size = 0x3C
};      // namespace Dungeon

#endif
