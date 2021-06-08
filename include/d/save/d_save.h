#ifndef D_SAVE_D_SAVE_H
#define D_SAVE_D_SAVE_H

#include "../../SSystem/SComponent/c_xyz.h"
#include <stdint.h>

#define DEFAULT_SELECT_ITEM_INDEX 0
#define MAX_SELECT_ITEM 3
#define MAX_EVENTS 256
#define MAX_ITEM_SLOTS 24
#define ITEM_XY_MAX_DUMMY 8
#define LIGHT_DROP_STAGE 4
#define LETTER_INFO_BIT 64
#define BOMB_BAG_MAX 3
#define BOTTLE_MAX 4
#define TBOX_MAX 64
#define DSV_MEMBIT_ENUM_MAX 8

enum Wallets { WALLET, BIG_WALLET, GIANT_WALLET };

enum ItemSlots {
    SLOT_0,
    SLOT_1,
    SLOT_2,
    SLOT_3,
    SLOT_4,
    SLOT_5,
    SLOT_6,
    SLOT_7,
    SLOT_8,
    SLOT_9,
    SLOT_10,
    SLOT_11,
    SLOT_12,
    SLOT_13,
    SLOT_14,
    SLOT_15,
    SLOT_16,
    SLOT_17,
    SLOT_18,
    SLOT_19,
    SLOT_20,
    SLOT_21,
    SLOT_22,
    SLOT_23
};

