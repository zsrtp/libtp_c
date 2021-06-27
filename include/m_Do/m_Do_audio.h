#ifndef M_DO_M_DO_AUDIO_H
#define M_DO_M_DO_AUDIO_H

#include <stdint.h>
#include "../dolphin/mtx/vec.h"
#include "../addrs.h"

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
    void* link_debug_ptr;                    // 803DCE54 -> 8044B5CC -> 804334D0
    uint8_t _p2[0x47C];                      // 803DCE58
};
#endif

#ifdef WII_PLATFORM
struct ZelAudio {
    uint8_t _p0[0x468];                      // 803DBF4C -> 8044a6ac -> 804325AC // TODO recheck all wii alignment for ZelAudio
    float bg_audio;                          // 803DC3A0
#ifdef WII_PAL
    uint8_t _p1[0x70];                       // 803DC3A4
#else
    uint8_t _p1[0x6C];                       // 803DC3A4
#endif
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
    void *link_debug_ptr;               // 803DCE54 -> 8044B5CC
    uint8_t _p2[0x480];                      // 803DCE58 -> 8044B5D0
};
#endif

#define tp_zelAudio (*(ZelAudio *)(tp_zelAudio_addr))


// Functions
#ifdef GCN_PLATFORM
typedef void (*mDoAud_seStartLevel_t)(uint32_t, Vec const*, uint32_t, int8_t);
#define mDoAud_seStartLevel ((mDoAud_seStartLevel_t)mDoAud_seStartLevel_addr)

#endif

#endif /* M_DO_M_DO_AUDIO_H */
