//
// Generated By: dol2asm
// Translation Unit: JASDSPInterface
//

#include "JSystem/JAudio2/JASDSPInterface.h"
#include "JSystem/JAudio2/JASCalc.h"
#include "JSystem/JAudio2/JASHeapCtrl.h"
#include "JSystem/JAudio2/JASWaveInfo.h"
#include "JSystem/JAudio2/dsptask.h"
#include "JSystem/JAudio2/osdsp_task.h"
#include "JSystem/JAudio2/JASCriticalSection.h"
#include "JSystem/JKernel/JKRSolidHeap.h"
#include "dolphin/dsp.h"
#include "dolphin/os/OSCache.h"

//
// Forward References:
//

//
// External References:
//

//
// Declarations:
//

/* ############################################################################################## */
/* 804512E8-804512EC 0007E8 0004+00 5/5 0/0 0/0 .sbss            CH_BUF__6JASDsp */
JASDsp::TChannel* JASDsp::CH_BUF;

/* 804512EC-804512F0 0007EC 0004+00 3/3 0/0 0/0 .sbss            FX_BUF__6JASDsp */
JASDsp::FxBuf* JASDsp::FX_BUF;

/* 804512F0-804512F4 0007F0 0004+00 2/2 0/0 0/0 .sbss            sDSPVolume__6JASDsp */
f32 JASDsp::sDSPVolume;

/* 8029D958-8029D9A4 298298 004C+00 0/0 1/1 0/0 .text            boot__6JASDspFPFPv_v */
void JASDsp::boot(void (*param_0)(void*)) {
    static bool data_804512F4 = true;
    if (data_804512F4) {
        DspBoot(param_0);
        data_804512F4 = false;
    }
}

/* 8029D9A4-8029D9C4 2982E4 0020+00 0/0 1/1 0/0 .text            releaseHalt__6JASDspFUl */
void JASDsp::releaseHalt(u32 param_0) {
    DSPReleaseHalt2(param_0);
}

/* 8029D9C4-8029D9E4 298304 0020+00 0/0 1/1 0/0 .text            finishWork__6JASDspFUs */
void JASDsp::finishWork(u16 param_0) {
    DspFinishWork(param_0);
}

/* 8029D9E4-8029DA04 298324 0020+00 0/0 1/1 0/0 .text            syncFrame__6JASDspFUlUlUl */
void JASDsp::syncFrame(u32 param_0, u32 param_1, u32 param_2) {
    DsyncFrame2(param_0, param_1, param_2);
}

/* 8029DA04-8029DA30 298344 002C+00 0/0 1/1 0/0 .text            setDSPMixerLevel__6JASDspFf */
void JASDsp::setDSPMixerLevel(f32 dsp_level) {
    sDSPVolume = dsp_level;
    dsp_level *= 4.0f;
    DsetMixerLevel(dsp_level);
}

/* 8029DA30-8029DA38 298370 0008+00 0/0 1/1 0/0 .text            getDSPMixerLevel__6JASDspFv */
f32 JASDsp::getDSPMixerLevel() {
    return sDSPVolume;
}

/* 8029DA38-8029DA48 298378 0010+00 0/0 1/1 0/0 .text            getDSPHandle__6JASDspFi */
JASDsp::TChannel* JASDsp::getDSPHandle(int param_0) {
    return CH_BUF + param_0;
}

/* 8029DA48-8029DA6C 298388 0024+00 3/3 0/0 0/0 .text            setFilterTable__6JASDspFPsPsUl */
void JASDsp::setFilterTable(s16* param_0, s16* param_1, u32 param_2) {
    for (int i = 0; i < param_2; i++) {
        *param_0++ = *param_1++;
    }
}

/* 8029DA6C-8029DAA0 2983AC 0034+00 1/1 0/0 0/0 .text            flushBuffer__6JASDspFv */
void JASDsp::flushBuffer() {
    DCFlushRange(CH_BUF, sizeof(TChannel) * 64);
    DCFlushRange(FX_BUF, sizeof(FxBuf) * 4);
}

/* 8029DAA0-8029DAC8 2983E0 0028+00 0/0 1/1 0/0 .text            invalChannelAll__6JASDspFv */
void JASDsp::invalChannelAll() {
    DCInvalidateRange(CH_BUF, sizeof(TChannel) * 64);
}

