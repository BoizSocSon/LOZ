//
// Generated By: dol2asm
// Translation Unit: d_a_tag_attack_item
//

#include "rel/d/a/tag/d_a_tag_attack_item/d_a_tag_attack_item.h"
#include "SSystem/SComponent/c_math.h"
#include "d/a/d_a_player.h"
#include "d/cc/d_cc_d.h"
#include "d/com/d_com_inf_game.h"
#include "d/event/d_event_lib.h"
#include "dol2asm.h"

//
// Types:
//

// need to figure out how to use dEvLib_callback_c properly
class daTagAtkItem_c : public fopAc_ac_c /* , public dEvLib_callback_c */ {
public:
    /* 805A2958 */ void setBaseMtx();
    /* 805A2990 */ int Create();
    /* 805A2A34 */ int create();
    /* 805A2C48 */ int execute();
    /* 805A2CA8 */ void action();
    /* 805A2D58 */ BOOL checkHit();
    /* 805A2F54 */ void createItem();
    /* 805A3038 */ int _delete();

    /* 805A3118 */ ~daTagAtkItem_c();
    /* 805A2D10 */ BOOL eventStart();
    /* 805A2D34 */ BOOL eventEnd();

    u8 getEvId() { return fopAcM_GetParamBit(this, 0x18, 8); }
    u8 getNum() { return fopAcM_GetParamBit(this, 8, 8); }
    u8 getItemBit() { return fopAcM_GetParamBit(this, 0x10, 8); }
    u8 getItemNo() { return fopAcM_GetParamBit(this, 0, 8); }

    /* 0x568 */ u8 temp[0x57C - 0x568];  // remove when dEvLib_callback_c setup
    /* 0x57C */ u8 field_0x57C[0x584 - 0x57C];
    /* 0x584 */ dCcD_Stts mCcStts;
    /* 0x5C0 */ dCcD_Cyl mCyl;
};

//
// Forward References:
//

extern "C" void setBaseMtx__14daTagAtkItem_cFv();
extern "C" void Create__14daTagAtkItem_cFv();
extern "C" void create__14daTagAtkItem_cFv();
extern "C" void __dt__8cM3dGCylFv();
extern "C" void __dt__8cM3dGAabFv();
extern "C" void __dt__10dCcD_GSttsFv();
extern "C" void execute__14daTagAtkItem_cFv();
extern "C" void action__14daTagAtkItem_cFv();
extern "C" void eventStart__14daTagAtkItem_cFv();
extern "C" void eventEnd__14daTagAtkItem_cFv();
extern "C" void checkHit__14daTagAtkItem_cFv();
extern "C" void createItem__14daTagAtkItem_cFv();
extern "C" bool _delete__14daTagAtkItem_cFv();
extern "C" static void daTagAtkItem_Execute__FP14daTagAtkItem_c();
extern "C" static void daTagAtkItem_Delete__FP14daTagAtkItem_c();
extern "C" static void daTagAtkItem_Create__FP14daTagAtkItem_c();
extern "C" void __dt__17dEvLib_callback_cFv();
extern "C" bool eventRun__17dEvLib_callback_cFv();
extern "C" bool eventStart__17dEvLib_callback_cFv();
extern "C" bool eventEnd__17dEvLib_callback_cFv();
extern "C" static void func_805A3100();
extern "C" static void func_805A3108();
extern "C" static void func_805A3110();
extern "C" void __dt__14daTagAtkItem_cFv();
extern "C" void __dt__10cCcD_GSttsFv();

//
// External References:
//

