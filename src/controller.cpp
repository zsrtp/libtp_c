#include "../include/JSystem/JUtility/JUTGamePad.h"
#include "../include/controller.h"

#ifdef GCN_PLATFORM
#define mPad (tp_mPadButton)
#endif
#ifdef WII_PLATFORM
#define mPad (tp_mPad)
#endif

void setGamepadButtons(uint16_t buttons) {
    mPad.mButton = buttons;
}

void setGamepadTrig(uint16_t buttons) {
    mPad.mTrigger = buttons;
}