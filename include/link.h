#ifndef LIB_TP_LINK
#define LIB_TP_LINK

#include <stdint.h>
#include "utils.h"
#include "addrs.h"

namespace Link {
    struct Link {
        uint8_t _p0;                // 804061C0
        uint8_t heart_pieces;       // 804061C1
        uint8_t _p1;                // 804061C2
        uint8_t heart_quarters;     // 804061C3
        uint16_t rupees;            // 804061C4
        uint8_t _p2[2];             // 804061C6
        uint16_t lamp_fuel;         // 804061C8
        uint8_t _p3;                // 804061CA
        uint8_t item_on_x;          // 804061CB
        uint8_t item_on_y;          // 804061CC
        uint8_t _p4[2];             // 804061CD
        uint8_t slot_x_combo_item;  // 804061CF
        uint8_t slot_y_combo_item;  // 804061D0
        uint8_t _p5[2];             // 804061D1
        uint8_t armor;              // 804061D3
        uint8_t sword;              // 804061D4
        uint8_t shield;             // 804061D5
        uint8_t scent;              // 804061D6 // bitfield for scents
        uint8_t _p6[2];             // 804061D7
        uint8_t wallet_upgrade;     // 804061D9
        uint8_t _p7[4];             // 804061DA
        bool is_wolf;               // 804061DE
        uint8_t _p8;                // 804061DF
    };
    static_assert(sizeof(Link) == 0x20);

    Link *get_link();
    Vec3 *get_position();
    uint16_t *get_air();

    struct FrontRoll {
        uint8_t _p0[0x18];                // 8038D7BC
        float bonk_recovery_anim_factor;  // 8038D7D4
        float bonk_recoil_anim_speed;     // 8038D7D8
        uint8_t _p1[0x28];                // 8038D7DC
        float roll_factor;                // 8038D804
        uint8_t _p2[0x24];                // 8038d808
    };
    static_assert(sizeof(FrontRoll) == 0x70);



    struct BackJump {
        uint8_t _p0[0x38];  // 8038D82C
    };
    static_assert(sizeof(BackJump) == 0x38);

    struct SideStep {
        uint8_t _p0[0x68];  // 8038d864
    };
    static_assert(sizeof(SideStep) == 0x68);

    struct Slide {
        uint8_t _p0[0x78];  // 8038d8cc
    };
    static_assert(sizeof(Slide) == 0x78);

    struct Swim {
        uint8_t _p0[0x14];  // 8038ED2C
        uint16_t diving_anim_frames;
        uint8_t _p1[0x02];
        float diving_anim_speed;
        uint8_t _p2[0x04];
        float diving_bob_anim_frames;
        float _p3;
        uint16_t underwater_dive_anim_frames;
        uint8_t _p4[0x02];
        float underwater_dive_anim_speed;
        uint8_t _p5[0x04];
        float prep_underwater_dive_anim_speed;
        float _p6;
        uint16_t surface_swim_anim_frames;
        uint8_t _p7[0x02];
        float surface_swim_anim_speed;
        float surface_swim_anim_frames_2;
        float start_swim_anim_frames;
        float _p8;
        uint8_t _p9[0x02];
        uint8_t surface_rotation_speed;
        uint8_t _p10[0x0D];
        float distance_from_water_to_surface;
        float resurface_anim_speed;
        float forward_swim_speed;
        float side_swim_speed;
        float back_swim_speed;
        float swim_up_speed;
        float ib_swim_speed;
        float _p11;
        float _p12;
        float _p13;
        float _p14;
        float _p15;
        float idle_anim_speed;
        float return_to_idle_from_swim_anim_frames;
        float idle_bob_depth;
        float ess_forward_swim_anim_speed;
        float full_forward_swim_anim_speed;
        float ess_side_swim_anim_speed;
        float full_side_swim_anim_speed;
        float ess_back_swim_anim_speed;
        float full_back_swim_anim_speed;
        float ready_after_dive_anim_speed;
        float underwater_swim_anim_speed;
        float ready_underwater_anim_frames;
        float _p16;
        float _p17;
        float unk_transition_into_swimming;
        float _p18;
        float sinking_speed;
        float _p19;
        float _p20;
        float swim_up_max_anim_speed;
        float swim_up_init_anim_speed;
        float initial_sinking_speed;
        float swim_up_max_speed;
        float dash_swim_max_speed;
        float _p21;
        float _p22;
        float _p23;
    };
    static_assert(sizeof(Swim) == 0xFC);

}  // namespace Link
#define tp_link_swim (*(Link::Swim *)(tp_link_swim_addr))
#define tp_link_frontroll (*(Link::FrontRoll *)(tp_link_frontroll_addr))

#endif  // LIB_TP_LINK