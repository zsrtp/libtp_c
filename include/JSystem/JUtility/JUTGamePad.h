#ifndef JUTGAMEPAD_H
#define JUTGAMEPAD_H

#include <stdint.h>
#include "../../dolphin/mtx/vec.h"
#include "../../addrs.h"

namespace Controller {
    namespace Pad {
        const uint16_t DPAD_LEFT = 0x0001;
        const uint16_t DPAD_RIGHT = 0x0002;
        const uint16_t DPAD_DOWN = 0x0004;
        const uint16_t DPAD_UP = 0x0008;
        const uint16_t Z = 0x0010;
        const uint16_t R = 0x0020;
        const uint16_t L = 0x0040;
        const uint16_t A = 0x0100;
        const uint16_t B = 0x0200;
        const uint16_t X = 0x0400;
        const uint16_t Y = 0x0800;
        const uint16_t START = 0x1000;
    }  // namespace Pad

    struct PadStatus {
        uint16_t sval;
        int8_t control_x;
        int8_t control_y;
        int8_t c_x;
        int8_t c_y;
        uint8_t trig_L;
        uint8_t trig_R;
        uint8_t _p01[0x27];
    };
    static_assert(sizeof(PadStatus) == 0x30);

#ifdef WII_PLATFORM

    namespace Mote {
        const uint16_t DPAD_LEFT = 0x0001;
        const uint16_t DPAD_RIGHT = 0x0002;
        const uint16_t DPAD_DOWN = 0x0004;
        const uint16_t DPAD_UP = 0x0008;
        const uint16_t PLUS = 0x0010;
        const uint16_t TWO = 0x0100;
        const uint16_t ONE = 0x0200;
        const uint16_t B = 0x0400;
        const uint16_t A = 0x0800;
        const uint16_t MINUS = 0x1000;
        const uint16_t Z = 0x2000;
        const uint16_t C = 0x4000;
        const uint16_t HOME = 0x8000;
    }  // namespace Pad

    struct Pointer {
        Vec2 pos;                   // 8044BB84
        uint8_t _p1[0x20];          // 8044BB8C
        float scr_dist;             // 8044BBAC // Relative distance of the remote to the sensor bar
    };
    static_assert(sizeof(Pointer) == 0x2C);

    struct MoteStatus {
        uint8_t _unk1[4];           // 8044BB60
        uint8_t _p1[2];             // 8044BB64
        uint16_t buttons;           // 8044BB66
        uint8_t _p2[2];             // 8044BB68
        uint16_t buttons_down;      // 8044BB6A
        uint8_t _p3[2];             // 8044BB6C
        uint16_t buttons_up;        // 8044BB6E
        Vec wiimote_acc;            // 8044BB70
        float wiimote_acc_strength; // 8044BB7C
        float wiimote_shake;        // 8044BB80 // Unsure of the real meaning of this, needs more verification
        Pointer pointer;            // 8044BB84
        uint8_t _p4[8];             // 8044BBB0
        float horizontal;           // 8044BBB8 // Goes from 0.0 to 1.0, shows how much the remote is horizontal
        float vertical;             // 8044BBBC // Goes from -1.0 to 1.0, shows how much the remote is vertical (up is 1.0, down is -1.0)
        uint8_t _p5[4];             // 8044BBC0
        Vec2 stick;                 // 8044BBC4
        Vec nunchuck_acc;           // 8044BBCC
        float nunchuck_acc_strength;// 8044BBD8
        float nunchuck_shake;       // 8044BBDC // Unsure of the real meaning of this, needs more verification
        uint8_t _p6[0x1CF0];        // 8044BBE0
        float stick_amplitude;      // 8044D8D0
        uint8_t _p7[0x5AAC];        // 8044D8D4
    };
    static_assert(sizeof(MoteStatus) == 0x7820);
#endif

    struct PadButton {
        uint8_t analog_cardinal;
        uint8_t c_cardinal;
        uint16_t buttons;
        uint8_t _p1[2];
        uint16_t buttons_down;
        uint8_t _p2[8];
        float l_analog;
        float r_analog;
        uint8_t _p4[2];
        uint16_t sval;
        uint8_t _p3[0xA4];
    };
    static_assert(sizeof(PadButton) == 0xC0);

    struct PadMStick{
        Vec2 control_analog;
        uint8_t _p0[0x38];
    };
    static_assert(sizeof(PadMStick) == 0x40);

    struct PadSStick{
        Vec2 c_analog;
        uint8_t _p0[0x38];
    };
    static_assert(sizeof(PadSStick) == 0x40);

    struct CPadInfo{
        uint8_t _p0[0x30];
        uint32_t input;
        uint32_t triggerInput;
        uint8_t _p1[0xC8];
    };
    static_assert(sizeof(CPadInfo) == 0x100);

#define tp_mPadStatus (*(Controller::PadStatus *)tp_mPadStatus_addr)
#define tp_mPadButton (*(Controller::PadButton *)tp_mPadButton_addr)
#define tp_mPadMStick (*(Controller::PadMStick *)tp_mPadMStick_addr)
#define tp_mPadSStick (*(Controller::PadSStick *)tp_mPadSStick_addr)
#define tp_cPadInfo (*(Controller::CPadInfo *)tp_cPadInfo_addr)
#ifdef WII_PLATFORM
#define tp_mPad (*(Controller::MoteStatus *)tp_mPad_addr)
#endif

    uint16_t buttons_down();
    uint16_t buttons_pressed();
    void set_buttons_down(uint16_t buttons);
    void set_buttons_pressed(uint16_t buttons);
    bool is_down(uint16_t buttons);
    bool is_pressed(uint16_t buttons);
}  // namespace Controller


typedef void (*tp_JUTGamePadRead_t)(void);
#define tp_JUTGamePadRead ((tp_JUTGamePadRead_t)tp_JUTGamePadRead_addr)

#endif /* JUTGAMEPAD_H */
