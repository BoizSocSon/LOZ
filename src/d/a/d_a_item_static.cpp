//
// Generated By: dol2asm
// Translation Unit: d/a/d_a_item_static
//

#include "d/a/d_a_item_static.h"
#include "dolphin/types.h"

//
// Forward References:
//

extern "C" void startCtrl__8daItem_cFv();
extern "C" void startControl__8daItem_cFv();
extern "C" void endControl__8daItem_cFv();

u32 daItem_c::startCtrl() {
    setFlag(4);
    return 1;
}

u32 daItem_c::startControl() {
    mStatus = 1;
    return 1;
}

u32 daItem_c::endControl() {
    mStatus = 0;
    return 1;
}