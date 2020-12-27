#ifndef LIB_TP_INVENTORY
#define LIB_TP_INVENTORY

#include <stdint.h>
#include "flag.h"

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

namespace Inventory {
struct ItemValues {
    union {
        uint8_t value[24];  // 8040625C
        struct {
            uint8_t gale_boomerang_id;              // 8040625C
            uint8_t lantern_id;                     // 8040625D
            uint8_t spinner_id;                     // 8040625E
            uint8_t iron_boots_id;                  // 8040625F
            uint8_t hero_s_bow_id;                  // 80406260
            uint8_t hawkeye_id;                     // 80406261
            uint8_t ball_and_chain_id;              // 80406262
            uint8_t _unk_0;                         // 80406263
            uint8_t dominion_rod_id;                // 80406264
            uint8_t clawshot_id;                    // 80406265
            uint8_t double_clawshot_id;             // 80406266
            uint8_t bottle_1_id;                    // 80406267
            uint8_t bottle_2_id;                    // 80406268
            uint8_t bottle_3_id;                    // 80406269
            uint8_t bottle_4_id;                    // 8040626A
            uint8_t bomb_bag_1_id;                  // 8040626B
            uint8_t bomb_bag_2_id;                  // 8040626C
            uint8_t bomb_bag_3_id;                  // 8040626D
            uint8_t ooccoo_id;                      // 8040626E
            uint8_t auru_s_memo_ashei_s_sketch_id;  // 8040626F
            uint8_t fishing_rod_earring_id;         // 80406270
            uint8_t horse_call_id;                  // 80406271
            uint8_t ancient_sky_book_id;            // 80406272
            uint8_t slingshot_id;                   // 80406273
        };
    };
};
static_assert(sizeof(ItemValues) == 0x18);

struct ItemWheel {
    uint8_t slot[24];  // 80406274
};
static_assert(sizeof(ItemWheel) == 0x18);

struct Inventory {
    ItemValues item_values;     // 8040625C
    ItemWheel item_wheel;       // 80406274
    uint8_t _p0[0x03];          // 8040628C
    uint8_t rupee_cs_flags;     // 8040628F
    uint8_t wood_sword_flag;    // 80406290 // bit 7 wooden sword
    uint8_t equipment_flags_0;  // 80406291 // bit 0 magic armor, bit 1 zora armor
    uint8_t equipment_flags_1;  // 80406292 // bit 0 ordon sword, bit 1 master sword, bit 2 ordon
                                // shield, bit 3 wooden shield, bit 4 hylian shield, bit 7 hero's
                                // clothes
    uint8_t _p2[0x03];          // 80406293
    uint8_t light_sword_flag;   // 80406296 // bit 2 sets light sword
    uint8_t _p3[0x0E];          // 80406297
    uint8_t snail_dragonfly_ant_dayfly_flags;         // 804062A5
    uint8_t phasmid_pillbug_mantis_ladybug_flags;     // 804062A6
    uint8_t beetle_butterfly_stag_grasshopper_flags;  // 804062A7
    uint8_t gm_key_shards;    // 804062A8 // bit 1 sets shard 1, bit 2 shard 2, bit 3 shard 3
    uint8_t spr_key_items;    // 804062A9 // bit 4 sets pumpkin, bit 5 cheese, bit 6 bedroom key
    uint8_t _p4[0x02];        // 804062AA
    uint8_t arrow_count;      // 804062AC
    uint8_t bomb_bag_1_amnt;  // 804062AD
    uint8_t bomb_bag_2_amnt;  // 804062AE
    uint8_t bomb_bag_3_amnt;  // 804062AF
    uint8_t _p5[0x04];        // 804062B0
    uint8_t slingshot_count;  // 804062B4
    uint8_t _p6[0x03];        // 804062B5
    uint8_t arrow_capacity;   // 804062B8
    uint8_t _p7[0x13];        // 804062B9
    uint8_t poe_count;        // 804062CC
    uint8_t _p8[0x8];         // 804062CD
    uint8_t tears;            // 804062D5
    uint8_t _p11[0x8];        // 804062D6
    uint16_t letters;         // 804062DE
    uint8_t _p9[0x4C];        // 804062E0
    uint16_t fishing_jrnl_hbass_no_caught;      // 8040632C
    uint16_t fishing_jrnl_hloach_no_caught;     // 8040632E
    uint16_t fishing_jrnl_hpike_no_caught;      // 80406330
    uint16_t fishing_jrnl_ocatfish_no_caught;   // 80406332
    uint16_t fishing_jrnl_reekfish_no_caught;   // 80406334
    uint16_t fishing_jrnl_greengill_no_caught;  // 80406336
    uint8_t _p10[0x14];                         // 80406338
    uint8_t fishing_jrnl_hbass_largest;         // 8040634C
    uint8_t fishing_jrnl_hloach_largest;        // 8040634D
    uint8_t fishing_jrnl_hpike_largest;         // 8040634E
    uint8_t fishing_jrnl_ocatfish_largest;      // 8040634F
    uint8_t fishing_jrnl_reekfish_largest;      // 80406350
    uint8_t fishing_jrnl_greengill_largest;     // 80406351
};
static_assert(sizeof(Inventory) == 0xF6);
//int i = sizeof(Inventory);
typedef void (*tp_execItemGet)(uint8_t item);
#define tp_execItemGet ((tp_execItemGet)tp_execItemGet_addr)

Inventory* get_inventory();
Flag bomb_capacity_flag();
Flag ordon_sword_flag();
Flag master_sword_flag();
Flag light_sword_flag();
Flag ordon_shield_flag();
Flag wooden_shield_flag();
Flag hylian_shield_flag();
Flag heros_clothes_flag();
Flag magic_armor_flag();
Flag zora_armor_flag();
Flag silver_rupee_flag();
Flag orange_rupee_flag();
Flag purple_rupee_flag();
Flag red_rupee_flag();
Flag yellow_rupee_flag();
Flag blue_rupee_flag();
void clear_rupee_flags();
void set_rupee_flags();
void get_item(uint8_t item);
}  // namespace Inventory

#endif  // LIB_TP_INVENTORY
