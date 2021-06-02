#include "../include/JSystem/JUtility/JUTGamePad.h"

#ifdef GCN_PLATFORM
#define mPad (tp_mPadButton)
#endif
#ifdef WII_PLATFORM
#define mPad (tp_mPad)
#endif

namespace Controller {
    uint16_t buttons_down() {
        return mPad.buttons;
    }

    uint16_t buttons_pressed() {
        return mPad.buttons_down;
    }

    void set_buttons_down(uint16_t buttons) {
        mPad.buttons = buttons;
    }

    void set_buttons_pressed(uint16_t buttons) {
        mPad.buttons_down = buttons;
    }

    bool is_down(uint16_t buttons) {
        return (mPad.buttons & buttons) == buttons;
    }

    bool is_pressed(uint16_t buttons) {
        return (mPad.buttons_down & buttons) == buttons;
    }
}  // namespace Controller