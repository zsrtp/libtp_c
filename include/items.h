#ifndef LIB_TP_ITEMS
#define LIB_TP_ITEMS

#include <stdint.h>
#include "addrs.h"

namespace Items {
    namespace GaleBoomerang {
        struct GaleBoomerangProperty {
            uint8_t _p0[0x04];                          // 8038E6C8
            float link_throw_anim_speed_1;              // 8038E6CC
            float link_throw_anim_speed_2;              // 8038E6D0
            float link_throw_anim_speed_3;              // 8038E6D4
            float link_walking_throw_anim_speed;        // 8038E6D8
            uint8_t _p1[0x04];                          // 8038E6DC
            float link_catch_anim_speed_1;              // 8038E6E0
            float link_catch_and_hold_anim_speed;       // 8038E6E4
            float link_catch_anim_speed_2;              // 8038E6E8
            float link_walking_catch_anim_speed;        // 8038E6EC
            uint8_t _p2[0x04];                          // 8038E6F0
            float boomerang_idle_sway_anim_speed;       // 8038E6F4
            float boomerang_idle_ready_anim_speed;      // 8038E6F8
            float _p3;                                  // 8038E6FC
            float boomerang_speed;                      // 8038E700
            float boomerang_throw_distance;             // 8038E704
            float _p4;                                  // 8038E708
            float _p5;                                  // 8038E70C
            float boomerang_item_grabbed_return_speed;  // 8038E710
        };                                              // struct GaleBoomerangProperty
        static_assert(sizeof(GaleBoomerangProperty) == 0x4C);
    };  // namespace GaleBoomerang
    namespace Spinner {
        struct SpinnerProperty {
            uint8_t _p0[0x18];            // 8038EA30
            uint16_t turning;             // 8038EA48
            uint8_t _p1[0x06];            // 8038EA4A
            float vertical_speed_1;       // 8038EA50 // checked when y pos decreases at all
            float vertical_speed_2;       // 8038EA50 // not sure what conditions are needed for this
            uint8_t _p2[0x04];            // 8038EA58
            float horizontal_speed;       // 8038EA5C
            uint8_t _p3[0x04];            // 8038EA60
            float deceleration_factor_1;  // 8038EA64
            float deceleration_factor_2;  // 8038EA68
            uint8_t _p4[0x04];            // 8038EA6C
        };                                // struct Spinner
        static_assert(sizeof(SpinnerProperty) == 0x40);
    };  // namespace Spinner
    namespace Clawshot {
        struct ClawshotProperty {
            uint8_t _p0[0x04];                       // 8038E9C0
            uint16_t arm_animation1;                 // 8038E9C4 affects first person anim while firing
            uint8_t _p1[0x02];                       // 8038E9C6
            uint16_t arm_animation2;                 // 8038E9C8 affects first person anim while firing
            uint8_t _p20[0x22];                      // 8038E9CA
            uint16_t wall_hang_anim_speed;           // 8038E9EC
            uint8_t _p3[0x02];                       // 8038E9EE
            uint16_t wall_hang_anim;                 // 8038E9F0 has something to do with wall anim but not speed specifically
            uint8_t _p4[0x06];                       // 8038EAF2
            uint16_t second_clawshot_wait_frames;    // 8038EAF8 how long before you can use clawshot 2 when hanging from wall (ceiling is different)
            uint8_t _p5[0x06];                       // 8038EAFA
            uint16_t third_person_ready_anim_angle;  // 8038EA00 data type is wrong probably
            uint16_t third_person_ready_anim_speed;  // 8038EA02 data type is wrong probably
            float first_person_ready_anim_frames;    // 8038EA04
            float extension_rate;                    // 8038EA08
            float speed;                             // 8038EA0C
            float retraction_rate;                   // 8038EA10
            float pull_rate;                         // 8038EA14
            uint8_t _p6[0x1C];                       // 8038EA18
        };                                           // struct ClawshotProperty
        static_assert(sizeof(ClawshotProperty) == 0x74);

        struct ClawshotBG {
            uint8_t _p0[0x30];   // 801087B0
            uint32_t is_target;  // 801087E0
            uint8_t _p1[0x44];   // 801087E4
        };                       // struct ClawshotBG // pretty sure this actually needs to be a function pointer
        static_assert(sizeof(ClawshotBG) == 0x78);
    };  // namespace Clawshot

