#include "utils.h"
#include <cstring>

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
    dSv_player_return_place_c__set(&g_dComIfG_gameInfo.info.getPlayer().mPlayerReturnPlace, stage,
                                   room, spawn);
}

void setNextStageName(const char* name) {
    strcpy((char*)g_dComIfG_gameInfo.play.mNextStage.mStage, name);
}

void setNextStageLayer(int8_t layer) {
    g_dComIfG_gameInfo.play.mNextStage.setLayer(layer);
}

void setNextStageRoom(int8_t room) {
    g_dComIfG_gameInfo.play.mNextStage.setRoomNo(room);
}

void setNextStagePoint(int16_t point) {
    g_dComIfG_gameInfo.play.mNextStage.setPoint(point);
}
