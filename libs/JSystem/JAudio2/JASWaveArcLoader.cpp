//
// Generated By: dol2asm
// Translation Unit: JASWaveArcLoader
//

#include "JSystem/JAudio2/JASWaveArcLoader.h"
#include "JSystem/JAudio2/JASDvdThread.h"
#include "JSystem/JAudio2/JASTaskThread.h"
#include "JSystem/JAudio2/JASMutex.h"
#include "JSystem/JKernel/JKRDvdAramRipper.h"
#include "string.h"
#include "dolphin/dvd.h"
#include "dolphin/os.h"

//
// Forward References:
//

extern "C" void getRootHeap__16JASWaveArcLoaderFv();
extern "C" void setCurrentDir__16JASWaveArcLoaderFPCc();
extern "C" void getCurrentDir__16JASWaveArcLoaderFv();
extern "C" void __ct__10JASWaveArcFv();
extern "C" void __dt__10JASWaveArcFv();
extern "C" void loadSetup__10JASWaveArcFUl();
extern "C" void eraseSetup__10JASWaveArcFv();
extern "C" void loadToAramCallback__10JASWaveArcFPv();
extern "C" void sendLoadCmd__10JASWaveArcFv();
extern "C" void load__10JASWaveArcFP7JASHeap();
extern "C" void loadTail__10JASWaveArcFP7JASHeap();
extern "C" void erase__10JASWaveArcFv();
extern "C" void onDispose__10JASWaveArcFv();
extern "C" void setEntryNum__10JASWaveArcFl();
extern "C" void setFileName__10JASWaveArcFPCc();
extern "C" void __dt__11JASDisposerFv();
extern "C" u8 sCurrentDir__16JASWaveArcLoader[64];
extern "C" u8 sAramHeap__16JASWaveArcLoader[4 + 4 /* padding */];

//
// External References:
//

extern "C" void sendCmdMsg__13JASTaskThreadFPFPv_vPCvUl();
extern "C" void getThreadPointer__6JASDvdFv();
extern "C" void __ct__7JASHeapFP11JASDisposer();
extern "C" void alloc__7JASHeapFP7JASHeapUl();
extern "C" void allocTail__7JASHeapFP7JASHeapUl();
extern "C" void free__7JASHeapFv();
extern "C" void getSystemHeap__9JASKernelFv();
extern "C" void getAramHeap__9JASKernelFv();
extern "C" void onDispose__11JASDisposerFv();
extern "C" void onLoadDone__10JASWaveArcFv();
extern "C" void onEraseDone__10JASWaveArcFv();
extern "C" void* __nwa__FUlP7JKRHeapi();
extern "C" void __dl__FPv();
extern "C" void __dla__FPv();
extern "C" void loadToAram__16JKRDvdAramRipperFlUl15JKRExpandSwitchUlUlPUl();
extern "C" void __dt__10JSUPtrLinkFv();
extern "C" void __dt__10JSUPtrListFv();
extern "C" void _savegpr_27();
extern "C" void _restgpr_27();

//
// Declarations:
//

/* ############################################################################################## */
/* 80451290-80451298 000790 0004+04 1/1 0/0 0/0 .sbss            sAramHeap__16JASWaveArcLoader */
JASHeap* JASWaveArcLoader::sAramHeap;

/* 8029A0A0-8029A0D0 2949E0 0030+00 2/2 0/0 0/0 .text            getRootHeap__16JASWaveArcLoaderFv
 */
JASHeap* JASWaveArcLoader::getRootHeap() {
    if (JASWaveArcLoader::sAramHeap) {
        return JASWaveArcLoader::sAramHeap;
    }
    return JASKernel::getAramHeap();
}

/* ############################################################################################## */
/* 803C77E0-803C7820 024900 0040+00 2/2 0/0 0/0 .data            sCurrentDir__16JASWaveArcLoader */
char JASWaveArcLoader::sCurrentDir[DIR_MAX] = "/AudioRes/Waves/";