extern "C" void transS__14mDoMtx_stack_cFRC4cXyz();
extern "C" void ZXYrotM__14mDoMtx_stack_cFRC5csXyz();
extern "C" void __ct__10fopAc_ac_cFv();
extern "C" void __dt__10fopAc_ac_cFv();
extern "C" void fopAcM_delete__FP10fopAc_ac_c();
extern "C" void fopAcM_createItemFromTable__FPC4cXyziiiPC5csXyziPC4cXyzPfPfb();
extern "C" void eventUpdate__17dEvLib_callback_cFv();
extern "C" void orderEvent__17dEvLib_callback_cFiii();
extern "C" void __ct__10dCcD_GSttsFv();
extern "C" void Init__9dCcD_SttsFiiP10fopAc_ac_c();
extern "C" void __ct__12dCcD_GObjInfFv();
extern "C" void __dt__12dCcD_GObjInfFv();
extern "C" void ChkTgHit__12dCcD_GObjInfFv();
extern "C" void GetTgHitObj__12dCcD_GObjInfFv();
extern "C" void Set__8dCcD_CylFRC11dCcD_SrcCyl();
extern "C" void Set__4cCcSFP8cCcD_Obj();
extern "C" void __ct__5csXyzFsss();
extern "C" void cM_rndFX__Ff();
extern "C" void SetC__8cM3dGCylFRC4cXyz();
extern "C" void SetH__8cM3dGCylFf();
extern "C" void SetR__8cM3dGCylFf();
extern "C" void __dl__FPv();
extern "C" void _savegpr_27();
extern "C" void _savegpr_29();
extern "C" void _restgpr_27();
extern "C" void _restgpr_29();
extern "C" extern void* __vt__8dCcD_Cyl[36];
extern "C" extern void* __vt__9dCcD_Stts[11];
extern "C" extern void* __vt__12cCcD_CylAttr[25];
extern "C" extern void* __vt__14cCcD_ShapeAttr[22];
extern "C" extern void* __vt__9cCcD_Stts[8];

//
// Declarations:
//

/* 805A2958-805A2990 000078 0038+00 1/1 0/0 0/0 .text            setBaseMtx__14daTagAtkItem_cFv */
void daTagAtkItem_c::setBaseMtx() {
    mDoMtx_stack_c::transS(current.pos);
    mDoMtx_stack_c::ZXYrotM(shape_angle);
}

/* 805A32F4-805A3338 000000 0044+00 1/1 0/0 0/0 .data            l_cyl_src */
static dCcD_SrcCyl l_cyl_src = {
    {
        {0x0, {{0x0, 0x0, 0x1f}, {0x400020, 0x11}, 0x78}},  // mObj
        {dCcD_SE_NONE, 0x0, 0x0, 0x0, 0x0},                 // mGObjAt
        {dCcD_SE_NONE, 0x0, 0x0, 0x0, 0x6},                 // mGObjTg
        {0x0},                                              // mGObjCo
    },                                                      // mObjInf
    {
        {0.0f, 0.0f, 0.0f},  // mCenter
        50.0f,               // mRadius
        100.0f               // mHeight
    }                        // mCyl
};

/* 805A2990-805A2A34 0000B0 00A4+00 1/1 0/0 0/0 .text            Create__14daTagAtkItem_cFv */
int daTagAtkItem_c::Create() {
    mCcStts.Init(0, 0xFF, this);
    mCyl.Set(l_cyl_src);
    mCyl.SetStts(&mCcStts);
    mCyl.SetR(scale.x * 50.0f);
    mCyl.SetH(scale.y * 100.0f);

    current.pos.y = home.pos.y - scale.y * 100.0f;
    return 1;
}

/* ############################################################################################## */
/* 805A3338-805A3358 -00001 0020+00 1/0 0/0 0/0 .data            l_daTagAtkItem_Method */
SECTION_DATA static void* l_daTagAtkItem_Method[8] = {
    (void*)daTagAtkItem_Create__FP14daTagAtkItem_c,
    (void*)daTagAtkItem_Delete__FP14daTagAtkItem_c,
    (void*)daTagAtkItem_Execute__FP14daTagAtkItem_c,
    (void*)NULL,
    (void*)NULL,
    (void*)NULL,
    (void*)NULL,
    (void*)NULL,
};

/* 805A3358-805A3388 -00001 0030+00 0/0 0/0 1/0 .data            g_profile_Tag_AttackItem */
SECTION_DATA extern void* g_profile_Tag_AttackItem[12] = {
    (void*)0xFFFFFFFD, (void*)0x0007FFFD,
    (void*)0x01AA0000, (void*)&g_fpcLf_Method,
    (void*)0x000006FC, (void*)NULL,
    (void*)NULL,       (void*)&g_fopAc_Method,
    (void*)0x02490000, (void*)&l_daTagAtkItem_Method,
    (void*)0x00040000, (void*)0x000E0000,
};

/* 805A3388-805A33B4 000094 002C+00 2/2 0/0 0/0 .data            __vt__14daTagAtkItem_c */
SECTION_DATA extern void* __vt__14daTagAtkItem_c[11] = {
    (void*)NULL /* RTTI */,
    (void*)NULL,
    (void*)NULL,
    (void*)NULL,
    (void*)func_805A3110,
    (void*)func_805A3108,
    (void*)eventRun__17dEvLib_callback_cFv,
    (void*)func_805A3100,
    (void*)__dt__14daTagAtkItem_cFv,
    (void*)eventStart__14daTagAtkItem_cFv,
    (void*)eventEnd__14daTagAtkItem_cFv,
};