enum ItemTable {
    HEART,
    GREEN_RUPEE,
    BLUE_RUPEE,
    YELLOW_RUPEE,
    RED_RUPEE,
    PURPLE_RUPEE,
    ORANGE_RUPEE,
    SILVER_RUPEE,
    S_MAGIC,
    L_MAGIC,
    BOMB_5,
    BOMB_10,
    BOMB_20,
    BOMB_30,
    ARROW_10,
    ARROW_20,
    ARROW_30,
    ARROW_1,
    PACHINKO_SHOT,
    noentry1,
    noentry2,
    noentry3,
    WATER_BOMB_5,
    WATER_BOMB_10,
    WATER_BOMB_20,
    WATER_BOMB_30,
    BOMB_INSECT_5,
    BOMB_INSECT_10,
    BOMB_INSECT_20,
    BOMB_INSECT_30,
    RECOVERY_FAILY,
    TRIPLE_HEART,
    SMALL_KEY,
    KAKERA_HEART,
    UTAWA_HEART,
    MAP,
    COMPUS,
    DUNGEON_EXIT,
    BOSS_KEY,
    DUNGEON_BACK,
    SWORD,
    MASTER_SWORD,
    WOOD_SHIELD,
    SHIELD,
    HYLIA_SHIELD,
    TKS_LETTER,
    WEARS_CASUAL,
    WEAR_KOKIRI,
    ARMOR,
    WEAR_ZORA,
    MAGIC_LV1,
    DUNGEON_EXIT_2,
    WALLET_LV1,
    WALLET_LV2,
    WALLET_LV3,
    noentry4,
    noentry5,
    noentry6,
    noentry7,
    noentry8,
    noentry9,
    ZORAS_JEWEL,
    HAWK_EYE,
    WOOD_STICK,
    BOOMERANG,
    SPINNER,
    IRONBALL,
    BOW,
    HOOKSHOT,
    HVY_BOOTS,
    COPY_ROD,
    W_HOOKSHOT,
    KANTERA,
    LIGHT_SWORD,
    FISHING_ROD_1,
    PACHINKO,
    COPY_ROD_2,
    noentry10,
    noentry11,
    BOMB_BAG_LV2,
    BOMB_BAG_LV1,
    BOMB_IN_BAG,
    noentry12,
    LIGHT_ARROW,
    ARROW_LV1,
    ARROW_LV2,
    ARROW_LV3,
    noentry13,
    LURE_ROD,
    BOMB_ARROW,
    HAWK_ARROW,
    BEE_ROD,
    JEWEL_ROD,
    WORM_ROD,
    JEWEL_BEE_ROD,
    JEWEL_WORM_ROD,
    EMPTY_BOTTLE,
    RED_BOTTLE,
    GREEN_BOTTLE,
    BLUE_BOTTLE,
    MILK_BOTTLE,
    HALF_MILK_BOTTLE,
    OIL_BOTTLE,
    WATER_BOTTLE,
    OIL_BOTTLE_2,
    RED_BOTTLE_2,
    UGLY_SOUP,
    HOT_SPRING,
    FAIRY,
    HOT_SPRING_2,
    OIL2,
    OIL,
    NORMAL_BOMB,
    WATER_BOMB,
    POKE_BOMB,
    FAIRY_DROP,
    WORM,
    DROP_BOTTLE,
    BEE_CHILD,
    CHUCHU_RARE,
    CHUCHU_RED,
    CHUCHU_BLUE,
    CHUCHU_GREEN,
    CHUCHU_YELLOW,
    CHUCHU_PURPLE,
    LV1_SOUP,
    LV2_SOUP,
    LV3_SOUP,
    LETTER,
    BILL,
    WOOD_STATUE,
    IRIAS_PENDANT,
    HORSE_FLUTE,
    noentry14,
    noentry15,
    noentry16,
    noentry17,
    noentry18,
    noentry19,
    noentry20,
    noentry21,
    noentry22,
    noentry23,
    noentry24,
    RAFRELS_MEMO,
    ASHS_SCRIBBLING,
    noentry25,
    noentry26,
    noentry27,
    noentry28,
    noentry29,
    noentry30,
    noentry31,
    noentry32,
    noentry33,
    noentry34,
    CHUCHU_YELLOW2,
    OIL_BOTTLE3,
    SHOP_BEE_CHILD,
    CHUCHU_BLACK,
    LIGHT_DROP,
    DROP_CONTAINER,
    DROP_CONTAINER02,
    DROP_CONTAINER03,
    FILLED_CONTAINER,
    MIRROR_PIECE_2,
    MIRROR_PIECE_3,
    MIRROR_PIECE_4,
    noentry35,
    noentry36,
    noentry37,
    noentry38,
    noentry39,
    noentry40,
    noentry41,
    noentry42,
    SMELL_YELIA_POUCH,
    SMELL_PUMPKIN,
    SMELL_POH,
    SMELL_FISH,
    SMELL_CHILDREN,
    SMELL_MEDICINE,
    noentry43,
    noentry44,
    noentry45,
    noentry46,
    noentry47,
    noentry48,
    noentry49,
    noentry50,
    noentry51,
    noentry52,
    M_BEETLE,
    F_BEETLE,
    M_BUTTERFLY,
    F_BUTTERFLY,
    M_STAG_BEETLE,
    F_STAG_BEETLE,
    M_GRASSHOPPER,
    F_GRASSHOPPER,
    M_NANAFUSHI,
    F_NANAFUSHI,
    M_DANGOMUSHI,
    F_DANGOMUSHI,
    M_MANTIS,
    F_MANTIS,
    M_LADYBUG,
    F_LADYBUG,
    M_SNAIL,
    F_SNAIL,
    M_DRAGONFLY,
    F_DRAGONFLY,
    M_ANT,
    F_ANT,
    M_MAYFLY,
    F_MAYFLY,
    noentry53,
    noentry54,
    noentry55,
    noentry56,
    noentry57,
    noentry58,
    noentry59,
    noentry60,
    POU_SPIRIT,
    noentry61,
    noentry62,
    noentry63,
    noentry64,
    noentry65,
    noentry66,
    noentry67,
    noentry68,
    ANCIENT_DOCUMENT,
    AIR_LETTER,
    ANCIENT_DOCUMENT2,
    LV7_DUNGEON_EXIT,
    LINKS_SAVINGS,
    SMALL_KEY2,
    POU_FIRE1,
    POU_FIRE2,
    POU_FIRE3,
    POU_FIRE4,
    BOSSRIDER_KEY,
    TOMATO_PUREE,
    TASTE,
    LV5_BOSS_KEY,
    SURFBOARD,
    KANTERA2,
    L2_KEY_PIECES1,
    L2_KEY_PIECES2,
    L2_KEY_PIECES3,
    KEY_OF_CARAVAN,
    LV2_BOSS_KEY,
    KEY_OF_FILONE,
    NO_ITEM
};

