#ifndef LIB_TP_TP
#define LIB_TP_TP

#include <stdint.h>
#include <cstddef>
#include "flag.h"
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

    struct LinkCollision {        // offsets
        uint8_t _p0[0x199F];      // 0x0000
        uint8_t door_collision;   // 0x199F // lock to 0x40 for door storage collisions, lock to 0xF0 for sidehop hovering
        uint8_t chest_collision;  // 0x19A0 // Set to 0xE4 or 0xF4 for chest storage collisions, set to 0x40 to disable collision
    };
    static_assert(sizeof(LinkCollision) == 0x19A1);

    struct LinkDebug {                     // offsets
        Vec3 position;                     // 0x0000
        uint8_t _p0[0xA];                  // 0x000C
        uint16_t facing;                   // 0x0016
        uint8_t _p1[0x44];                 // 0x0018
        float speed;                       // 0x005C
        uint8_t _p2[0x40];                 // 0x0060
        uint8_t current_boots;             // 0x00A0
        uint8_t _p11;                      // 0x00A1
        uint8_t status;                    // 0x00A2
        uint8_t _p3[0x14EF];               // 0x00A3
        bool over_void;                    // 0x1592
        uint8_t _p4[0x64D];                // 0x1593
        bool appears_clawshottable;        // 0x1BE0 // only the visual effect when using clawshot
        uint8_t _p13[0x77E];               // 0x1BE1
        uint8_t held_item_animation;       // 0x235F // 0xF9 for big rock
        uint16_t held_item_collision_ptr;  // 0x2360 // may be more than collision
        uint8_t _p12[0x376];               // 0x2362
        float sand_height_lost;            // 0x26D8
        uint8_t _p5[0x412];                // 0x26DC
        uint8_t air_timer;                 // 0x2AEE
        uint8_t _p6[0x1E];                 // 0x2AEF
        uint8_t current_item;              // 0x2B0D
        uint8_t _p10[0x0A];                // 0x2B0E
        uint16_t current_action_id;        // 0x2B18
        uint8_t _p7[0x28];                 // 0x2B1A
        uint16_t action_value_2;           // 0x2B42
        uint8_t _p8[0x184];                // 0x2B44
        uint32_t action_value_1;           // 0x2CC8
        uint8_t _p9[0x228];                // 0x2CCC
        float last_ground_y_pos_fall;      // 0x2EF4
        float last_ground_y_pos_void;      // 0x2EF8
    };
    static_assert(sizeof(LinkDebug) == 0x2EFC);

    struct GlobalCounters {
        uint32_t game_counter;      // 80430CD8
        uint32_t game_counter2;     // 80430CDC
        uint32_t non_menu_counter;  // 80430CE0
    };
    static_assert(sizeof(GlobalCounters) == 0xC);

    struct EponaDebug {
        uint8_t _p0[0x4CF];  // 0x0000
        Vec3 position;       // 0x04D0
    };
    static_assert(sizeof(EponaDebug) == 0x04DC);

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
        uint8_t _p10;                                // 80406384
        Epona::Filename epona_filename;              // 80406385
        uint8_t _p11[0x28];                          // 80406395
        Minimap::Warps warps;                        // 804063BD
        uint8_t _p23[0x174];                         // 804064FF
        Dungeon::CityInTheSky::Flags flags;          // 80406673
        uint8_t _p54[0x338];                         // 8040667D
        uint8_t epona_stolen_and_midna_charge_flag;  // 804069B5 // bit 7 sets stolen, bit 0 gives midna charge
        uint8_t epona_tamed_and_map_warp_flag;       // 804069B6 // bit 0 sets tamed, bit 2 sets map warp
        uint8_t _p24[0x03];                          // 804069B7
        uint8_t meteor_warp_enabled;                 // 804069BA // bit 4 enables meteor warp
        uint8_t _p53;                                // 804069BB
        uint8_t midna_on_z;                          // 804069BC // bit 4 sets midna
        uint8_t transform_flag;                      // 804069BD // bit 2 sets transform
        uint8_t _p56[0x06];                          // 804069BE
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
        Flags::TempFlags temp_flags;                 // 80406B14
        Dungeon::CaveOfOrdeals::Floors floors;       // 80406B3C
        uint8_t _p34[0x37];                          // 80406B40
        uint8_t boss_room_event_flags;               // 80406B77
        uint8_t _p63[0xDC];                          // 80406B78
        uint8_t _p51;                                // 80406C54 // end of mem card 1:1 copy
        uint8_t _p52[0x31F];                         // 80406C55 // start of game RAM
        uint8_t respawn_room_id;                     // 80406F74
        uint8_t _p35[0x04];                          // 80406F75
        uint8_t respawn_next_spawn_id;               // 80406F79
        uint16_t respawn_angle;                      // 80406F7A
        Vec3 respawn_position;                       // 80406F7C
        uint8_t event_to_play;                       // 80406F88 // setting this to 0xFF skips most cutscenes
        uint8_t _p36[0x07];                          // 80406F89
        uint8_t respawn_item_id;                     // 80406F90 // the item in link's hand
        bool voided_as_wolf;                         // 80406F91
        uint8_t _p37;                                // 80406F92
        uint8_t respawn_animation;                   // 80406F93
        uint8_t _p38[0x402C];                        // 80406F94
        uint8_t current_stage[8];                    // 8040AFC0
        uint8_t _p39;                                // 8040AFC8
        uint8_t current_spawn_id;                    // 8040AFC9
        uint8_t _p40[0x04];                          // 8040AFCA
        Warp warp;                                   // 8040AFCE
        uint8_t _p42[0xBF];                          // 8040AFDD
        uint16_t cs_val;                             // 8040B09C
        uint8_t _p57[0xCF];                          // 8040B09E
        uint8_t freeze_game;                         // 8040B16D // this is cs event flag, rename later maybe
        uint8_t _p43[0x05];                          // 8040B16E
        uint8_t current_event_id;                    // 8040B173
        uint8_t _p44[0x1C];                          // 8040B174
        bool last_cs_skipped_flag;                   // 8040B190
        uint8_t _p45[0x1B6];                         // 8040B191
        bool lock_camera;                            // 8040B347
        uint8_t _p46[0x23];                          // 8040B348
        uint8_t last_room_id;                        // 8040B36B
        uint8_t _p47[0x50C];                         // 8040B36C
        Momentum *momentum_ptr;                      // 8040B878
        uint8_t _p48[0x6F0];                         // 8040B87C
        LinkCollision *link_collision_ptr;           // 8040BF6C
        uint8_t _p59[0x8];                           // 8040BF70
        EponaDebug *epona_debug_ptr;                 // 8040BF78
        uint8_t _p64[0x2A];                          // 8040BF7C
        uint16_t link_air_meter;                     // 8040BFA2
        uint8_t _p58[0x02];                          // 8040BFA4
        uint16_t link_air_meter_2;                   // 8040BFA6 // appears to be the same as 8040BFA2
        uint8_t _p61[0x02];                          // 8040BFA8
        uint16_t link_max_air_meter;                 // 8040BFAA
        uint8_t _p62[0xCB];                          // 8040BFAC
        uint8_t air_time_depleted;                   // 8040C077
        uint8_t _p100[0x17F58];                      // 8040C078
    } __attribute__((packed));
    // int a = sizeof(GameInfo);
    // 80423fd0 next struct start
    //static_assert(sizeof(GameInfo) == 0x1DE10);

    struct ZelAudio {
        uint8_t _p0[0x4C4];         // 803DBF4C
        uint8_t time_hours;         // 803DC410
        uint8_t time_minutes;       // 803DC411
        uint8_t _p1[0xA42];         // 803DC412
        LinkDebug *link_debug_ptr;  // 803DCE54
        uint8_t _p2[0x480];         // 803DCE58
    };
    static_assert(sizeof(ZelAudio) == 0x138c);

    struct LoadingInfo {
        uint32_t isLoading;  // 80450CE0
        uint8_t _p0[0x04];   // 80450CE4
    };
    static_assert(sizeof(LoadingInfo) == 0x08);

    struct TitleScreenPtr {
        uint8_t _p0[0x59];             // 0x00
        uint8_t trigger_on_next_load;  // 0x59
    };

    struct TitleScreenInfo {
        TitleScreenPtr *title_screen_info;
    };

    struct MatrixPtr {
        uint8_t _p0[0x9C];   // 0x0000
        float camera0;       // 0x009C
        float camera1;       // 0x00A0
        float camera2;       // 0x00A4
        float camera3;       // 0x00A8
        float camera4;       // 0x00AC
        float camera5;       // 0x00B0
        uint8_t _p1[0x134];  // 0x00B4
        float camera6;       // 0x01E8
        uint8_t _p2[0x25C];  // 0x01EC
        float camera7;       // 0x0448
    };

    struct MatrixInfo {
        MatrixPtr *matrix_info;
    };

