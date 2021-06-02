#ifndef D_A_D_A_ALINK_H
#define D_A_D_A_ALINK_H

#include "../../Z2AudioLib/Z2Creature.h"
#include "../../Z2AudioLib/Z2WolfHowlMgr.h"
#include "d_a_player.h"
#include "../bg/d_bg_s.h"
#include "../cc/d_cc_d.h"
#include "../cc/d_cc_mass_s.h"
#include "../d_attention.h"
#include "../d_drawlist.h"
#include "../d_eye_hl.h"
#include "../d_jnt_col.h"
#include "../kankyo/d_kankyo.h"
#include "../meter/d_meter2_info.h"
#include "../msg/d_msg_flow.h"
#include "../particle/d_particle.h"
#include "../particle/d_particle_copoly.h"
#include "../../JSystem/J2DGraph/J2DPane.h"

class J2DScreen {};
class J2DAnmBase {};
class J3DAnmBase {};
class JKRExpHeap {};
class J3DModelData {};

class daAlink_lockCursor_c : public dDlst_base_c {
public:
    /* 0x04 */ bool field_0x4;
    /* 0x05 */ uint8_t field_0x5[3];
    /* 0x08 */ J2DScreen* field_0x8;
    /* 0x0C */ J2DPane* field_0xc;
    /* 0x10 */ J2DPane* field_0x10;
    /* 0x14 */ J2DPane* field_0x14;
    /* 0x18 */ J2DPane* field_0x18;
    /* 0x1C */ J2DAnmBase* field_0x1c;
    /* 0x20 */ J2DAnmBase* field_0x20;
    /* 0x24 */ J2DAnmBase* field_0x24;
    /* 0x28 */ J2DAnmBase* field_0x28;
    /* 0x2C */ float field_0x2c;
    /* 0x30 */ float field_0x30;
    /* 0x34 */ float field_0x34;
    /* 0x38 */ float field_0x38;
};

class daAlink_sight_c : public daPy_sightPacket_c {
public:
    /* 0x4C */ bool mLockFlag;
    /* 0x4D */ uint8_t field_0x4d[3];
    /* 0x50 */ daAlink_lockCursor_c field_0x50;
};

class daAlink_blur_c : public J3DPacket {
public:
    /* 0x010 */ uint8_t field_0x10[4];
    /* 0x014 */ int field_0x14;
    /* 0x018 */ uint8_t field_0x18[4];
    /* 0x01C */ int field_0x1c;
    /* 0x020 */ uint8_t field_0x20[4];
    /* 0x024 */ float field_0x24;
    /* 0x028 */ uint8_t field_0x28[4];
    /* 0x02C */ cXyz field_0x2c;
    /* 0x038 */ cXyz field_0x38[0x3C];
    /* 0x308 */ cXyz field_0x308[0x3C];
};  // Size = 0x5D8

class dAlink_bottleWaterPcallBack_c : public JPAParticleCallBack {
public:
    /* 0x04 */ int16_t mHitFlg;
    /* 0x06 */ int16_t mAppearFlg;
    /* 0x08 */ float mKeepMinY;
    /* 0x0C */ cXyz mHitPos;
};  // Size = 0x18

class daAlink_footData_c {
public:
    uint8_t field_0x00[0x8];
    cXyz field_0x08;
    Mtx field_0x14;
    Mtx field_0x44;
    Mtx field_0x74;
}; // Size = 0xA4


class daAlink_c : public daPy_py_c {
public:
    enum daAlink_ANM {
        GANON_FINISH = 408  // name probably wrong, fix later
    };

    enum daAlink_UPPER {
        Unk0,
        Unk1,
        UPPER_NOW  // needs better name. main upper anmheap idx checked for actions
    };

    enum daAlink_UNDER {};
    enum daAlink_FTANM {};
    enum daAlink_WARP_MAT_MODE {};
    enum daAlink_WANM {};

    enum MODE_FLG {
        PLAYER_FLY = 0x70852,
    };

    enum daAlink_PROC {
        PREACTION_UNEQUIP,
        SERVICE_WAIT,
        HUMAN_WAIT = 3,
        HUMAN_SIDESTEP = 10,
        HUMAN_SIDESTEP_LAND,
        HUMAN_SLIDE,
        FRONT_ROLL = 14,
        FRONT_ROLL_CRASH,
        HUMAN_KNOCKBACK,
        SIDE_ROLL,
        BACK_JUMP,
        BACK_JUMP_LAND,
        SLIP,
        HUMAN_AUTOJUMP,
        DIVE_JUMP,
        ROLL_JUMP,
        FALL,
        LAND,
        SMALL_JUMP,
        STEP_MOVE,
        GUARD_SLIP = 29,
        GUARD_ATTACK,
        GUARD_BREAK,
        TURN_MOVE,
        CUT_NORMAL,
        CUT_FINISH,
        CUT_FINISH_JUMP_UP,
        CUT_FINISH_JUMP_UP_LAND,
        CUT_REVERSE,
        CUT_JUMP,
        CUT_JUMP_LAND,
        COMBO_CUT_TURN,
        CUT_CHARGE,
        CUT_TURN_MOVE,
        CUT_DOWN,
        CUT_DOWN_LAND,
        CUT_HEAD,
        CUT_HEAD_LAND,
        CUT_LARGE_JUMP_CHARGE,
        CUT_LARGE_JUMP,
        CUT_LARGE_JUMP_LAND,
        DAMAGE,
        LAND_DAMAGE = 52,
        CRAWL_START,
        CRAWL_MOVE,
        CRAWL_AUTOMOVE,
        CRAWL_END,
        PULL_MOVE,
        HORSE_RIDE,
        HORSE_GETOFF,
        HORSE_TURN = 61,
        HORSE_JUMP,
        HORSE_LAND,
        HORSE_SUBJECTIVITY,
        HORSE_CUT,
        HORSE_CUT_CHARGE_READY,
        HORSE_CUT_TURN,
        HORSE_DAMAGE,
        RIDE_BOW_READY,
        HORSE_BOTTLE_DRINK = 76,
        HORSE_KANDELAAR_POUR = 78,
        HORSE_RUN,
        HORSE_HANG,
        BOAR_RUN = 83,
        HANG_START = 85,
        HANG_FALL_START,
        HANG_UP,
        HANG_WAIT,
        HANG_MOVE,
        COPY_ROD_SWING = 101,
        GRAB_READY = 108,
        GRAB_UP,
        GRAB_THROW = 111,
        GRAB_DOWN,
        GRAB_REBOUND = 114,
        GRAB_STAND,
        INSECT_CATCH,
        PICK_UP,
        PICK_PUT,
        HUMAN_ST_ESCAPE,
        CLIMB_MOVE_VERTICAL = 130,
        CLIMB_MOVE_HORIZONTAL,
        CANOE_RIDE = 140,
        CANOE_JUMP_RIDE,
        CANOE_GETOFF,
        CANOE_ROW = 144,
        CANOE_PADDLE_SHIFT,
        CANOE_PADDLE_PUT,
        CANOE_PADDLE_GRAB,
        CANOE_ROD_GRAB,
        CANOE_FISHING_REEL = 150,
        CANOE_FISHING_GET,
        CANOE_SUBJECTIVITY,
        CANOE_BOTTLE_DRINK = 160,
        CANOE_KANDELAAR_POUR,
        FISHING_FOOD = 163,
        BOARD_CUT_TURN = 173,
        FM_CHAIN_UP,
        BOTTLE_DRINK = 179,
        EMPTY_BOTTLE_SWING = 181,
        GRASS_WHISTLE = 186,
        HAWK_WAIT = 188,
        FLOOR_DOWN_REBOUND = 189,
        GORON_RIDE_WAIT,
        GOAT_THROW = 192,
        GOAT_STROKE,
        MAGNE_BOOTS_FLY = 204,
        BOOTS_EQUIP,
        SUMOU_PUSH = 207,
        SUMOU_SIDE_MOVE,
        SUMOU_ACTION,
        SUMOU_STAGGER,
        SUMOU_WIN_LOSE,
        BOSS_ENEMY_HANG = 220,
        SCREAM_WAIT = 222,
        DUNGEON_WARP_READY = 234,
        WOLF_HOWL = 237,
        WOLF_WAIT = 241,
        WOLF_DASH = 243,
        WOLF_KNOCKBACK = 244,
        WOLF_SIDESTEP = 247,
        WOLF_AUTOJUMP = 252,
        WOLF_RSIT = 255,
        WOLF_DAMAGE = 263,
        WOLF_SLIDE = 271,
        WOLF_ROPE_HANG = 275,
        WOLF_TAGLOCK_JUMP = 280,
        WOLF_TAGLOCK_LAND,
        WOLF_DOWNATTACK_PULLOUT = 291,
        WOLF_JUMPATTACK = 284,
        WOLF_ST_ESCAPE = 289,
        WOLF_CHAIN = 305,
        WOLF_DIG,
        WOLF_ENEMY_HANG_BITE = 310,
        SUBJECTIVITY = 318,
        POLY_DAMAGE = 321,
        ELEC_DAMAGE,
        PUSH_PULL_WAIT,
        PUSH_MOVE,
        TRESURE_STAND = 328,
        METAMORPHOSE = 333,
        DEAD = 336,
        LARGE_DAMAGE = 345,
        LARGE_DAMAGE_WALL,
    };

