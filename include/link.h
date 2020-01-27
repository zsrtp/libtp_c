#ifndef LIB_TP_LINK
#define LIB_TP_LINK

#include <stdint.h>
#include "utils.h"

namespace Link {
    struct Link {
        uint8_t _p0;                // 804061C0
        uint8_t heart_pieces;       // 804061C1
        uint8_t _p1;                // 804061C2
        uint8_t heart_quarters;     // 804061C3
        uint16_t rupees;            // 804061C4
        uint8_t _p2[2];             // 804061C6
        uint16_t lamp_fuel;         // 804061C8
        uint8_t _p3;                // 804061CA
        uint8_t item_on_x;          // 804061CB
        uint8_t item_on_y;          // 804061CC
        uint8_t _p4[2];             // 804061CD
        uint8_t slot_x_combo_item;  // 804061CF
        uint8_t slot_y_combo_item;  // 804061D0
        uint8_t _p5[2];             // 804061D1
        uint8_t armor;              // 804061D3
        uint8_t sword;              // 804061D4
        uint8_t shield;             // 804061D5
        uint8_t _p6[3];             // 804061D6
        uint8_t wallet_upgrade;     // 804061D9
        uint8_t _p7[4];             // 804061DA
        bool is_wolf;               // 804061DE
        uint8_t _p8;                // 804061DF
    };

    Link *get_link();
    Vec3 *get_position();
    uint16_t *get_air();
}  // namespace Link

#endif  // LIB_TP_LINK