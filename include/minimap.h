#ifndef LIB_TP_MINIMAP
#define LIB_TP_MINIMAP

#include <stdint.h>

namespace Minimap {
    struct Warps {
        uint8_t ordon_spring_warp;                  // 804063BD // bit 4 gives the warp
        uint8_t _p12[0x3D];                         // 804063BE
        uint8_t nfaron_woods_warp;                  // 804063FB // bit 2 gives the warp
        uint8_t _p13[0x07];                         // 804063FC                          
        uint8_t sfaron_woods_warp;                  // 80406403 // bit 7 gives the warp
        uint8_t _p14[0x14];                         // 80406404
        uint8_t kak_village_warp;                   // 80406418 // bit 7 gives the warp
        uint8_t death_mountain_warp;                // 80406419 // bit 5 gives the warp
        uint8_t _p15[0x1F];                         // 8040641A
        uint8_t uzr_warp;                           // 80406439 // bit 5 gives the warp
        uint8_t lake_hylia_warp;                    // 8040643A // bit 2 gives the warp
        uint8_t zoras_domain_warp;                  // 8040643B // bit 2 gives the warp
        uint8_t _p16[0x3C];                         // 8040643C
        uint8_t kak_gorge_unk;                      // 80406478
        uint8_t kak_gorge_warp;                     // 80406479 // bit 5 gives the warp
        uint8_t _p17[0x01];                         // 8040647A
        uint8_t castle_town_warp;                   // 8040647B // bit 3 gives the warp
        uint8_t _p18[0x0B];                         // 8040647C
        uint8_t eldin_bridge_warp;                  // 80406487 // bit 3 gives the warp
        uint8_t _p19[0x1F];                         // 80406488
        uint8_t sacred_grove_warp;                  // 804064A7 // bit 4 gives the warp
        uint8_t _p20[0x11];                         // 804064A8
        uint8_t snowpeak_warp;                      // 804064B9 // bit 5 gives the warp
        uint8_t _p21[0x3F];                         // 804064BA
        uint8_t gerudo_mesa_warp;                   // 804064F9 // bit 5 gives the warp
        uint8_t _p22[0x04];                         // 804064FA
        uint8_t mirror_chamber_warp;                // 804064FE // bit 0 gives the warp
    }; // struct Warps

    static_assert(sizeof(Warps) == 0x142);

    struct Region {
        uint8_t area_unlocked;                      // 8040623D // bits - 0: n/a, 1: ordon, 2: faron, 3: eldin, 4: lanayru, 5: gerudo, 6: snowpeak, 7: n/a   
    }; // struct Region

    static_assert(sizeof(Region) == 0x01);
};

#endif // LIB_TP_MINIMAP