enum CollectItem { COLLECT_CLOTHING, COLLECT_SWORD, COLLECT_SHIELD, COLLECT_SMELL, B_BUTTON_ITEM };

enum Swords { ORDON_SWORD_FLAG, MASTER_SWORD_FLAG, WOODEN_SWORD_FLAG, LIGHT_SWORD_FLAG };

enum Shields { ORDON_SHIELD_FLAG, HYLIAN_SHIELD_FLAG, WOODEN_SHIELD_FLAG };

enum Armors { KOKIRI_CLOTHES_FLAG };

enum LightDropStages { FARON_VESSEL, ELDIN_VESSEL, LANAYRU_VESSEL };

enum ItemMax { ARROW_MAX, NORMAL_BOMB_MAX, WATER_BOMB_MAX, POKE_BOMB_MAX = 6 };

enum SelectItem { SELECT_ITEM_X, SELECT_ITEM_Y, };
enum MixItem { MIX_ITEM_X, MIX_ITEM_Y, };

enum TransformStatus { STATUS_HUMAN, STATUS_WOLF };

enum BombBags { BOMB_BAG_1, BOMB_BAG_2, BOMB_BAG_3 };

class dSv_player_status_a_c {
public:
    uint16_t& getMaxLife() { return mMaxLife; }
    uint16_t& getLife() { return mLife; }
    uint16_t& getRupee() { return mRupee; }
    uint16_t& getOil() { return mOil; }
    uint8_t& getWalletSize() { return mWalletSize; }
    uint8_t getSelectEquip(int item) const { return mSelectEquip[item]; }
    uint8_t getTransformStatus() const { return mTransformStatus; }

    void setOil(uint16_t oil) { mOil = oil; }
    void setMaxOil(uint16_t max) { mMaxOil = max; }
    void setWalletSize(uint8_t size) { mWalletSize = size; }
    void setMagic(uint8_t magic) { mMagic = magic; }
    void setMaxMagic(uint8_t max) { mMaxMagic = max; }
    void setRupee(uint16_t rupees) { mRupee = rupees; }
    void setLife(uint16_t life) { mLife = life; }
    void setMaxLife(uint8_t max) { mMaxLife = max; }
    void setSelectEquip(int item_index, uint8_t item) { mSelectEquip[item_index] = item; }
    void setTransformStatus(uint8_t status) { mTransformStatus = status; }

    /* 0x00 */ uint16_t mMaxLife;
    /* 0x02 */ uint16_t mLife;
    /* 0x04 */ uint16_t mRupee;
    /* 0x06 */ uint16_t mMaxOil;
    /* 0x08 */ uint16_t mOil;
    /* 0x0A */ uint8_t unk10;
    /* 0x0B */ uint8_t mSelectItem[3];
    /* 0x0E */ uint8_t mMixItem[3];
    /* 0x11 */ uint8_t unk17;
    /* 0x12 */ uint8_t unk18;
    /* 0x13 */ uint8_t mSelectEquip[6];
    /* 0x19 */ uint8_t mWalletSize;
    /* 0x1A */ uint8_t mMaxMagic;
    /* 0x1B */ uint8_t mMagic;
    /* 0x1C */ uint8_t mMagicFlag;
    /* 0x1D */ uint8_t unk29;
    /* 0x1E */ uint8_t mTransformStatus;
    /* 0x1F */ uint8_t unk31[3];
    /* 0x22 */ uint8_t padding[6];
};