/* 805A33B4-805A33C0 0000C0 000C+00 3/3 0/0 0/0 .data            __vt__10cCcD_GStts */
SECTION_DATA extern void* __vt__10cCcD_GStts[3] = {
    (void*)NULL /* RTTI */,
    (void*)NULL,
    (void*)__dt__10cCcD_GSttsFv,
};

/* 805A33C0-805A33CC 0000CC 000C+00 2/2 0/0 0/0 .data            __vt__10dCcD_GStts */
SECTION_DATA extern void* __vt__10dCcD_GStts[3] = {
    (void*)NULL /* RTTI */,
    (void*)NULL,
    (void*)__dt__10dCcD_GSttsFv,
};

/* 805A33CC-805A33D8 0000D8 000C+00 3/3 0/0 0/0 .data            __vt__8cM3dGCyl */
SECTION_DATA extern void* __vt__8cM3dGCyl[3] = {
    (void*)NULL /* RTTI */,
    (void*)NULL,
    (void*)__dt__8cM3dGCylFv,
};

/* 805A33D8-805A33E4 0000E4 000C+00 3/3 0/0 0/0 .data            __vt__8cM3dGAab */
SECTION_DATA extern void* __vt__8cM3dGAab[3] = {
    (void*)NULL /* RTTI */,
    (void*)NULL,
    (void*)__dt__8cM3dGAabFv,
};

/* 805A33E4-805A33FC 0000F0 0018+00 3/3 0/0 0/0 .data            __vt__17dEvLib_callback_c */
SECTION_DATA extern void* __vt__17dEvLib_callback_c[6] = {
    (void*)NULL /* RTTI */,
    (void*)NULL,
    (void*)__dt__17dEvLib_callback_cFv,
    (void*)eventStart__17dEvLib_callback_cFv,
    (void*)eventRun__17dEvLib_callback_cFv,
    (void*)eventEnd__17dEvLib_callback_cFv,
};

/* 805A2A34-805A2B5C 000154 0128+00 1/1 0/0 0/0 .text            create__14daTagAtkItem_cFv */
#pragma push
#pragma optimization_level 0
#pragma optimizewithasm off
asm int daTagAtkItem_c::create() {
    nofralloc
#include "asm/rel/d/a/tag/d_a_tag_attack_item/d_a_tag_attack_item/func_805A2A34.s"
}
#pragma pop

/* 805A2B5C-805A2BA4 00027C 0048+00 1/0 0/0 0/0 .text            __dt__8cM3dGCylFv */
#pragma push
#pragma optimization_level 0
#pragma optimizewithasm off
// asm cM3dGCyl::~cM3dGCyl() {
extern "C" asm void __dt__8cM3dGCylFv() {
    nofralloc
#include "asm/rel/d/a/tag/d_a_tag_attack_item/d_a_tag_attack_item/__dt__8cM3dGCylFv.s"
}
#pragma pop

/* 805A2BA4-805A2BEC 0002C4 0048+00 1/0 0/0 0/0 .text            __dt__8cM3dGAabFv */
#pragma push
#pragma optimization_level 0
#pragma optimizewithasm off
// asm cM3dGAab::~cM3dGAab() {
extern "C" asm void __dt__8cM3dGAabFv() {
    nofralloc
#include "asm/rel/d/a/tag/d_a_tag_attack_item/d_a_tag_attack_item/__dt__8cM3dGAabFv.s"
}
#pragma pop

/* 805A2BEC-805A2C48 00030C 005C+00 1/0 0/0 0/0 .text            __dt__10dCcD_GSttsFv */
#pragma push
#pragma optimization_level 0
#pragma optimizewithasm off
// asm dCcD_GStts::~dCcD_GStts() {
extern "C" asm void __dt__10dCcD_GSttsFv() {
    nofralloc
#include "asm/rel/d/a/tag/d_a_tag_attack_item/d_a_tag_attack_item/__dt__10dCcD_GSttsFv.s"
}
#pragma pop

