#ifndef LIB_TP_LINK
#define LIB_TP_LINK

#include <stdint.h>
#include "utils.h"
#include "addrs.h"

namespace Link {
    struct Link {
        uint16_t heart_pieces;              // 804061C0
        uint16_t heart_quarters;            // 804061C2
        uint16_t rupees;                    // 804061C4
        uint16_t max_lantern_oil;           // 804061C6
        uint16_t current_lantern_oil;       // 804061C8
        uint8_t _unk0;                      // 804061CA
        uint8_t item_on_x;                  // 804061CB
        uint8_t item_on_y;                  // 804061CC
        uint8_t _unk_set_during_poe_sniff;  // 804061CD
        uint8_t _unk1;                      // 804061CE
        uint8_t slot_x_combo_item;          // 804061CF
        uint8_t slot_y_combo_item;          // 804061D0
        uint8_t _p5[2];                     // 804061D1
        uint8_t armor;                      // 804061D3
        uint8_t sword;                      // 804061D4
        uint8_t shield;                     // 804061D5
        uint8_t scent;                      // 804061D6 // bitfield for scents
        uint8_t _p6[2];                     // 804061D7
        uint8_t wallet_upgrade;             // 804061D9
        uint8_t _p7[4];                     // 804061DA
        bool is_wolf;                       // 804061DE
        uint8_t _p8;                        // 804061DF
    };
    static_assert(sizeof(Link) == 0x20);

    Link *get_link();
    Vec3 *get_position();
    uint16_t *get_air();

    namespace Animations {
        struct HumanFrontRoll {
            uint8_t _p0[0x18];                // 8038D7BC
            float bonk_recovery_anim_factor;  // 8038D7D4
            float bonk_recoil_anim_speed;     // 8038D7D8
            uint8_t _p1[0x28];                // 8038D7DC
            float roll_factor;                // 8038D804
            uint8_t _p2[0x24];                // 8038d808
        };
        static_assert(sizeof(HumanFrontRoll) == 0x70);

        struct HumanBackJump {
            uint8_t _p0[0x38];  // 8038D82C
        };
        static_assert(sizeof(HumanBackJump) == 0x38);

        struct HumanSideStep {
            uint8_t _p0[0x68];  // 8038d864
        };
        static_assert(sizeof(HumanSideStep) == 0x68);

        struct HumanSlide {
            uint8_t _p0[0x78];  // 8038d8cc
        };
        static_assert(sizeof(HumanSlide) == 0x78);

        struct HumanSwim {
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
        static_assert(sizeof(HumanSwim) == 0xFC);

        struct WolfGeneral {
            uint16_t slide_turn_around_anim_frames1;
            uint16_t _p0;
            float slide_turn_around_anim_speed1;
            uint32_t unk1;
            float unk2;
            float unk3;
            uint16_t slide_turn_around_anim_frames2;
            uint16_t _p1;
            float slide_turn_around_anim_speed2;
            uint32_t unk4;
            float unk5;
            float unk6;
            uint16_t dash_to_walking_anim_frames;
            uint16_t _p2;
            float dashing_anim_speed;
            uint32_t unk7;
            float unk8;
            float start_dash_anim_frames;
            uint16_t unk9;
            uint16_t _p3;
            float bonk_recoil_anim_speed;
            uint32_t unk10;
            float unk11;
            float unk12;
            uint16_t unk_dash_turning;
            uint16_t unk13;
            uint16_t dash_anim_frames;
            uint16_t unk14;
            uint16_t unk15;
            uint16_t dash_length_frames;
            uint16_t dash_reload_time_frames;
            uint16_t unk17;
            uint16_t unk18;
            uint16_t _p4;
            float unk19;
            float unk20;
            float unk21;
            float unk22;
            float unk23;
            float unk24;
            float unk25;
            float unk26;
            float unk27;
            float dash_to_walk_transition_factor;
            float dash_to_walk_transition_speed;
            float dash_to_walk_unk;
            float inital_dash_transition_factor;
            float initial_dash_transiiton_unk;
            float unk28;
            float unk29;
            float unk30;
            float slide_distance_unk;
            float slide_turn_around_distance;
            float unk31;
            float unk32;
            float unk33;
            float unk34;
            float unk35;
            float unk36;
            float dash_speed_large_area;
            float unk38;
            float unk39;
            float dash_initial_speed_large_area;
            float bonk_recoil_horizontal_distance;
            float bonk_recoil_vertical_distance;
            float dash_speed_small_area;
            float dash_initial_speed_small_area;
            float dash_anim_speed;
            float unk41;
            float unk42;
            float unk43;
            float unk44;
            float unk45;
        };
        static_assert(sizeof(WolfGeneral) == 0x100);

        struct WolfSwim {
            uint16_t surfacing_anim_frames;
            uint16_t _p0;
            float surfacing_anim_speed;
            uint32_t _p1;
            float inital_surfacing_anim_frames;
            float unk1;
            uint16_t unk2;
            uint16_t _p2;
            float unk3;
            uint32_t unk4;
            float unk5;
            float unk6;
            uint16_t dash_to_swim_anim_frames;
            uint16_t _p3;
            float initial_dash_anim_speed;
            uint32_t unk7;
            float initial_dash_anim_frames;
            float unk8;
            uint16_t surface_turning_speed_factor;
            uint16_t surface_turning_speed;
            uint16_t surface_turning_speed2;
            uint16_t unk9;
            uint16_t unk10;
            uint16_t unk11;
            float distance_from_water_to_surface;
            float unk12;
            float dash_swim_speed;
            float dash_to_swim_speed_decrease_factor;
            float gravity_entering_water_sinking;
            float gravity_in_water_rising;
            float gravity_in_water_rising_factor;
            float dash_to_swim_anim_speed;
            float swim_to_idle_anim_frames;
            float idle_bobbing_depth;
            float unk13;
            float unk14;
            float idle_to_swim_anim_frames;
            float climb_out_of_water_unk;
            float swim_speed;
            float unk15;
            float idle_doggy_padle_anim_speed;
            float idle_to_swim_anim_speed;
            float swim_anim_speed;
            float unk16;
            float unk17;
            float unk18;
            float unk19;
            float unk20;
        };
        static_assert(sizeof(WolfSwim) == 0xA8);

    };  // namespace Animations

}  // namespace Link
#define tp_link_human_swim (*(Link::Animations::HumanSwim *)(tp_link_human_swim_addr))
#define tp_link_human_frontroll (*(Link::Animations::HumanFrontRoll *)(tp_link_human_frontroll_addr))
#define tp_link_wolf_general (*(Link::Animations::WolfGeneral *)(tp_link_wolf_general_addr))
#define tp_link_wolf_swim (*(Link::Animations::WolfSwim *)(tp_link_wolf_swim_addr))

#endif  // LIB_TP_LINK