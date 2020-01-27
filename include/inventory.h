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
            uint8_t value[24];
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

    struct ItemWheel {
        uint8_t slot[24];
    };

    struct Inventory {
        ItemValues item_values;      // 8040625C
        ItemWheel item_wheel;        // 80406274
        uint8_t _p0[3];              // 8040628C
        uint8_t rupee_cs_flags;      // 8040628F
        uint8_t _p1;                 // 80406290
        uint8_t collection_flags_0;  // 80406291
        uint8_t collection_flags_1;  // 80406292
        uint8_t _p2[3];              // 80406293
        uint8_t master_sword_flag;   // 80406296
        uint8_t _p3[21];             // 80406297
        uint8_t arrow_count;         // 804062aC
        uint8_t bomb_bag_1_amnt;     // 804062aD
        uint8_t bomb_bag_2_amnt;     // 804062aE
        uint8_t bomb_bag_3_amnt;     // 804062aF
        uint8_t _p4[8];              // 804062b0
        uint8_t arrow_capacity;      // 804062b8
    };

    typedef void (*tp_execItemGet)(uint8_t item);
#define tp_execItemGet ((tp_execItemGet)tp_execItemGet_addr)

    Inventory *get_inventory();
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
    // uint8_t get_by_slot_id(uint8_t slot_id);
    // void set_by_slot_id(uint8_t slot_id, uint8_t item_id);
    void get_item(uint8_t item);
}  // namespace Inventory

#endif  // LIB_TP_INVENTORY