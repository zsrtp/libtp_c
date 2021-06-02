#ifndef D_D_ATTENTION_H
#define D_D_ATTENTION_H

#include "../SSystem/SComponent/c_angle.h"
#include "save/d_save.h"
#include "../m_Do/m_Do_ext.h"

class dAttHint_c {
public:
    uint32_t field_0x0;
    uint32_t field_0x4;
    uint32_t field_0x8;
};

class dAttCatch_c {
public:
    void* field_0x0;
    uint32_t field_0x4;
    float field_0x8;
    uint8_t field_0xc;
    uint8_t field_0xd;
    uint8_t field_0xe;
    uint8_t field_0xf;
    void* field_0x10;
};

class dAttParam_c {
public:
    uint8_t field_0x0;
    uint8_t field_0x1;
    uint8_t field_0x2;
    uint8_t field_0x3;
    uint8_t field_0x4;
    uint8_t field_0x5;
    uint8_t field_0x6;
    uint8_t field_0x7;
    uint8_t field_0x8;
    uint8_t field_0x9;
    uint8_t field_0xa;
    uint8_t field_0xb;
    uint8_t field_0xc;
    uint8_t field_0xd;
    uint8_t field_0xe;
    uint8_t field_0xf;
    uint8_t field_0x10;
    uint8_t field_0x11;
    uint8_t field_0x12;
};

class dAttLook_c {
public:
    uint32_t field_0x0;
    uint32_t field_0x4;
    float field_0x8;
};

#pragma pack(push, 1)
class dAttList_c {
public:
    uint8_t field_0x0[8];
    cSAngle angle;
    uint8_t field_0xa[10];
};
#pragma pack(pop)

#pragma pack(push, 1)
class dAttDraw_c {
public:
    uint8_t field_0x0;
    uint8_t field_0x1;
    uint8_t field_0x2;
    uint8_t field_0x3;
    uint8_t field_0x4;
    uint8_t field_0x5;
    uint8_t field_0x6;
    uint8_t field_0x7;
    /* 0x008 */ mDoExt_bckAnm bckAnm[2];
    /* 0x040 */ mDoExt_bpkAnm bpkAnm[2];
    /* 0x070 */ mDoExt_brkAnm brkAnm[2];
    /* 0x0A0 */ mDoExt_brkAnm brkAnm2[2];
    /* 0x0D0 */ mDoExt_btkAnm btkAnm[2];
    /* 0x100 */ mDoExt_bckAnm bckAnm2;
    /* 0x11C */ mDoExt_bpkAnm bpkAnm2;
    /* 0x134 */ mDoExt_brkAnm brkAnm3;
    /* 0x14C */ mDoExt_btkAnm btkAnm2;
    /* 0x164 */ uint8_t field_0x164[0xC];
    /* 0x170 */ uint8_t field_0x170;
    /* 0x171 */ uint8_t field_0x171;
    /* 0x172 */ uint8_t field_0x172;
    /* 0x173 */ uint8_t field_0x173;
    /* 0x174 */ uint8_t field_0x174;
    /* 0x175 */ uint8_t field_0x175;
};
#pragma pack(pop)

class dAttDraw_CallBack_c {
public:
    mDoExt_McaMorfCallBack1_c mDoExt_McaMorfCallback;
};

// size is right but members are off, fix later
class dAttention_c {
public:
    uint8_t field_0x0[4];
    uint32_t field_0x4;
    dAttDraw_CallBack_c dattdraw_callback;
    uint32_t field_0xc;
    uint32_t field_0x10;
    uint8_t field_0x14[8];
    cXyz field_0x1c;
    /* 0x028 */ dAttDraw_c attention_draw[2];
    int field_0x318;
    cXyz field_0x31c;
    uint8_t field_0x328[12];
    uint32_t field_0x334;
    /* 0x0338 */ dAttList_c attention_list1[8];
    int* field_0x3d8;
    int* field_0x3dc;
    /* 0x03E0 */ dAttList_c attention_list2[4];
    int* field_0x430;
    int field_0x434;
    /* 0x0438 */ dAttList_c attention_list3[4];
    int* field_0x488;
    int field_0x48c;
    dAttHint_c attention_hint;
    dAttCatch_c attention_catch;
    uint8_t field_0x4b0[4];
    dAttLook_c attention_look;
    uint8_t field_0x4c0;
    uint8_t field_0x4c1;
    uint8_t field_0x4c2;
    uint8_t field_0x4c3;
    int* field_0x4c4;
    uint8_t field_0x4c8;
    uint8_t field_0x4c9;
    uint8_t field_0x4ca;
    uint8_t field_0x4cb;
    uint8_t field_0x4cc;
    uint8_t field_0x4cd;
    uint8_t field_0x4ce;
    uint8_t field_0x4cf;
    /* 0x04D0 */ dAttParam_c attention_param;
    uint8_t field_0x4e3;
    uint8_t field_0x4e4;
    uint8_t field_0x4e5;
    int* field_0x4e6;
    uint8_t field_0x4ea;
    uint8_t field_0x4eb;
    uint8_t field_0x4ec;
    uint8_t field_0x4ed;
    uint8_t field_0x4ee;
    uint8_t field_0x4ef;
    uint8_t field_0x4f0[0x14];
    void* vtable;
};

#endif /* D_D_ATTENTION_H */
