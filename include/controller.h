#ifndef LIB_TP_CONTROLLER
#define LIB_TP_CONTROLLER

#include <stdint.h>
#include "addrs.h"

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

    class Button {
       private:
        uint8_t idx;

       public:
        Button(uint8_t _idx) {
            idx = _idx;
        }
        bool is_pressed();
        bool is_down();
    };

    static Button DPAD_LEFT = Button(0);
    static Button DPAD_RIGHT = Button(1);
    static Button DPAD_DOWN = Button(2);
    static Button DPAD_UP = Button(3);
    static Button Z = Button(4);
    static Button R = Button(5);
    static Button L = Button(6);
    static Button A = Button(7);
    static Button B = Button(8);
    static Button X = Button(9);
    static Button Y = Button(10);
    static Button START = Button(11);

    struct PadStatus {
        uint16_t sval;
    };
    static_assert(sizeof(PadStatus) == 0x2);

    struct PadButton {
        uint8_t analog_cardinal;
        uint8_t c_cardinal;
        uint16_t buttons;
        uint8_t _p1[2];
        uint16_t buttons_down;
        uint8_t _p2[18];
        uint16_t sval;
        uint8_t _p3[0xA4];
    };
    static_assert(sizeof(PadButton) == 0xC0);

#define tp_mPadButton (*(Controller::PadButton *)tp_mPadButton_addr)
#define tp_mPadStatus (*(Controller::PadStatus *)tp_mPadStatus_addr)

    uint16_t buttons_down();
    uint16_t buttons_pressed();
    void set_buttons_down(uint16_t buttons);
    void set_buttons_pressed(uint16_t buttons);
    bool is_down(uint16_t buttons);
    bool is_pressed(uint16_t buttons);
}  // namespace Controller

#endif  // LIB_TP_CONTROLLER