/* 8029A0D0-8029A130 294A10 0060+00 0/0 1/1 0/0 .text setCurrentDir__16JASWaveArcLoaderFPCc */
void JASWaveArcLoader::setCurrentDir(char const* dir) {
    ASSERT(std::strlen(dir) < DIR_MAX - 1);
    strcpy(sCurrentDir, dir);
    u32 len = strlen(sCurrentDir);
    if (sCurrentDir[len - 1] != '/') {
        ASSERT(len + 1 < DIR_MAX);
        sCurrentDir[len] = '/';
        sCurrentDir[len + 1] = '\0';
    }
}

/* 8029A130-8029A13C 294A70 000C+00 1/1 0/0 0/0 .text            getCurrentDir__16JASWaveArcLoaderFv
 */

char* JASWaveArcLoader::getCurrentDir() {
    return sCurrentDir;
}

/* ############################################################################################## */
/* 803C7820-803C7838 024940 0018+00 2/2 0/0 0/0 .data            __vt__10JASWaveArc */
SECTION_DATA extern void* __vt__10JASWaveArc[6] = {
    (void*)NULL /* RTTI */,
    (void*)NULL,
    (void*)__dt__10JASWaveArcFv,
    (void*)onDispose__10JASWaveArcFv,
    (void*)onLoadDone__10JASWaveArcFv,
    (void*)onEraseDone__10JASWaveArcFv,
};

/* 803C7838-803C7848 024958 0010+00 3/3 0/0 0/0 .data            __vt__11JASDisposer */
SECTION_DATA extern void* __vt__11JASDisposer[4] = {
    (void*)NULL /* RTTI */,
    (void*)NULL,
    (void*)__dt__11JASDisposerFv,
    (void*)onDispose__11JASDisposerFv,
};

/* 8029A13C-8029A1B4 294A7C 0078+00 0/0 2/2 0/0 .text            __ct__10JASWaveArcFv */

JASWaveArc::JASWaveArc() : mHeap(this) {
    _48 = 0;
    _4c = 0;
    mEntryNum = -1;
    mFileLength = 0;
    _58 = 0;
    _5a = 0;
    OSInitMutex(&mMutex);
}

/* 8029A1B4-8029A258 294AF4 00A4+00 1/0 2/2 0/0 .text            __dt__10JASWaveArcFv */
#ifdef NONMATCHING
JASWaveArc::~JASWaveArc() {}
#else
asm void __dt__10JASWaveArcFv() {
    nofralloc
#include "asm/JSystem/JAudio2/JASWaveArcLoader/__dt__10JASWaveArcFv.s"
}
#endif

/* 8029A258-8029A2EC 294B98 0094+00 1/1 0/0 0/0 .text            loadSetup__10JASWaveArcFUl */
bool JASWaveArc::loadSetup(u32 param_0) {
    JASMutexLock mutexLock(&mMutex);
    if (_58 != param_0) {
        return false;
    }
    if (_4c != 1) {
        return false;
    }
    _48 = 1;
    _4c = 2;
    return true;
}

/* 8029A2EC-8029A378 294C2C 008C+00 1/1 0/0 0/0 .text            eraseSetup__10JASWaveArcFv */
bool JASWaveArc::eraseSetup() {
    JASMutexLock mutexLock(&mMutex);
    if (_4c == 0) {
        return false;
    }
    if (_4c == 1) {
        _4c = 0;
        return false;
    }
    _48 = 0;
    _4c = 0;
    return true;
}

/* 8029A378-8029A404 294CB8 008C+00 1/1 0/0 0/0 .text            loadToAramCallback__10JASWaveArcFPv
 */
void JASWaveArc::loadToAramCallback(void* this_) {
    loadToAramCallbackParams* tmp = (loadToAramCallbackParams*)this_;
    JASWaveArc* wavArc = tmp->mWavArc;
    JKRAramBlock* block = JKRDvdAramRipper::loadToAram(tmp->mEntryNum, tmp->mBase,
                                                       EXPAND_SWITCH_UNKNOWN0, 0, 0, NULL);
    if (block == NULL) {
        // "loadToAram Failed"
        return;
    }
    wavArc->_5a--;
    if (wavArc->loadSetup(tmp->_c)) {
        wavArc->onLoadDone();
    }
}