    // this might be one of the above enums, but not clear yet
    enum UPPER_ANM {
        ANM_SMALL_GUARD = 22,
        ANM_HUMAN_CHAIN_GRAB = 98,
        ANM_WOLF_CHAIN_GRAB = 672,
        ANM_WOLF_ENEMY_THROW_LEFT = 701,
        ANM_WOLF_ENEMY_THROW_RIGHT,
    };

    class firePointEff_c {
        /* 0x00 */ uint8_t field_0x0[0xc];
        /* 0x0C */ cXyz field_0xc;
        /* 0x18 */ cXyz field_0x18;
        /* 0x24 */ cXyz field_0x24;
    };

    class hsChainShape_c {
    };

    // inlined version of checkModeFlg
    uint32_t checkModeFlg(uint32_t pFlag) const { return mModeFlg & pFlag; }
    bool checkUpperAnime(uint16_t pIdx) const { return mUpperAnime[UPPER_NOW].getIdx() == pIdx; }


    /* 0x0062C */ void* field_0x062C;
    /* 0x00630 */ void* field_0x0630;
    /* 0x00634 */ void* field_0x0634;
    /* 0x00638 */ JKRExpHeap** field_0x0638;
    /* 0x0063C */ void* field_0x063C;
    /* 0x00640 */ void* field_0x0640;
    /* 0x00644 */ void* field_0x0644;
    /* 0x00648 */ JKRExpHeap** field_0x0648;
    /* 0x0064C */ J3DModelData* field_0x064C;
    /* 0x00650 */ J3DModel* field_0x0650;
    /* 0x00654 */ J3DModel* field_0x0654;
    /* 0x00658 */ J3DModel* field_0x0658;
    /* 0x0065C */ J3DModel* field_0x065c;
    /* 0x00660 */ J3DModel* field_0x0660;
    /* 0x00664 */ J3DModel* field_0x0664;
    /* 0x00668 */ J3DModel* field_0x0668;
    /* 0x0066C */ J3DModel* field_0x066c;
    /* 0x00670 */ J3DModel* field_0x0670;
    /* 0x00674 */ J3DModel* field_0x0674;
    /* 0x00678 */ J3DModel* field_0x0678;
    /* 0x0067C */ J3DAnmBase* field_0x067c;
    /* 0x00680 */ J3DAnmBase* field_0x0680;
    /* 0x00684 */ J3DModel* field_0x0684;
    /* 0x00688 */ J3DModel* field_0x0688;
    /* 0x0068C */ J3DAnmBase* field_0x068c;
    /* 0x00690 */ mDoExt_baseAnm** field_0x0690;
    /* 0x00694 */ void* field_0x0694;  // J3DDeformData
    /* 0x00698 */ void* field_0x0698;
    /* 0x0069C */ void* field_0x069c;
    /* 0x006A0 */ J3DModel* field_0x06a0;
    /* 0x006A4 */ mDoExt_bckAnm* field_0x06a4;
    /* 0x006A8 */ J3DModel* field_0x06a8;
    /* 0x006AC */ mDoExt_bckAnm* field_0x06ac;
    /* 0x006B0 */ mDoExt_bckAnm* field_0x06b0;
    /* 0x006B4 */ J3DAnmTransform* field_0x06b4;
    /* 0x006B8 */ J3DModel* field_0x06b8;
    /* 0x006BC */ J3DModel* field_0x06bc;
    /* 0x006C0 */ J3DModelData* field_0x06c0;
    /* 0x006C4 */ J3DAnmBase* field_0x06c4;
    /* 0x006C8 */ J3DAnmBase* field_0x06c8;
    /* 0x006CC */ J3DAnmBase* field_0x06cc;
    /* 0x006D0 */ void* field_0x06d0;
    /* 0x006D4 */ void* field_0x06d4;
    /* 0x006D8 */ void* field_0x06d8;
    /* 0x006DC */ void* field_0x06dc;
    /* 0x006E0 */ void* field_0x06e0;
    /* 0x006E4 */ void* field_0x06e4;
    /* 0x006E8 */ void* field_0x06e8;
    /* 0x006EC */ void* field_0x06ec;
    /* 0x006F0 */ void* field_0x06f0;
    /* 0x006F4 */ J3DAnmBase* field_0x06f4;
    /* 0x006F8 */ J3DAnmBase* field_0x06f8;
    /* 0x006FC */ J3DModel* field_0x06fc;
    /* 0x00700 */ J3DModel* field_0x0700;
    /* 0x00704 */ J3DAnmBase* field_0x0704;
    /* 0x00708 */ J3DModel* field_0x0708;
    /* 0x0070C */ J3DModel* field_0x070c;
    /* 0x00710 */ J3DModel* field_0x0710;
    /* 0x00714 */ J3DModel* field_0x0714;
    /* 0x00718 */ J3DAnmBase* field_0x0718;
    /* 0x0071C */ J3DAnmBase* field_0x071c;
    /* 0x00720 */ J3DAnmBase* field_0x0720;
    /* 0x00724 */ J3DAnmBase* field_0x0724;
    /* 0x00728 */ J3DAnmBase* field_0x0728;
    /* 0x0072C */ J3DAnmBase* field_0x072c;
    /* 0x00730 */ mDoExt_bckAnm field_0x730;
    /* 0x0074C */ mDoExt_bckAnm field_0x74C;
    /* 0x00768 */ uint8_t field_0x0768[0x5C];
    /* 0x007C4 */ daPy_actorKeep_c field_0x07C4[10];
    /* 0x00814 */ dCcD_Stts field_0x814;
    /* 0x00850 */ dCcD_Cyl field_0x850[3];
    /* 0x00C04 */ dCcD_Cyl field_0xC04[3];
    /* 0x00FB8 */ dCcD_Sph field_0xFB8;
    /* 0x010F0 */ dCcD_Cyl field_0x10F0;
    /* 0x0122C */ dCcD_Cps field_0x122C[3];
    /* 0x015F8 */ dCcD_Cps field_0x15F8;
    /* 0x0173C */ dCcD_Stts field_0x173c;
    /* 0x01778 */ dCcD_Sph field_0x1778;
    /* 0x018B0 */ dBgS_AcchCir field_0x18B0[3];
    /* 0x01970 */ dBgS_LinkAcch mLinkAcch;
    /* 0x01B48 */ dBgS_LinkLinChk mLinkLinChk;
    /* 0x01BB8 */ dBgS_RopeLinChk mRopeLinChk;
    /* 0x01C28 */ dBgS_BoomerangLinChk mBoomerangLinChk;
    /* 0x01C98 */ dBgS_ArrowLinChk mArrowLinChk;
    /* 0x01D08 */ dBgS_LinkGndChk mLinkGndChk;
    /* 0x01D5C */ dBgS_LinkRoofChk mLinkRoofChk;
    /* 0x01DAC */ dBgS_LinkLinChk mLinkLinChk2;
    /* 0x01E1C */ cBgS_PolyInfo mPolyInfo1;
    /* 0x01E2C */ cBgS_PolyInfo mPolyInfo2;
    /* 0x01E3C */ cBgS_PolyInfo mPolyInfo3;
    /* 0x01E4C */ cBgS_PolyInfo mPolyInfo4;
    /* 0x01E5C */ dBgS_ObjLinChk mObjLinChk;
    /* 0x01ECC */ dBgS_ObjGndChk mObjGndChk;
    /* 0x01F20 */ uint8_t field_0x1f20[8];
    /* 0x01F28 */ mDoExt_AnmRatioPack field_0x1f28[3];
    /* 0x01F40 */ mDoExt_AnmRatioPack field_0x1f40[3];
    /* 0x01F58 */ daPy_anmHeap_c mUnderAnime[3];
    /* 0x01F94 */ daPy_anmHeap_c mUpperAnime[3];
    /* 0x01FD0 */ daPy_frameCtrl_c mFrameCtrl1[3];
    /* 0x02018 */ daPy_frameCtrl_c mFrameCtrl2[3];
    /* 0x02060 */ void* field_0x2060;  // mDoExt_MtxCalcOldFrame*
    /* 0x02064 */ daAlink_sight_c mSight;
#ifdef WII_PLATFORM
    uint8_t unk_field0[4];
#endif
    /* 0x020F0 */ daPy_anmHeap_c mAnmHeap3;
    /* 0x02104 */ daPy_anmHeap_c mAnmHeap4;
    /* 0x02118 */ daPy_anmHeap_c mAnmHeap5;
    /* 0x0212C */ daPy_anmHeap_c mAnmHeap6;
    /* 0x02140 */ daPy_anmHeap_c mAnmHeap7;
    /* 0x02154 */ mDoExt_bckAnm field_0x2154;
    /* 0x02170 */ uint8_t field_0x2170[0x18];
    /* 0x02188 */ dEyeHL_c mEyeHL1;
    /* 0x0219C */ dEyeHL_c mEyeHL2;
    /* 0x021B0 */ daPy_anmHeap_c mAnmHeap8[2];
    /* 0x021D8 */ daPy_anmHeap_c mAnmHeap9;
    /* 0x021EC */ uint8_t field_0x21ec[4];
    /* 0x021F0 */ daAlink_blur_c mBlur;
    /* 0x027C8 */ dAlink_bottleWaterPcallBack_c field_0x27c8;
    /* 0x027E0 */ dAttention_c* mAttention;
    /* 0x027E4 */ dAttList_c* mAttList;
    /* 0x027E8 */ dAttList_c* mAttList2;
    /* 0x027EC */ fopAc_ac_c* mTargetedActor;
    /* 0x027F0 */ fopAc_ac_c* field_0x27f0;
    /* 0x027F4 */ fopAc_ac_c* field_0x27f4;
    /* 0x027F8 */ fopAc_ac_c* field_0x27f8;
    /* 0x027FC */ fopAc_ac_c* field_0x27fc;
    /* 0x02800 */ fopAc_ac_c* field_0x2800;
    /* 0x02804 */ fopAc_ac_c* field_0x2804;
    /* 0x02808 */ fopAc_ac_c* field_0x2808;
    /* 0x0280C */ daPy_actorKeep_c field_0x280c;
    /* 0x02814 */ daPy_actorKeep_c mRideActor;  // daspinnerc?
    /* 0x0281C */ daPy_actorKeep_c field_0x281c;
    /* 0x02824 */ daPy_actorKeep_c mItemActor;  // name might be wrong
    /* 0x0282C */ daPy_actorKeep_c field_0x282c;
    /* 0x02834 */ daPy_actorKeep_c field_0x2834;
    /* 0x0283C */ daPy_actorKeep_c field_0x283c;
    /* 0x02844 */ daPy_actorKeep_c field_0x2844;
    /* 0x0284C */ daPy_actorKeep_c field_0x284c;
    /* 0x02854 */ daPy_actorKeep_c field_0x2854;
    /* 0x0285C */ daPy_actorKeep_c field_0x285c;
    /* 0x02864 */ dMsgFlow_c mMsgFlow;
    /* 0x028B0 */ uint8_t field_0x28b0[0x40];
    /* 0x028F0 */ int field_0x28f0;
    /* 0x028F4 */ int mAtnActorID;
    /* 0x028F8 */ int field_0x28f8;
    /* 0x028FC */ int field_0x28fc;
    /* 0x02900 */ void* field_0x2900;
    /* 0x02904 */ daAlink_footData_c mFootData1[2];
    /* 0x02A4C */ daAlink_footData_c mFootData2[2];
    /* 0x02B94 */ float* field_0x2b94;
    /* 0x02B98 */ float* field_0x2b98;
    /* 0x02B98 */ float* field_0x2b9c;
    /* 0x02BA0 */ float* field_0x2ba0;
    /* 0x02BA4 */ float* field_0x2ba4;
    /* 0x02BA8 */ float* field_0x2ba8;
    /* 0x02BAC */ cXyz field_0x2bac;
    /* 0x02BB8 */ Mtx mInvMtx;
    /* 0x02BE8 */ Mtx field_0x2be8;
    /* 0x02C18 */ Mtx field_0x2c18;
    /* 0x02C48 */ Mtx field_0x2c48;
    /* 0x02C78 */ Mtx field_0x2c78;
    /* 0x02CA8 */ Z2CreatureLink mZ2Link;
    /* 0x02D75 */ uint8_t field_0x2d75[3];  // padding?
    /* 0x02D78 */ void* field_0x2d78;
    /* 0x02D7C */ daPy_frameCtrl_c* field_0x2d7c;
    /* 0x02D80 */ int field_0x2d80;
    /* 0x02D84 */ Z2WolfHowlMgr mZ2WolfHowlMgr;
    /* 0x02E44 */ dJntCol_c field_0x2e44;
    /* 0x02E54 */ dPaPo_c field_0x2e54;
    /* 0x02E8C */ uint8_t field_0x2e8c[0x90];
    /* 0x02F1C */ dPaPo_c* field_0x2f1c;
    /* 0x02F20 */ dPa_hermiteEcallBack_c field_0x2f20;
    /* 0x02F38 */ dPa_hermiteEcallBack_c field_0x2f38;
    /* 0x02F50 */ Vec* field_0x2f50;
    /* 0x02F54 */ Vec* field_0x2f54;
    /* 0x02F58 */ uint16_t* field_0x2f58;
    /* 0x02F5C */ LIGHT_INFLUENCE field_0x2f5c;
    /* 0x02F7C */ uint8_t field_0x2f7c[16];
    /* 0x02F8C */ uint8_t field_0x2f8c;
    /* 0x02F8D */ uint8_t mItemTrigger;
    /* 0x02F8E */ uint8_t mItemButton;
    /* 0x02F8F */ uint8_t field_0x2f8f;
    /* 0x02F90 */ uint8_t field_0x2f90;
    /* 0x02F91 */ uint8_t field_0x2f91;
    /* 0x02F92 */ uint8_t field_0x2f92;
    /* 0x02F93 */ uint8_t field_0x2f93;
    /* 0x02F94 */ uint8_t field_0x2f94;
    /* 0x02F95 */ uint8_t field_0x2f95;
    /* 0x02F96 */ uint8_t field_0x2f96;
    /* 0x02F97 */ uint8_t field_0x2f97;
    /* 0x02F98 */ uint8_t field_0x2f98;
    /* 0x02F99 */ uint8_t field_0x2f99;
    /* 0x02F9A */ int8_t field_0x2f9a;
    /* 0x02F9B */ uint8_t field_0x2f9b;
    /* 0x02F9C */ uint8_t mSelectItemId;
    /* 0x02F9D */ uint8_t field_0x2f9d;
    /* 0x02F9E */ uint8_t field_0x2f9e;
    /* 0x02F9F */ uint8_t field_0x2f9f;
    /* 0x02FA0 */ uint8_t field_0x2fa0;
    /* 0x02FA1 */ uint8_t field_0x2fa1;
    /* 0x02FA2 */ uint8_t field_0x2fa2;
    /* 0x02FA3 */ uint8_t field_0x2fa3;
    /* 0x02FA4 */ uint8_t field_0x2fa4;
    /* 0x02FA5 */ uint8_t field_0x2fa5;
    /* 0x02FA6 */ uint8_t field_0x2fa6;
    /* 0x02FA7 */ uint8_t field_0x2fa7;
    /* 0x02FA8 */ uint8_t field_0x2fa8;
    /* 0x02FA9 */ uint8_t field_0x2fa9;
    /* 0x02FAA */ uint8_t mRideStatus;
    /* 0x02FAB */ uint8_t field_0x2fab;
    /* 0x02FAC */ uint8_t field_0x2fac;
    /* 0x02FAD */ uint8_t field_0x2fad;
    /* 0x02FAE */ uint8_t field_0x2fae;
    /* 0x02FAF */ uint8_t field_0x2faf;
    /* 0x02FB0 */ uint8_t field_0x2fb0;
    /* 0x02FB1 */ uint8_t field_0x2fb1;
    /* 0x02FB2 */ uint8_t field_0x2fb2;
    /* 0x02FB3 */ uint8_t field_0x2fb3;
    /* 0x02FB4 */ uint8_t field_0x2fb4;
    /* 0x02FB5 */ uint8_t field_0x2fb5;
    /* 0x02FB6 */ uint8_t field_0x2fb6;
    /* 0x02FB7 */ uint8_t field_0x2fb7;
    /* 0x02FB8 */ uint8_t field_0x2fb8;
    /* 0x02FB9 */ uint8_t field_0x2fb9;
    /* 0x02FBA */ uint8_t field_0x2fba;
    /* 0x02FBB */ uint8_t field_0x2fbb;
    /* 0x02FBC */ uint8_t field_0x2fbc;
    /* 0x02FBD */ uint8_t field_0x2fbd;
    /* 0x02FBE */ uint8_t field_0x2fbe;
    /* 0x02FBF */ uint8_t mClothesChangeWaitTimer;
    /* 0x02FC0 */ uint8_t field_0x2fc0;
    /* 0x02FC1 */ uint8_t field_0x2fc1;
    /* 0x02FC2 */ uint8_t field_0x2fc2;
    /* 0x02FC3 */ uint8_t field_0x2fc3;
    /* 0x02FC4 */ uint8_t field_0x2fc4;
    /* 0x02FC5 */ uint8_t field_0x2fc5;
    /* 0x02FC6 */ uint8_t field_0x2fc6;
    /* 0x02FC7 */ uint8_t field_0x2fc7;
    /* 0x02FC8 */ uint8_t field_0x2fc8;
    /* 0x02FC9 */ uint8_t field_0x2fc9;
    /* 0x02FCA */ uint8_t field_0x2fca;
    /* 0x02FCB */ uint8_t field_0x2fcb;
    /* 0x02FCC */ uint8_t field_0x2fcc;
    /* 0x02FCD */ uint8_t field_0x2fcd;
    /* 0x02FCE */ uint8_t field_0x2fce;
    /* 0x02FCF */ uint8_t field_0x2fcf;
    /* 0x02FD0 */ uint8_t field_0x2fd0;
    /* 0x02FD1 */ uint8_t mShieldChangeWaitTimer;
    /* 0x02FD2 */ uint8_t field_0x2fd2;
    /* 0x02FD3 */ uint8_t field_0x2fd3;
    /* 0x02FD4 */ uint8_t field_0x2fd4;
    /* 0x02FD5 */ uint8_t field_0x2fd5;
    /* 0x02FD6 */ uint8_t field_0x2fd6;
    /* 0x02FD7 */ uint8_t field_0x2fd7;
    /* 0x02FD8 */ uint8_t field_0x2fd8;
    /* 0x02FD9 */ uint8_t field_0x2fd9[3];
    /* 0x02FDC */ uint16_t field_0x2fdc;
    /* 0x02FDE */ uint16_t field_0x2fde;
    /* 0x02FE0 */ uint16_t field_0x2fe0;
    /* 0x02FE2 */ int16_t field_0x2fe2;
    /* 0x02FE4 */ int16_t field_0x2fe4;
    /* 0x02FE6 */ int16_t field_0x2fe6;
    /* 0x02FE8 */ uint16_t mActionID;
    /* 0x02FEA */ uint16_t field_0x2fea;
    /* 0x02FEC */ int16_t field_0x2fec;
    /* 0x02FEE */ int16_t field_0x2fee;
    /* 0x02FF0 */ int16_t field_0x2ff0;
    /* 0x02FF2 */ int16_t field_0x2ff2;
    /* 0x02FF4 */ int16_t field_0x2ff4;
    /* 0x02FF6 */ int16_t field_0x2ff6;
    /* 0x02FF8 */ int16_t field_0x2ff8;
    /* 0x02FFA */ int16_t field_0x2ffa;
    /* 0x02FFC */ int16_t field_0x2ffc;
    /* 0x02FFE */ int16_t field_0x2ffe;
    /* 0x03000 */ int16_t field_0x3000;
    /* 0x03002 */ int16_t field_0x3002;
    /* 0x03004 */ int16_t field_0x3004;
    /* 0x03006 */ int16_t field_0x3006;
    /* 0x03008 */ int16_t field_0x3008;
    /* 0x0300A */ int16_t field_0x300a;
    /* 0x0300C */ int16_t mCommonCounter;  // might need more accurate name
    /* 0x0300E */ int16_t field_0x300e;
    /* 0x03010 */ int16_t field_0x3010;
    /* 0x03012 */ int16_t field_0x3012;
    /* 0x03014 */ int16_t field_0x3014;
    /* 0x03016 */ uint8_t field_0x3016[2];
    /* 0x03018 */ int16_t field_0x3018;
    /* 0x0301A */ int16_t field_0x301a;
    /* 0x0301C */ int16_t field_0x301c;
    /* 0x0301E */ int16_t field_0x301e;
    /* 0x03020 */ int16_t field_0x3020;
    /* 0x03022 */ int16_t field_0x3022;
    /* 0x03024 */ int16_t field_0x3024;
    /* 0x03026 */ int16_t field_0x3026;
    /* 0x03028 */ int16_t field_0x3028;
    /* 0x0302A */ uint8_t field_0x302a[2];
    /* 0x0302C */ int16_t field_0x302c;
    /* 0x0302E */ int16_t field_0x302e;
    /* 0x03030 */ int16_t field_0x3030;
    /* 0x03032 */ int16_t field_0x3032;
    /* 0x03034 */ int16_t field_0x3034;
    /* 0x03036 */ int16_t field_0x3036;
    /* 0x03038 */ uint8_t field_0x3038[2];
    /* 0x0303A */ int16_t field_0x303a;
    /* 0x0303C */ uint8_t field_0x303c[4];
    /* 0x03040 */ int16_t field_0x3040;
    /* 0x03042 */ int16_t field_0x3042;
    /* 0x03044 */ int16_t field_0x3044;
    /* 0x03046 */ int16_t field_0x3046;
    /* 0x03048 */ int16_t field_0x3048;
    /* 0x0304A */ int16_t field_0x304a;
    /* 0x0304C */ uint8_t field_0x304c[2];
    /* 0x0304E */ int16_t field_0x304e;
    /* 0x03050 */ uint8_t field_0x3050[4];
    /* 0x03054 */ int16_t field_0x3054;
    /* 0x03056 */ int16_t field_0x3056;
    /* 0x03058 */ uint8_t field_0x3058[2];
    /* 0x0305A */ int16_t field_0x305a;
    /* 0x0305C */ int16_t field_0x305c;
    /* 0x0305E */ uint8_t field_0x305e[2];
    /* 0x03060 */ int16_t field_0x3060;
    /* 0x03062 */ int16_t field_0x3062;
    /* 0x03064 */ int16_t field_0x3064;
    /* 0x03066 */ int16_t field_0x3066;
    /* 0x03068 */ uint8_t field_0x3068[4];
    /* 0x0306C */ int16_t field_0x306c;
    /* 0x0306E */ int16_t field_0x306e;
    /* 0x03070 */ int16_t field_0x3070;
    /* 0x03072 */ int16_t field_0x3072;
    /* 0x03074 */ int16_t field_0x3074;
    /* 0x03076 */ int16_t field_0x3076;
    /* 0x03078 */ int16_t field_0x3078;
    /* 0x0307A */ int16_t field_0x307a;
    /* 0x0307C */ int16_t field_0x307c;
    /* 0x0307E */ int16_t field_0x307e;
    /* 0x03080 */ int16_t field_0x3080;
    /* 0x03082 */ int16_t field_0x3082;
    /* 0x03084 */ uint16_t field_0x3084;
    /* 0x03086 */ uint16_t field_0x3086;
    /* 0x03088 */ int16_t field_0x3088;
    /* 0x0308A */ int16_t field_0x308a;
    /* 0x0308C */ int16_t field_0x308c;
    /* 0x0308E */ int16_t field_0x308e;
    /* 0x03090 */ int16_t field_0x3090;
    /* 0x03092 */ int16_t field_0x3092;
    /* 0x03094 */ int16_t field_0x3094;
    /* 0x03096 */ uint8_t field_0x3096[4];
    /* 0x0309A */ int16_t field_0x309a;
    /* 0x0309C */ uint8_t field_0x309c[4];
    /* 0x030A0 */ int16_t field_0x30a0;
    /* 0x030A2 */ int16_t field_0x30a2;
    /* 0x030A4 */ int16_t field_0x30a4;
    /* 0x030A6 */ int16_t field_0x30a6;
    /* 0x030A8 */ uint16_t field_0x30a8;
    /* 0x030AA */ uint16_t field_0x30aa;
    /* 0x030AC */ int16_t field_0x30ac;
    /* 0x030AE */ uint16_t field_0x30ae;
    /* 0x030B0 */ int16_t field_0x30b0;
    /* 0x030B2 */ int16_t field_0x30b2;
    /* 0x030B4 */ uint16_t field_0x30b4;
    /* 0x030B6 */ uint16_t field_0x30b6;
    /* 0x030B8 */ uint16_t field_0x30b8;
    /* 0x030BA */ uint16_t field_0x30ba;
    /* 0x030BC */ uint16_t field_0x30bc;
    /* 0x030BE */ uint16_t field_0x30be;
    /* 0x030C0 */ uint16_t field_0x30c0;
    /* 0x030C2 */ uint16_t field_0x30c2;
    /* 0x030C4 */ uint16_t field_0x30c4;
    /* 0x030C6 */ uint16_t field_0x30c6;
    /* 0x030C8 */ int16_t field_0x30c8;
    /* 0x030CA */ int16_t field_0x30ca;
    /* 0x030CC */ int16_t field_0x30cc;
    /* 0x030CE */ uint16_t field_0x30ce;
    /* 0x030D0 */ int16_t field_0x30d0;
    /* 0x030D2 */ int16_t field_0x30d2;
    /* 0x030D4 */ uint16_t field_0x30d4;
    /* 0x030D6 */ int16_t field_0x30d6;
    /* 0x030D8 */ uint8_t field_0x30d8[0x14];
    /* 0x030EC */ int16_t field_0x30ec;
    /* 0x030EE */ int16_t field_0x30ee;
    /* 0x030F0 */ uint16_t field_0x30f0;
    /* 0x030F2 */ uint8_t field_0x30f2[2];
    /* 0x030F4 */ int16_t field_0x30f4;
    /* 0x030F6 */ int16_t field_0x30f6;
    /* 0x030F8 */ int16_t field_0x30f8;
    /* 0x030FA */ int16_t field_0x30fa;
    /* 0x030FC */ uint16_t field_0x30fc;
    /* 0x030FE */ uint16_t field_0x30fe;
    /* 0x03100 */ uint16_t field_0x3100;
    /* 0x03102 */ int16_t field_0x3102;
    /* 0x03104 */ int16_t field_0x3104;
    /* 0x03106 */ uint16_t field_0x3106;
    /* 0x03108 */ int16_t field_0x3108;
    /* 0x0310A */ int16_t field_0x310a;
    /* 0x0310C */ int16_t field_0x310c;
    /* 0x0310E */ int16_t field_0x310e;
    /* 0x03110 */ int16_t field_0x3110;
    /* 0x03112 */ uint16_t field_0x3112;
    /* 0x03114 */ int16_t field_0x3114;
    /* 0x03116 */ int16_t field_0x3116;
    /* 0x03118 */ int16_t field_0x3118;
    /* 0x0311A */ int16_t field_0x311a;
    /* 0x0311C */ int16_t field_0x311c;
    /* 0x0311E */ int16_t field_0x311e;
    /* 0x03120 */ uint16_t mMidnaMsgNum;
    /* 0x03122 */ int16_t field_0x3122;
    /* 0x03124 */ int16_t field_0x3124;
    /* 0x03126 */ int16_t field_0x3126;
    /* 0x03128 */ int16_t field_0x3128;
    /* 0x0312A */ csXyz field_0x312a[2];
    /* 0x03136 */ csXyz field_0x3136[2];
    /* 0x03142 */ csXyz field_0x3142[4];
    /* 0x0315A */ csXyz field_0x315a;
    /* 0x03160 */ csXyz field_0x3160;
    /* 0x03166 */ csXyz field_0x3166;
    /* 0x0316C */ csXyz field_0x316c;
    /* 0x03172 */ uint8_t field_0x3172[2];
    /* 0x03174 */ int field_0x3174;
    /* 0x03178 */ int field_0x3178;
    /* 0x0317C */ dAttention_c* field_0x317c;
    /* 0x03180 */ int field_0x3180;
    /* 0x03184 */ int field_0x3184;
    /* 0x03184 */ int field_0x3188;
    /* 0x0318C */ int field_0x318c;
    /* 0x03190 */ int field_0x3190;
    /* 0x03194 */ int field_0x3194;
    /* 0x03198 */ int field_0x3198;
    /* 0x0319C */ int field_0x319c;
    /* 0x031A0 */ uint32_t mModeFlg;
    /* 0x031A4 */ int field_0x31a4;
    /* 0x031A8 */ uint8_t field_0x31a8[8];
    /* 0x031B0 */ int field_0x31b0;
    /* 0x031B4 */ uint8_t field_0x31b4[8];
    /* 0x031BC */ uint32_t field_0x31bc;
    /* 0x031C0 */ uint32_t field_0x31c0;
    /* 0x031C4 */ uint32_t field_0x31c4;
    /* 0x031C8 */ uint32_t field_0x31c8;
    /* 0x031CC */ uint32_t field_0x31cc;
    /* 0x031D0 */ uint32_t field_0x31d0;
    /* 0x031D4 */ uint32_t field_0x31d4;
    /* 0x031D8 */ uint8_t field_0x31d8[12];
    /* 0x031E4 */ uint32_t field_0x31e4;
    /* 0x031E8 */ uint8_t field_0x31e8[16];
    /* 0x031F8 */ uint32_t field_0x31f8;
    /* 0x031FC */ uint32_t field_0x31fc;
    /* 0x03200 */ uint32_t field_0x3200;
    /* 0x03204 */ uint32_t field_0x3204;
    /* 0x03208 */ uint32_t field_0x3208;
    /* 0x0320C */ uint8_t field_0x320c[16];
    /* 0x0321C */ uint32_t field_0x321c;
    /* 0x03220 */ uint32_t field_0x3220;
    /* 0x03224 */ uint32_t field_0x3224;
    /* 0x03228 */ uint8_t field_0x3228[24];
    /* 0x03240 */ uint32_t field_0x3240;
    /* 0x03244 */ uint8_t field_0x3244[20];
    /* 0x03258 */ uint32_t field_0x3258;
    /* 0x0325C */ uint32_t field_0x325c;
    /* 0x03260 */ uint8_t field_0x3260[40];
    /* 0x03288 */ uint32_t field_0x3288;
    /* 0x0328C */ uint32_t field_0x328c;
    /* 0x03290 */ uint32_t field_0x3290;
    /* 0x03294 */ uint32_t field_0x3294;
    /* 0x03298 */ uint8_t field_0x3298[8];
    /* 0x032A0 */ J3DGXColorS10 field_0x32a0[2];
    /* 0x032B0 */ J3DGXColorS10 field_0x32b0[2];
    /* 0x032C0 */ int16_t field_0x32c0;
    /* 0x032C2 */ uint8_t field_0x32c2[2];
    /* 0x032C4 */ uint16_t field_0x32c4;
    /* 0x032C6 */ uint16_t field_0x32c6;
    /* 0x032C8 */ uint32_t field_0x32c8;
    /* 0x032CC */ uint32_t field_0x32cc;
    /* 0x032D0 */ uint32_t field_0x32d0;
    /* 0x032D4 */ uint32_t field_0x32d4;
    /* 0x032D8 */ firePointEff_c field_0x32d8[4];
    /* 0x03398 */ float mNormalSpeed;
    /* 0x0339C */ float mSpeedModifier;
    /* 0x033A0 */ float field_0x33a0;
    /* 0x033A4 */ float field_0x33a4;
    /* 0x033A8 */ float field_0x33a8;
    /* 0x033AC */ float field_0x33ac;
    /* 0x033B0 */ float field_0x33b0;
    /* 0x033B4 */ float field_0x33b4;
    /* 0x033B8 */ float field_0x33b8;
    /* 0x033BC */ float field_0x33bc;
    /* 0x033C0 */ float field_0x33c0;
    /* 0x033C4 */ float field_0x33c4;
    /* 0x033C8 */ float field_0x33c8;
    /* 0x033CC */ float field_0x33cc;
    /* 0x033D0 */ float field_0x33d0;
    /* 0x033D4 */ float field_0x33d4;
    /* 0x033D8 */ float field_0x33d8;
    /* 0x033DC */ float field_0x33dc;
    /* 0x033E0 */ float field_0x33e0;
    /* 0x033E4 */ float field_0x33e4;
    /* 0x033E8 */ float field_0x33e8;
    /* 0x033EC */ float field_0x33ec;
    /* 0x033F0 */ float field_0x33f0;
    /* 0x033F4 */ float field_0x33f4;
    /* 0x033F8 */ float field_0x33f8;
    /* 0x033FC */ float field_0x33fc;
    /* 0x03400 */ float field_0x3400;
    /* 0x03404 */ float field_0x3404;
    /* 0x03408 */ float field_0x3408;
    /* 0x0340C */ float field_0x340c;
    /* 0x03410 */ float field_0x3410;
    /* 0x03414 */ float field_0x3414;
    /* 0x03418 */ float field_0x3418;
    /* 0x0341C */ float field_0x341c;
    /* 0x03420 */ float field_0x3420;
    /* 0x03424 */ float field_0x3424;
    /* 0x03428 */ float field_0x3428;
    /* 0x0342C */ float field_0x342c;
    /* 0x03430 */ float field_0x3430;
    /* 0x03434 */ float mHeavySpeedMultiplier;
    /* 0x03438 */ float field_0x3438;
    /* 0x0343C */ float field_0x343c;
    /* 0x03440 */ float field_0x3440;
    /* 0x03444 */ float field_0x3444;
    /* 0x03448 */ float field_0x3448;
    /* 0x0344C */ float field_0x344c;
    /* 0x03450 */ uint8_t field_0x3450[4];
    /* 0x03454 */ float field_0x3454;
    /* 0x03458 */ float field_0x3458;
    /* 0x0345C */ float field_0x345c;
    /* 0x03460 */ float field_0x3460;
    /* 0x03464 */ float field_0x3464;
    /* 0x03468 */ float field_0x3468;
    /* 0x0346C */ float field_0x346c;
    /* 0x03470 */ float field_0x3470;
    /* 0x03474 */ float field_0x3474;
    /* 0x03478 */ float field_0x3478;
    /* 0x0347C */ float field_0x347c;
    /* 0x03480 */ float field_0x3480;
    /* 0x03484 */ float field_0x3484;
    /* 0x03488 */ float field_0x3488;
    /* 0x0348C */ float field_0x348c;
    /* 0x03490 */ float field_0x3490;
    /* 0x03494 */ float field_0x3494;
    /* 0x03498 */ cXyz field_0x3498;
    /* 0x034A4 */ cXyz field_0x34a4;
    /* 0x034B0 */ cXyz field_0x34b0;
    /* 0x034BC */ cXyz field_0x34bc;
    /* 0x034C8 */ cXyz field_0x34c8;
    /* 0x034D4 */ cXyz field_0x34d4;
    /* 0x034E0 */ cXyz field_0x34e0;
    /* 0x034EC */ cXyz field_0x34ec;
    /* 0x034F8 */ cXyz field_0x34f8;
    /* 0x03504 */ cXyz field_0x3504;
    /* 0x03510 */ cXyz field_0x3510;
    /* 0x0351C */ cXyz field_0x351c;
    /* 0x03528 */ cXyz field_0x3528;
    /* 0x03534 */ cXyz field_0x3534;
    /* 0x03540 */ cXyz field_0x3540;
    /* 0x0354C */ cXyz field_0x354c[4];
    /* 0x0357C */ cXyz mLookPosFromOut;
    /* 0x03588 */ cXyz field_0x3588;
    /* 0x03594 */ cXyz field_0x3594;
    /* 0x035A0 */ cXyz field_0x35a0;
    /* 0x035AC */ cXyz field_0x35ac;
    /* 0x035B8 */ cXyz field_0x35b8;
    /* 0x035C4 */ cXyz field_0x35c4;
    /* 0x035D0 */ cXyz field_0x35d0;
    /* 0x035DC */ cXyz field_0x35dc;
    /* 0x035E8 */ cXyz field_0x35e8;
    /* 0x035F4 */ cXyz mMidnaAtnPos;
    /* 0x03600 */ cXyz field_0x3600;
    /* 0x0360C */ cXyz field_0x360c;
    /* 0x03618 */ cXyz field_0x3618;
    /* 0x03624 */ cXyz field_0x3624;
    /* 0x03630 */ cXyz field_0x3630;
    /* 0x0363C */ cXyz field_0x363c[4];
    /* 0x0366C */ cXyz field_0x366c[4];
    /* 0x0369C */ cXyz field_0x369c;
    /* 0x036A8 */ cXyz field_0x36a8;
    /* 0x036B4 */ cXyz field_0x36b4;
    /* 0x036C0 */ cXyz field_0x36c0[4];
    /* 0x036F0 */ cXyz field_0x36f0[4];
    /* 0x03720 */ cXyz field_0x3720;
    /* 0x0372C */ cXyz field_0x372c;
    /* 0x03738 */ cXyz field_0x3738;
    /* 0x03744 */ cXyz field_0x3744;
    /* 0x03750 */ cXyz field_0x3750;
    /* 0x0375C */ cXyz field_0x375c;
    /* 0x03768 */ cXyz field_0x3768;
    /* 0x03774 */ cXyz mForcePutPos;
    /* 0x03780 */ cXyz field_0x3780;
    /* 0x0378C */ cXyz field_0x378c;
    /* 0x03798 */ cXyz field_0x3798;
    /* 0x037A4 */ cXyz field_0x37a4;
    /* 0x037B0 */ cXyz field_0x37b0[2];
    /* 0x037C8 */ cXyz field_0x37c8;
    /* 0x037D4 */ cXyz field_0x37d4;
    /* 0x037E0 */ cXyz field_0x37e0;
    /* 0x037EC */ cXyz field_0x37ec;
    /* 0x037F8 */ cXyz field_0x37f8;
    /* 0x03804 */ cXyz field_0x3804;
    /* 0x03810 */ cXyz field_0x3810;
    /* 0x0381C */ cXyz field_0x381c;
    /* 0x03828 */ cXyz field_0x3828;
    /* 0x03834 */ cXyz field_0x3834;
    /* 0x03840 */ cXyz* mIronBallChainPos;
    /* 0x03844 */ csXyz* mIronBallChainAngle;
    /* 0x03848 */ void* field_0x3848;
    /* 0x0384C */ float* field_0x384c;
};

