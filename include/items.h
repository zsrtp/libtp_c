#ifndef LIB_TP_ITEMS
#define LIB_TP_ITEMS

#include <stdint.h>
#include "addrs.h"

namespace Items {
    namespace Spinner {
        struct Spinner {
            uint8_t _p0[0x18];       // 8038EA30
            uint16_t turning;        // 8038EA48
            uint8_t _p1[0x06];       // 8038EA4A
            float vertical_speed_1;  // 8038EA50 // checked when y pos decreases at all
            float vertical_speed_2;  // 8038EA50 // not sure what conditions are needed for this
            uint8_t _p2[0x04];       // 8038EA58
            float horizontal_speed;  // 8038EA5C
            uint8_t _p3[0x04];
        };  // struct Spinner
    };      // namespace Spinner
    namespace Clawshot {
        struct ClawshotProperty {
            uint8_t _p0[0x04];                       //8038E9C0
            uint16_t arm_animation1;                 //8038E9C4 affects first person anim while firing
            uint8_t _p1[0x02];                       //8038E9C6
            uint16_t arm_animation2;                 //8038E9C8 affects first person anim while firing
            uint8_t _p20[0x22];                      //8038E9CA
            uint16_t wall_hang_anim_speed;           //8038E9EC
            uint8_t _p3[0x02];                       //8038E9EE
            uint16_t wall_hang_anim;                 //8038E9F0 has something to do with wall anim but not speed specifically
            uint8_t _p4[0x06];                       //8038EAF2
            uint16_t second_clawshot_wait_frames;    //8038EAF8 how long before you can use clawshot 2 when hanging from wall (ceiling is different)
            uint8_t _p5[0x06];                       //8038EAFA
            uint16_t third_person_ready_anim_angle;  //8038EA00 data type is wrong probably
            uint16_t third_person_ready_anim_speed;  //8038EA02 data type is wrong probably
            float first_person_ready_anim_frames;    //8038EA04
            float extension_rate;                    //8038EA08
            float speed;                             //8038EA0C
            float retraction_rate;                   //8038EA10
            float pull_rate;                         //8038EA14
            uint8_t _p6[0x1C];                       //8038EA18
        };

        struct ClawshotBG {
            uint8_t _p0[0x30];   //801087B0
            uint32_t is_target;  //801087E0
            uint8_t _p1[0x44];   // 801087E4
        };
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
        };
    };  // namespace IronBoots

    namespace BallAndChain {
        struct BallAndChainProperty {
        };  // struct BallAndChainProperty
    };      // namespace BallAndChain
};          // namespace Items

#define tp_clawshot (*(Items::Clawshot::ClawshotProperty *)tp_clawshot_addr)
#define tp_clawshot_bg (*(Items::Clawshot::ClawshotBG *)tp_clawshot_checkbg_addr)
#define tp_ironboots (*(Items::IronBoots::IronBootsProperty *)tp_ironboots_addr)

#endif  // LIB_TP_ITEMS