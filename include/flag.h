#ifndef LIB_TP_FLAG
#define LIB_TP_FLAG

#include <stdint.h>

class Flag {
   private:
    uint32_t addr;
    uint8_t bit;

   public:
    Flag(uint32_t addr, uint8_t bit) : addr(addr), bit(bit) {}
    void activate();
    void deactivate();
    bool is_active();
    void toggle();
};

#endif  // LIB_TP_FLAG