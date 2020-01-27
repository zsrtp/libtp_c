#include "link.h"
#include <stdint.h>
#include <cstddef>
#include "tp.h"
#include "utils.h"

namespace Link {
    using namespace TP;
    Link *get_link() {
        return &tp_gameInfo.link;
    }
    Vec3 *get_position() {
        LinkDebug *link_debug = get_link_debug();
        if (link_debug) {
            return &link_debug->position;
        } else {
            return NULL;
        }
    }

    uint16_t *get_angle() {
        LinkDebug *link_debug = get_link_debug();
        if (link_debug) {
            return &link_debug->facing;
        } else {
            return NULL;
        }
    }

    float *get_speed() {
        LinkDebug *link_debug = get_link_debug();
        if (link_debug) {
            return &link_debug->speed;
        } else {
            return NULL;
        }
    }

    uint16_t *get_air() {
        return &tp_gameInfo.link_air_meter;
    }
}  // namespace Link