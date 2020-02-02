#ifndef LIB_TP_TP
#define LIB_TP_TP

#include <stdint.h>
#include <cstddef>
#include "addrs.h"
#include "dungeon.h"
#include "epona.h"
#include "inventory.h"
#include "link.h"
#include "minimap.h"
#include "ooccoo.h"
#include "player.h"
#include "utils.h"
#include "warping.h"

namespace TP {
    struct Momentum {
        uint8_t _p0[0x4F8];
        Vec3 link_momentum;
    };
    static_assert(sizeof(Momentum) == 0x504);

    struct LinkDebug {
        Vec3 position;
        uint8_t _p0[0xA];
        uint16_t facing;
        uint8_t _p1[0x44];
        float speed;
    };
    static_assert(sizeof(LinkDebug) == 0x60);

    struct GlobalCounters {
        uint32_t game_counter;      // 80430CD8
        uint32_t game_counter2;     // 80430CDC
        uint32_t non_menu_counter;  // 80430CE0
    };
    static_assert(sizeof(GlobalCounters) == 0xC);

    struct GameInfo {
        Link::Link link;                             // 804061C0 // mem card 1:1 copy starts here
        uint8_t _p0[0x10];                           // 804061E0
        uint8_t midna_on_back_flag;                  // 804061F0 // bit 3 puts midna on back, bit 1 gets set when first time wolf
        uint8_t _p1[0x0F];                           // 804061F1
        Epona::Epona epona;                          // 80406200
        Player::Player player;                       // 80406218
        uint8_t _p4[0x03];                           // 8040623A
        Minimap::Region region;                      // 8040623D
        uint8_t _p5[0x02];                           // 8040623E
        Ooccoo::Ooccoo ooccoo;                       // 80406240
        uint8_t _p49[0x04];                          // 80406258
        Inventory::Inventory inventory;              // 8040625C
        uint8_t _p9[0x22];                           // 80406352
        Player::Filename player_filename;            // 80406374
        uint8_t _p10[0x01];                          // 80406384
        Epona::Filename epona_filename;              // 80406385
        uint8_t _p11[0x28];                          // 80406395
        Minimap::Warps warps;                        // 804063BD
        uint8_t _p23[0x174];                         // 804064FF
        Dungeon::CityInTheSky::flags flags;          // 80406673
        uint8_t _p54[0x338];                         // 8040667D
        uint8_t epona_stolen_and_midna_charge_flag;  // 804069B5 // bit 7 sets stolen, bit 0 gives midna charge
        uint8_t epona_tamed_and_map_warp_flag;       // 804069B6 // bit 0 sets tamed, bit 2 sets map warp
        uint8_t _p24[0x03];                          // 804069B7
        uint8_t meteor_warp_enabled;                 // 804069BA // bit 4 enables meteor warp
        uint8_t _p53;                                // 804069BB
        uint8_t midna_on_z;                          // 804069BC // bit 4 sets midna
        uint8_t transform_flag;                      // 804069BD // bit 2 sets transform
        uint8_t goron_flag;                          // 804069C4
        uint8_t epona_visible_flag;                  // 804069C5 // bit 7, makes her visible in ordon spring
        uint8_t _p25[0x08];                          // 804069C6
        uint8_t midna_state_flag;                    // 804069CE // bit 3 makes midna healthy
        uint8_t _p26[0x06];                          // 804069CF
        uint8_t dominion_rod_state;                  // 804069D5 // bit 7 controls dominion rod being restored
        uint8_t _p27[0x03];                          // 804069D6
        uint16_t hidden_skills_flags;                // 804069D9
        uint8_t _p28[0x18];                          // 804069DB
        uint8_t have_sense_flag;                     // 804069F3 // bit 3 gives sense
        uint8_t _p29[0x120];                         // 804069F4
        uint8_t temp_flags_start;                    // 80406B14
        uint8_t _p43[0x22];                          // 80406B19
        uint8_t temp_flags_end;                      // 80406B3B
        Dungeon::CaveOfOrdeals::Floors floors;       // 80406B3C
        uint8_t _p34[0x114];                         // 80406B40
        uint8_t _p51;                                // 80406C54 // end of mem card 1:1 copy
        uint8_t _p52[0x31F];                         // 80406C55 // start of game RAM
        uint8_t respawn_room_id;                     // 80406F74
        uint8_t _p35[0x04];                          // 80406F75
        uint8_t respawn_next_spawn_id;               // 80406F79
        uint16_t respawn_angle;                      // 80406F7A
        float respawn_x_pos;                         // 80406F7C
        float respawn_y_pos;                         // 80406F80
        float respawn_z_pos;                         // 80406F84
        uint8_t event_to_play;                       // 80406F88 // setting this to 0xFF skips most cutscenes
        uint8_t _p36[0x01];                          // 80406F89
        uint8_t respawn_item_id;                     // 80406F90 // the item in link's hand
        bool voided_as_wolf;                         // 80406F91
        uint8_t _p37[0x01];                          // 80406F92
        uint8_t respawn_animation;                   // 80406F93
        uint8_t _p38[0x402C];                        // 80406F94
        uint8_t current_stage[8];                    // 8040AFC0
        uint8_t _p39[0x01];                          // 8040AFC8
        uint8_t current_spawn_id;                    // 8040AFC9
        uint8_t _p40[0x04];                          // 8040AFCA
        Warp warp;                                   // 8040AFCE
        uint8_t _p41[0x01];                          // 8040AFD6
        uint8_t next_spawn_id;                       // 8040AFD7 // works similar to 80406F79
        uint8_t next_room_id;                        // 8040AFD8
        uint8_t next_state_id;                       // 8040AFD9
        uint8_t _p42[0x193];                         // 8040AFDA
        uint8_t freeze_game;                         // 8040B16D // this is cs event flag bool, fix later
        uint8_t _p43[0x1FD];                         // 8040B16E
        uint8_t current_event_id;                    // 8040B173
        uint8_t _p44[0x1C];                          // 8040B174
        bool last_cs_skipped_flag;                   // 8040B190
        uint8_t _p45[0x1B7];                         // 8040B191
        bool lock_camera;                            // 8040B347
        uint8_t _p46[0x23];                          // 8040B348
        uint8_t last_room_id;                        // 8040B36B
        uint8_t _p47[0x50C];                         // 8040B36C
        Momentum *momentum_ptr;                      // 8040B878
        uint8_t _p48[0x726];                         // 8040B87C
        uint16_t link_air_meter;                     // 8040BFA2
    };
    static_assert(sizeof(GameInfo) == 0x5DE4);

