#ifndef JKRDISPOSER_H_
#define JKRDISPOSER_H_

#include "../JSupport/JSUList.h"

class JKRHeap;
class JKRDisposer {
public:
    JKRDisposer();
    virtual ~JKRDisposer();

public:
    /* 0x00 */  // vtable
    /* 0x04 */ JKRHeap* mHeap;
    /* 0x08 */ JSULink<JKRDisposer> mLink;
};

#endif