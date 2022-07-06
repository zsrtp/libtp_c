#ifndef JAISEMGR_H
#define JAISEMGR_H

#include "JAIAudience.h"
#include "JAISeqDataMgr.h"
#include "JAISound.h"
#include "../JSupport/JSUList.h"

struct JASNonCopyable {
    /* 0x0 */ int field_0x0;
};  // Size: 0x4

struct JAISeCategoryArrangement {};

class JAISeMgr;

struct JAISe {};

class JAISeCategoryMgr : public JAISeqDataUser {
public:
    /* 0x04 */ JASNonCopyable field_0x4;
    /* 0x08 */ JAISoundParamsMove mParams;
    /* 0x58 */ JSUList<JAISe> mSeList;
    /* 0x64 */ int mMaxInactiveSe;
    /* 0x68 */ int mMaxActiveSe;
};  // Size: 0x6C

class JAISeMgr : public JAISeqDataUser, public JAISoundActivity {
public:
    /* 0x008 */ JAIAudience* mAudience;
    /* 0x00C */ JAISeqDataMgr* mSeqDataMgr;
    /* 0x010 */ int field_0x10;
    /* 0x014 */ JAISeCategoryMgr mCategoryMgrs[16];
    /* 0x6D4 */ JAISoundParamsMove mParams;
};  // Size: 0x724

#endif /* JAISEMGR_H */