/* ############################################################################################## */
/* 8039B360-8039B3A0 0279C0 0040+00 1/1 0/0 0/0 .rodata          DSPADPCM_FILTER__6JASDsp */
u8 const JASDsp::DSPADPCM_FILTER[64] = {
    0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x04, 0x00, 0x04, 0x00,
    0x10, 0x00, 0xF8, 0x00, 0x0E, 0x00, 0xFA, 0x00, 0x0C, 0x00, 0xFC, 0x00, 0x12, 0x00, 0xF6, 0x00,
    0x10, 0x68, 0xF7, 0x38, 0x12, 0xC0, 0xF7, 0x04, 0x14, 0x00, 0xF4, 0x00, 0x08, 0x00, 0xF8, 0x00,
    0x04, 0x00, 0xFC, 0x00, 0xFC, 0x00, 0x04, 0x00, 0xFC, 0x00, 0x00, 0x00, 0xF8, 0x00, 0x00, 0x00,
};

/* 8039B3A0-8039B8A0 -00001 0500+00 1/1 0/0 0/0 .rodata          DSPRES_FILTER__6JASDsp */
u32 const JASDsp::DSPRES_FILTER[320] = {
    0x0C3966AD,
    0x0D46FFDF,
    0x0B396696,
    0x0E5FFFD8,
    0x0A446669,
    0x0F83FFD0,
    0x095A6626,
    0x10B4FFC8,
    0x087D65CD,
    0x11F0FFBF,
    0x07AB655E,
    0x1338FFB6,
    0x06E464D9,
    0x148CFFAC,
    0x0628643F,
    0x15EBFFA1,
    0x0577638F,
    0x1756FF96,
    0x04D162CB,
    0x18CBFF8A,
    0x043561F3,
    0x1A4CFF7E,
    0x03A46106,
    0x1BD7FF71,
    0x031C6007,
    0x1D6CFF64,
    0x029F5EF5,
    0x1F0BFF56,
    0x022A5DD0,
    0x20B3FF48,
    0x01BE5C9A,
    0x2264FF3A,
    0x015B5B53,
    0x241EFF2C,
    0x010159FC,
    0x25E0FF1E,
    0x00AE5896,
    0x27A9FF10,
    0x00635720,
    0x297AFF02,
    0x001F559D,
    0x2B50FEF4,
    0xFFE2540D,
    0x2D2CFEE8,
    0xFFAC5270,
    0x2F0DFEDB,
    0xFF7C50C7,
    0x30F3FED0,
    0xFF534F14,
    0x32DCFEC6,
    0xFF2E4D57,
    0x34C8FEBD,
    0xFF0F4B91,
    0x36B6FEB6,
    0xFEF549C2,
    0x38A5FEB0,
    0xFEDF47ED,
    0x3A95FEAC,
    0xFECE4611,
    0x3C85FEAB,
    0xFEC04430,
    0x3E74FEAC,
    0xFEB6424A,
    0x4060FEAF,
    0xFEAF4060,
    0x424AFEB6,
    0xFEAC3E74,
    0x4430FEC0,
    0xFEAB3C85,
    0x4611FECE,
    0xFEAC3A95,
    0x47EDFEDF,
    0xFEB038A5,
    0x49C2FEF5,
    0xFEB636B6,
    0x4B91FF0F,
    0xFEBD34C8,
    0x4D57FF2E,
    0xFEC632DC,
    0x4F14FF53,
    0xFED030F3,
    0x50C7FF7C,
    0xFEDB2F0D,
    0x5270FFAC,
    0xFEE82D2C,
    0x540DFFE2,
    0xFEF42B50,
    0x559D001F,
    0xFF02297A,
    0x57200063,
    0xFF1027A9,
    0x589600AE,
    0xFF1E25E0,
    0x59FC0101,
    0xFF2C241E,
    0x5B53015B,
    0xFF3A2264,
    0x5C9A01BE,
    0xFF4820B3,
    0x5DD0022A,
    0xFF561F0B,
    0x5EF5029F,
    0xFF641D6C,
    0x6007031C,
    0xFF711BD7,
    0x610603A4,
    0xFF7E1A4C,
    0x61F30435,
    0xFF8A18CB,
    0x62CB04D1,
    0xFF961756,
    0x638F0577,
    0xFFA115EB,
    0x643F0628,
    0xFFAC148C,
    0x64D906E4,
    0xFFB61338,
    0x655E07AB,
    0xFFBF11F0,
    0x65CD087D,
    0xFFC810B4,
    0x6626095A,
    0xFFD00F83,
    0x66690A44,
    0xFFD80E5F,
    0x66960B39,
    0xFFDF0D46,
    0x66AD0C39,
    0x00000C8B,
    0x18F82527,
    0x30FB3C56,
    0x471C5133,
    0x5A8262F1,
    0x6A6D70E2,
    0x76417A7C,
    0x7D897F61,
    0x7FFF7F61,
    0x7D897A7C,
    0x764170E2,
    0x6A6D62F1,
    0x5A825133,
    0x471C3C56,
    0x30FB2527,
    0x18F80C8B,
    0x0000F375,
    0xE708DAD9,
    0xCF05C3AA,
    0xB8E4AECD,
    0xA57E9D0F,
    0x95938F1E,
    0x89BF8584,
    0x8277809F,
    0x8001809F,
    0x82778584,
    0x89BF8F1E,
    0x95939D0F,
    0xA57EAECD,
    0xB8E4C3AA,
    0xCF05DAD9,
    0xE708F375,
    0x000007FF,
    0x0FFF17FF,
    0x1FFF27FF,
    0x2FFF37FF,
    0x3FFF47FF,
    0x4FFF57FF,
    0x5FFF67FF,
    0x6FFF77FF,
    0x7FFF7800,
    0x70006800,
    0x60005800,
    0x50004800,
    0x40003800,
    0x30002800,
    0x20001800,
    0x10000800,
    0x0000F801,
    0xF001E801,
    0xE001D801,
    0xD001C801,
    0xC001B801,
    0xB001A801,
    0xA0019801,
    0x90018801,
    0x80018800,
    0x90009800,
    0xA000A800,
    0xB000B800,
    0xC000C800,
    0xD000D800,
    0xE000E800,
    0xF000F800,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0x1FFF3FFF,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0x1FFFC001,
    0x00000192,
    0x032404B6,
    0x064707D9,
    0x096A0AFB,
    0x0C8B0E1B,
    0x0FAB1139,
    0x12C71455,
    0x15E1176D,
    0x18F81A82,
    0x1C0B1D93,
    0x1F19209F,
    0x222323A6,
    0x252726A7,
    0x282629A3,
    0x2B1F2C98,
    0x2E102F87,
    0x30FB326E,
    0x33DE354D,
    0x36B93824,
    0x398C3AF2,
    0x3C563DB7,
    0x3F174073,
    0x41CD4325,
    0x447A45CC,
    0x471C4869,
    0x49B34AFB,
    0x4C3F4D81,
    0x4EBF4FFB,
    0x51335268,
    0x539A54C9,
    0x55F5571D,
    0x58425964,
    0x5A825B9C,
    0x5CB35DC7,
    0x5ED75FE3,
    0x60EB61F0,
    0x62F163EE,
    0x64E865DD,
    0x66CF67BC,
    0x68A6698B,
    0x6A6D6B4A,
    0x6C236CF8,
    0x6DC96E96,
    0x6F5E7022,
    0x70E2719D,
    0x72547307,
    0x73B5745F,
    0x750475A5,
    0x764176D8,
    0x776B77FA,
    0x78847909,
    0x79897A05,
    0x7A7C7AEE,
    0x7B5C7BC5,
    0x7C297C88,
    0x7CE37D39,
    0x7D897DD5,
    0x7E1D7E5F,
    0x7E9C7ED5,
    0x7F097F37,
    0x7F617F86,
    0x7FA67FC1,
    0x7FD87FE9,
    0x7FF57FFD,
};