struct daAlinkHIO_anm_c {
    /* 0x00 */ int16_t field_0x00;
    /* 0x04 */ float field_0x04;
    /* 0x08 */ float field_0x08;
    /* 0x0C */ float field_0x0c;
    /* 0x10 */ float field_0x10;
};  // size = 0x14

struct daAlinkHIO_basic_c1 {
    /* 0x00 */ int16_t field_0x00;
    /* 0x02 */ int16_t mNeckAimAngleX;
    /* 0x04 */ int16_t mNeckAimAngleY;
    /* 0x06 */ int16_t mNeckAimAngleZ;
    /* 0x08 */ int16_t field_0x08;
    /* 0x0A */ int16_t field_0x0a;
    /* 0x0C */ int16_t field_0x0c;
    /* 0x0E */ int16_t field_0x0e;
    /* 0x10 */ int16_t mMetamorphoseFarAngle;
    /* 0x14 */ float field_0x14;
    /* 0x18 */ float mAnmBlendFactor;
    /* 0x1C */ float mWaitTurnSpeed;
    /* 0x20 */ float field_0x20;
    /* 0x24 */ float field_0x24;
    /* 0x28 */ float field_0x28;
    /* 0x2C */ float field_0x2c;
    /* 0x30 */ float field_0x30;
    /* 0x34 */ float field_0x34;
    /* 0x38 */ float field_0x38;
    /* 0x3C */ float field_0x3c;
    /* 0x40 */ float field_0x40;
    /* 0x44 */ float field_0x44;
    /* 0x48 */ float field_0x48;
    /* 0x4C */ float field_0x4c;
    /* 0x50 */ float mMetamorphoseNearDis;
    /* 0x54 */ float mMetamorphoseFarDis;
};

