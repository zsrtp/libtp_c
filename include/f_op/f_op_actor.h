#ifndef F_OP_ACTOR_H_
#define F_OP_ACTOR_H_

#include "../SSystem/SComponent/c_sxyz.h"
#include "../SSystem/SComponent/c_xyz.h"
#include "../dolphin/mtx/mtx.h"
#include "../f_pc/f_pc_leaf.h"

struct JKRSolidHeap;

struct actor_place {
    cXyz mPosition;
    csXyz mAngle;
    uint8_t mRoomNo;
    uint8_t field_0x13;
};

class fopAc_ac_c : public leafdraw_class {
public:
    /* 0x0C0 */ int mAcType;
    /* 0x0C4 */ create_tag_class mAcTg;
    /* 0x0D8 */ create_tag_class mDwTg;
    /* 0x0EC */ profile_method_class* mSubMtd;
    /* 0x0F0 */ JKRSolidHeap* unk_0x0F0;
    /* 0x0F4 */ uint8_t unk_0x0F4[0x496 - 0xF4];
    /* 0x496 */ uint8_t unk_0x496;
    /* 0x497 */ uint8_t unk_0x497[0x499 - 0x497];
    /* 0x499 */ int8_t unk_0x499;
    /* 0x49A */ uint8_t unk_0x49A[0x4A8 - 0x49A];
    /* 0x4A8 */ actor_place mOrig;
    /* 0x4BC */ actor_place mNext;
    /* 0x4D0 */ actor_place mCurrent;
    /* 0x4E4 */ csXyz mCollisionRot;
    /* 0x4EC */ cXyz mScale;
    /* 0x4F8 */ cXyz mSpeed;
    /* 0x504 */ Mtx* mCullMtx;
    /* 0x508 */ cXyz mCullMin;
    /* 0x514 */ cXyz mCullMax;
    /* 0x520 */ uint8_t unk_0x520[0xC];
    /* 0x52C */ float mSpeedF;
    /* 0x530 */ float mGravity;
    /* 0x534 */ float mMaxFallSpeed;

    const cXyz& getPosition() const { return mCurrent.mPosition; }
    const csXyz& getAngle() const { return mCurrent.mAngle; }
};  // Size: unknown

#endif