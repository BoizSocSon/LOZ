//
// Generated By: dol2asm
// Translation Unit: d_a_tag_wljump
//

#include "rel/d/a/tag/d_a_tag_wljump/d_a_tag_wljump.h"
#include "rel/d/a/d_a_midna/d_a_midna.h"
#include "f_op/f_op_actor_mng.h"
#include "dol2asm.h"
#include "d/d_path.h"
#include "d/d_procname.h"
#include "JSystem/JKernel/JKRHeap.h"

//
// Types:
//

//
// Forward References:
//

extern "C" void create__13daTagWljump_cFv();
extern "C" static void daTagWljump_Create__FP10fopAc_ac_c();
extern "C" void __dt__13daTagWljump_cFv();
extern "C" static void daTagWljump_Delete__FP13daTagWljump_c();
extern "C" void execute__13daTagWljump_cFv();
extern "C" static void daTagWljump_Execute__FP13daTagWljump_c();
extern "C" bool draw__13daTagWljump_cFv();
extern "C" static void daTagWljump_Draw__FP13daTagWljump_c();

//
// External References:
//

extern "C" void __ct__10fopAc_ac_cFv();
extern "C" void __dt__10fopAc_ac_cFv();
extern "C" void isTransformLV__21dSv_player_status_b_cCFi();
extern "C" void isEventBit__11dSv_event_cCFUs();
extern "C" void onSwitch__10dSv_info_cFii();
extern "C" void isSwitch__10dSv_info_cCFii();
extern "C" void reset__14dEvt_control_cFv();
extern "C" void dPath_GetRoomPath__Fii();
extern "C" void request__10dAttHint_cFP10fopAc_ac_ci();
extern "C" void __ct__10dMsgFlow_cFv();
extern "C" void __dt__10dMsgFlow_cFv();
extern "C" void init__10dMsgFlow_cFP10fopAc_ac_ciiPP10fopAc_ac_c();
extern "C" void doFlow__10dMsgFlow_cFP10fopAc_ac_cPP10fopAc_ac_ci();
extern "C" void seStart__7Z2SeMgrF10JAISoundIDPC3VecUlScffffUc();
extern "C" void __dl__FPv();
extern "C" void _savegpr_26();
extern "C" void _restgpr_26();
extern "C" u8 m_midnaActor__9daPy_py_c[4];
extern "C" u8 mAudioMgrPtr__10Z2AudioMgr[4 + 4 /* padding */];

//
// Declarations:
//

/* 80D64EB8-80D64FE4 000078 012C+00 1/1 0/0 0/0 .text            create__13daTagWljump_cFv */
int daTagWljump_c::create() {
    fopAcM_SetupActor(this, daTagWljump_c);
    u32 param = (fopAcM_GetParam(this) >> 8) & 0xff;
    field_0x571 = (u8)param;
    s32 uVar2 = fopAcM_GetParam(this);
    if ((uVar2 & 0xff) == 0xff) {
        return 5;
    }

    field_0x5c4 = dPath_GetRoomPath(uVar2 & 0xff, fopAcM_GetRoomNo(this));
    if (field_0x5c4 == NULL || field_0x5c4->m_num < 2) {
        return 5;
    }

    attention_info.field_0x0[0] = 0x32;
    attention_info.field_0x0[7] = 0x32;
    shape_angle.z = 0;
    field_0x568 = -1;
    field_0x56c[0] = (fopAcM_GetParam(this) >> 16) & 0xf;
    if (field_0x56c[0] != 1) {
        field_0x56c[0] = 0;
    }
    if (field_0x56c[0] == 0 && field_0x571 != 0xff) {
        if (dComIfGs_isSwitch(field_0x571, fopAcM_GetHomeRoomNo(this)) == 0) {
            field_0x573 = 1;
        }
    }
    return 4;
}

/* 80D64FE4-80D65004 0001A4 0020+00 1/0 0/0 0/0 .text            daTagWljump_Create__FP10fopAc_ac_c
 */
static int daTagWljump_Create(fopAc_ac_c* param_0) {
    return ((daTagWljump_c*)param_0)->create();
}