class dSv_player_status_b_c {
public:
    void setTime(float pTime) { mTime = pTime; }
    float getTime() const { return mTime; }
    void offTransformLV(int32_t flag) { mTransformLevelFlag &= ~(1 << flag); }

    uint64_t mDateIpl;
    uint8_t mTransformLevelFlag;
    uint8_t mDarkClearLevelFlag;
    uint8_t unk10;
    uint8_t unk11;
    float mTime;
    uint16_t mDate;
    uint8_t unk18[3];
    uint8_t padding[3];
};

class dSv_horse_place_c {
public:
    cXyz mPosition;
    uint16_t mXRotation;
    char mCurrentStage[8];
    uint8_t mSpawnId;
    uint8_t mRoomId;
};

class dSv_player_return_place_c {
public:
    char mCurrentStage[8];
    uint8_t mSpawnId;
    uint8_t mRoomId;
    uint8_t unk10;
    uint8_t unk11;
};

class dSv_player_field_last_stay_info_c {
public:
    cXyz mPos;
    int16_t mAngleY;
    char mName[8];
    uint8_t mLastSpawnId;
    uint8_t mRegionNo;
    bool mFieldDataExistFlag;
    uint8_t mRegion;
    uint8_t unk26[2];
};

class dSv_player_last_mark_info_c {
public:
    const char* getName(void) { return mOoccooStage; }
    cXyz getPos(void) { return mOoccooPosition; }
    int16_t getAngleY(void) { return mOoccooXRotation; }
    int8_t getRoomNo(void) { return mOoccooRoomId; }
    char getWarpAcceptStage(void) { return mWarpAcceptStage; }

    cXyz mOoccooPosition;
    int16_t mOoccooXRotation;
    char mOoccooStage[8];
    uint8_t mOoccooSpawnId;
    int8_t mOoccooRoomId;
    char mWarpAcceptStage;
    uint8_t unk25[3];
};

class dSv_player_item_c {
public:
    uint8_t mItems[24];
    uint8_t mItemSlots[24];
};

class dSv_player_get_item_c {
public:
    uint32_t mItemBit[8];
};

class dSv_player_item_record_c {
public:
    void setArrowNum(uint8_t amount) { mArrowNum = amount; }
    uint8_t getArrowNum() { return mArrowNum; }
    void setPachinkoNum(uint8_t amount) { mPachinkoNum = amount; }
    uint8_t getPachinkoNum() { return mPachinkoNum; }

    uint8_t mArrowNum;
    uint8_t mBombNum[3];
    uint8_t mBottleNum[4];
    uint8_t mPachinkoNum;
    uint8_t unk5[3];
};

class dSv_player_item_max_c {
public:
    void setArrowNum(uint8_t max) { mItemMax[ARROW_MAX] = max; }
    uint8_t getArrowNum() { return mItemMax[ARROW_MAX]; }

    uint8_t mItemMax[8];
};

class dSv_player_collect_c {
public:
    uint8_t getPohNum() { return mPohNum; }
    void setPohNum(uint8_t num) { mPohNum = num; }

    uint8_t mItem[8];
    uint8_t unk8;
    uint8_t mCrystal;
    uint8_t mMirror;
    uint8_t unk11;
    uint8_t mPohNum;
    uint8_t padding[3];
};

class dSv_player_wolf_c {
public:
    uint8_t unk0[3];
    uint8_t unk3;
};

class dSv_light_drop_c {
public:
    uint8_t mLightDropNum[4];
    uint8_t mLightDropGetFlag;
    uint8_t unk5[3];
};

class dSv_letter_info_c {
public:
    uint32_t mLetterGetBitfields[2];
    uint32_t mLetterReadBitfields[2];
    uint8_t unk16[64];
};

class dSv_fishing_info_c {
public:
    uint16_t mFishCount[16];
    uint8_t mMaxSize[16];
    uint8_t padding[4];
};

class dSv_player_info_c {
public:
    char* getLinkName() { return (char*)mPlayerName; }

