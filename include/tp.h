#ifndef LIB_TP_TP
#define LIB_TP_TP

#include <stdint.h>
#include <cstddef>
#include "flag.h"
#include "addrs.h"
#include "cave.h"
#include "dungeon.h"
#include "epona.h"
#include "inventory.h"
#include "link.h"
#include "minimap.h"
#include "ooccoo.h"
#include "overworld.h"
#include "player.h"
#include "utils.h"
#include "warping.h"
template <size_t S> class Sizer { };

namespace TP {
    struct Momentum {
        uint8_t _p0[0x4F8];
        Vec3 link_momentum;
    };
    static_assert(sizeof(Momentum) == 0x504);

#ifdef WII_NTSCU_10
    struct LinkCollision {             // offsets
        uint8_t _p0[0x570];            // 0x0000
        uint16_t invincibility_timer;  // 0x0570
        uint8_t _p1[0x1430];           // 0x0572 // TODO check the alignment for the next attributes
        uint8_t door_collision;        // 0x199F // lock to 0x40 for door storage collisions, lock to 0xF0 for sidehop hovering
        uint8_t chest_collision;       // 0x19A0 // Set to 0xE4 or 0xF4 for chest storage collisions, set to 0x40 to disable collision
    };
    static_assert(sizeof(LinkCollision) == 0x19a4);
#else
    struct LinkCollision {             // offsets
        uint8_t _p0[0x56C];            // 0x0000
        uint16_t invincibility_timer;  // 0x056C
        uint8_t _p1[0x1430];           // 0x056D
        uint8_t door_collision;        // 0x199E // lock to 0x40 for door storage collisions, lock to 0xF0 for sidehop hovering
        uint8_t chest_collision;       // 0x199F // Set to 0xE4 or 0xF4 for chest storage collisions
        uint8_t no_collision;          // 0x19A0 // Set to 0x40 to disable collision
    };
    static_assert(sizeof(LinkCollision) == 0x19A2);
#endif

#ifdef GCN_PLATFORM
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
        uint8_t _p4[0x574];                // 0x1593
        uint8_t unk_attack_1;              // 0x1B07
        uint8_t _p15[0x03];                // 0x1B08
        uint8_t unk_attack_2;              // 0x1B0B
        uint8_t _p14[0xD4];                // 0x1B0C
        bool appears_clawshottable;        // 0x1BE0 // only the visual effect when using clawshot
        uint8_t _p13[0x77E];               // 0x1BE1
        uint8_t held_item_animation;       // 0x235F // 0xF9 for big rock
        uint16_t held_item_collision_ptr;  // 0x2360 // may be more than collision
        uint8_t _p12[0x376];               // 0x2362
        float sand_height_lost;            // 0x26D8
        uint8_t _p5[0x412];                // 0x26DC
        uint8_t air_timer;                 // 0x2AEE
        uint8_t _p6[0x1D];                 // 0x2AEF -> 0x2AF7
        uint16_t current_item;              // 0x2B0D
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
#endif

#ifdef WII_NTSCU_10
    struct LinkDebug {                     // offsets
        Vec3 position;                     // 0x0000
        uint8_t _p0[0xA];                  // 0x000C
        uint16_t facing;                   // 0x0016
        uint8_t _p1[0x44];                 // 0x0018
        float speed;                       // 0x005C
        uint8_t _p2[0x40];                 // 0x0060
        uint8_t _p2_2[0x4];
        uint8_t current_boots;             // 0x00A0
        uint8_t _p11;                      // 0x00A1
        uint8_t status;                    // 0x00A2
        uint8_t _p3[0x14EF];               // 0x00A3
        bool over_void;                    // 0x1592
        uint8_t _p4[0x574];                // 0x1593
        uint8_t unk_attack_1;              // 0x1B07
        uint8_t _p15[0x03];                // 0x1B08
        uint8_t unk_attack_2;              // 0x1B0B
        float link_animation_speed;        //           0x1B10
        uint8_t _p14[0xA4];                // 0x1B0C -> 0x1B14
        bool show_aim_pointer;             //           0x1BB8
        bool appears_clawshottable;        // 0x1BE0 // only the visual effect when using clawshot
        uint8_t _p14_2;                    //           0x1BBA
        bool appears_targetable;           //           0x1BBB // only the visual effect when using Gale
        uint8_t _p13[0x7A8];               // 0x1BE1 -> 0x1BBC
        uint32_t held_item_animation;      // 0x235F -> 0x2364 // 0xF9 for big rock
        uint32_t held_item_collision_ptr;  // 0x2360 -> 0x2368 // may be more than collision
        uint8_t _p12[0x374];               // 0x2362 -> 0x236C
        float sand_height_lost;            // 0x26D8 -> 0x26E0
        uint8_t _p5[0x412];                // 0x26DC
        uint8_t air_timer;                 // 0x2AEE
        uint8_t _p6[0x1D];                 // 0x2AEF -> 0x2AF7
        uint16_t current_item;              // 0x2B0D
        uint8_t _p10[0x0A];                // 0x2B0E
        uint16_t current_action_id;        // 0x2B18
        uint8_t _p7[0x28];                 // 0x2B1A
        uint16_t action_value_2;           // 0x2B42
        uint8_t _p8[0xB6];                 // 0x2B44 -> 0x2B4C
        uint16_t idle_timer;               //           0x2C02
        uint8_t _p8_1[0xCC];               //           0x2C04
        uint32_t action_value_1;           // 0x2CC8
        uint8_t _p8_2[0x4];                //           0x2CD4
        uint32_t equipped_item_usable;     //           0x2CD8 // bit 2 sets if buttons are globaly enabled
        uint8_t _p9[0x25C];                // 0x2CCC -> 0x2CDC
        float last_ground_y_pos_fall;      // 0x2EF4
        float last_ground_y_pos_void;      // 0x2EF8
    };
    static_assert(sizeof(LinkDebug) == 0x2F40);
#endif

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

#ifdef GCN_PLATFORM
    struct LinkTunic {
        uint8_t _p0[0x32A0];          // 0x0000
        int16_t tunic_top_red;       // 0x32A0
        int16_t tunic_top_green;     // 0x32A2
        int16_t tunic_top_blue;      // 0x32A4
        int16_t tunic_top_unk;       // 0x32A6 // might be a timer?
        int16_t tunic_bottom_red;    // 0x32A8
        int16_t tunic_bottom_green;  // 0x32AA
        int16_t tunic_bottom_blue;   // 0x32AC
        int16_t tunic_bottom_unk;    // 0x32AE // might be a timer?
    };
#endif
#ifdef WII_NTSCU_10
    struct LinkTunic {
        uint8_t _p0[0x32A8];          // 0x0000
        int16_t tunic_top_red;        // 0x32A8
        int16_t tunic_top_green;      // 0x32AA
        int16_t tunic_top_blue;       // 0x32AC
        int16_t tunic_top_unk;        // 0x32AE // might be a timer?
        int16_t tunic_bottom_red;     // 0x32B0
        int16_t tunic_bottom_green;   // 0x32B2
        int16_t tunic_bottom_blue;    // 0x32B4
        int16_t tunic_bottom_unk;     // 0x32B6 // might be a timer?
        int16_t not_tunic_red;        // 0x32B8 // when non 0, overwrites tunic_top and tunic_bottom with tunic and not_tunic
        int16_t not_tunic_green;      // 0x32BA
        int16_t not_tunic_blue;       // 0x32BC
        int16_t not_tunic_unk;        // 0x32BE
        int16_t tunic_red;            // 0x32C0
        int16_t tunic_green;          // 0x32C2
        int16_t tunic_blue;           // 0x32C4
        int16_t tunic_unk;            // 0x32C6
    };
#endif

#ifdef GCN_PLATFORM
    struct GameInfo {
        Link::Link link;                             // 804061C0 // mem card 1:1 copy starts here
        uint8_t _p0[0x10];                           // 804061E0
        uint8_t midna_on_back_flag;                  // 804061F0 // bit 3 puts midna on back, bit 1 gets set when first time wolf
        uint8_t _p1[0x03];                           // 804061F1
        float raw_game_time;                         // 804061F4 // used to determine hours/minutes in ZelAudio. range is 0.0 - 360.0, 90.0 - 285.0 is day, 285.0 - 90.0 is night.
        uint8_t _unk0[0x08];                         // 804061F8
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
        uint8_t _p11[0x1B];                          // 80406395
        Overworld::OverworldFlags overworld_flags;   // 804063B0
        uint8_t _p23[0x80];                          // 80406530
        Dungeon::DungeonFlags dungeon_flags;         // 804065B0
        Cave::CaveFlags cave_flags;                  // 804066D0
        uint8_t _p55[0x280];                         // 80406730
        Flags::EventFlags event_flags;               // 804069B0
        Flags::TempFlags temp_flags;                 // 80406B14
        Dungeon::danBit dungeon_temp_flags;          // 80406B38
        uint8_t _p34[0x3];                           // 80406B74
        uint8_t boss_room_event_flags;               // 80406B77
        uint8_t _p63[0xDC];                          // 80406B78
        uint8_t _p51;                                // 80406C54 // end of mem card 1:1 copy
        uint8_t _p52[0x31F];                         // 80406C55 // start of game RAM
        uint8_t respawn_room_id;                     // 80406F74
        uint8_t _p35[0x04];                          // 80406F75
        uint8_t special_spawn_id;                    // 80406F79 // used by things like spawning in boat in lake hylia
        uint16_t respawn_angle;                      // 80406F7A
        Vec3 respawn_position;                       // 80406F7C
        uint8_t event_to_play;                       // 80406F88 // setting this to 0xFF skips most cutscenes
        uint8_t _p66[0x03];                          // 80406F89
        float spawn_speed;                           // 80406F8C
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
        uint8_t loading_animation;                   // 8040AFDD
        uint8_t _p42[0xBE];                          // 8040AFDE
        uint16_t cs_val;                             // 8040B09C
        uint8_t _p57[0xCF];                          // 8040B09E
        uint8_t freeze_game;                         // 8040B16D // this is cs event flag, rename later maybe
        uint8_t _p43[0x05];                          // 8040B16E
        uint8_t current_event_id;                    // 8040B173
        uint8_t _p44[0x1C];                          // 8040B174
        bool last_cs_skipped_flag;                   // 8040B190
        uint8_t _p45[0x1B3];                         // 8040B191
        uint32_t lock_camera;                        // 8040B344
        uint8_t _p46[0x23];                          // 8040B348
        uint8_t last_room_id;                        // 8040B36B -> 80497AD7
        uint8_t _p47[0x50C];                         // 8040B36C -> 80497AD8
        Momentum *momentum_ptr;                      // 8040B878 -> 80497FE4
        uint8_t _p48[0x330];                         // 8040B87C
        uint8_t target_mode;                         // 8040BBAC // all the bits except the bit 0 and the bit 4 (they self reset to 0) keep their value if we modify them, but only the bit 5 seem to have an effect (target mode), and setting bit 4 resets the bit 5 to 0
        uint8_t _p54[0x3BF];                         // 8040BBAD
        LinkCollision *link_collision_ptr;           // 8040BF6C -> 804986E4
        uint8_t _p59[0x4];                           // 8040BF70
        LinkTunic *link_tunic_ptr;                   // 8040BF74
        EponaDebug *epona_debug_ptr;                 // 8040BF78
        uint8_t _p64[0x26];                          // 8040BF7C
        uint16_t link_air_meter;                     // 8040BFA2 -> 8049871A
        uint8_t _p58[0x02];                          // 8040BFA4
        uint16_t link_air_meter_2;                   // 8040BFA6 // appears to be the same as 8040BFA2
        uint8_t _p61[0x02];                          // 8040BFA8
        uint16_t link_max_air_meter;                 // 8040BFAA
        uint8_t _p62[0xCB];                          // 8040BFAC
        uint8_t air_time_depleted;                   // 8040C077
        uint8_t _p100[0x17F58];                      // 8040C078
    };
    // int a = sizeof(GameInfo);
    // 80423fd0 next struct start
    //static_assert(sizeof(GameInfo) == 0x1DE10);
#endif
#ifdef WII_PLATFORM
    struct GameInfo {
        Link::Link link;                             // 804061C0 // mem card 1:1 copy starts here
        uint8_t _p0[0x10];                           // 804061E0
        uint8_t midna_on_back_flag;                  // 804061F0 // bit 3 puts midna on back, bit 1 gets set when first time wolf
        uint8_t _p1[0x03];                           // 804061F1
        float raw_game_time;                         // 804061F4 // used to determine hours/minutes in ZelAudio. range is 0.0 - 360.0, 90.0 - 285.0 is day, 285.0 - 90.0 is night.
        uint8_t _unk0[0x08];                         // 804061F8
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
        uint8_t _p11[0x0D];                          // 80406395 -> 80492AFD
        bool lockon_type;                            //             80492B0A // 0 : hold, 1 : switch
        uint8_t _p12[0x03];                          //             80492B0B
        uint16_t hori_pointer_calib;                 //             80492B0E // Default is 0x015E
        uint8_t vert_pointer_calib;                  //             80492B10 // Default is 0x00
        bool icon_shortcut;                          //             80492B11
        bool camera_control;                         //             80492B12 // 0 : normal, 1 : inverted
        bool pointer;                                //             80492B13
        uint8_t _p14[0x04];                          //             80492B14
        Overworld::OverworldFlags overworld_flags;   // 804063B0
        uint8_t _p23[0x80];                          // 80406530
        Dungeon::DungeonFlags dungeon_flags;         // 804065B0
        Cave::CaveFlags cave_flags;                  // 804066D0
        uint8_t _p55[0x280];                         // 80406730
        Flags::EventFlags event_flags;               // 804069B0
        Flags::TempFlags temp_flags;                 // 80406B14
        uint8_t area_id;                             // 80406B38
        uint8_t _p65[0x03];                          // 80406B39
        Cave::CaveOfOrdeals::Floors floors;          // 80406B3C
        uint8_t _p34[0x37];                          // 80406B40
        uint8_t boss_room_event_flags;               // 80406B77
        uint8_t _p63[0xDC];                          // 80406B78
        uint8_t _p51;                                // 80406C54 // end of mem card 1:1 copy
        uint8_t _p52[0x31F];                         // 80406C55 // start of game RAM
        uint8_t respawn_room_id;                     // 80406F74
        uint8_t _p35[0x04];                          // 80406F75
        uint8_t special_spawn_id;                    // 80406F79 // used by things like spawning in boat in lake hylia
        uint16_t respawn_angle;                      // 80406F7A
        Vec3 respawn_position;                       // 80406F7C
        uint8_t event_to_play;                       // 80406F88 // setting this to 0xFF skips most cutscenes
        uint8_t _p66[0x03];                          // 80406F89
        float spawn_speed;                           // 80406F8C
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
        uint8_t loading_animation;                   // 8040AFDD
        uint8_t _p42[0xBE];                          // 8040AFDE
        uint16_t cs_val;                             // 8040B09C
        uint8_t _p57[0xCF];                          // 8040B09E
        uint8_t freeze_game;                         // 8040B16D // this is cs event flag, rename later maybe
        uint8_t _p43[0x05];                          // 8040B16E
        uint8_t current_event_id;                    // 8040B173
        uint8_t _p44[0x1C];                          // 8040B174
        uint32_t cs_skip_counter;                    // 8040B190 -> 804978F8
        uint8_t _p45[0x1B4];                         // 8040B191 -> 804978FC
        uint32_t lock_camera;                        // 8040B344
        uint8_t _p46[0x23];                          // 8040B348
        uint8_t last_room_id;                        // 8040B36B -> 80497AD7
        uint8_t _p47[0x50C];                         // 8040B36C -> 80497AD8
        Momentum *momentum_ptr;                      // 8040B878 -> 80497FE4
        uint8_t _p48[0x330];                         // 8040B87C
        uint8_t target_mode;                         // 8040BBAC // all the bits except the bit 0 and the bit 4 (they self reset to 0) keep their value if we modify them, but only the bit 5 seem to have an effect (target mode), and setting bit 4 resets the bit 5 to 0
        uint8_t _p54[0x3CB];                         // 8040BBAD
        LinkCollision *link_collision_ptr;           // 8040BF6C -> 804986E4
        uint8_t _p59[0x4];                           // 8040BF70
        LinkTunic *link_tunic_ptr;                   // 8040BF74
        EponaDebug *epona_debug_ptr;                 // 8040BF78
        uint8_t _p64[0x26];                          // 8040BF7C
        uint16_t link_air_meter;                     // 8040BFA2 -> 8049871A
        uint8_t _p58[0x02];                          // 8040BFA4
        uint16_t link_air_meter_2;                   // 8040BFA6 // appears to be the same as 8040BFA2
        uint8_t _p61[0x02];                          // 8040BFA8
        uint16_t link_max_air_meter;                 // 8040BFAA
        uint8_t _p62[0xCB];                          // 8040BFAC
        uint8_t air_time_depleted;                   // 8040C077
        uint8_t _p100[0x17F58];                      // 8040C078
    };
    // int a = sizeof(GameInfo);
    // 80423fd0 next struct start
    //static_assert(sizeof(GameInfo) == 0x1DE10);
#endif

#ifdef GCN_PLATFORM
    struct ZelAudio {
        uint8_t _p0[0x454];                      // 803DBF4C
        float bg_audio;                          // 803DC3A0
        uint8_t _p1[0x6C];                       // 803DC3A4
        uint8_t time_hours;                      // 803DC410
        uint8_t time_minutes;                    // 803DC411
        uint8_t day_of_week;                     // 803DC412
        uint8_t _p22[0x89];                      // 803DC413
        float menu_sfx_volume;                   // 803DC49C
        float menu_sfx_reverb;                   // 803DC4A0
        float menu_sfx_speed;                    // 803DC4A4
        float menu_sfx_lr_stereo;                // 803DC4A8
        uint8_t _p4[0x5C];                       // 803DC4AC
        float link_voice_volume;                 // 803DC508
        float link_voice_reverb;                 // 803DC50C
        float link_voice_speed;                  // 803DC510
        float link_voice_lr_stereo;              // 803DC514
        uint8_t _p5[0x5C];                       // 803DC518
        float item_sfx_volume;                   // 803DC574
        float item_sfx_reverb;                   // 803DC578
        float item_sfx_speed;                    // 803DC57C
        float item_sfx_lr_stereo;                // 803DC580
        uint8_t _p6[0x5C];                       // 803DC584
        float link_idle_sfx_volume;              // 803DC5E0
        float link_idle_sfx_reverb;              // 803DC5E4
        float link_idle_sfx_speed;               // 803DC5E8
        float link_idle_lr_stereo;               // 803DC5EC
        uint8_t _p7[0x5C];                       // 803DC5F0
        float item_recoil_sfx_volume;            // 803DC64C
        float item_recoil_sfx_reverb;            // 803DC650
        float item_recoil_sfx_speed;             // 803DC654
        float item_recoil_sfx_lr_stereo;         // 803DC658
        uint8_t _p8[0x5C];                       // 803DC65C
        float npc_volume;                        // 803DC6B8
        float npc_reverb;                        // 803DC6BC
        float npc_speed;                         // 803DC6C0
        float npc_lr_stereo;                     // 803DC6C4
        uint8_t _p9[0x5C];                       // 803DC6C8
        float midna_sfx_volume;                  // 803DC724
        float midna_sfx_reverb;                  // 803DC728
        float midna_sfx_speed;                   // 803DC72C
        float midna_sfx_lr_stereo;               // 803DC730
        uint8_t _p10[0x5C];                      // 803DC734
        float enemy_sfx_volume;                  // 803DC790
        float enemy_sfx_reverb;                  // 803DC794
        float enemy_sfx_speed;                   // 803DC798
        float enemy_sfx_lr_stereo;               // 803DC79C
        uint8_t _p11[0x5C];                      // 803DC7A0
        float env_sfx_volume;                    // 803DC7FC
        float env_sfx_reverb;                    // 803DC800
        float env_sfx_speed;                     // 803DC804
        float env_sfx_stereo;                    // 803DC808
        uint8_t _p12[0x5C];                      // 803DC80C
        float weather_sfx_stereo;                // 803DC868
        float weather_sfx_reverb;                // 803DC86C
        float weather_sfx_speed;                 // 803DC870
        float weather_sfx_lr_stereo;             // 803DC874
        uint8_t _p13[0x5C];                      // 803DC878
        float unk1_volume;                       // 803DC8D4
        float unk1_reverb;                       // 803DC8D8
        float unk1_speed;                        // 803DC8DC
        float unk1_lr_stereo;                    // 803DC8E0
        uint8_t _p14[0x5C];                      // 803DC8E4
        float unk2_volume;                       // 803DC940
        float unk2_reverb;                       // 803DC944
        float unk2_speed;                        // 803DC948
        float unk2_lr_stereo;                    // 803DC94C
        uint8_t _p15[0x5C];                      // 803DC950
        float unk3_volume;                       // 803DC9AC
        float unk3_reverb;                       // 803DC9B0
        float unk3_speed;                        // 803DC9B4
        float unk3_lr_stereo;                    // 803DC9B8
        uint8_t _p16[0x5C];                      // 803DC9BC
        float unk4_volume;                       // 803DCA18
        float unk4_reverb;                       // 803DCA1C
        float unk4_speed;                        // 803DCA20
        float unk4_lr_stereo;                    // 803DCA24
        uint8_t _p17[0x5C];                      // 803DCA28
        float unk5_volume;                       // 803DCA84
        float unk5_reverb;                       // 803DCA88
        float unk5_speed;                        // 803DCA8C
        float unk5_lr_stereo;                    // 803DCA90
        uint8_t _p18[0x5C];                      // 803DCA94
        float unk6_volume;                       // 803DCAF0
        float unk6_reverb;                       // 803DCAF4
        float unk6_speed;                        // 803DCAF8
        float unk6_lr_stereo;                    // 803DCAFC
        uint8_t _p19[0x54];                      // 803DCB00
        float pause_button_volume;               // 803DCB54
        float pause_button_reverb;               // 803DCB58
        float pause_button_speed;                // 803DCB5C
        float pause_button_lr_stereo;            // 803DCB60
        uint8_t _p20[0x54];                      // 803DCB64
        float enemy_bg_music_volume;             // 803DCBB8
        float enemy_bg_music_reverb;             // 803DCBBC
        float enemy_bg_music_speed;              // 803DCBC0
        float enemy_bg_music_lr_stereo;          // 803DCBC4
        uint8_t _p21[0x54];                      // 803DCBC8
        float hyrule_castle_bg_music_volume;     // 803DCC1C
        float hyrule_castle_bg_music_reverb;     // 803DCC20
        float hyrule_castle_bg_music_speed;      // 803DCC24
        float hyrule_castle_bg_music_lr_stereo;  // 803DCC28
        uint8_t _p3[0x228];                      // 803DCC2C
        LinkDebug *link_debug_ptr;               // 803DCE54 -> 8044B5CC
        uint8_t _p2[0x47C];                      // 803DCE58
    };

