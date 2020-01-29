#ifndef LIB_TP_EPONA
#define LIB_TP_EPONA

#include <stdint.h>

namespace Epona {
    struct Epona {
        float epona_x_pos;                          // 80406200
        float epona_y_pos;                          // 80406204
        float epona_z_pos;                          // 80406208
        uint16_t epona_angle;                       // 8040620C
        uint8_t epona_stage[0x08];                  // 8040620E
        uint8_t epona_spawn_point_id;               // 80406216
        uint8_t epona_room_id;                      // 80406217
    }; // struct Epona

    struct Filename {
        uint8_t epona_file_name[0x10];              // 80406385
    }; // struct filename
}; // namespace Epona

#endif //LIB_TP_EPONA