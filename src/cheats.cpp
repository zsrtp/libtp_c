#include "cheats.h"
#include "controller.h"
#include "inventory.h"
#include "items.h"
#include "tp.h"

namespace Cheats {
    using namespace Controller;

    void apply_cheats() {
        if (tp_mPadStatus.sval == (Pad::R | Pad::A)) {
            if (tp_gameInfo.momentum_ptr) {
                tp_gameInfo.momentum_ptr->link_momentum.y = 56.0f;
            }
            Inventory::set_rupee_flags();
            Controller::set_buttons_down(0x0);
            Controller::set_buttons_pressed(0x0);
            tp_mPadButton.sval = 0x0;
            tp_mPadStatus.sval = 0x0;
        }
        tp_clawshot.speed = 2870.0f;
        tp_clawshot.pull_rate = 500.0f;
        tp_clawshot.extension_rate = 69120.0f;
        tp_clawshot.retraction_rate = 2870.0f;
        tp_clawshot_bg.is_target = 0x3C600004;
        tp_ironboots.speed = 1000.0f;
    }
}  // namespace Cheats