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
};      // namespace Dungeon

#endif
