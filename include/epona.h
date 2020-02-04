#ifndef LIB_TP_EPONA
#define LIB_TP_EPONA

#include <stdint.h>

namespace Epona {
    struct Epona {
        float epona_x_pos;             // 80406200
        float epona_y_pos;             // 80406204
        float epona_z_pos;             // 80406208
        uint16_t epona_angle;          // 8040620C
        uint8_t epona_stage[0x08];     // 8040620E
        uint8_t epona_spawn_point_id;  // 80406216
        uint8_t epona_room_id;         // 80406217
    };                                 // struct Epona

    static_assert(sizeof(Epona) == 0x18);

    struct EponaProperty {
        uint8_t _p0[0x04];                        // 8038E5A4
        float link_start_trot_anim_speed;         // 8038E5A8
        uint8_t _p1[0x04];                        // 8038E5AC
        float _p2;                                // 8038E5B0
        float _p3;                                // 8038E5B4
        uint8_t _p4[0x04];                        // 8038E5B8
        float _p5;                                // 8038E5BC
        uint8_t _p6[0x04];                        // 8038E5C0
        float _p7;                                // 8038E5C4
        float _p8;                                // 8038E5C8
        uint8_t _p9[0x04];                        // 8038E5CC
        float link_dash_anim_speed_1;             // 8038E5D0
        float link_dash_anim_speed_2;             // 8038E5D4
        float link_transition_to_dash_ride_anim;  // 8038E5D8
        float _p20;                               // 8038E5DC
        uint8_t _p10[0x04];                       // 8038E5E0
        float _p11;                               // 8038E5E4
        uint8_t _p12[0x04];                       // 8038E5E8
        float _p13;                               // 8038E5EC
        float _p14;                               // 8038E5F0
        uint8_t _p15[0x06];                       // 8038E5F4
        uint16_t dash_cooldown_timer;             // 8038E5FA
        uint8_t _p16[0x04];                       // 8038E5FC
        float _p17;                               // 8038E600
        float _p18;                               // 8038E604
        float wait_before_gallop;                 // 8038E608
        float _p19;                               // 8038E60C
    };                                            // struct EponaProperty

    static_assert(sizeof(EponaProperty) == 0x6C);

    struct Filename {
        uint8_t epona_file_name[0x10];  // 80406385
    };                                  // struct filename

    static_assert(sizeof(Filename) == 0x10);
};  // namespace Epona

#endif  //LIB_TP_EPONA