/* 8029DAC8-8029DB78 298408 00B0+00 0/0 1/1 0/0 .text            initBuffer__6JASDspFv */
void JASDsp::initBuffer() {
    CH_BUF = new(JASDram, 0x20) TChannel[64];
    FX_BUF = new(JASDram, 0x20) FxBuf[4];
    JASCalc::bzero(CH_BUF, 0x6000);
    JASCalc::bzero(FX_BUF, sizeof(FxBuf) * 4);
    for (u8 i = 0; i < 4; i++) {
        setFXLine(i, NULL, NULL);
    }
    DsetupTable(0x40, u32(CH_BUF), u32(&DSPRES_FILTER), u32(&DSPADPCM_FILTER), u32(FX_BUF));
    flushBuffer();
}

/* ############################################################################################## */
/* 803C78F0-803C7920 024A10 0018+18 1/1 0/0 0/0 .data            SEND_TABLE__6JASDsp */
u16 JASDsp::SEND_TABLE[12 + 12 /* padding */] = {
    0x0D00,
    0x0D60,
    0x0DC8,
    0x0E28,
    0x0E88,
    0x0EE8,
    0x0CA0,
    0x0F40,
    0x0FA0,
    0x0B00,
    0x09A0,
    0x0000,
    /* padding */
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
};

