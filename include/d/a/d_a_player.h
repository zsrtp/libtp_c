#ifndef D_A_D_A_PLAYER_H
#define D_A_D_A_PLAYER_H

#include "../../SSystem/SComponent/c_bg_s_poly_info.h"
#include "../d_drawlist.h"
#include "../d_stage.h"
#include "../save/d_save.h"
#include "../../f_op/f_op_actor.h"
#include "../../m_Do/m_Do_ext.h"
#include "../../JSystem/JUtility/JUTTexture.h"

class daPy_sightPacket_c : dDlst_base_c {
public:
    /* 0x04 */ bool mDrawFlag;
    /* 0x05 */ uint8_t field_0x5[3];
    /* 0x08 */ cXyz mPos;
    /* 0x14 */ Mtx field_0x14;
    /* 0x44 */ ResTIMG* field_0x44;
    /* 0x48 */ ResTIMG* field_0x48;
};

struct daPy_boomerangMove_c {
};

struct JKRHeap{};

class daPy_anmHeap_c {
public:
    enum daAlinkHEAP_TYPE {};

    uint16_t getIdx() const { return mIdx; }
    void resetIdx() { mIdx = 0xffff; }
    void resetPriIdx() { mPriIdx = 0xffff; }
    void resetArcNo() { mArcNo = 0xffff; }

    /* 0x00 */ uint16_t mIdx;
    /* 0x02 */ uint16_t mPriIdx;
    /* 0x04 */ uint16_t mArcNo;
    /* 0x06 */ uint16_t field_0x06;
    /* 0x08 */ int mBufferSize;
    /* 0x0C */ void* mBuffer;
    /* 0x10 */ JKRHeap* mAnimeHeap;
};  // Size = 0x14

class daPy_actorKeep_c {
public:
    uint32_t getID(void) const { return mID; }
    void setID(uint32_t id) { mID = id; }
    fopAc_ac_c* getActor(void) const { return mActor; }

    uint32_t mID;
    fopAc_ac_c* mActor;
};

#pragma pack(push, 1)
class daPy_frameCtrl_c : public J3DFrameCtrl {
public:
    uint16_t getEndFlg() { return mEndFlg; }
    uint16_t getNowSetFlg() { return mNowSetFlg; }
    void onEndFlg() { mEndFlg = 1; }
    void onNowSetFlg() { mNowSetFlg = 1; }
    void offNowSetFlg() { mNowSetFlg = 0; }
    void offEndFlg() {
        mEndFlg = 0;
        mNowSetFlg = 0;
    }

    /* 0x14 */ uint16_t mEndFlg;
    /* 0x16 */ uint16_t mNowSetFlg;
};
#pragma pack(pop)

class daPy_demo_c {
public:
    void setDemoType(uint16_t pType) { mDemoType = pType; }
    uint16_t getDemoType() const { return mDemoType; }

    /* 0x00 */ uint16_t mDemoType;
    /* 0x02 */ int16_t mDemoMoveAngle;
    /* 0x04 */ int16_t mTimer;
    /* 0x06 */ int16_t mParam2;
    /* 0x08 */ int mParam0;
    /* 0x0C */ int mParam1;
    /* 0x10 */ int mDemoMode;
    /* 0x14 */ float mStick;
    /* 0x18 */ cXyz mDemoPos0;
};  // Size = 0x24

class daPy_py_c : public fopAc_ac_c {
public:
    /* 0x0538 */ uint8_t field_0x538[0x32];
#ifdef WII_PLATFORM
    uint8_t unk_field0[4]; // might be part of fopAc_ac_c, fix later
#endif
    /* 0x056A */ uint8_t field_0x56a;
    /* 0x056B */ uint8_t field_0x56b[5];
    /* 0x0570 */ int mNoResetFlg0;
    /* 0x0574 */ int mNoResetFlg1;
    /* 0x0578 */ int mNoResetFlg2;
    /* 0x057C */ int mNoResetFlg3;
    /* 0x0580 */ int mResetFlg0;
    /* 0x0584 */ int mResetFlg1;
    /* 0x0588 */ int mEndResetFlg0;
    /* 0x058C */ int mEndResetFlg1;
    /* 0x0590 */ int mEndResetFlg2;
    /* 0x0594 */ uint8_t field_0x594[0x10];
    /* 0x05A4 */ cXyz mHeadTopPos;
    /* 0x05B0 */ cXyz mItemPos;
    /* 0x05BC */ cXyz mSwordTopPos;
    /* 0x05C8 */ cXyz mLeftHandPos;
    /* 0x05D4 */ cXyz mRightHandPos;
    /* 0x05E0 */ cXyz mLeftFootPosP;
    /* 0x05EC */ cXyz mRightFootPosP;
    /* 0x05F8 */ uint8_t field_0x5f8[0xC];
    /* 0x0604 */ daPy_demo_c mDemo;
    void* vtable;

public:
    enum daPy_FLG0 {
        EquipHeavyBoots = 0x2000000,
        MagneBootsOn = 0x1000,
        UnkFrollCrashFlg2 = 0x10,
        UnkFrollCrashFlg1 = 0x8
    };
    enum daPy_FLG1 { Wolf = 0x2000000, ThrowDamage = 0x4000 };
    enum daPy_FLG2 { BoarSingleBattle = 0x1800000, UnkArmor = 0x80000, Unk = 1 };
    enum daPy_FLG3 { CopyRodThrowAfter = 0x40000 };
    enum daPy_ERFLG0 {};
    enum daPy_ERFLG1 { GanonFinish = 0x80000000, UnkForcePutPos = 0x2000 };
    enum daPy_ERFLG2 {};
    enum daPy_RFLG0 {};

    inline bool getSumouCameraMode() const {
        bool sumouCameraMode = false;
        if (field_0x56a != 0 && field_0x56a < 0x26) {
            sumouCameraMode = true;
        }
        return sumouCameraMode;
    }

    int checkNoResetFlg0(daPy_FLG0 pFlag) const { return mNoResetFlg0 & pFlag; }
    int checkNoResetFlg1(daPy_FLG1 pFlag) const { return mNoResetFlg1 & pFlag; }
    int checkNoResetFlg2(daPy_FLG2 pFlag) const { return mNoResetFlg2 & pFlag; }
    void onNoResetFlg0(int pFlg) { mNoResetFlg0 |= pFlg; }
    void onEndResetFlg1(daPy_ERFLG1 pFlg) { mEndResetFlg1 |= pFlg; }
    int checkWolf() { return checkNoResetFlg1(Wolf); }
};

#endif /* D_A_D_A_PLAYER_H */