class daAlinkHIO_basic_c0 {
public:
    //static daAlinkHIO_basic_c1 const m;
};

class daAlinkHIO_autoJump_c1 {
public:
    /* 0x00 */ daAlinkHIO_anm_c field_0x00;
    /* 0x14 */ daAlinkHIO_anm_c field_0x14;
    /* 0x28 */ daAlinkHIO_anm_c field_0x28;
    /* 0x3C */ daAlinkHIO_anm_c field_0x3c;
    /* 0x50 */ uint8_t field_0x50;
    /* 0x52 */ int16_t field_0x52;
    /* 0x54 */ int16_t field_0x54;
    /* 0x56 */ int16_t field_0x56;
    /* 0x58 */ int16_t field_0x58;
    /* 0x5C */ float field_0x5c;
    /* 0x60 */ float field_0x60;
    /* 0x64 */ float field_0x64;
    /* 0x68 */ float field_0x68;
    /* 0x6C */ float field_0x6c;
    /* 0x70 */ float field_0x70;
    /* 0x74 */ float field_0x74;
    /* 0x78 */ float field_0x78;
    /* 0x7C */ float field_0x7c;
    /* 0x80 */ float field_0x80;
    /* 0x84 */ float field_0x84;
    /* 0x88 */ float field_0x88;
    /* 0x8C */ float field_0x8c;
    /* 0x90 */ float field_0x90;
    /* 0x94 */ float field_0x94;
    /* 0x98 */ float field_0x98;
    /* 0x9C */ float field_0x9c;
    /* 0xA0 */ float field_0xa0;
    /* 0xA4 */ float field_0xa4;
    /* 0xA8 */ float field_0xa8;
    /* 0xAC */ float field_0xac;
    /* 0xB0 */ float field_0xb0;
};  // size = 0xB4

