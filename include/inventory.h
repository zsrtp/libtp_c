#ifndef LIB_TP_INVENTORY
#define LIB_TP_INVENTORY

#include <stdint.h>

#define GALE_BOOMERANG_ID_INDEX 0
#define LANTERN_ID_INDEX 1
#define SPINNER_ID_INDEX 2
#define IRON_BOOTS_ID_INDEX 3
#define HEROS_BOW_ID_INDEX 4
#define HAWKEYE_ID_INDEX 5
#define BALL_AND_CHAIN_ID_INDEX 6
#define DOMINION_ROD_ID_INDEX 8
#define CLAWSHOT_ID_INDEX 9
#define DOUBLE_CLAWSHOT_ID_INDEX 10
#define BOTTLE_1_ID_INDEX 11
#define BOTTLE_2_ID_INDEX 12
#define BOTTLE_3_ID_INDEX 13
#define BOTTLE_4_ID_INDEX 14
#define BOMB_BAG_1_ID_INDEX 15
#define BOMB_BAG_2_ID_INDEX 16
#define BOMB_BAG_3_ID_INDEX 17
#define OOCCOO_ID_INDEX 18
#define LETTER_ID_INDEX 19
#define FISHING_ROD_ID_INDEX 20
#define ILIA_QUEST_ID_INDEX 21
#define SKY_BOOK_ID_INDEX 22
#define SLINGSHOT_ID_INDEX 23

typedef struct {
    uint8_t value[24];
} ItemValues;

typedef struct {
    uint8_t slot[24];
} ItemWheel;

typedef struct {
    ItemValues item_values;
    ItemWheel item_wheel;
    uint8_t _p0[3];
    uint8_t rupee_cs_flags;
    uint8_t _p1;
    uint8_t collection_flags_0;
    uint8_t collection_flags_1;
    uint8_t _p2[3];
    uint8_t master_sword_flag;
    uint8_t _p3[21];
    uint8_t arrow_count;
    uint8_t bomb_bag_1_amnt;
    uint8_t bomb_bag_2_amnt;
    uint8_t bomb_bag_3_amnt;
    uint8_t _p4[8];
    uint8_t arrow_capacity;
} Inventory;

#endif // LIB_TP_INVENTORY