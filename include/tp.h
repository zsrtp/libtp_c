#ifndef LIB_TP_TP
#define LIB_TP_TP

#include <stdint.h>
#include <cstddef>
#include "addrs.h"
#include "inventory.h"
#include "link.h"
#include "utils.h"
#include "warping.h"

namespace TP {
    struct Momentum {
        uint8_t _p0[0x4F8];
        Vec3 link_momentum;
    };

    struct GameInfo {
        Link::Link link;                            // 804061C0
        uint8_t _p0[0x10];                          // 804061E0
        uint8_t midna_on_back_flag;                 // 804061F0 // bit 3 puts midna on back        
        uint8_t _p0[0x0F];                          // 804061F1
        float epona_x_pos;                          // 80406200
        float epona_y_pos;                          // 80406204
        float epona_z_pos;                          // 80406208
        uint16_t epona_angle;                       // 8040620C
        uint8_t epona_stage[8];                     // 8040620E
        uint8_t _p0[0x01];                          // 80406216
        uint8_t epona_room_id;                      // 80406217
        uint8_t player_stage[8];                    // 80406218
        uint8_t player_spawn_id;                    // 80406220
        uint8_t player_room_id;                     // 80406221
        uint8_t _p0[0x10];                          // 80406222
        uint8_t player_previous_stage[0x08];        // 80406232
        uint8_t _p0[0x03];                          // 8040623A
        uint8_t minimap_area_unlocked;              // 8040623D // bits - 0: n/a, 1: ordon, 2: faron, 3: eldin, 4: lanayru, 5: gerudo, 6: snowpeak, 7: n/a   
        uint8_t _p0[0x02];                          // 8040623E
        float ooccoo_x_pos;                         // 80406240
        float ooccoo_y_pos;                         // 80406244
        float ooccoo_z_pos;                         // 80406248
        uint16_t ooccoo_angle;                      // 8040624C
        uint8_t ooccoo_stage[8];                    // 8040624E
        uint8_t _p0[0x01];                          // 80406256
        uint8_t ooccoo_room_id;                     // 80406257
        Inventory::Inventory inventory;             // 8040625C
        uint8_t _p0[0x4C];                          // 804062E0 
        uint16_t fishing_jrnl_hbass_no_caught;      // 8040632C
        uint16_t fishing_jrnl_hloach_no_caught;     // 8040632E
        uint16_t fishing_jrnl_hpike_no_caught;      // 80406330
        uint16_t fishing_jrnl_ocatfish_no_caught;   // 80406332
        uint16_t fishing_jrnl_reekfish_no_caught;   // 80406334
        uint16_t fishing_jrnl_greengill_no_caught;  // 80406336
        uint8_t _p0[0x14];                          // 80406338
        uint8_t fishing_jrnl_hbass_largest;         // 8040634C
        uint8_t fishing_jrnl_hbass_largest;         // 8040634D
        uint8_t fishing_jrnl_hbass_largest;         // 8040634E
        uint8_t fishing_jrnl_hbass_largest;         // 8040634F
        uint8_t fishing_jrnl_hbass_largest;         // 80406350
        uint8_t fishing_jrnl_hbass_largest;         // 80406351
        uint8_t _p0[0x22];                          // 80406352
        uint8_t player_file_name[8];                // 80406374
        uint8_t _p0[0x09];                          // 8040637C
        uint8_t epona_file_name[8];                 // 80406385
        uint8_t _p0[0x30];                          // 8040638D
        uint8_t minimap_ordon_spring_flags;         // 804063BD // bit 4 gives the warp
        uint8_t _p0[0x3D];                          // 804063BE
        uint8_t minimap_nfaron_woods_flags;         // 804063FB // bit 2 gives the warp
        uint8_t _p0[0x07];                          // 804063FC                          
        uint8_t minimap_sfaron_woods_flags;         // 80406403 // bit 7 gives the warp
        uint8_t _p0[0x14];                          // 80406404
        uint8_t minimap_kak_village_flags;          // 80406418 // bit 7 gives the warp
        uint8_t minimap_death_mountain_flags;       // 80406419 // bit 5 gives the warp
        uint8_t _p0[0x1F];                          // 8040641A
        uint8_t minimap_uzr_flags;                  // 80406439 // bit 5 gives the warp
        uint8_t minimap_lake_hylia_flags;           // 8040643A // bit 2 gives the warp
        uint8_t minimap_zoras_domain_flags;         // 8040643B // bit 2 gives the warp
        uint8_t _p0[0x3D];                          // 8040643C
        uint8_t minimap_kak_gorge_flags;            // 80406479 // bit 5 gives the warp
        uint8_t _p0[0x01];                          // 8040647A
        uint8_t minimap_castle_town_flags;          // 8040647B // bit 3 gives the warp
        uint8_t _p0[0x00];                          // 8040647C
        uint8_t minimap_eldin_bridge_flags;         // 80406487 // bit 3 gives the warp
        uint8_t _p0[0x00];                          // 80406488
        uint8_t minimap_sacred_grove_flags;         // 804064A7 // bit 4 gives the warp
        uint8_t _p0[0x00];                          // 804064A8
        uint8_t minimap_snowpeak_flags;             // 804064B9 // bit 5 gives the warp
        uint8_t _p0[0x00];                          // 804064BA
        uint8_t minimap_gerudo_mesa_flags;          // 804064F9 // bit 5 gives the warp
        uint8_t _p0[0x00];                          // 804064FA
        uint8_t minimap_mirror_chamber_flags;       // 804064FE // bit 0 gives the warp
        uint8_t _p0[0x00];                          // 804064FF
        uint8_t epona_stolen_and_midna_charge_flag; // 804069B5 // bit 7 sets stolen, bit 0 gives midna charge
        uint8_t epona_tamed_and_map_warp_flag;      // 804069B6 // bit 0 sets tamed, bit 2 sets map warp
        uint8_t _p0[0x00];                          // 804069B7
        uint8_t midna_on_z;                         // 804069BC // bit 4 sets midna
        uint8_t transform_flag;                     // 804069BD // bit 2 sets transform
        uint8_t goron_flag;                         // 804069C4
        uint8_t epona_visible_flag;                 // 804069C5 // bit 7, makes her visible in ordon spring
        uint8_t _p0[0x00];                          // 804069C6
        uint8_t midna_state_flag;                   // 804069CE // bit 3 makes midna healthy
        uint8_t _p0[0x00];                          // 804069CF
        uint8_t dominion_rod_state;                 // 804069D5 // bit 7 controls dominion rod being restored
        uint8_t _p0[0x03];                          // 804069D6
        uint16_t hidden_skills_flags;               // 804069D9
        uint8_t _p0[0x00];                          // 804069DB
        uint8_t have_sense;                         // 804069F3 // bit 3 gives sense
        uint8_t _p0[0x00];                          // 804069F4
        uint8_t cits_physical_chest_flags;          // 80406B1B // controls the chests being physically opened
        uint8_t _p0[0x00];                          // 80406B1C
        uint8_t argorok_bridge_cs_flag;             // 80406B20 // bit 0 controls wheter or not cs has been seen (1 = seen & bridge destroyed)
        uint8_t _p0[0x00];                          // 80406B21
        uint8_t cits_event_flags;                   // 80406B2A
        uint8_t _p0[0x00];                          // 80406B2B
        uint8_t local_area_keys;                    // 80406B34
        uint8_t _p0[0x00];                          // 80406B35
        uint8_t cave_of_ordeals_27_34;              // 80406B3C
        uint8_t cave_of_ordeals_18_26;              // 80406B3D
        uint8_t cave_of_ordeals_09_17;              // 80406B3E
        uint8_t cave_of_ordeals_01_08;              // 80406B3F
        uint8_t _p0[0x00];                          // 80406B40
        uint8_t respawn_room_id;                    // 80406F74
        uint8_t _p0[0x00];                          // 80406F75
        uint8_t respawn_next_spawn_id;              // 80406F79
        uint16_t respawn_angle;                     // 80406F7A
        float respawn_x_pos;                        // 80406F7C
        float respawn_y_pos;                        // 80406F80
        float respawn_z_pos;                        // 80406F84
        uint8_t event_to_play;                      // 80406F88 // setting this to 0xFF skips most cutscenes
        uint8_t _p0[0x00];                          // 80406F89
        uint8_t respawn_item_id;                    // 80406F90 // the item in link's hand
        bool voided_as_wolf;                        // 80406F91
        uint8_t _p0[0x00];                          // 80406F92
        uint8_t current_stage[8];                   // 8040AFC0
        uint8_t _p0[0x00];                          // 8040AFC8
        uint8_t next_stage[8];                      // 8040AFCE
        uint8_t _p0[0x00];                          // 8040AFD6 // FIX ME
        uint8_t current_spawn_id;                   // 8040AFC9 // FIX ME
        uint8_t _p0[0x00];                          // 8040AFCA // FIX ME
        uint8_t next_spawn_id;                      // 8040AFD7 // works similar to 80406F79
        uint8_t next_room_id;                       // 8040AFD8
        uint8_t next_state_id;                      // 8040AFD9
        Warp warp;                                  // 8040AFCE
        uint8_t _p2[0x190];                         // 8040AFDD
        uint8_t freeze_game;                        // 8040B16D // this is cs event flag bool, fix later
        uint8_t _p3[0x1FD];                         // 8040B16E
        uint8_t current_event_id;                   // 8040B173
        uint8_t _p0[0x00];                          // 8040B174
        bool last_cs_skipped_flag;                  // 8040B190
        uint8_t _p0[0x00];                          // 8040B191
        bool lock_camera;                           // 8040B347 
        uint8_t _p0[0x00];                          // 8040B348
        uint8_t last_room_id;                       // 8040B36B
        uint8_t _p0[0x00];                          // 8040B36C
        Momentum *momentum_ptr;                     // 8040B878
        uint8_t _p4[0x726];                         // 8040B87C
        uint16_t link_air_meter;                    // 8040BFA2

        // 80423FCF last prop
    };

    struct GlobalCounters {
        uint32_t game_counter;
        uint32_t game_counter2;
        uint32_t non_menu_counter;
    };

    struct LinkDebug {
        Vec3 position;
        uint8_t _p0[0xA];
        uint16_t facing;
        uint8_t _p1[0x44];
        float speed;
    };

    struct ZelAudio {
        uint8_t _p0[0x4C4];         // 803DBF4C
        uint8_t time_hours;         // 803DC410
        uint8_t time_minutes;       // 803DC411
        uint8_t _p1[0xA42];         // 803DC412
        LinkDebug *link_debug_ptr;  // 803DCE54
    };

    struct LinkRollConstants {
        uint8_t _p0[0x48];
        float roll_factor;
    };

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