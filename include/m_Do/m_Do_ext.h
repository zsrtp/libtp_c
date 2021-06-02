#ifndef M_DO_M_DO_EXT_H
#define M_DO_M_DO_EXT_H

#include <stdint.h>
#include "../dolphin/gx/GXTexture.h"

struct J3DAnmTransform {};

class J3DGXColorS10 {
public:
    _GXColorS10 mColor;
};

#pragma pack(push, 1)
class J3DFrameCtrl {
public:
    void* vtable;
    uint8_t mAttribute;
    bool mState;
    int16_t mStart;
    int16_t mEnd;
    int16_t mLoop;
    float mRate;
    float mFrame;
};
#pragma pack(pop)

#pragma pack(push, 1)
class mDoExt_baseAnm {
public:
    J3DFrameCtrl frame_control;
};
#pragma pack(pop)

#pragma pack(push, 1)
class mDoExt_btkAnm {
public:
    mDoExt_baseAnm mBaseAnm;
    uint32_t field_0x14;
};
#pragma pack(pop)

#pragma pack(push, 1)
class mDoExt_brkAnm {
public:
    mDoExt_baseAnm mBaseAnm;
    uint32_t field_0x14;
};
#pragma pack(pop)

#pragma pack(push, 1)
class mDoExt_bpkAnm {
public:
    mDoExt_baseAnm mBaseAnm;
    uint32_t field_0x14;
};
#pragma pack(pop)

#pragma pack(push, 1)
class mDoExt_bckAnm {
public:
    mDoExt_baseAnm mBaseAnm;
    uint8_t field_0x14[4];
    uint32_t field_0x18;
};  // Size = 0x1C
#pragma pack(pop)

#pragma pack(push, 1)
class mDoExt_McaMorfCallBack1_c {
public:
private:
    void* vtable;
};
#pragma pack(pop)

class mDoExt_AnmRatioPack {
public:
    /* 0x0 */ float mRatio;
    /* 0x4 */ J3DAnmTransform* mAnmTransform;
};  // Size = 0x8

#endif /* M_DO_M_DO_EXT_H */
