#ifndef F_F_OP_SCENE_REQ_H_
#define F_F_OP_SCENE_REQ_H_

#include <stdint.h>
#include "../addrs.h"

struct LoadingInfo {
    uint32_t isLoading;  // 80450CE0
    uint8_t _p0[0x04];   // 80450CE4
};

#define tp_fopScnRq (*(LoadingInfo *)(tp_fopScnRq_addr))

#endif