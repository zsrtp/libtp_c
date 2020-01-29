#ifndef LIB_TP_MINIMAP
#define LIB_TP_MINIMAP

#include <stdint.h>

namespace Minimap {
    struct Flags {
        uint8_t minimap_ordon_spring_flags;         // 804063BD // bit 4 gives the warp
        uint8_t _p12[0x3D];                         // 804063BE
        uint8_t minimap_nfaron_woods_flags;         // 804063FB // bit 2 gives the warp
        uint8_t _p13[0x07];                         // 804063FC                          
        uint8_t minimap_sfaron_woods_flags;         // 80406403 // bit 7 gives the warp
        uint8_t _p14[0x14];                         // 80406404
        uint8_t minimap_kak_village_flags;          // 80406418 // bit 7 gives the warp
        uint8_t minimap_death_mountain_flags;       // 80406419 // bit 5 gives the warp
        uint8_t _p15[0x1F];                         // 8040641A
        uint8_t minimap_uzr_flags;                  // 80406439 // bit 5 gives the warp
        uint8_t minimap_lake_hylia_flags;           // 8040643A // bit 2 gives the warp
        uint8_t minimap_zoras_domain_flags;         // 8040643B // bit 2 gives the warp
        uint8_t _p16[0x3D];                         // 8040643C
        uint8_t minimap_kak_gorge_flags;            // 80406479 // bit 5 gives the warp
        uint8_t _p17[0x01];                         // 8040647A
        uint8_t minimap_castle_town_flags;          // 8040647B // bit 3 gives the warp
        uint8_t _p18[0x0B];                         // 8040647C
        uint8_t minimap_eldin_bridge_flags;         // 80406487 // bit 3 gives the warp
        uint8_t _p19[0x1F];                         // 80406488
        uint8_t minimap_sacred_grove_flags;         // 804064A7 // bit 4 gives the warp
        uint8_t _p20[0x11];                         // 804064A8
        uint8_t minimap_snowpeak_flags;             // 804064B9 // bit 5 gives the warp
        uint8_t _p21[0x3F];                         // 804064BA
        uint8_t minimap_gerudo_mesa_flags;          // 804064F9 // bit 5 gives the warp
        uint8_t _p22[0x04];                         // 804064FA
        uint8_t minimap_mirror_chamber_flags;       // 804064FE // bit 0 gives the warp
    };
};

#endif // LIB_TP_MINIMAP