/* 8029DB78-8029DCA4 2984B8 012C+00 1/1 1/1 0/0 .text
 * setFXLine__6JASDspFUcPsPQ26JASDsp13FxlineConfig_             */
int JASDsp::setFXLine(u8 param_0, s16* param_1, JASDsp::FxlineConfig_* param_2) {
    FxBuf* puVar3 = FX_BUF + param_0;
    JASCriticalSection aJStack_20;
    puVar3->field_0x0 = 0;
    if (param_2 != NULL) {
        puVar3->field_0xa = param_2->field_0x4;
        puVar3->field_0x8 = SEND_TABLE[param_2->field_0x2];
        puVar3->field_0xe = param_2->field_0x8;
        puVar3->field_0xc = SEND_TABLE[param_2->field_0x6];
        puVar3->field_0x2 = param_2->field_0xc;
        setFilterTable(puVar3->field_0x10, param_2->field_0x10, 8);
    }
    if (param_1 != NULL && param_2 != NULL) {
        u32 iVar1 = param_2->field_0xc * 0xa0;
        puVar3->field_0x4 = param_1;
        JASCalc::bzero(param_1, iVar1);
        DCFlushRange(param_1, iVar1);
    } else if (param_2 == NULL || param_1 != NULL) {
        puVar3->field_0x4 = param_1;
    }

    if (puVar3->field_0x4 != NULL) {
        puVar3->field_0x0 = param_2->field_0x0;
    } else {
        puVar3->field_0x0 = 0;
    }
    DCFlushRange(puVar3, sizeof(FxBuf));
    return 1;
}

/* 8029DCA4-8029DCE0 2985E4 003C+00 0/0 1/1 0/0 .text            init__Q26JASDsp8TChannelFv */
void JASDsp::TChannel::init() {
    mPauseFlag = 0;
    mIsFinished = 0;
    mForcedStop = 0;
    mIsActive = 0;
    field_0x058 = 0;
    field_0x068 = 0;
    initFilter();
}

/* 8029DCE0-8029DD44 298620 0064+00 0/0 1/1 0/0 .text            playStart__Q26JASDsp8TChannelFv */
void JASDsp::TChannel::playStart() {
    field_0x10c = 0;
    field_0x060 = 0;
    field_0x008 = 1;
    field_0x066 = 0;
    int i;
    for (i = 0; i < 4; i++) {
        field_0x078[i] = 0;
        field_0x0a8[i] = 0;
    }
    for (i = 0; i < 20; i++) {
        field_0x080[i] = 0;
    }
    mIsActive = 1;
}

/* 8029DD44-8029DD50 298684 000C+00 0/0 1/1 0/0 .text            playStop__Q26JASDsp8TChannelFv */
void JASDsp::TChannel::playStop() {
    mIsActive = 0;
}

/* 8029DD50-8029DD60 298690 0010+00 0/0 1/1 0/0 .text replyFinishRequest__Q26JASDsp8TChannelFv */
void JASDsp::TChannel::replyFinishRequest() {
    mIsFinished = 0;
    mIsActive = 0;
}

/* 8029DD60-8029DD6C 2986A0 000C+00 0/0 1/1 0/0 .text            forceStop__Q26JASDsp8TChannelFv */
void JASDsp::TChannel::forceStop() {
    mForcedStop = 1;
}

/* 8029DD6C-8029DD7C 2986AC 0010+00 1/1 0/0 0/0 .text            isActive__Q26JASDsp8TChannelCFv */
bool JASDsp::TChannel::isActive() const {
    return mIsActive != 0;
}

/* 8029DD7C-8029DD8C 2986BC 0010+00 0/0 1/1 0/0 .text            isFinish__Q26JASDsp8TChannelCFv */
bool JASDsp::TChannel::isFinish() const {
    return mIsFinished != 0;
}

