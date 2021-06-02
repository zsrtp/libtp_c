#ifndef D_METER_D_METER_HIO_H
#define D_METER_D_METER_HIO_H

#include <stdint.h>
#include "../../addrs.h"

// figure out actual struct later
namespace Draw {
    struct DrawProperty {
        uint8_t _p0[0x18];   // 8042EBC8
        uint16_t hud;        // 8042EBE0
        uint8_t _p1[0xF0E];  // 8042EBE2
    };
    static_assert(sizeof(DrawProperty) == 0xF28);

};  // namespace Draw

#define g_drawHIO (*(Draw::DrawProperty *)tp_draw_addr)

#endif /* D_METER_D_METER_HIO_H */
