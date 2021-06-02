#ifndef J2DPICTURE_H_
#define J2DPICTURE_H_

#include "J2DPane.h"
#include "../JKernel/JKRArchive.h"

// define and move to appropriate header later
class JUTPalette;

class J2DPicture : public J2DPane {
public:
    virtual void initiate();

public:
    /* 0x00 */ uint8_t field_0x00[0x08];
    /* 0x08 */ uint8_t field_0x08;
};

typedef void (*J2DPicture__J2DPicture4_t)(void* addr, const ResTIMG* img);
#define J2DPicture__J2DPicture4 ((J2DPicture__J2DPicture4_t)J2DPicture__J2DPicture4_addr)

typedef void (*J2DPicture__draw_t)(void* addr, double xpos, double ypos, double width, double height, bool mirrorX, bool mirrorY, bool tumble);
#define J2DPicture__draw ((J2DPicture__draw_t)J2DPicture__draw_addr)

#endif