    // alignment padding is being a pain
    // static_assert(sizeof(ZelAudio) == 0x1390);
#endif

#ifdef WII_PLATFORM
    struct ZelAudio {
        uint8_t _p0[0x468];                      // 803DBF4C -> 8044a6ac // TODO recheck all wii alignment for ZelAudio
        float bg_audio;                          // 803DC3A0
        uint8_t _p1[0x6C];                       // 803DC3A4
        uint8_t time_hours;                      // 803DC410
        uint8_t time_minutes;                    // 803DC411
        uint8_t day_of_week;                     // 803DC412
        uint8_t _p22[0x89];                      // 803DC413
        float menu_sfx_volume;                   // 803DC49C
        float menu_sfx_reverb;                   // 803DC4A0
        float menu_sfx_speed;                    // 803DC4A4
        float menu_sfx_lr_stereo;                // 803DC4A8
        uint8_t _p4[0x5C];                       // 803DC4AC
        float link_voice_volume;                 // 803DC508
        float link_voice_reverb;                 // 803DC50C
        float link_voice_speed;                  // 803DC510
        float link_voice_lr_stereo;              // 803DC514
        uint8_t _p5[0x5C];                       // 803DC518
        float item_sfx_volume;                   // 803DC574
        float item_sfx_reverb;                   // 803DC578
        float item_sfx_speed;                    // 803DC57C
        float item_sfx_lr_stereo;                // 803DC580
        uint8_t _p6[0x5C];                       // 803DC584
        float link_idle_sfx_volume;              // 803DC5E0
        float link_idle_sfx_reverb;              // 803DC5E4
        float link_idle_sfx_speed;               // 803DC5E8
        float link_idle_lr_stereo;               // 803DC5EC
        uint8_t _p7[0x5C];                       // 803DC5F0
        float item_recoil_sfx_volume;            // 803DC64C
        float item_recoil_sfx_reverb;            // 803DC650
        float item_recoil_sfx_speed;             // 803DC654
        float item_recoil_sfx_lr_stereo;         // 803DC658
        uint8_t _p8[0x5C];                       // 803DC65C
        float npc_volume;                        // 803DC6B8
        float npc_reverb;                        // 803DC6BC
        float npc_speed;                         // 803DC6C0
        float npc_lr_stereo;                     // 803DC6C4
        uint8_t _p9[0x5C];                       // 803DC6C8
        float midna_sfx_volume;                  // 803DC724
        float midna_sfx_reverb;                  // 803DC728
        float midna_sfx_speed;                   // 803DC72C
        float midna_sfx_lr_stereo;               // 803DC730
        uint8_t _p10[0x5C];                      // 803DC734
        float enemy_sfx_volume;                  // 803DC790
        float enemy_sfx_reverb;                  // 803DC794
        float enemy_sfx_speed;                   // 803DC798
        float enemy_sfx_lr_stereo;               // 803DC79C
        uint8_t _p11[0x5C];                      // 803DC7A0
        float env_sfx_volume;                    // 803DC7FC
        float env_sfx_reverb;                    // 803DC800
        float env_sfx_speed;                     // 803DC804
        float env_sfx_stereo;                    // 803DC808
        uint8_t _p12[0x5C];                      // 803DC80C
        float weather_sfx_stereo;                // 803DC868
        float weather_sfx_reverb;                // 803DC86C
        float weather_sfx_speed;                 // 803DC870
        float weather_sfx_lr_stereo;             // 803DC874
        uint8_t _p13[0x5C];                      // 803DC878
        float unk1_volume;                       // 803DC8D4
        float unk1_reverb;                       // 803DC8D8
        float unk1_speed;                        // 803DC8DC
        float unk1_lr_stereo;                    // 803DC8E0
        uint8_t _p14[0x5C];                      // 803DC8E4
        float unk2_volume;                       // 803DC940
        float unk2_reverb;                       // 803DC944
        float unk2_speed;                        // 803DC948
        float unk2_lr_stereo;                    // 803DC94C
        uint8_t _p15[0x5C];                      // 803DC950
        float unk3_volume;                       // 803DC9AC
        float unk3_reverb;                       // 803DC9B0
        float unk3_speed;                        // 803DC9B4
        float unk3_lr_stereo;                    // 803DC9B8
        uint8_t _p16[0x5C];                      // 803DC9BC
        float unk4_volume;                       // 803DCA18
        float unk4_reverb;                       // 803DCA1C
        float unk4_speed;                        // 803DCA20
        float unk4_lr_stereo;                    // 803DCA24
        uint8_t _p17[0x5C];                      // 803DCA28
        float unk5_volume;                       // 803DCA84
        float unk5_reverb;                       // 803DCA88
        float unk5_speed;                        // 803DCA8C
        float unk5_lr_stereo;                    // 803DCA90
        uint8_t _p18[0x5C];                      // 803DCA94
        float unk6_volume;                       // 803DCAF0
        float unk6_reverb;                       // 803DCAF4
        float unk6_speed;                        // 803DCAF8
        float unk6_lr_stereo;                    // 803DCAFC
        uint8_t _p19[0x54];                      // 803DCB00
        float pause_button_volume;               // 803DCB54
        float pause_button_reverb;               // 803DCB58
        float pause_button_speed;                // 803DCB5C
        float pause_button_lr_stereo;            // 803DCB60
        uint8_t _p20[0x54];                      // 803DCB64
        float enemy_bg_music_volume;             // 803DCBB8
        float enemy_bg_music_reverb;             // 803DCBBC
        float enemy_bg_music_speed;              // 803DCBC0
        float enemy_bg_music_lr_stereo;          // 803DCBC4
        uint8_t _p21[0x54];                      // 803DCBC8
        float hyrule_castle_bg_music_volume;     // 803DCC1C
        float hyrule_castle_bg_music_reverb;     // 803DCC20
        float hyrule_castle_bg_music_speed;      // 803DCC24
        float hyrule_castle_bg_music_lr_stereo;  // 803DCC28
        uint8_t _p3[0x22C];                      // 803DCC2C -> 8044B3A0
        LinkDebug *link_debug_ptr;               // 803DCE54 -> 8044B5CC
        uint8_t _p2[0x480];                      // 803DCE58 -> 8044B5D0
    };

