#ifndef J3DPACKET_H
#define J3DPACKET_H

#include "../../dolphin/mtx/mtx.h"
#include <stdint.h>
#include <cstddef>

class J3DMatPacket;
class J3DDrawBuffer;
class J3DMaterial;
class J3DMaterialAnm;
class J3DModel;
class J3DMtxBuffer;
class J3DShape;
class J3DTexMtx;
class J3DTexture;

class J3DDisplayListObj {
public:
    void* mpData[2];
    uint32_t mSize;
    uint32_t mCapacity;
};

class J3DPacket {
public:
    inline void clear() {
        mpNextSibling = NULL;
        mpFirstChild = NULL;
    }
    void* vtable;
    J3DPacket* mpNextSibling;
    J3DPacket* mpFirstChild;
    void* mpUserData;
};

class J3DDrawPacket : public J3DPacket {
public:
    int mFlags;
    char mPad0[0x0C];  // unk
    J3DDisplayListObj* mpDisplayListObj;
    J3DTexMtx* mpTexMtx;
};

class J3DShapePacket : public J3DDrawPacket {
public:
    J3DShape* mpShape;
    J3DMtxBuffer* mpMtxBuffer;
    Mtx* mpViewMtx;
    uint32_t mDiffFlag;
    J3DModel* mpModel;
};

class J3DMatPacket : public J3DDrawPacket {
public:
    J3DShapePacket* mpShapePacket;
    J3DShapePacket* mpFirstShapePacket;
    J3DMaterial* mpMaterial;
    int32_t mSortFlags;
    J3DTexture* mpTexture;
    J3DMaterialAnm* mpMaterialAnm;
};

#endif /* J3DPACKET_H */
