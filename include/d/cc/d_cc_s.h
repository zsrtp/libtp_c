#ifndef D_CC_D_CC_S_H
#define D_CC_D_CC_S_H

#include "../../SSystem/SComponent/c_cc_s.h"
#include "d_cc_d.h"
#include "d_cc_mass_s.h"

class dCcS {
public:
    /* 0x0000 */ cCcS mCCcS;
    /* 0x2834 */ uint8_t field_0x2834[0x18];
    /* 0x284C */ dCcMassS_Mng mMass_Mng;
};

#endif /* D_CC_D_CC_S_H */
