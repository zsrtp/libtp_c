#ifndef LIB_TP_OOCCOO
#define LIB_TP_OOCCOO

#include <stdint.h>

namespace Ooccoo {
    struct Ooccoo {
        float ooccoo_x_pos;                         // 80406240
        float ooccoo_y_pos;                         // 80406244
        float ooccoo_z_pos;                         // 80406248
        uint16_t ooccoo_angle;                      // 8040624C
        uint8_t ooccoo_stage[0x08];                 // 8040624E
        uint8_t ooccoo_spawn_id;                    // 80406256 // appears unused
        uint8_t ooccoo_room_id;                     // 80406257
    }; // struct Ooccoo
}; // namespace Ooccoo

#endif //LIB_TP_EPONA