    uint32_t unk0;
    uint32_t unk4;
    uint64_t mTotalTime;
    uint16_t unk16;
    uint16_t mDeathCount;
    uint8_t mPlayerName[16];
    uint8_t unk36;
    uint8_t mHorseName[16];
    uint8_t unk53;
    uint8_t mClearCount;
    uint8_t unk55[5];
    uint8_t padding[4];
};

class dSv_player_config_c {
public:
    uint8_t unk0;
    uint8_t mSoundMode;
    uint8_t mAttentionType;
    uint8_t mVibration;
    uint8_t unk4;
    uint8_t unk5;
    uint16_t mCalibrateDist;
    uint8_t mCalValue;
    uint8_t mShortCut;
    uint8_t mCameraControl;
    uint8_t mPointer;
    uint8_t padding[4];
};

class dSv_player_c {
public:
    dSv_player_info_c& getPlayerInfo() { return mPlayerInfo; }
    dSv_player_status_a_c& getPlayerStatusA() { return player_status_a; }
    dSv_player_status_b_c& getPlayerStatusB() { return player_status_b; }
    dSv_player_item_c& getPlayerItem() { return player_item; }
    dSv_player_collect_c& getPlayerCollect() { return player_collect; }
    dSv_player_item_record_c& getPlayerItemRecord() { return player_item_record; }
    dSv_player_item_max_c& getPlayerItemMax() { return player_item_max; }
    dSv_player_last_mark_info_c& getPlayerLastMarkInfo() { return player_last_mark; }
    dSv_light_drop_c& getLightDrop() { return light_drop; }
    dSv_player_get_item_c& getPlayerGetItem() { return player_get_item; }

    dSv_player_status_a_c player_status_a;
    dSv_player_status_b_c player_status_b;
    dSv_horse_place_c horse_place;
    dSv_player_return_place_c player_return;
    dSv_player_field_last_stay_info_c player_last_field;
    dSv_player_last_mark_info_c player_last_mark;
    dSv_player_item_c player_item;
    dSv_player_get_item_c player_get_item;
    dSv_player_item_record_c player_item_record;
    dSv_player_item_max_c player_item_max;
    dSv_player_collect_c player_collect;
    dSv_player_wolf_c player_wolf;
    dSv_light_drop_c light_drop;
    dSv_letter_info_c letter_info;
    dSv_fishing_info_c fishing_info;
    dSv_player_info_c mPlayerInfo;
    dSv_player_config_c player_config;
};

#pragma pack(push, 1)
class dSv_memBit_c {
public:
    enum {
        MAP_FLAG,
        COMPASS_FLAG,
        BOSS_KEY_FLAG,
        STAGE_BOSS_ENEMY,
        STAGE_LIFE,
        STAGE_BOSS_DEMO,
        OOCCOO_NOTE_FLAG,
        STAGE_BOSS_ENEMY_2
    };

    uint8_t getKeyNum() { return mKeyNum; }
    void setKeyNum(uint8_t num) { mKeyNum = num; }
    void offDungeonItem(int flag) { mDungeonItem &= ~(1 << flag); }

    /* 0x00 */ uint32_t mTbox[2];
    /* 0x08 */ uint32_t mSwitch[4];
    /* 0x18 */ uint32_t mItem[1];  // not sure if this is right
    /* 0x1C */ uint8_t mKeyNum;
    /* 0x1D */ uint8_t mDungeonItem;
};
#pragma pack(pop)

class dSv_event_c {
public:
    uint8_t mEvent[256];
};

class dSv_MiniGame_c {
public:
    uint8_t unk0;
    uint8_t unk1[3];
    uint32_t unk4;
    uint32_t mBalloonScore;
    uint32_t mRaceGameTime;
    uint32_t unk16;
    uint32_t unk20;
};

class dSv_memory_c {
public:
    dSv_memBit_c& getMemBit() { return mMemBit; }
    const dSv_memBit_c& getMemBitConst() const { return mMemBit; }

