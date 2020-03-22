#ifndef LIB_TP_DUNGEON
#define LIB_TP_DUNGEON

#include <stdint.h>

namespace Dungeon {
    namespace ArbitersGrounds {
        // struct Flags {
        //     
        // };
        // static_assert(sizeof(Flags) == 0x00);
    }; // namespace ArbitersGrounds
    namespace CityInTheSky {
        struct Flags {
            uint8_t flags_1;    // 80406673 // controls chests
            uint8_t _p0[0x07];  // 80406674
            uint8_t flags_2;    // 8040667B // controls first gate
            uint8_t flags_3;    // 8040667C 
        }; // struct Flags

        static_assert(sizeof(Flags) == 0x0A);
    }; // namespace CityInTheSky

    namespace CaveOfOrdeals {
        struct Floors {
            uint8_t floor_27_34; // 80406B3C
            uint8_t floor_18_26; // 80406B3D
            uint8_t floor_09_17; // 80406B3E
            uint8_t floor_01_08; // 80406B3F
        };

        static_assert(sizeof(Floors) == 0x04);
    }; // namespace CaveOfOrdeals
};

#endif