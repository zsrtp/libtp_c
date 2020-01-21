#ifndef LIB_TP_CONTROLLER
#define LIB_TP_CONTROLLER

#include <stdint.h>
#include <stdbool.h>
#include "addrs.h"

#define DPAD_LEFT 0x0001
#define DPAD_RIGHT 0x0002
#define DPAD_DOWN 0x0004
#define DPAD_UP 0x0008
#define Z 0x0010
#define R 0x0020
#define L 0x0040
#define A 0x0100
#define B 0x0200
#define X 0x0400
#define Y 0x0800
#define START 0x1000

typedef struct
{
    uint16_t sval;
} PadStatus;

typedef struct
{
    uint8_t analog_cardinal;
    uint8_t c_cardinal;
    uint16_t buttons;
    uint8_t _p1[2];
    uint16_t buttons_down;
    uint8_t _p2[18];
    uint16_t sval;
} PadButton;

#define tp_mPadButton (*(PadButton *)tp_mPadButton_addr)
#define tp_mPadStatus (*(PadStatus *)tp_mPadStatus_addr)

uint16_t buttons_down();
uint16_t buttons_pressed();
void set_buttons_down(uint16_t buttons);
void set_buttons_pressed(uint16_t buttons);
bool is_down(uint16_t buttons);
bool is_pressed(uint16_t buttons);

#endif // LIB_TP_CONTROLLER