    enum {
        ORDON,
        SEWERS,
        FARON,
        ELDIN,
        LANAYRU,
        FIELD = 6,
        GROVE,
        SNOWPEAK,
        TOWN,
        DESERT,
        POND,
        FOREST_TEMPLE = 16,
        GORON_MINES,
        LAKEBED,
        ARBITERS,
        SNOWPEAK_RUINS,
        TEMPLE_OF_TIME,
        CITY,
        PALACE,
        HYRULE_CASTLE,
        CAVE_1,
        CAVE_2,
        GROTTO
    };

    dSv_memBit_c mMemBit;
    uint8_t padding30[2];
};

class dSv_memory2_c {
public:
    uint32_t mVisitedRoom[2];
};

class dSv_danBit_c {
public:
    int8_t mStageNo;
    uint8_t unk1;
    uint8_t unk2[2];
    uint32_t mSwitch[2];
    uint32_t mItem[4];
    int16_t unk28[16];
};

class dSv_zoneBit_c {
public:
    uint16_t mSwitch[2];
    uint16_t mRoomSwitch;
    uint16_t mItem[2];
    uint16_t mRoomItem;
    uint16_t unk12;
};

class dSv_zoneActor_c {
public:
    static const int ACTOR_MAX = 0xFFFF;

    uint32_t actor_bitfield[4];
};

class dSv_zone_c {
public:
    dSv_zoneBit_c& getZoneBit() { return mBit; }
    const dSv_zoneBit_c& getZoneBitConst() const { return mBit; }
    dSv_zoneActor_c& getZoneActor() { return mActor; }
    const dSv_zoneActor_c& getZoneActorConst() const { return mActor; }

    int8_t& getRoomNo() { return mRoomNo; }

    int8_t mRoomNo;
    uint8_t unk1;
    dSv_zoneBit_c mBit;
    dSv_zoneActor_c mActor;
};

class dSv_restart_c {
public:
    /* 0x00 */ int8_t mRoomNo;
    /* 0x01 */ uint8_t field_0x01[3];
    /* 0x04 */ int16_t mStartPoint;
    /* 0x06 */ int16_t mRoomAngleY;
    /* 0x08 */ cXyz mRoomPos;
    /* 0x14 */ uint32_t mRoomParam;
    /* 0x18 */ float mLastSpeedF;
    /* 0x1C */ uint32_t mLastMode;
    /* 0x20 */ int16_t mLastAngleY;
};

class dSv_turnRestart_c {
public:
    class dSv_turnRestart_camera_c {
        cXyz mCameraCtr;
        cXyz mCameraEye;
        cXyz mCameraUp;
    };

    /* 0x00 */ cXyz mPosition;
    /* 0x0C */ uint32_t mParam;
    /* 0x10 */ int16_t mAngleY;
    /* 0x12 */ int8_t unk18;
    /* 0x14 */ dSv_turnRestart_camera_c mCamera;
    /* 0x38 */ float mCameraFvy;
};

class dSv_reserve_c {
public:
    uint8_t unk[80];
};

class dSv_save_c {
public:
    dSv_player_c& getPlayer() { return mPlayer; }
    dSv_player_status_a_c& getPlayerStatusA() { return mPlayer.getPlayerStatusA(); }
    dSv_player_get_item_c& getPlayerGetItem() { return mPlayer.getPlayerGetItem(); }
    dSv_player_item_record_c& getPlayerItemRecord() { return mPlayer.getPlayerItemRecord(); }
    dSv_player_item_max_c& getPlayerItemMax() { return mPlayer.getPlayerItemMax(); }
    dSv_player_last_mark_info_c& getPlayerLastMarkInfo() { return mPlayer.getPlayerLastMarkInfo(); }
    dSv_player_item_c& getPlayerItem() { return mPlayer.getPlayerItem(); }
    dSv_player_collect_c& getPlayerCollect() { return mPlayer.getPlayerCollect(); }
    dSv_light_drop_c& getLightDrop() { return mPlayer.getLightDrop(); }
    dSv_event_c& getEvent() { return mEvent; }