/* ############################################################################################## */
/* 8045574C-80455754 003D4C 0008+00 1/1 0/0 0/0 .sdata2          COMP_BLOCKSAMPLES$331 */
static const u8 COMP_BLOCKSAMPLES[8] = {
    0x10, 0x10, 0x01, 0x01, 0x01, 0x10, 0x10, 0x01,
};

/* 80455754-8045575C 003D54 0008+00 1/1 0/0 0/0 .sdata2          COMP_BLOCKBYTES$332 */
static const u8 COMP_BLOCKBYTES[8] = {
    0x09, 0x05, 0x08, 0x10, 0x01, 0x01, 0x01, 0x01,
};

/* 8029DD8C-8029DEAC 2986CC 0120+00 0/0 1/1 0/0 .text
 * setWaveInfo__Q26JASDsp8TChannelFRC11JASWaveInfoUlUl          */
void JASDsp::TChannel::setWaveInfo(JASWaveInfo const& param_0, u32 param_1, u32 param_2) {
    field_0x118 = param_1;
    field_0x064 = COMP_BLOCKSAMPLES[param_0.field_0x00];
    field_0x100 = COMP_BLOCKBYTES[param_0.field_0x00];
    field_0x068 = 0;
    if (field_0x100 >= 4) {
        field_0x11c = param_0.field_0x18;
        field_0x102 = param_0.field_0x02;
        if (field_0x102) {
            if (param_2 == 1) {
                param_2 = param_0.field_0x10;
            }
            field_0x110 = param_0.field_0x10;
            field_0x114 = param_0.field_0x14;
            field_0x104 = param_0.field_0x1c;
            field_0x106 = param_0.field_0x1e;
        } else {
            field_0x114 = field_0x11c;
        }
        if (param_2 && field_0x114 > param_2) {
            switch (param_0.field_0x00) {
            case 0:
            case 1:
                field_0x068 = param_2;
                field_0x118 += param_2 * field_0x100 >> 4;
                field_0x110 -= param_2;
                field_0x114 -= param_2;
                break;
            case 2:
            case 3:
                field_0x068 = param_2;
                break;
            }
        }
        for (int i = 0; i < 16; i++) {
            field_0x0b0[i] = 0;
        }
    }
}

/* 8029DEAC-8029DEC4 2987EC 0018+00 0/0 1/1 0/0 .text            setOscInfo__Q26JASDsp8TChannelFUl
 */
void JASDsp::TChannel::setOscInfo(u32 param_0) {
    field_0x118 = 0;
    field_0x064 = 16;
    field_0x100 = param_0;
}

/* 8029DEC4-8029DEF0 298804 002C+00 0/0 1/1 0/0 .text            initAutoMixer__Q26JASDsp8TChannelFv
 */
void JASDsp::TChannel::initAutoMixer() {
    if (field_0x058) {
        field_0x054 = field_0x056;
    } else {
        field_0x054 = 0;
        field_0x058 = 1;
    }
}

/* 8029DEF0-8029DF1C 298830 002C+00 0/0 1/1 0/0 .text setAutoMixer__Q26JASDsp8TChannelFUsUcUcUcUc
 */
void JASDsp::TChannel::setAutoMixer(u16 param_0, u8 param_1, u8 param_2, u8 param_3,
                                        u8 param_4) {
    field_0x050 = (param_1 << 8) | param_2;
    field_0x052 = param_3 << 8 | param_3 << 1;
    field_0x056 = param_0;
    field_0x058 = 1;
}

/* 8029DF1C-8029DF34 29885C 0018+00 0/0 2/2 0/0 .text            setPitch__Q26JASDsp8TChannelFUs */
void JASDsp::TChannel::setPitch(u16 param_0) {
    if (param_0 >= 0x7fff) {
        param_0 = 0x7fff;
    }
    mPitch = param_0;
}

/* 8029DF34-8029DF54 298874 0020+00 0/0 1/1 0/0 .text setMixerInitVolume__Q26JASDsp8TChannelFUcs
 */
void JASDsp::TChannel::setMixerInitVolume(u8 param_0, s16 param_1) {
    u16* tmp = field_0x010[param_0];
    tmp[2] = param_1;
    tmp[1] = param_1;
    tmp[3] = 0;
}

