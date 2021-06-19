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

// Set Savefile spawn info
void setReturnPlace(const char* stage, int8_t room, uint8_t spawn) {
    dSv_player_return_place_c__set(&g_dComIfG_gameInfo.mInfo.getPlayer().player_return,
                                    stage, room, spawn);
}

#endif