#include "inventory.h"
#include "flag.h"
#include "tp.h"

namespace Inventory {
    Inventory *get_inventory() {
        return &tp_gameInfo.inventory;
    }

    Flag bomb_capacity_flag() {
        return Flag((uint32_t)&tp_gameInfo.inventory.master_sword_flag, 7);
    }

    Flag ordon_sword_flag() {
        return Flag((uint32_t)&tp_gameInfo.inventory.collection_flags_1, 0);
    }

    Flag master_sword_flag() {
        return Flag((uint32_t)&tp_gameInfo.inventory.collection_flags_1, 1);
    }

    Flag light_sword_flag() {
        return Flag((uint32_t)&tp_gameInfo.inventory.master_sword_flag, 1);
    }

    Flag ordon_shield_flag() {
        return Flag((uint32_t)&tp_gameInfo.inventory.collection_flags_1, 2);
    }

    Flag wooden_shield_flag() {
        return Flag((uint32_t)&tp_gameInfo.inventory.collection_flags_1, 3);
    }

    Flag hylian_shield_flag() {
        return Flag((uint32_t)&tp_gameInfo.inventory.collection_flags_1, 4);
    }

    Flag heros_clothes_flag() {
        return Flag((uint32_t)&tp_gameInfo.inventory.collection_flags_1, 7);
    }

    Flag magic_armor_flag() {
        return Flag((uint32_t)&tp_gameInfo.inventory.collection_flags_0, 0);
    }

    Flag zora_armor_flag() {
        return Flag((uint32_t)&tp_gameInfo.inventory.collection_flags_0, 1);
    }

    void get_item(uint8_t item) {
        tp_execItemGet(item);
    }
}  // namespace Inventory