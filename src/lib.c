#include <math.h>
#include <stdbool.h>
#include "tp.h"
#include "controller.h"

static uint16_t sButtons_down_last_frame = 0;
static uint16_t sButtons_down = 0;
static uint16_t sButtons_pressed = 0;

typedef struct {
    uint16_t button;
    uint32_t pressed_frame;
    bool is_down;
} ButtonState;

#define BUTTON_STATES 12
static ButtonState buttonStates[BUTTON_STATES] = {
    { DPAD_LEFT, 0xFFFFFFFF, false },
    { DPAD_RIGHT, 0xFFFFFFFF, false },
    { DPAD_DOWN, 0xFFFFFFFF, false },
    { DPAD_UP, 0xFFFFFFFF, false },
    { Z, 0xFFFFFFFF, false },
    { R, 0xFFFFFFFF, false },
    { L, 0xFFFFFFFF, false },
    { A, 0xFFFFFFFF, false },
    { B, 0xFFFFFFFF, false },
    { X, 0xFFFFFFFF, false },
    { Y, 0xFFFFFFFF, false },
    { START, 0xFFFFFFFF, false }
};

uint32_t read_controller() {
    sButtons_down_last_frame = sButtons_down;
    sButtons_down = tp_mPadStatus.sval;
    sButtons_pressed = sButtons_down & (0xFFF ^ sButtons_down_last_frame);

    uint8_t idx = 0;
    for(; idx < BUTTON_STATES; idx++) {
        buttonStates[idx].is_down = buttonStates[idx].button & sButtons_down != 0;
        if(buttonStates[idx].button & sButtons_pressed != 0) {
            buttonStates[idx].pressed_frame = get_frame_count() + 1;
        }
    }
    return 0x80000000;
}

void game_loop()
{
    if(buttonStates[2].is_down) {
        tp_linkRollConstants.roll_factor = (float) sqrt(9.0f);
    } else {
        tp_linkRollConstants.roll_factor = 1.3f;
    }
}