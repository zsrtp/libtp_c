#include <stdbool.h>
#include "controller.h"
#include "tp.h"
#include "system.h"

static bool visible = false;

void render() {
    if (is_pressed(B)){
        visible = false;
        tp_osReport("Goodbye!");
        return;
    }
    tp_osReport("Hello!");
}

void game_loop()
{
    tp_gameInfo.link.heart_quarters = 12;
    bool rt_down = is_down(R);
    bool lt_down = is_down(L);
    bool d_down = is_down(DPAD_DOWN);

    if(visible) {
        render();
    } else if (rt_down && d_down && lt_down && !visible) {
        visible = true;
    } else {
        //something
    }
}