class daAlinkHIO_autoJump_c0 {
public:
    //static daAlinkHIO_autoJump_c1 const m;
};

class daAlinkHIO_wlAutoJump_c1 {
public:
    /* 0x00 */ daAlinkHIO_anm_c field_0x00;
    /* 0x14 */ daAlinkHIO_anm_c field_0x14;
    /* 0x28 */ daAlinkHIO_anm_c field_0x28;
    /* 0x3C */ uint8_t field_0x3c;
    /* 0x3E */ int16_t field_0x3e;
    /* 0x40 */ int16_t field_0x40;
    /* 0x42 */ int16_t field_0x42;
    /* 0x44 */ float field_0x44;
    /* 0x48 */ float field_0x48;
    /* 0x4C */ float field_0x4c;
    /* 0x50 */ float field_0x50;
    /* 0x54 */ float field_0x54;
    /* 0x58 */ float field_0x58;
    /* 0x5C */ float field_0x5c;
    /* 0x60 */ float field_0x60;
    /* 0x64 */ float field_0x64;
    /* 0x68 */ float field_0x68;
    /* 0x6C */ float field_0x6c;
    /* 0x70 */ float field_0x70;
    /* 0x74 */ float field_0x74;
    /* 0x78 */ float field_0x78;
};  // size = 0x7C