    static const int STAGE_MAX = 32;
    static const int STAGE2_MAX = 64;

    dSv_player_c mPlayer;
    dSv_memory_c mSave[STAGE_MAX];
    dSv_memory2_c mSave2[STAGE2_MAX];
    dSv_event_c mEvent;
    dSv_reserve_c reserve;
    dSv_MiniGame_c mMiniGame;
};
#pragma pack(push, 1)
class dSv_info_c {
public:
    dSv_save_c& getSavedata() { return mSavedata; }
    dSv_memory_c& getMemory() { return mMemory; }
    dSv_zone_c* getZones() { return mZone; }
    dSv_player_c& getPlayer() { return mSavedata.getPlayer(); }
    dSv_event_c& getTmp() { return mTmp; }

    /* 0x000 */ dSv_save_c mSavedata;
    /* 0x958 */ dSv_memory_c mMemory;
    /* 0x978 */ dSv_danBit_c mDan;
    /* 0x9B4 */ dSv_zone_c mZone[32];
    /* 0xDB4 */ dSv_restart_c mRestart;
    /* 0xDD8 */ dSv_event_c mTmp;
    /* 0xED8 */ dSv_turnRestart_c mTurnRestart;
    /* 0xF14 */ uint8_t field_0xf14[4];
    /* 0xF18 */ uint8_t mDataNum;
    /* 0xF19 */ uint8_t mNewFile;
    /* 0xF1A */ uint8_t mNoFile;
    /* 0xF1B */ uint8_t field_0xf1b[13];
    /* 0xF28 */ uint64_t mStartTime;
    /* 0xF30 */ uint64_t mSaveTotalTime;
};
#pragma pack(pop)



// Functions
typedef void (*dSv_player_item_c__setItem_t)(void* addr, int32_t slot, uint8_t item);
#define dSv_player_item_c__setItem ((dSv_player_item_c__setItem_t)dSv_player_item_c__setItem_addr)

typedef uint8_t (*dSv_player_item_c__getItem_t)(void* addr, int32_t slot, bool is_combo_item);
#define dSv_player_item_c__getItem ((dSv_player_item_c__getItem_t)dSv_player_item_c__getItem_addr)

typedef void (*dSv_player_item_record_c__setBombNum_t)(void* addr, uint8_t idx, uint8_t i_no);
#define dSv_player_item_record_c__setBombNum ((dSv_player_item_record_c__setBombNum_t)dSv_player_item_record_c__setBombNum_addr)

typedef void (*dSv_player_get_item_c__onFirstBit_t)(void* addr, uint8_t item);
#define dSv_player_get_item_c__onFirstBit ((dSv_player_get_item_c__onFirstBit_t)dSv_player_get_item_c__onFirstBit_addr)

typedef void (*dSv_player_get_item_c__offFirstBit_t)(void* addr, uint8_t item);
#define dSv_player_get_item_c__offFirstBit ((dSv_player_get_item_c__offFirstBit_t)dSv_player_get_item_c__offFirstBit_addr)

typedef uint8_t (*dSv_player_item_record_c__getBombNum_t)(void* addr, uint8_t bag);
#define dSv_player_item_record_c__getBombNum ((dSv_player_item_record_c__getBombNum_t)dSv_player_item_record_c__getBombNum_addr)

typedef uint8_t (*dSv_player_status_a_c__getSelectItemIndex_t)(void* addr, int32_t idx);
#define dSv_player_status_a_c__getSelectItemIndex ((dSv_player_status_a_c__getSelectItemIndex_t)dSv_player_status_a_c__getSelectItemIndex_addr)

typedef bool (*dSv_player_status_b_c__isTransformLV_t)(void* addr, int32_t flag);
#define dSv_player_status_b_c__isTransformLV ((dSv_player_status_b_c__isTransformLV_t)dSv_player_status_b_c__isTransformLV_addr)

