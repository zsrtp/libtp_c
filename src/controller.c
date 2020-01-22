#include "controller.h"
#include "tp.h"

#define BUTTON_STATES 12
#define REPEAT_TIME 6
#define REPEAT_DELAY 10

uint16_t buttons_down()
{
    return tp_mPadButton.buttons;
}

uint16_t buttons_pressed()
{
    return tp_mPadButton.buttons_down;
}

void set_buttons_down(uint16_t buttons)
{
    tp_mPadButton.buttons = buttons;
}

void set_buttons_pressed(uint16_t buttons)
{
    tp_mPadButton.buttons_down = buttons;
}

bool is_down(uint16_t buttons)
{
    return (tp_mPadButton.buttons & buttons) == buttons;
}

bool is_pressed(uint16_t buttons)
{
    return (tp_mPadButton.buttons_down & buttons) == buttons;
}

static uint16_t sButtons_down_last_frame = 0;
static uint16_t sButtons_down = 0;
static uint16_t sButtons_pressed = 0;

typedef struct
{
    uint16_t button;
    uint32_t pressed_frame;
    bool is_down;
} ButtonState;

static ButtonState buttonStates[BUTTON_STATES] = {
    {DPAD_LEFT, 0xFFFFFFFF, false},
    {DPAD_RIGHT, 0xFFFFFFFF, false},
    {DPAD_DOWN, 0xFFFFFFFF, false},
    {DPAD_UP, 0xFFFFFFFF, false},
    {Z, 0xFFFFFFFF, false},
    {R, 0xFFFFFFFF, false},
    {L, 0xFFFFFFFF, false},
    {A, 0xFFFFFFFF, false},
    {B, 0xFFFFFFFF, false},
    {X, 0xFFFFFFFF, false},
    {Y, 0xFFFFFFFF, false},
    {START, 0xFFFFFFFF, false}};

void apply_cheats() {
    if(tp_mPadStatus.sval == 0x0120) {
        if(tp_gameInfo.momentum_ptr) {
            tp_gameInfo.momentum_ptr->link_momentum.y = 56.0f;
        }
        set_buttons_down(0x0);
        set_buttons_pressed(0x0);
        tp_mPadButton.sval = 0x0;
        tp_mPadStatus.sval = 0x0;
    }
}

uint32_t read_controller()
{
    sButtons_down_last_frame = sButtons_down;
    sButtons_down = tp_mPadStatus.sval;
    sButtons_pressed = sButtons_down & (0xFFF ^ sButtons_down_last_frame);

    uint8_t idx = 0;
    for (; idx < BUTTON_STATES; idx++)
    {
        buttonStates[idx].is_down = (buttonStates[idx].button & sButtons_down) != 0;
        if ((buttonStates[idx].button & sButtons_pressed) != 0)
        {
            buttonStates[idx].pressed_frame = get_frame_count() + 1;
        }
    }
    apply_cheats();
    return 0x80000000;
}

bool _is_pressed(uint8_t button) {
    uint32_t delta = get_frame_count() - buttonStates[button].pressed_frame;
    bool just_clicked = delta == 0;
    bool held_down_long_enough = delta > REPEAT_DELAY;
    bool is_repeat_frame = held_down_long_enough && (delta % REPEAT_TIME == 0);

    return is_down(button) && (just_clicked || is_repeat_frame);
}

bool _is_down(uint8_t button) {
    return buttonStates[button].is_down;
}