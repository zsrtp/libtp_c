#ifndef M_DO_M_DO_MTX_H
#define M_DO_M_DO_MTX_H

#include <stdint.h>
#include "../dolphin/mtx/mtx.h"

extern "C" void PSMTXConcat(const Mtx, const Mtx, Mtx);
extern "C" void PSMTXScale(Mtx, float, float, float);
extern "C" void PSMTXTrans(Mtx matrix, float x_trans, float y_trans, float z_trans);

#define mDoMtx_stack_c__now (*(Mtx*)(mDoMtx_stack_c__now_addr))

typedef void (*mDoMtx_XYZrotM__t)(Mtx, short, short, short);
#define mDoMtx_XYZrotM ((mDoMtx_XYZrotM__t)mDoMtx_XYZrotM__addr)

typedef void (*mDoMtx_stack_c__scaleM_t)(float, float, float);
#define mDoMtx_stack_c__scaleM ((mDoMtx_stack_c__scaleM_t)mDoMtx_stack_c__scaleM_addr)

class mDoMtx_stack_c {
public:
    static MtxP get() { return mDoMtx_stack_c__now; }
    static void transS(float x, float y, float z) { PSMTXTrans(mDoMtx_stack_c__now, x, y, z); }
    static void scaleS(float x, float y, float z) { PSMTXScale(mDoMtx_stack_c__now, x, y, z); }
    static void XYZrotM(short x, short y, short z) { mDoMtx_XYZrotM(mDoMtx_stack_c__now, x, y, z); }
    static void revConcat(MtxP mtx) { PSMTXConcat(mtx, mDoMtx_stack_c__now, mDoMtx_stack_c__now); }
};

#endif /* M_DO_M_DO_MTX_H */