/* 80D65004-80D65068 0001C4 0064+00 1/1 0/0 0/0 .text            __dt__13daTagWljump_cFv */
daTagWljump_c::~daTagWljump_c() {
}

/* 80D65068-80D65090 000228 0028+00 1/0 0/0 0/0 .text daTagWljump_Delete__FP13daTagWljump_c */
static int daTagWljump_Delete(daTagWljump_c* param_0) {
    param_0->~daTagWljump_c();
    return 1;
}

/* ############################################################################################## */

/* 80D65090-80D6587C 000250 07EC+00 1/1 0/0 0/0 .text            execute__13daTagWljump_cFv */
// reg swap
#ifdef NONMATCHING
int daTagWljump_c::execute() {
    attention_info.flags = 0;
    if (field_0x56c[1]) {
        field_0x56c[1]--;
    }

    daPy_py_c* linkPlayer = daPy_getLinkPlayerActorClass();
    daMidna_c* midnaActor = daPy_py_c::getMidnaActor();
    
    if (midnaActor == NULL) {
        return 1;
    }

    if (eventInfo.checkCommandTalk()) {
        s32 bVar2 = 1;
        if (!midnaActor->checkShadowModeTalkWait()) {
            if (shape_angle.x != 0 &&
                (field_0x571 == 0xff ||
                !fopAcM_isSwitch(this, field_0x571)))
            {
                if (field_0x56c[3] == 0) {
                    mMsgFlow.init(this, shape_angle.x & 0xffff, 0, NULL);
                    field_0x56c[3] = 1;
                    mDoAud_seStart(0x10, 0, 0, 0);
                } else {
                    ;
                    if (mMsgFlow.doFlow(this, NULL, 0)) {
                        mDoAud_seStart(0x11, 0, 0, 0);
                        shape_angle.x = 0;
                    }
                }
            } else {
                field_0x568 = field_0x570;
                if (midnaActor->current.pos.abs(eyePos) < 5.0f) {
                    bVar2 = 0;
                }
            } 
        }
        if (bVar2) {
            return 1;
        }
        field_0x56c[3] = 0;
        dComIfGp_event_reset();
        field_0x56c[0] = 0;
        field_0x572 = 1;
        if (field_0x571 != 0xff) {
            fopAcM_onSwitch(this, field_0x571);
        }
    } else if (!dComIfGp_getEvent().isOrderOK()) {
        field_0x572 = 0;
    } else {
        if (!midnaActor->checkWolfNoPos()) {
            field_0x574++;
            if (field_0x574 >= 5) {
                field_0x572 = 0;
            }
        } else {
            field_0x574 = 0;
        }
    }

    if (!linkPlayer->i_checkNowWolf() ||
            !daPy_py_c::i_checkFirstMidnaDemo() ||
        midnaActor->i_checkMidnaTired()) {
        return 1;
    } 
    if (field_0x571 != 0xff && fopAcM_isSwitch(this, field_0x571)) {
        field_0x56c[0] = 0;
        if (field_0x573) {
            field_0x573 = 0;
            field_0x572 = 1;
            field_0x574 = 0;
        }
    }
    if (field_0x56c[0] != 0 || field_0x572 != 0 || field_0x571 == 0xff ||
        fopAcM_isSwitch(this, field_0x571))
    {
        s32 uVar6;
        dStage_dPnt_c* pbVar7 = field_0x5c4->m_points;
        if (linkPlayer->checkWolfTagLockJumpLand() == 0) {
            if (linkPlayer->checkWolfTagLockJump() == 0) {
                for (uVar6 = 0; uVar6 < field_0x5c4->m_num; uVar6++, pbVar7++) {
                    if (linkPlayer->current.pos.abs2(pbVar7->m_position) < pbVar7->field_0x0 * pbVar7->field_0x0 * 10.0f * 10.0f) {
                        field_0x56a = uVar6;
                        if (uVar6 == 0) {
                            field_0x568 = 1;
                        } else if (uVar6 == field_0x5c4->m_num - 1) {
                            field_0x568 = uVar6 - 1;
                        } else {
                            field_0x568 = uVar6 + 1;
                        }
                        break;
                    }
                }
                if (uVar6 == field_0x5c4->m_num) {
                    field_0x568 = -1;
                }
            } else if (field_0x56b) {
                field_0x56b = 0;
                if (field_0x56a < field_0x568) {
                    field_0x568++;
                    if (field_0x5c4->m_num == field_0x568) {
                        field_0x568 = 0xff;
                    }
                } else {
                    field_0x568--;
                }
            }
        }
        if (field_0x568 >= 0) {
            dStage_dPnt_c* pPoint = &field_0x5c4->m_points[field_0x568];
            eyePos.set(pPoint->m_position.x, pPoint->m_position.y, pPoint->m_position.z);
            attention_info.position = eyePos;
            attention_info.position.y += 220.0f;
            field_0x5c8 = pPoint->field_0x3 * 10.0f;
            if (pPoint->field_0x1 == 1) {
                shape_angle.z = 1;
            } else {
                shape_angle.z = 0;
            }
            if (field_0x572 == 0) {
                if (!g_dComIfG_gameInfo.play.getEvent().runCheck()) {
                    eventInfo.i_onCondition(dEvtCnd_CANTALK_e);
                    if (!linkPlayer->checkPlayerFly() &&
                        linkPlayer->eventInfo.chkCondition(dEvtCnd_CANTALK_e)) {
                        dComIfGp_att_ZHintRequest(this, 0x1ff);
                        if (field_0x56c[2] == 0)  {
                            field_0x56c[2] = 1;
                            if (field_0x56c[1] == 0) {
                                mDoAud_seStart(0xe, 0, 0, 0);
                            }
                            field_0x56c[1] = 0x3c;
                        }
                    }
                }
                field_0x570 = field_0x568;
                field_0x568 = -1;
            } else {
                attention_info.flags |= 0x81;
            }
        } else {
            field_0x572 = 0;
        }
    } else {
        field_0x572 = 0;
        field_0x568 = -1;
    }
    current.pos = attention_info.position;
    if (!eventInfo.chkCondition(dEvtCnd_CANTALK_e)) {
        field_0x56c[2] = 0;
    }
    
    return 1;
}
#else
/* 80D658CC-80D658D0 000000 0004+00 1/1 0/0 0/0 .rodata          @4044 */
SECTION_RODATA static f32 const lit_4044 = 1.0f;
COMPILER_STRIP_GATE(0x80D658CC, &lit_4044);

