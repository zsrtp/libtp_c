#ifndef JAISOUNDPARAMS_H
#define JAISOUNDPARAMS_H

#include "JASSoundParams.h"

struct JAISoundParamsProperty {
    void init() {
        field_0x0 = 1.0f;
        field_0x4 = 0.0f;
        field_0x8 = 1.0f;
    }

    /* 0x00 */ float field_0x0;
    /* 0x04 */ float field_0x4;
    /* 0x08 */ float field_0x8;
};  // Size: 0xC

struct JAISoundParamsTransition {
    struct TTransition {
        void zero() {
            field_0x0 = 0.0f;
            mCount = 0;
            field_0x4 = 0.0f;
        }

        void set(float newValue, float param_1, uint32_t param_2) {
            mCount = param_2;
            field_0x0 = (newValue - param_1) / mCount;
            field_0x4 = newValue;
        }

        float apply(float param_0) {
            if (mCount > 1) {
                mCount--;
                param_0 += field_0x0;
            } else {
                if (mCount == 1) {
                    mCount = 0;
                    param_0 = field_0x4;
                }
            }
            return param_0;
        }

        /* 0x0 */ float field_0x0;
        /* 0x4 */ float field_0x4;
        /* 0x8 */ uint32_t mCount;
    };  // Size: 0xC

    void init() {
        mVolume.zero();
        mPitch.zero();
        mFxMix.zero();
        mPan.zero();
        mDolby.zero();
    }

    void apply(JASSoundParams* pParams) {
        pParams->mVolume = mVolume.apply(pParams->mVolume);
        pParams->mPitch = mPitch.apply(pParams->mPitch);
        pParams->mFxMix = mFxMix.apply(pParams->mFxMix);
        pParams->mDolby = mDolby.apply(pParams->mDolby);
        pParams->mPan = mPan.apply(pParams->mPan);
    }

    /* 0x00 */ TTransition mVolume;
    /* 0x0C */ TTransition mPitch;
    /* 0x18 */ TTransition mFxMix;
    /* 0x24 */ TTransition mPan;
    /* 0x30 */ TTransition mDolby;
};  // Size: 0x3C

struct JAISoundParamsMove {
    JAISoundParamsMove() : mParams() {}

    void init() {
        mParams.init();
        mTransition.init();
    }

    void calc() { mTransition.apply(&mParams); }

    /* 0x00 */ JASSoundParams mParams;
    /* 0x14 */ JAISoundParamsTransition mTransition;
};  // Size: 0x50

struct JAISoundParams {
    JAISoundParams() : mMove() {}

    void init() {
        mMove.init();
        mProperty.init();
    }

    /* 0x0 */ JAISoundParamsProperty mProperty;
    /* 0xC */ JAISoundParamsMove mMove;
};  // Size: 0x5C

#endif /* JAISOUNDPARAMS_H */