class daAlinkHIO_wlAutoJump_c0 {
public:
    //static daAlinkHIO_wlAutoJump_c1 const m;
};

class daHorse_c {
public:
    /* 0x0000 */ fopAc_ac_c mActor;
    /* 0x0538 */ uint8_t field_0x538[0xD1C];
    /* 0x1254 */ daPy_actorKeep_c mZeldaActorKeep;
};

class daMidna_c {
public:
    enum daMidna_ERFLG0 {
        NoServiceWait = 128,
        ForcePanic = 8,
    };
    enum daMidna_FLG1 { ForceNormalColor = 8, ForceTiredColor = 4 };

    void onEndResetStateFlg0(daMidna_ERFLG0 pFlg) { mEndResetStateFlg0 |= pFlg; }
    uint32_t checkStateFlg1(daMidna_FLG1 pFlg) const { return mStateFlg1 & pFlg; }

    /* 0x0000 */ fopAc_ac_c mActor;
    /* 0x0538 */ uint8_t field_0x538[0x35C];
    /* 0x0894 */ uint32_t mStateFlg1;
    /* 0x0898 */ uint32_t mEndResetStateFlg0;
};

// add actual animation structures later
    namespace Animations {
        struct HumanFrontRoll {
            uint8_t _p0[0x18];                // 8038D7BC
            float bonk_recovery_anim_factor;  // 8038D7D4
            float bonk_recoil_anim_speed;     // 8038D7D8
            uint8_t _p1[0x28];                // 8038D7DC
            float roll_factor;                // 8038D804
            uint8_t _p2[0x24];                // 8038d808
        };
        static_assert(sizeof(HumanFrontRoll) == 0x70);

        struct HumanBackJump {
            uint8_t _p0[0x38];  // 8038D82C
        };
        static_assert(sizeof(HumanBackJump) == 0x38);

        struct HumanSideStep {
            uint8_t _p0[0x68];  // 8038d864
        };
        static_assert(sizeof(HumanSideStep) == 0x68);

        struct HumanSlide {
            uint8_t _p0[0x78];  // 8038d8cc
        };
        static_assert(sizeof(HumanSlide) == 0x78);

        struct HumanSwim {
            uint8_t _p0[0x14];  // 8038ED2C
            uint16_t diving_anim_frames;
            uint8_t _p1[0x02];
            float diving_anim_speed;
            uint8_t _p2[0x04];
            float diving_bob_anim_frames;
            float _p3;
            uint16_t underwater_dive_anim_frames;
            uint8_t _p4[0x02];
            float underwater_dive_anim_speed;
            uint8_t _p5[0x04];
            float prep_underwater_dive_anim_speed;
            float _p6;
            uint16_t surface_swim_anim_frames;
            uint8_t _p7[0x02];
            float surface_swim_anim_speed;
            float surface_swim_anim_frames_2;
            float start_swim_anim_frames;
            float _p8;
            uint8_t _p9[0x02];
            uint8_t surface_rotation_speed;
            uint8_t _p10[0x0D];
            float distance_from_water_to_surface;
            float resurface_anim_speed;
            float forward_swim_speed;
            float side_swim_speed;
            float back_swim_speed;
            float swim_up_speed;
            float ib_swim_speed;
            float _p11;
            float _p12;
            float _p13;
            float _p14;
            float _p15;
            float idle_anim_speed;
            float return_to_idle_from_swim_anim_frames;
            float idle_bob_depth;
            float ess_forward_swim_anim_speed;
            float full_forward_swim_anim_speed;
            float ess_side_swim_anim_speed;
            float full_side_swim_anim_speed;
            float ess_back_swim_anim_speed;
            float full_back_swim_anim_speed;
            float ready_after_dive_anim_speed;
            float underwater_swim_anim_speed;
            float ready_underwater_anim_frames;
            float _p16;
            float _p17;
            float unk_transition_into_swimming;
            float _p18;
            float sinking_speed;
            float _p19;
            float _p20;
            float swim_up_max_anim_speed;
            float swim_up_init_anim_speed;
            float initial_sinking_speed;
            float swim_up_max_speed;
            float dash_swim_max_speed;
            float _p21;
            float _p22;
            float _p23;
        };
        static_assert(sizeof(HumanSwim) == 0xFC);

        struct WolfGeneral {
            uint16_t slide_turn_around_anim_frames1;
            uint16_t _p0;
            float slide_turn_around_anim_speed1;
            uint32_t unk1;
            float unk2;
            float unk3;
            uint16_t slide_turn_around_anim_frames2;
            uint16_t _p1;
            float slide_turn_around_anim_speed2;
            uint32_t unk4;
            float unk5;
            float unk6;
            uint16_t dash_to_walking_anim_frames;
            uint16_t _p2;
            float dashing_anim_speed;
            uint32_t unk7;
            float unk8;
            float start_dash_anim_frames;
            uint16_t unk9;
            uint16_t _p3;
            float bonk_recoil_anim_speed;
            uint32_t unk10;
            float unk11;
            float unk12;
            uint16_t unk_dash_turning;
            uint16_t unk13;
            uint16_t dash_anim_frames;
            uint16_t unk14;
            uint16_t unk15;
            uint16_t dash_length_frames;
            uint16_t dash_reload_time_frames;
            uint16_t unk17;
            uint16_t unk18;
            uint16_t _p4;
            float unk19;
            float unk20;
            float unk21;
            float unk22;
            float unk23;
            float unk24;
            float unk25;
            float unk26;
            float unk27;
            float dash_to_walk_transition_factor;
            float dash_to_walk_transition_speed;
            float dash_to_walk_unk;
            float inital_dash_transition_factor;
            float initial_dash_transiiton_unk;
            float unk28;
            float unk29;
            float unk30;
            float slide_distance_unk;
            float slide_turn_around_distance;
            float unk31;
            float unk32;
            float unk33;
            float unk34;
            float unk35;
            float unk36;
            float dash_speed_large_area;
            float unk38;
            float unk39;
            float dash_initial_speed_large_area;
            float bonk_recoil_horizontal_distance;
            float bonk_recoil_vertical_distance;
            float dash_speed_small_area;
            float dash_initial_speed_small_area;
            float dash_anim_speed;
            float unk41;
            float unk42;
            float unk43;
            float unk44;
            float unk45;
        };
        static_assert(sizeof(WolfGeneral) == 0x100);

        struct WolfSwim {
            uint16_t surfacing_anim_frames;
            uint16_t _p0;
            float surfacing_anim_speed;
            uint32_t _p1;
            float inital_surfacing_anim_frames;
            float unk1;
            uint16_t unk2;
            uint16_t _p2;
            float unk3;
            uint32_t unk4;
            float unk5;
            float unk6;
            uint16_t dash_to_swim_anim_frames;
            uint16_t _p3;
            float initial_dash_anim_speed;
            uint32_t unk7;
            float initial_dash_anim_frames;
            float unk8;
            uint16_t surface_turning_speed_factor;
            uint16_t surface_turning_speed;
            uint16_t surface_turning_speed2;
            uint16_t unk9;
            uint16_t unk10;
            uint16_t unk11;
            float distance_from_water_to_surface;
            float unk12;
            float dash_swim_speed;
            float dash_to_swim_speed_decrease_factor;
            float gravity_entering_water_sinking;
            float gravity_in_water_rising;
            float gravity_in_water_rising_factor;
            float dash_to_swim_anim_speed;
            float swim_to_idle_anim_frames;
            float idle_bobbing_depth;
            float unk13;
            float unk14;
            float idle_to_swim_anim_frames;
            float climb_out_of_water_unk;
            float swim_speed;
            float unk15;
            float idle_doggy_padle_anim_speed;
            float idle_to_swim_anim_speed;
            float swim_anim_speed;
            float unk16;
            float unk17;
            float unk18;
            float unk19;
            float unk20;
        };
        static_assert(sizeof(WolfSwim) == 0xA8);

    };  // namespace Animations
