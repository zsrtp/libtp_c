#ifndef LIB_TP_ACTOR
#define LIB_TP_ACTOR

#include <stdint.h>
#include "addrs.h"

namespace Actor {
    struct Property {
        uint8_t _p0[0x04];  // 80450610
        bool freeze;        // 80450614
        uint8_t _p1[0x03];  // 80450615
    };
    static_assert(sizeof(Property) == 0x8);

    struct StopStatus {
        uint8_t _p0[0x02];  // 80450CBC
        bool hide_actors;   // 80450CBD
        uint8_t _p1[0x01];  // 80450CBE
    };
    static_assert(sizeof(StopStatus) == 0x4);
};  // namespace Actor

#define tp_actor (*(Actor::Property *)tp_actor_addr)
#define tp_stopstatus (*(Actor::StopStatus *)tp_actor_stopstatus_addr)


#endif  // LIB_TP_ACTOR