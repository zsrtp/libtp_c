
#ifndef F_PC_LEAF_H_
#define F_PC_LEAF_H_

#include "f_pc_base.h"
#include "f_pc_draw_priority.h"
#include "f_pc_method.h"

typedef struct leafdraw_method_class {
    /* 0x00 */ process_method_class mBase;
    /* 0x10 */ process_method_func mpDrawFunc;
} leafdraw_method_class;

typedef struct leafdraw_class {
    /* 0x00 */ base_process_class mBase;
    /* 0xB8 */ leafdraw_method_class* mpDrawMtd;
    /* 0xBC */ int8_t mbUnk0;
    /* 0xBD */ uint8_t mbUnk1;
    /* 0xBE */ draw_priority_class mDwPi;
} leafdraw_class;

typedef struct leaf_process_profile_definition {
    /* 0x00 */ process_profile_definition mBase;
    /* 0x1C */ leafdraw_method_class* mLfDrwMth;
    /* 0x20 */ int16_t unk20;
    /* 0x22 */ uint8_t unk22[2];
    /* 0x24 */ int32_t unk24;
} leaf_process_profile_definition;

#endif
