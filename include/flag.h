#ifndef LIB_TP_FLAG
#define LIB_TP_FLAG

#include <stdint.h>
#include <stdbool.h>

typedef struct {
    uint32_t addr;
    uint8_t bit;
} Flag;

void flag_activate(Flag flag);
void flag_deactivate(Flag flag);
bool flag_is_active(Flag flag);
void flag_toggle(Flag flag);

#endif // LIB_TP_FLAG