#define tp_link_human_swim (*(Animations::HumanSwim *)(tp_link_human_swim_addr))
#define tp_link_human_frontroll (*(Animations::HumanFrontRoll *)(tp_link_human_frontroll_addr))
#define tp_link_wolf_general (*(Animations::WolfGeneral *)(tp_link_wolf_general_addr))
#define tp_link_wolf_swim (*(Animations::WolfSwim *)(tp_link_wolf_swim_addr))

    namespace Clawshot {
        struct ClawshotProperty {
            uint8_t _p0[0x04];                       // 8038E9C0
            uint16_t arm_animation1;                 // 8038E9C4 affects first person anim while firing
            uint8_t _p1[0x02];                       // 8038E9C6
            uint16_t arm_animation2;                 // 8038E9C8 affects first person anim while firing
            uint8_t _p20[0x22];                      // 8038E9CA
            uint16_t wall_hang_anim_speed;           // 8038E9EC
            uint8_t _p3[0x02];                       // 8038E9EE
            uint16_t wall_hang_anim;                 // 8038E9F0 has something to do with wall anim but not speed specifically
            uint8_t _p4[0x06];                       // 8038EAF2
            uint16_t second_clawshot_wait_frames;    // 8038EAF8 how long before you can use clawshot 2 when hanging from wall (ceiling is different)
            uint8_t _p5[0x06];                       // 8038EAFA
            uint16_t third_person_ready_anim_angle;  // 8038EA00 data type is wrong probably
            uint16_t third_person_ready_anim_speed;  // 8038EA02 data type is wrong probably
            float first_person_ready_anim_frames;    // 8038EA04
            float extension_rate;                    // 8038EA08
            float speed;                             // 8038EA0C
            float retraction_rate;                   // 8038EA10
            float pull_rate;                         // 8038EA14
            uint8_t _p6[0x1C];                       // 8038EA18
        };                                           // struct ClawshotProperty
        static_assert(sizeof(ClawshotProperty) == 0x74);

        struct ClawshotBG {
            uint8_t _p0[0x30];   // 801087B0
            uint32_t is_target;  // 801087E0
            uint8_t _p1[0x44];   // 801087E4
        };                       // struct ClawshotBG // pretty sure this actually needs to be a function pointer
        static_assert(sizeof(ClawshotBG) == 0x78);
    };  // namespace Clawshot

#define tp_clawshot (*(Clawshot::ClawshotProperty *)tp_clawshot_addr)
#define tp_clawshot_bg (*(Clawshot::ClawshotBG *)tp_clawshot_checkbg_addr)

#endif /* D_A_D_A_ALINK_H */