/* 8029A404-8029A4C0 294D44 00BC+00 2/2 0/0 0/0 .text            sendLoadCmd__10JASWaveArcFv */
bool JASWaveArc::sendLoadCmd() {
    JASMutexLock mutexLock(&mMutex);
    _48 = 0;
    _4c = 1;
    void* base = mHeap.getBase();
    loadToAramCallbackParams commandInfo;
    commandInfo.mWavArc = this;
    commandInfo.mEntryNum = mEntryNum;
    commandInfo.mBase = (u32)mHeap.mBase;
    commandInfo._c = ++_58;

    _5a++;

    JASTaskThread* thread = JASDvd::getThreadPointer();
    int status = thread->sendCmdMsg(loadToAramCallback, &commandInfo, 0x10);
    if (status == 0) {
        // "sendCmdMsg loadToAramCallback Failed"
        mHeap.free();
        return false;
    }
    return true;
}

/* 8029A4C0-8029A580 294E00 00C0+00 0/0 2/2 0/0 .text            load__10JASWaveArcFP7JASHeap */
bool JASWaveArc::load(JASHeap* heap) {
    if (mEntryNum < 0) {
        return false;
    }
    JASMutexLock mutexLock(&mMutex);
    if (_4c != 0) {
        return false;
    }
    if (heap == NULL) {
        heap = JASWaveArcLoader::getRootHeap();
    }
    bool result = mHeap.alloc(heap, mFileLength);
    if (result == false) {
        return false;
    }
    return sendLoadCmd();
}

/* 8029A580-8029A640 294EC0 00C0+00 0/0 1/1 0/0 .text            loadTail__10JASWaveArcFP7JASHeap */
bool JASWaveArc::loadTail(JASHeap* heap) {
    if (mEntryNum < 0) {
        return false;
    }
    JASMutexLock mutexLock(&mMutex);
    if (_4c != 0) {
        return false;
    }
    if (heap == NULL) {
        heap = JASWaveArcLoader::getRootHeap();
    }
    bool result = mHeap.allocTail(heap, mFileLength);
    if (result == false) {
        return false;
    }
    return sendLoadCmd();
}

/* 8029A640-8029A664 294F80 0024+00 0/0 2/2 0/0 .text            erase__10JASWaveArcFv */
void JASWaveArc::erase() {
    mHeap.free();
}

/* 8029A664-8029A6AC 294FA4 0048+00 1/0 2/0 0/0 .text            onDispose__10JASWaveArcFv */
void JASWaveArc::onDispose() {
    if (eraseSetup()) {
        onEraseDone();
    }
}

/* 8029A6AC-8029A70C 294FEC 0060+00 1/1 0/0 0/0 .text            setEntryNum__10JASWaveArcFl */
void JASWaveArc::setEntryNum(s32 entryNum) {
    DVDFileInfo fileInfo;
    if (entryNum < 0) {
        return;
    }
    BOOL openStatus = DVDFastOpen(entryNum, &fileInfo);
    if (openStatus == FALSE) {
        return;
    }
    mFileLength = fileInfo.length;
    DVDClose(&fileInfo);
    mEntryNum = entryNum;
}

/* 8029A70C-8029A7B8 29504C 00AC+00 0/0 2/2 0/0 .text            setFileName__10JASWaveArcFPCc */
void JASWaveArc::setFileName(char const* fileName) {
    char* currentDir = JASWaveArcLoader::getCurrentDir();
    size_t length = strlen(currentDir);
    length = length + strlen(fileName);
    JKRHeap* systemHeap = JASKernel::getSystemHeap();
    char* fileString = new (systemHeap, -4) char[length + 1];
    strcpy(fileString, currentDir);
    strcat(fileString, fileName);
    fileString[length] = '\0';
    int entryNum = DVDConvertPathToEntrynum(fileString);
    delete[] fileString;
    if (entryNum < 0) {
        return;
    }
    setEntryNum(entryNum);
}

/* 8029A7B8-8029A800 2950F8 0048+00 1/0 0/0 0/0 .text            __dt__11JASDisposerFv */
#pragma push
#pragma optimization_level 0
#pragma optimizewithasm off
asm void __dt__11JASDisposerFv() {
    nofralloc
#include "asm/JSystem/JAudio2/JASWaveArcLoader/__dt__11JASDisposerFv.s"
}
#pragma pop