/* 80D658D0-80D658D4 000004 0004+00 0/1 0/0 0/0 .rodata          @4045 */
#pragma push
#pragma force_active on
SECTION_RODATA static f32 const lit_4045 = -1.0f;
COMPILER_STRIP_GATE(0x80D658D0, &lit_4045);
#pragma pop

/* 80D658D4-80D658DC 000008 0004+04 0/1 0/0 0/0 .rodata          @4046 */
#pragma push
#pragma force_active on
SECTION_RODATA static u8 const lit_4046[4 + 4 /* padding */] = {
    0x00,
    0x00,
    0x00,
    0x00,
    /* padding */
    0x00,
    0x00,
    0x00,
    0x00,
};
COMPILER_STRIP_GATE(0x80D658D4, &lit_4046);
#pragma pop

/* 80D658DC-80D658E4 000010 0008+00 0/1 0/0 0/0 .rodata          @4047 */
#pragma push
#pragma force_active on
SECTION_RODATA static u8 const lit_4047[8] = {
    0x3F, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};
COMPILER_STRIP_GATE(0x80D658DC, &lit_4047);
#pragma pop

/* 80D658E4-80D658EC 000018 0008+00 0/1 0/0 0/0 .rodata          @4048 */
#pragma push
#pragma force_active on
SECTION_RODATA static u8 const lit_4048[8] = {
    0x40, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};
COMPILER_STRIP_GATE(0x80D658E4, &lit_4048);
#pragma pop

