#ifndef UTILS_H
#define UTILS_H

#include "d/com/d_com_inf_game.h"

// Toggles save event flags
void setEventFlag(uint16_t flag) {
    if (dComIfGs_isEventBit(flag)) {
        dComIfGs_offEventBit(flag);
    } else {
        dComIfGs_onEventBit(flag);
    }
}

#endif