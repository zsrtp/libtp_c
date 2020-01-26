#ifndef LIB_TP_ITEMS
#define LIB_TP_ITEMS

#include <stdint.h>
#include "addrs.h"

namespace Clawshot {

    struct ClawshotProperty {
        uint8_t _p0[4];                         //8038E9C0
        uint16_t arm_animation1;                //8038E9C4 affects first person anim while firing
        uint8_t _p1[2];                         //8038E9C6
        uint16_t arm_animation2;                //8038E9C8 affects first person anim while firing
        uint8_t _p2[22];                        //8038E9CA
        uint16_t wall_hang_anim_speed;          //8038E9EC
        uint8_t _p3[2];                         //8038E9EE
        uint16_t wall_hang_anim;                //8038E9F0 has something to do with wall anim but not speed specifically
        uint8_t _p4[6];                         //8038EAF2 
        uint16_t second_clawshot_wait_frames;   //8038EAF8 how long before you can use clawshot 2 when hanging from wall (ceiling is different) 
        uint8_t _p5[6];                         //8038EAFA
        uint16_t third_person_ready_anim_angle; //8038EA00 data type is wrong probably
        uint16_t third_person_ready_anim_speed; //8038EA02 data type is wrong probably
        float first_person_ready_anim_frames;   //8038EA04
        float extension_rate;                   //8038EA08 
        float speed;                            //8038EA0C 
        float retraction_rate;                  //8038EA10 
        float pull_rate;                        //8038EA14 
        uint8_t _p6[0x1C];                      //8038EA18
    };

    #define tp_clawshot (*(Clawshot::ClawshotProperty *)tp_clawshot_addr)

        float speed();
        float extension_rate();
        float retraction_rate();
        float pull_rate();
        void set_speed(float num);
        void set_extension_rate(float num);
        void set_retraction_rate(float num);
        void set_pull_rate(float num);
};
                    
#endif // LIB_TP_ITEMS