    // alignment padding is being a pain
    // static_assert(sizeof(ZelAudio) == 0x1390);
#endif

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
        Vec3 target;         // 0x009C
        Vec3 pos;            // 0x00A8
        uint8_t _p1[0x134];  // 0x00B4
        uint16_t camera6;    // 0x01E8 // Seems related to the pitch
        uint8_t _p2[0x25C];  // 0x01EC
        float camera7;       // 0x0448
    };

    struct MatrixInfo {
        MatrixPtr *matrix_info;
    };

    struct RNG {
        int32_t RNG0;
        int32_t RNG1;
        int32_t RNG2;
        int32_t RNG02;
        int32_t RNG12;
        int32_t RNG22;
    };

#ifdef WII_NTSCU_10
    struct HomeMenuSts {
        uint8_t is_visible; //              8053A968 // No idea if it is actually its true purpose, but it seems to work
    };
#endif

#define tp_rng (*(TP::RNG *)(tp_rng_addr))
#define tp_globalCounters (*(TP::GlobalCounters *)(tp_globalCounters_addr))
#define tp_zelAudio (*(TP::ZelAudio *)(tp_zelAudio_addr))
#define tp_gameInfo (*(TP::GameInfo *)(tp_gameInfo_addr))
#define tp_bossFlags (*(uint8_t *)(tp_sConsole_addr + 8))
#define tp_linkRollConstants (*(TP::LinkRollConstants *)(tp_linkRollConstants_addr))
#define tp_fopScnRq (*(TP::LoadingInfo *)(tp_fopScnRq_addr))
#define tp_titleScreenInfo (*(TP::TitleScreenInfo *)(tp_titleScreenPtr_addr))
#define tp_matrixInfo (*(TP::MatrixInfo *)(tp_matrixPtr_addr))
#ifdef WII_PLATFORM
#define tp_homeMenuSts (*(TP::HomeMenuSts *)(tp_homeMenuSts_addr))
#endif

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
