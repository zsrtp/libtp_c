#include "flag.h"
#include <stdint.h>

void Flag::activate() {
    (*(uint8_t *)addr) |= bit;
}

void Flag::deactivate() {
    (*(uint8_t *)addr) &= 0xFF ^ bit;
}

bool Flag::is_active() {
    return ((*(uint8_t *)addr) & bit) != 0;
}

void Flag::toggle() {
    if (is_active()) {
        deactivate();
    } else {
        activate();
    }
}