/* 805A2C48-805A2CA8 000368 0060+00 1/1 0/0 0/0 .text            execute__14daTagAtkItem_cFv */
// matches with dEvLib_callback_c setup
#ifdef NONMATCHING
int daTagAtkItem_c::execute() {
    action();
    setBaseMtx();
    eventUpdate();
    mCyl.SetC(current.pos);
    dComIfG_Ccsp()->Set(&mCyl);
    return 1;
}
#else
#pragma push
#pragma optimization_level 0
#pragma optimizewithasm off
asm int daTagAtkItem_c::execute() {
    nofralloc
#include "asm/rel/d/a/tag/d_a_tag_attack_item/d_a_tag_attack_item/execute__14daTagAtkItem_cFv.s"
}
#pragma pop
#endif

/* 805A2CA8-805A2D10 0003C8 0068+00 1/1 0/0 0/0 .text            action__14daTagAtkItem_cFv */
// matches with dEvLib_callback_c setup
#ifdef NONMATCHING
void daTagAtkItem_c::action() {
    if (checkHit()) {
        if (getEvId() != 0xFF) {
            orderEvent(getEvId(), 0xFF, 1);
        } else {
            createItem();
            fopAcM_delete(this);
        }
    }
}
#else
#pragma push
#pragma optimization_level 0
#pragma optimizewithasm off
asm void daTagAtkItem_c::action() {
    nofralloc
#include "asm/rel/d/a/tag/d_a_tag_attack_item/d_a_tag_attack_item/action__14daTagAtkItem_cFv.s"
}
#pragma pop
#endif

/* 805A2D10-805A2D34 000430 0024+00 2/1 0/0 0/0 .text            eventStart__14daTagAtkItem_cFv */
BOOL daTagAtkItem_c::eventStart() {
    createItem();
    return TRUE;
}

/* 805A2D34-805A2D58 000454 0024+00 2/1 0/0 0/0 .text            eventEnd__14daTagAtkItem_cFv */
BOOL daTagAtkItem_c::eventEnd() {
    fopAcM_delete(this);
    return TRUE;
}

/* 805A2D58-805A2F54 000478 01FC+00 1/1 0/0 0/0 .text            checkHit__14daTagAtkItem_cFv */
BOOL daTagAtkItem_c::checkHit() {
    if (mCyl.ChkTgHit()) {
        cCcD_Obj* hitobj_p = mCyl.GetTgHitObj();
        if (hitobj_p != NULL &&
            (hitobj_p->ChkAtType(AT_TYPE_IRON_BALL) || hitobj_p->ChkAtType(AT_TYPE_BOMB)))
        {
#ifdef DEBUG
            // "Attack Reaction Item: Rotate attack hit!\n"
            OSReport("攻撃反応アイテム：回転アタックヒット！\n");
#endif
            return true;
        }
    }

    daPy_py_c* player_p = daPy_getPlayerActorClass();

    if ((player_p->checkFrontRollCrash() || player_p->checkWolfAttackReverse()) &&
        player_p->current.pos.absXZ(current.pos) < scale.x * 50.0f &&
        fabsf(player_p->current.pos.y - current.pos.y) < scale.y * 100.0f)
    {
#ifdef DEBUG
        // "Attack Reaction Item: Rotate attack hit!\n"
        OSReport("攻撃反応アイテム：回転アタックヒット！\n");
#endif
        return true;
    }

    return false;
}

/* 805A2F54-805A3038 000674 00E4+00 2/2 0/0 0/0 .text            createItem__14daTagAtkItem_cFv */
void daTagAtkItem_c::createItem() {
    csXyz angle(0, 0, 0);

    int create_num;
    if (getNum() == 0xFF) {
        create_num = 1;
    } else {
        create_num = getNum();
    }

    int item_bit = getItemBit();
    for (int i = 0; i < create_num; i++) {
        angle.y += (s16)cM_rndFX(0x7FFF);

        fopAcM_createItemFromTable(&home.pos, getItemNo(), item_bit, fopAcM_GetHomeRoomNo(this),
                                   &angle, 0, NULL, NULL, NULL, false);

        if (item_bit != 0xFF) {
            item_bit++;
        }
    }
}

/* 805A3038-805A3040 000758 0008+00 1/1 0/0 0/0 .text            _delete__14daTagAtkItem_cFv */
int daTagAtkItem_c::_delete() {
    return 1;
}

/* 805A3040-805A3060 000760 0020+00 1/0 0/0 0/0 .text daTagAtkItem_Execute__FP14daTagAtkItem_c */
static int daTagAtkItem_Execute(daTagAtkItem_c* i_this) {
    return i_this->execute();
}

