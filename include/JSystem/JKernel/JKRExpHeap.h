#ifndef JKREXPHEAP_H
#define JKREXPHEAP_H

#include "JKRHeap.h"

class JKRExpHeap : public JKRHeap {
public:
    class CMemBlock {
        friend class JKRExpHeap;

    public:
        void newGroupId(uint8_t groupId) { this->mGroupId = groupId; }
        // bool isValid() const { return this->mMagic == 'HM'; }
        bool _isTempMemBlock() const { return (this->mFlags & 0x80) ? true : false; }
        int getAlignment() const { return this->mFlags & 0x7f; }
        void* getContent() const { return (void*)(this + 1); }
        CMemBlock* getPrevBlock() const { return this->mPrev; }
        CMemBlock* getNextBlock() const { return this->mNext; }
        uint32_t getSize() const { return this->size; }
        uint8_t getGroupId() const { return this->mGroupId; }
        static CMemBlock* getBlock(void* data) { return (CMemBlock*)((uint32_t)data + -0x10); }

    private:
        uint16_t mMagic;
        uint8_t mFlags;  // a|bbbbbbb a=temporary b=alignment
        uint8_t mGroupId;
        uint32_t size;
        CMemBlock* mPrev;
        CMemBlock* mNext;
    };
    friend class CMemBlock;

public:
    CMemBlock* getHeadUsedList() const { return mHeadUsedList; }

    uint8_t field_0x6c;
    uint8_t mCurrentGroupId;
    bool field_0x6e;
    void* field_0x70;
    uint32_t field_0x74;
    CMemBlock* mHeadFreeList;
    CMemBlock* mTailFreeList;
    CMemBlock* mHeadUsedList;
    CMemBlock* mTailUsedList;
};

#define zeldaHeap (*(JKRExpHeap**)(tp_zeldaHeap_addr))
#define gameHeap (*(JKRExpHeap**)(tp_gameHeap_addr))
#define archiveHeap (*(JKRExpHeap**)(tp_archiveHeap_addr))

typedef int32_t (*JKRExpHeap__getUsedSize_t)(uint8_t);
#define JKRExpHeap__getUsedSize ((JKRExpHeap__getUsedSize_t)JKRExpHeap__getUsedSize_addr)

typedef int32_t (*JKRHeap__getFreeSize_t)(JKRHeap* addr);
#define JKRHeap__getFreeSize ((JKRHeap__getFreeSize_t)JKRHeap__getFreeSize_addr)

typedef int32_t (*JKRHeap__getTotalFreeSize_t)(JKRHeap* addr);
#define JKRHeap__getTotalFreeSize ((JKRHeap__getTotalFreeSize_t)JKRHeap__getTotalFreeSize_addr)

typedef int32_t (*JKRExpHeap__do_getTotalFreeSize_t)(JKRExpHeap* addr);
#define JKRExpHeap__do_getTotalFreeSize                                                            \
    ((JKRExpHeap__do_getTotalFreeSize_t)JKRExpHeap__do_getTotalFreeSize_addr)

#endif /* JKREXPHEAP_H */
