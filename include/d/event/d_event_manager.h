#ifndef D_EVENT_D_EVENT_MANAGER_H
#define D_EVENT_D_EVENT_MANAGER_H

#include "d_event_data.h"

struct dEvDtData_c {};

#pragma pack(push, 1)
class dEvent_exception_c {
public:
    uint32_t field_0x0;
    uint8_t field_0x4;
    uint8_t field_0x5;
    uint8_t field_0x6;
    uint8_t field_0x7;
    uint32_t field_0x8;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct dEvent_manager_c {
    /* 0x0000 */ dEvDtBase_c mEventList[11];
    /* 0x018C */ int32_t mCameraPlay;
    /* 0x0190 */ dEvent_exception_c mEventException;
    /* 0x019C */ cXyz mGoal;
    /* 0x01A8 */ uint8_t field_0x1a8[2];
    /* 0x01AA */ uint16_t field_0x1aa;
    /* 0x01AC */ uint8_t field_0x1ac[4];
    /* 0x01B0 */ uint32_t field_0x1b0;
    /* 0x01B4 */ uint32_t field_0x1b4;
    /* 0x01B8 */ uint32_t field_0x1b8;
    /* 0x01BC */ dEvDtFlag_c mFlags;
    /* 0x06BC */ bool mDataLoaded;
};
#pragma pack(pop)

#endif /* D_EVENT_D_EVENT_MANAGER_H */
