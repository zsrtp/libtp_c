#include "../include/JSystem/JUtility/JUTGamePad.h"
#include "../include/controller.h"

#ifdef GCN_PLATFORM
#define mPad (tp_mPadButton)
#endif
#ifdef WII_PLATFORM
#define mPad (tp_mPad)
#endif

void setGamepadButtons(uint16_t buttons) {
    #ifdef GCN_PLATFORM
    mPad.mButton = buttons;
    #endif

    #ifdef WII_PLATFORM
    mPad.mHoldButton = buttons;
    #endif
}

void setGamepadTrig(uint16_t buttons) {
    #ifdef GCN_PLATFORM
    mPad.mTrigger = buttons;
    #endif

    #ifdef WII_PLATFORM
    mPad.mTrigButton = buttons;
    #endif
}