typedef void (*dSv_player_status_b_c__onTransformLV_t)(void* addr, int32_t flag);
#define dSv_player_status_b_c__onTransformLV ((dSv_player_status_b_c__onTransformLV_t)dSv_player_status_b_c__onTransformLV_addr)

typedef uint8_t (*dSv_light_drop_c__getLightDropNum_t)(void* addr, uint8_t area);
#define dSv_light_drop_c__getLightDropNum ((dSv_light_drop_c__getLightDropNum_t)dSv_light_drop_c__getLightDropNum_addr)

typedef void (*dSv_light_drop_c__setLightDropNum_t)(void* addr, uint8_t area, uint8_t num);
#define dSv_light_drop_c__setLightDropNum ((dSv_light_drop_c__setLightDropNum_t)dSv_light_drop_c__setLightDropNum_addr)

typedef void (*dSv_info_c__onSwitch_t)(void* addr, int i_no, int i_roomNo);
#define dSv_info_c__onSwitch ((dSv_info_c__onSwitch_t)dSv_info_c__onSwitch_addr)

typedef void (*dSv_info_c__offSwitch_t)(void* addr, int i_no, int i_roomNo);
#define dSv_info_c__offSwitch ((dSv_info_c__offSwitch_t)dSv_info_c__offSwitch_addr)

typedef bool (*dSv_memBit_c__isSwitch_t)(void* addr, int i_no);
#define dSv_memBit_c__isSwitch ((dSv_memBit_c__isSwitch_t)dSv_memBit_c__isSwitch_addr)

typedef void (*dSv_memBit_c__onSwitch_t)(void* addr, int i_no);
#define dSv_memBit_c__onSwitch ((dSv_memBit_c__onSwitch_t)dSv_memBit_c__onSwitch_addr)

typedef void (*dSv_memBit_c__offSwitch_t)(void* addr, int i_no);
#define dSv_memBit_c__offSwitch ((dSv_memBit_c__offSwitch_t)dSv_memBit_c__offSwitch_addr)

typedef void (*tp_getSave_t)(void* addr, int32_t areaID);
#define tp_getSave ((tp_getSave_t)tp_getSave_addr)

typedef void (*tp_putSave_t)(void* addr, int32_t areaID);
#define tp_putSave ((tp_putSave_t)tp_putSave_addr)

typedef bool (*dSv_event_c__isEventBit_t)(void* addr, uint16_t flag);
#define dSv_event_c__isEventBit ((dSv_event_c__isEventBit_t)dSv_event_c__isEventBit_addr)

typedef void (*dSv_event_c__onEventBit_t)(void* addr, uint16_t flag);
#define dSv_event_c__onEventBit ((dSv_event_c__onEventBit_t)dSv_event_c__onEventBit_addr)

typedef void (*dSv_event_c__offEventBit_t)(void* addr, uint16_t flag);
#define dSv_event_c__offEventBit ((dSv_event_c__offEventBit_t)dSv_event_c__offEventBit_addr)

typedef bool (*dSv_memBit_c__isDungeonItem_t)(void* addr, int32_t flag);
#define dSv_memBit_c__isDungeonItem ((dSv_memBit_c__isDungeonItem_t)dSv_memBit_c__isDungeonItem_addr)

typedef void (*dSv_memBit_c__onDungeonItem_t)(void* addr, int32_t flag);
#define dSv_memBit_c__onDungeonItem ((dSv_memBit_c__onDungeonItem_t)dSv_memBit_c__onDungeonItem_addr)

typedef void (*dSv_player_return_place_c__set_t)(void* addr, char const* i_name, int8_t roomNo, uint8_t pointNo);
#define dSv_player_return_place_c__set ((dSv_player_return_place_c__set_t)dSv_player_return_place_c__set_addr)

#endif /* D_SAVE_D_SAVE_H */
