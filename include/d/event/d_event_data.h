#ifndef D_EVENT_D_EVENT_DATA_H
#define D_EVENT_D_EVENT_DATA_H

#include "../d_stage.h"
#include "../save/d_save.h"

struct dEvDtStaff_c {

};

struct dEvDtEvent_c {

};

class dEvDtFlag_c {
public:
    uint32_t field_0x0[320];
};
#pragma pack(push, 1)
class dEvDtBase_c {
public:
    uint32_t field_0x0;
    uint32_t field_0x4;
    uint32_t field_0x8;
    uint32_t field_0xc;
    uint32_t field_0x10;
    uint32_t field_0x14;
    uint32_t field_0x18;
    uint32_t field_0x1c;
    uint32_t field_0x20;
};
#pragma pack(pop)

#endif /* D_EVENT_D_EVENT_DATA_H */