#define tp_globalCounters (*(TP::GlobalCounters *)(tp_globalCounters_addr))
#define tp_zelAudio (*(TP::ZelAudio *)(tp_zelAudio_addr))
#define tp_gameInfo (*(TP::GameInfo *)(tp_gameInfo_addr))
#define tp_bossFlags (*(uint8_t *)(tp_sConsole_addr + 8))
#define tp_linkRollConstants (*(TP::LinkRollConstants *)(tp_linkRollConstants_addr))
#define tp_fopScnRq (*(TP::LoadingInfo *)(tp_fopScnRq_addr))
#define tp_titleScreenInfo (*(TP::TitleScreenInfo *)(tp_titleScreenPtr_addr))
#define tp_matrixInfo (*(TP::MatrixInfo *)(tp_matrixPtr_addr))

    uint32_t get_frame_count() {
        return tp_globalCounters.game_counter;
    }

    uint8_t get_boss_flags() {
        return tp_bossFlags;
    }

    void set_boss_flags() {
        tp_bossFlags = 0xFF;
    }

    void set_boss_flags(uint8_t value) {
        tp_bossFlags = value;
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

    void set_respawn_angle(uint16_t angle) {
        tp_gameInfo.respawn_angle = angle;
    }

    void set_respawn_position(Vec3 position) {
        tp_gameInfo.respawn_position = position;
    }

    void set_respawn_animation(uint8_t animation_id) {
        tp_gameInfo.respawn_animation = animation_id;
    }

}  // namespace TP

#endif  // LIB_TP_TP