/* 80D658EC-80D658F4 000020 0008+00 0/1 0/0 0/0 .rodata          @4049 */
#pragma push
#pragma force_active on
SECTION_RODATA static u8 const lit_4049[8] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};
COMPILER_STRIP_GATE(0x80D658EC, &lit_4049);
#pragma pop

/* 80D658F4-80D658F8 000028 0004+00 0/1 0/0 0/0 .rodata          @4050 */
#pragma push
#pragma force_active on
SECTION_RODATA static f32 const lit_4050 = 5.0f;
COMPILER_STRIP_GATE(0x80D658F4, &lit_4050);
#pragma pop

/* 80D658F8-80D658FC 00002C 0004+00 0/1 0/0 0/0 .rodata          @4051 */
#pragma push
#pragma force_active on
SECTION_RODATA static f32 const lit_4051 = 10.0f;
COMPILER_STRIP_GATE(0x80D658F8, &lit_4051);
#pragma pop

/* 80D658FC-80D65904 000030 0004+04 0/1 0/0 0/0 .rodata          @4052 */
#pragma push
#pragma force_active on
SECTION_RODATA static f32 const lit_4052[1 + 1 /* padding */] = {
    220.0f,
    /* padding */
    0.0f,
};
COMPILER_STRIP_GATE(0x80D658FC, &lit_4052);
#pragma pop

/* 80D65904-80D6590C 000038 0008+00 0/1 0/0 0/0 .rodata          @4054 */
#pragma push
#pragma force_active on
SECTION_RODATA static u8 const lit_4054[8] = {
    0x43, 0x30, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00,
};
COMPILER_STRIP_GATE(0x80D65904, &lit_4054);
#pragma pop

/* 80D6590C-80D65914 000040 0008+00 0/1 0/0 0/0 .rodata          @4055 */
#pragma push
#pragma force_active on
SECTION_RODATA static u8 const lit_4055[8] = {
    0x43, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};
COMPILER_STRIP_GATE(0x80D6590C, &lit_4055);
#pragma pop

#pragma push
#pragma optimization_level 0
#pragma optimizewithasm off
asm int daTagWljump_c::execute() {
    nofralloc
#include "asm/rel/d/a/tag/d_a_tag_wljump/d_a_tag_wljump/execute__13daTagWljump_cFv.s"
}
#pragma pop
#endif

/* 80D6587C-80D6589C 000A3C 0020+00 1/0 0/0 0/0 .text daTagWljump_Execute__FP13daTagWljump_c */
static int daTagWljump_Execute(daTagWljump_c* param_0) {
    return param_0->execute();
}

/* 80D6589C-80D658A4 000A5C 0008+00 1/1 0/0 0/0 .text            draw__13daTagWljump_cFv */
int daTagWljump_c::draw() {
    return 1;
}

/* 80D658A4-80D658C4 000A64 0020+00 1/0 0/0 0/0 .text            daTagWljump_Draw__FP13daTagWljump_c
 */
static int daTagWljump_Draw(daTagWljump_c* param_0) {
    return param_0->draw();
}

/* ############################################################################################## */
/* 80D65914-80D65934 -00001 0020+00 1/0 0/0 0/0 .data            l_daTagWljump_Method */
static actor_method_class l_daTagWljump_Method = {
    (process_method_func)daTagWljump_Create,
    (process_method_func)daTagWljump_Delete,
    (process_method_func)daTagWljump_Execute,
    NULL,
    (process_method_func)daTagWljump_Draw,
};

/* 80D65934-80D65964 -00001 0030+00 0/0 0/0 1/0 .data            g_profile_Tag_Wljump */
extern actor_process_profile_definition g_profile_Tag_Wljump = {
    fpcLy_CURRENT_e,
    7,
    fpcPi_CURRENT_e,
    PROC_Tag_Wljump,
    &g_fpcLf_Method.mBase,
    sizeof(daTagWljump_c),
    0,
    0,
    &g_fopAc_Method.base,
    260,
    &l_daTagWljump_Method,
    0x44000,
    fopAc_ENV_e,
    fopAc_CULLBOX_CUSTOM_e,
};