    namespace IronBoots {
        struct IronBootsProperty {
            uint8_t _p0[0x04];             // 8038E7F4
            uint16_t switch_speed;         // 8038E7F8
            uint8_t _p1[0x02];             // 8038E7FA
            uint8_t switch_speed2;         // 8038E7FC this single byte seem to affect switching speed as well?
            uint8_t _p2[0x07];             // 8038E7FD
            uint16_t wait_after_switch;    // 8038E804
            uint8_t _p3[0x02];             // 8038E806
            uint8_t weight1;               // 8038E808 can't figure out this one :(
            uint8_t weight2;               // 8038E809
            uint8_t _p4[0x02];             // 8038E80A
            float speed;                   // 8038E80C affects speed but doesn't appear to be float? // this also affects speed while sinking in sand. shared i'm guess
            uint16_t stepping_anim_speed;  // 8038E810
            uint8_t _p5[0x02];             // 8038E812
            uint16_t ess_anim_speed;       // 8038E814
            uint8_t _p6[0x12];             // 8038E816
            uint8_t magnet_strength;       // 8038E828
            uint8_t _p7[0x17];             // 8038E829
        };                                 // struct IronBootsProperty
        static_assert(sizeof(IronBootsProperty) == 0x4C);
    };  // namespace IronBoots

    namespace BallAndChain {
        struct BallAndChainProperty {
            uint8_t _p0[0x04];                  // 8038EA70
            float return_anim_speed_1;          // 8038EA74 // how fast link returns to idle anim after catching b&c
            float return_anim_speed_2;          // 8038EA78 // affects arm animation specifically?
            float return_anim_speed_3;          // 8038EA7C
            float _p1;                          // 8038EA80 // appears to be float but idk what it is
            uint8_t _p2[0x04];                  // 8038EA84
            float _p3;                          // 8038EA88 // appears to be float but idk what it is
            float swinging_ready_anim_speed;    // 8038EA8C
            float link_arm_anim_speed;          // 8038EA90
            float rotation_speed;               // 8038EA94
            float link_body_sway_anim_speed;    // 8038EA98
            float link_throw_anim_speed_1;      // 8038EA9C
            float link_throw_anim_speed_2;      // 8038EAA0
            float unk_throw_speed;              // 8038EAA4 // not quite sure what this controls
            float link_extend_arm_anim_speed;   // 8038EAA8
            float link_raise_arm_anim_speed_1;  // 8038EAAC
            float link_raise_arm_anim_speed_2;  // 8038EAB0
            float chain_anim_speed;             // 8038EAB4
            float chain_position_throw;         // 8038EAB8 // affects chain position while throwing
            float chain_position_return;        // 8038EABC // affects chain position when its returning
            float ball_return_v_speed_1;        // 8038EAC0
            float link_throw_anim_speed_3;      // 8038EAC4
            float link_throw_anim_speed_4;      // 8038EAC8
            float chain_falling_anim_speed;     // 8038EACC
            float ball_v_speed_after_throw_1;   // 8038EAD0
            float ball_v_speed_during_throw;    // 8038EAD4
            float ball_v_speed_after_throw_2;   // 8038EAD8 // very similar to the first one
            float _p4;                          // 8038EADC // appears to be float but idk what it is
            float ball_h_speed_during_throw;    // 8038EAE0
            float ball_throw_height;            // 8038EAE4
            float _p5;                          // 8038EAE8 // appears to be float but idk what it is
            float _p6;                          // 8038EAEC // appears to be float but idk what it is
            float link_running_speed;           // 8038EAF0 // takes priority over next two
            float link_walking_speed;           // 8038EAF4
            float link_ess_walking_speed;       // 8038EAF8

        };  // struct BallAndChainProperty
        static_assert(sizeof(BallAndChainProperty) == 0x8C);

    };  // namespace BallAndChain
};      // namespace Items

#define tp_clawshot (*(Items::Clawshot::ClawshotProperty *)tp_clawshot_addr)
#define tp_clawshot_bg (*(Items::Clawshot::ClawshotBG *)tp_clawshot_checkbg_addr)
#define tp_ironboots (*(Items::IronBoots::IronBootsProperty *)tp_ironboots_addr)
#define tp_spinner (*(Items::Spinner::SpinnerProperty *)tp_spinner_addr)
#define tp_ball_and_chain (*(Items::BallAndChain::BallAndChainProperty *)tp_ball_and_chain_addr)

#endif  // LIB_TP_ITEMS