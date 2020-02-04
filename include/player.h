#ifndef LIB_TP_PLAYER
#define LIB_TP_PLAYER

#include <stdint.h>

namespace Player {
    struct Player {
        uint8_t player_stage[0x08];                 // 80406218
        uint8_t player_spawn_id;                    // 80406220
        uint8_t player_room_id;                     // 80406221
        uint8_t _p3[0x10];                          // 80406222
        uint8_t player_previous_stage[0x08];        // 80406232
    }; // struct Player

    static_assert(sizeof(Player) == 0x22);

    struct Filename {
        uint8_t player_file_name[0x10];             // 80406374
    }; // struct Filename

    static_assert(sizeof(Filename) == 0x10);
}; // namespace Player

#endif // LIB_TP_PLAYER