#include "cheats.h"
#include "controller.h"
#include "tp.h"
#include "items.h"

namespace Cheats {
    using namespace Controller;
    using namespace Clawshot;

    void apply_cheats() {
        if (tp_mPadStatus.sval == (Pad::R | Pad::A)) {
            if (tp_gameInfo.momentum_ptr) {
                tp_gameInfo.momentum_ptr->link_momentum.y = 56.0f;
            }
            Controller::set_buttons_down(0x0);
            Controller::set_buttons_pressed(0x0);
            tp_mPadButton.sval = 0x0;
            tp_mPadStatus.sval = 0x0;
        }

        tp_clawshot.speed = 100.0f;
        tp_clawshot.pull_rate = 60.0f;
        tp_clawshot.extension_rate = 2000.0f;
        tp_clawshot.retraction_rate = 150.0f;          
    }
}  // namespace Cheats