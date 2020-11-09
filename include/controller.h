#ifndef LIB_TP_CONTROLLER
#define LIB_TP_CONTROLLER

#include <stdint.h>
#include "addrs.h"
#include "utils.h"

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

    uint16_t buttons_down();
    uint16_t buttons_pressed();
    void set_buttons_down(uint16_t buttons);
    void set_buttons_pressed(uint16_t buttons);
    bool is_down(uint16_t buttons);
    bool is_pressed(uint16_t buttons);
}  // namespace Controller

#endif  // LIB_TP_CONTROLLER
