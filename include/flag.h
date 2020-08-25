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
namespace Flags {
    struct TempFlags {
        uint8_t temp_flag_bit_field_1;   // 80406B14
        uint8_t temp_flag_bit_field_2;   // 80406B15
        uint8_t temp_flag_bit_field_3;   // 80406B16
        uint8_t temp_flag_bit_field_4;   // 80406B17
        uint8_t temp_flag_bit_field_5;   // 80406B18
        uint8_t temp_flag_bit_field_6;   // 80406B19
        uint8_t temp_flag_bit_field_7;   // 80406B1A
        uint8_t temp_flag_bit_field_8;   // 80406B1B
        uint8_t temp_flag_bit_field_9;   // 80406B1C
        uint8_t temp_flag_bit_field_10;  // 80406B1D
        uint8_t temp_flag_bit_field_11;  // 80406B1E
        uint8_t temp_flag_bit_field_12;  // 80406B1F
        uint8_t temp_flag_bit_field_13;  // 80406B20
        uint8_t temp_flag_bit_field_14;  // 80406B21
        uint8_t temp_flag_bit_field_15;  // 80406B22
        uint8_t temp_flag_bit_field_16;  // 80406B23
        uint8_t temp_flag_bit_field_17;  // 80406B24
        uint8_t temp_flag_bit_field_18;  // 80406B25
        uint8_t temp_flag_bit_field_19;  // 80406B26
        uint8_t temp_flag_bit_field_20;  // 80406B27
        uint8_t temp_flag_bit_field_21;  // 80406B28
        uint8_t temp_flag_bit_field_22;  // 80406B29
        uint8_t temp_flag_bit_field_23;  // 80406B2A
        uint8_t temp_flag_bit_field_24;  // 80406B2B
        uint8_t temp_flag_bit_field_25;  // 80406B2C
        uint8_t temp_flag_bit_field_26;  // 80406B2D
        uint8_t temp_flag_bit_field_27;  // 80406B2E
        uint8_t temp_flag_bit_field_28;  // 80406B2F
        uint8_t temp_flag_bit_field_29;  // 80406B30
        uint8_t temp_flag_bit_field_30;  // 80406B31
        uint8_t temp_flag_bit_field_31;  // 80406B32
        uint8_t temp_flag_bit_field_32;  // 80406B33
        uint8_t temp_flag_bit_field_33;  // 80406B34 // handles local area keys
        uint8_t temp_flag_bit_field_34;  // 80406B35 // in dungeons: map is bit 0, compass bit 1, boss key bit 2 
        uint8_t temp_flag_bit_field_35;  // 80406B36
        uint8_t temp_flag_bit_field_36;  // 80406B37
    };                                   // struct TempFlags
    static_assert(sizeof(TempFlags) == 0x24);

    struct GlobalFlags {
        uint8_t flags_0;   // 0x00
        uint8_t flags_1;   // 0x01
        uint8_t flags_2;   // 0x02
        uint8_t flags_3;   // 0x03
        uint8_t flags_4;   // 0x04
        uint8_t flags_5;   // 0x05
        uint8_t flags_6;   // 0x06
        uint8_t flags_7;   // 0x07
        uint8_t flags_8;   // 0x08
        uint8_t flags_9;   // 0x09
        uint8_t flags_10;  // 0x0A
        uint8_t flags_11;  // 0x0B
        uint8_t flags_12;  // 0x0C
        uint8_t flags_13;  // 0x0D
        uint8_t flags_14;  // 0x0E
        uint8_t flags_15;  // 0x0F
        uint8_t flags_16;  // 0x10
        uint8_t flags_17;  // 0x11
        uint8_t flags_18;  // 0x12
        uint8_t flags_19;  // 0x13
        uint8_t flags_20;  // 0x14
        uint8_t flags_21;  // 0x15
        uint8_t flags_22;  // 0x16
        uint8_t flags_23;  // 0x17
        uint8_t flags_24;  // 0x18
        uint8_t flags_25;  // 0x19
        uint8_t flags_26;  // 0x1A
        uint8_t flags_27;  // 0x1B
        uint8_t flags_28;  // 0x1C // handles small key count
        uint8_t flags_29;  // 0x1D // handles key items; bit 0 map, bit 1 compass, bit 2 boss key. bit 3 boss beaten, bit 4 obtained heart container, bit 6 obtained ooccoo, bit 7 miniboss defeated
        uint8_t flags_30;  // 0x1E
        uint8_t flags_31;  // 0x1F
    };
    static_assert(sizeof(GlobalFlags) == 0x20);
};      // namespace Flags
#endif  // LIB_TP_FLAG