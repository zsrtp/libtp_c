#ifndef LIB_TP_ACTOR
#define LIB_TP_ACTOR

#include <stdint.h>
#include "addrs.h"

namespace Actor {
    struct ActorProperty {
        uint8_t _p0[0x04];  // 80450610
        bool freeze;        // 80450614
        uint8_t _p1[0x03];  // 80450615
    };
    static_assert(sizeof(ActorProperty) == 0x8);
};  // namespace Actor

#define tp_actor (*(Actor::ActorProperty *)tp_actor_addr)

#endif  // LIB_TP_ACTOR