    struct ZelAudio {
        uint8_t _p0[0x4C4];         // 803DBF4C
        uint8_t time_hours;         // 803DC410
        uint8_t time_minutes;       // 803DC411
        uint8_t _p1[0xA42];         // 803DC412
        LinkDebug *link_debug_ptr;  // 803DCE54
    };
    static_assert(sizeof(ZelAudio) == 0xF0C);

    struct LinkRollConstants {
        uint8_t _p0[0x48];  // 8038D7BC
        float roll_factor;  // 8038D804
    };
    static_assert(sizeof(LinkRollConstants) == 0x4C);

#define tp_globalCounters (*(TP::GlobalCounters *)(tp_globalCounters_addr))
#define tp_zelAudio (*(TP::ZelAudio *)(tp_zelAudio_addr))
#define tp_gameInfo (*(TP::GameInfo *)(tp_gameInfo_addr))
#define tp_bossFlags (*(uint8_t *)(tp_sConsole_addr + 8))
#define tp_linkRollConstants (*(TP::LinkRollConstants *)(tp_linkRollConstants_addr))

    uint32_t get_frame_count() {
        return tp_globalCounters.game_counter;
    }

    GameInfo *get_game_info() {
        return &tp_gameInfo;
    }

    LinkDebug *get_link_debug() {
        if (tp_zelAudio.link_debug_ptr) {
            return tp_zelAudio.link_debug_ptr;
        } else {
            return NULL;
        }
    }
}  // namespace TP

#endif  //LIB_TP_TP