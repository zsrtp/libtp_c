#include <stdint.h>
#include <stdbool.h>
#include "flag.h"

void flag_activate(Flag flag) {
    (*(uint8_t*)flag.addr) |= flag.bit;
}

void flag_deactivate(Flag flag) {
    (*(uint8_t*)flag.addr) &= 0xFF ^ flag.bit;
}

bool flag_is_active(Flag flag) {
    return (*(uint8_t*)flag.addr) & flag.bit != 0;
}

void flag_toggle(Flag flag) {
    if (flag_is_active(flag)) {
        flag_deactivate(flag);
    } else {
        flag_activate(flag);
    }
}