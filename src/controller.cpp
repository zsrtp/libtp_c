#include "controller.h"
#include "tp.h"

namespace Controller {
    uint16_t buttons_down() {
        return tp_mPadButton.buttons;
    }

    uint16_t buttons_pressed() {
        return tp_mPadButton.buttons_down;
    }

    void set_buttons_down(uint16_t buttons) {
        tp_mPadButton.buttons = buttons;
    }

    void set_buttons_pressed(uint16_t buttons) {
        tp_mPadButton.buttons_down = buttons;
    }

    bool is_down(uint16_t buttons) {
        return (tp_mPadButton.buttons & buttons) == buttons;
    }

    bool is_pressed(uint16_t buttons) {
        return (tp_mPadButton.buttons_down & buttons) == buttons;
    }
}  // namespace Controller