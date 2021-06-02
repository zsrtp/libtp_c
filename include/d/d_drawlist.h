#ifndef D_D_DRAWLIST_H
#define D_D_DRAWLIST_H

#include <stdint.h>
#include "../JSystem/J3DGraphBase/J3DPacket.h"

class dDlst_FileInfo_c {
public:
    void draw(void);
    ~dDlst_FileInfo_c();

private:
};

#pragma pack(push, 1)
class dDlst_peekZ_c {
public:
    uint8_t unk[7];
};  // actual size unknown!!!
#pragma pack(pop)

#pragma pack(push, 1)
class dDlst_window_c {
public:
    float view_port1;
    float view_port2;
    float view_port3;
    float view_port4;
    float view_port5;
    float view_port6;
    float scissor1;
    float scissor2;
    float scissor3;
    float scissor4;
    int camera_id;
};
#pragma pack(pop)

class dDlst_base_c {
public:
    virtual void draw();
};

#pragma pack(push, 1)
class dDlst_list_c {
public:
    /* 0x00000 */ uint8_t field_0x00[0x1C];
    /* 0x0001C */ J3DPacket* mpPacket;
    /* 0x00020 */ uint8_t field_0x20[0x16170];
    /* 0x16180 */ dDlst_peekZ_c dlstPeekZ;
    /* 0x16184 */ uint8_t unk_0x16194[0x1F];
};  // Size: 0x161A0
#pragma pack(pop)

#endif /* D_D_DRAWLIST_H */