/* 8029DF54-8029DF80 298894 002C+00 0/0 1/1 0/0 .text setMixerVolume__Q26JASDsp8TChannelFUcs */
void JASDsp::TChannel::setMixerVolume(u8 param_0, s16 param_1) {
    if (mForcedStop == 0) {
        u16* tmp = field_0x010[param_0];
        tmp[1] = param_1;
        tmp[3] &= 0xff;
    }
}

/* 8029DF80-8029DF8C 2988C0 000C+00 0/0 2/2 0/0 .text            setPauseFlag__Q26JASDsp8TChannelFUc
 */
void JASDsp::TChannel::setPauseFlag(u8 param_0) {
    mPauseFlag = param_0;
}

/* 8029DF8C-8029DFB0 2988CC 0024+00 0/0 1/1 0/0 .text            flush__Q26JASDsp8TChannelFv */
void JASDsp::TChannel::flush() {
    DCFlushRange(this, sizeof(*this));
}

/* 8029DFB0-8029E00C 2988F0 005C+00 1/1 0/0 0/0 .text            initFilter__Q26JASDsp8TChannelFv */
void JASDsp::TChannel::initFilter() {
    int i;
    for (i = 0; i < 8; i++) {
        fir_filter_params[i] = 0;
    }
    fir_filter_params[0] = 0x7fff;
    for (i = 0; i < 8; i++) {
        iir_filter_params[i] = 0;
    }
    iir_filter_params[0] = 0x7fff;
    iir_filter_params[4] = 0;
}

/* 8029E00C-8029E044 29894C 0038+00 0/0 1/1 0/0 .text setFilterMode__Q26JASDsp8TChannelFUs */
void JASDsp::TChannel::setFilterMode(u16 param_0) {
    u8 r30 = param_0 & 0x20;
    u8 r31 = param_0 & 0x1f;
    if (r30) {
        if (r31 > 0x14) {
            r31 = 0x14;
        }
    } else {
        if (r31 > 0x18) {
            r31 = 0x18;
        }
    }
    mFilterMode = r30 + r31;
}

/* 8029E044-8029E06C 298984 0028+00 0/0 1/1 0/0 .text setIIRFilterParam__Q26JASDsp8TChannelFPs */
void JASDsp::TChannel::setIIRFilterParam(s16* param_0) {
    setFilterTable(iir_filter_params, param_0, 8);
}

/* 8029E06C-8029E094 2989AC 0028+00 0/0 1/1 0/0 .text setFIR8FilterParam__Q26JASDsp8TChannelFPs */
void JASDsp::TChannel::setFIR8FilterParam(s16* param_0) {
    setFilterTable(fir_filter_params, param_0, 8);
}

/* 8029E094-8029E09C -00001 0008+00 0/0 0/0 0/0 .text            setDistFilter__Q26JASDsp8TChannelFs
 */
void JASDsp::TChannel::setDistFilter(s16 param_0) {
    iir_filter_params[4] = param_0;
}

/* ############################################################################################## */
/* 8039B8A0-8039B8B8 027F00 0018+00 1/1 0/0 0/0 .rodata          connect_table$463 */
static u16 const connect_table[12] = {
    0x0000, 0x0D00, 0x0D60, 0x0DC0, 0x0E20, 0x0E80,
    0x0EE0, 0x0CA0, 0x0F40, 0x0FA0, 0x0B00, 0x09A0,
};

/* 8029E09C-8029E0BC 2989DC 0020+00 0/0 1/1 0/0 .text setBusConnect__Q26JASDsp8TChannelFUcUc */
void JASDsp::TChannel::setBusConnect(u8 param_0, u8 param_1) {
    u16* tmp = field_0x010[param_0];
    tmp[0] = connect_table[param_1];
}

/* 8029E0BC-8029E130 2989FC 0074+00 0/0 1/1 0/0 .text            DSP_CreateMap2__FUl */
u16 DSP_CreateMap2(u32 param_0) {
    u16 r30 = 0;
    JASDsp::TChannel* channel = &JASDsp::CH_BUF[param_0 << 4];
    for (int i = 0; i < 16; i++) {
        r30 <<= 1;
        if (channel->isActive()) {
            r30 |= 1;
        }
        channel++;
    }
    return r30;
}

/* 804507B8-804507C0 000238 0004+04 0/0 5/5 0/0 .sdata           one__11JASWaveInfo */
u32 JASWaveInfo::one = 1;