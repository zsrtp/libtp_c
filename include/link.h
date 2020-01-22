#ifndef LIB_TP_LINK
#define LIB_TP_LINK

#include <stdint.h>

struct Link {
    uint8_t _p0;                // C0
    uint8_t heart_pieces;       // C1
    uint8_t _p1;                // C2
    uint8_t heart_quarters;     // C3
    uint16_t rupees;            // C4
    uint8_t _p2[2];             // C6
    uint16_t lamp_fuel;         // C8
    uint8_t _p3;                // CA
    uint8_t item_on_x;          // CB
    uint8_t item_on_y;          // CC
    uint8_t _p4[2];             // CD
    uint8_t slot_x_combo_item;  // CF
    uint8_t slot_y_combo_item;  // D0
    uint8_t _p5[2];             // D1
    uint8_t armor;              // D3
    uint8_t sword;              // D4
    uint8_t shield;             // D5
    uint8_t _p6[3];             // D6
    uint8_t wallet_upgrade;     // D9
    uint8_t _p7[4];             // DA
    bool is_wolf;               // DE
    uint8_t _p8;                // DF
};

#endif  // LIB_TP_LINK