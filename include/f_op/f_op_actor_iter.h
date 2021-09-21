#ifndef F_OP_ACTOR_ITER_H_
#define F_OP_ACTOR_ITER_H_

#include "f_op_actor.h"

typedef void* (*fopAcIt_JudgeFunc)(void*, void*);

typedef void* (*fpcSch_JudgeForPName_t)(void*, void*);
#define fpcSch_JudgeForPName ((fpcSch_JudgeForPName_t)fpcSch_JudgeForPName_addr)

typedef void* (*fopAcIt_Judge_t)(fopAcIt_JudgeFunc, void*);
#define fopAcIt_Judge ((fopAcIt_Judge_t)fopAcIt_Judge_addr)

inline void* fopAcM_SearchByName(int16_t name) {
    return fopAcIt_Judge(fpcSch_JudgeForPName, &name);
}

#endif