/* 805A3060-805A3080 000780 0020+00 1/0 0/0 0/0 .text daTagAtkItem_Delete__FP14daTagAtkItem_c */
static int daTagAtkItem_Delete(daTagAtkItem_c* i_this) {
    return i_this->_delete();
}

/* 805A3080-805A30A0 0007A0 0020+00 1/0 0/0 0/0 .text daTagAtkItem_Create__FP14daTagAtkItem_c */
static int daTagAtkItem_Create(daTagAtkItem_c* i_this) {
    return i_this->create();
}

/* 805A30A0-805A30E8 0007C0 0048+00 1/0 0/0 0/0 .text            __dt__17dEvLib_callback_cFv */
#pragma push
#pragma optimization_level 0
#pragma optimizewithasm off
// asm dEvLib_callback_c::~dEvLib_callback_c() {
extern "C" asm void __dt__17dEvLib_callback_cFv() {
    nofralloc
#include "asm/rel/d/a/tag/d_a_tag_attack_item/d_a_tag_attack_item/__dt__17dEvLib_callback_cFv.s"
}
#pragma pop

/* 805A30E8-805A30F0 000808 0008+00 2/0 0/0 0/0 .text            eventRun__17dEvLib_callback_cFv */
// bool dEvLib_callback_c::eventRun() {
extern "C" bool eventRun__17dEvLib_callback_cFv() {
    return true;
}

/* 805A30F0-805A30F8 000810 0008+00 1/0 0/0 0/0 .text            eventStart__17dEvLib_callback_cFv
 */
// bool dEvLib_callback_c::eventStart() {
extern "C" bool eventStart__17dEvLib_callback_cFv() {
    return true;
}

/* 805A30F8-805A3100 000818 0008+00 1/0 0/0 0/0 .text            eventEnd__17dEvLib_callback_cFv */
// bool dEvLib_callback_c::eventEnd() {
extern "C" bool eventEnd__17dEvLib_callback_cFv() {
    return true;
}

/* 805A3100-805A3108 000820 0008+00 1/0 0/0 0/0 .text            @1384@eventEnd__14daTagAtkItem_cFv
 */
#pragma push
#pragma optimization_level 0
#pragma optimizewithasm off
static asm void func_805A3100() {
    nofralloc
#include "asm/rel/d/a/tag/d_a_tag_attack_item/d_a_tag_attack_item/func_805A3100.s"
}
#pragma pop

/* 805A3108-805A3110 000828 0008+00 1/0 0/0 0/0 .text @1384@eventStart__14daTagAtkItem_cFv */
#pragma push
#pragma optimization_level 0
#pragma optimizewithasm off
static asm void func_805A3108() {
    nofralloc
#include "asm/rel/d/a/tag/d_a_tag_attack_item/d_a_tag_attack_item/func_805A3108.s"
}
#pragma pop

/* 805A3110-805A3118 000830 0008+00 1/0 0/0 0/0 .text            @1384@__dt__14daTagAtkItem_cFv */
#pragma push
#pragma optimization_level 0
#pragma optimizewithasm off
static asm void func_805A3110() {
    nofralloc
#include "asm/rel/d/a/tag/d_a_tag_attack_item/d_a_tag_attack_item/func_805A3110.s"
}
#pragma pop

/* 805A3118-805A3278 000838 0160+00 2/1 0/0 0/0 .text            __dt__14daTagAtkItem_cFv */
#pragma push
#pragma optimization_level 0
#pragma optimizewithasm off
asm daTagAtkItem_c::~daTagAtkItem_c() {
    nofralloc
#include "asm/rel/d/a/tag/d_a_tag_attack_item/d_a_tag_attack_item/__dt__14daTagAtkItem_cFv.s"
}
#pragma pop

/* 805A3278-805A32C0 000998 0048+00 1/0 0/0 0/0 .text            __dt__10cCcD_GSttsFv */
#pragma push
#pragma optimization_level 0
#pragma optimizewithasm off
// asm cCcD_GStts::~cCcD_GStts() {
extern "C" asm void __dt__10cCcD_GSttsFv() {
    nofralloc
#include "asm/rel/d/a/tag/d_a_tag_attack_item/d_a_tag_attack_item/__dt__10cCcD_GSttsFv.s"
}
#pragma pop