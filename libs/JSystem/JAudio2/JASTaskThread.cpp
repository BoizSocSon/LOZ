//
// Generated By: dol2asm
// Translation Unit: JASTaskThread
//

#include "JSystem/JAudio2/JASTaskThread.h"
#include "JSystem/JAudio2/JASCalc.h"
#include "JSystem/JAudio2/JASCriticalSection.h"
#include "JSystem/JKernel/JKRSolidHeap.h"
#include "dol2asm.h"
#include "dolphin/os/OSInterrupt.h"
#include "dolphin/os.h"

//
// Forward References:
//

extern "C" void __ct__13JASTaskThreadFiiUl();
extern "C" void __dt__13JASTaskThreadFv();
extern "C" void allocCallStack__13JASTaskThreadFPFPv_vPCvUl();
extern "C" void allocCallStack__13JASTaskThreadFPFPv_vPv();
extern "C" void sendCmdMsg__13JASTaskThreadFPFPv_vPCvUl();
extern "C" void sendCmdMsg__13JASTaskThreadFPFPv_vPv();
extern "C" void run__13JASTaskThreadFv();
extern "C" void pause__13JASTaskThreadFb();

//
// External References:
//

extern "C" void bcopy__7JASCalcFPCvPvUl();
extern "C" void getSystemHeap__9JASKernelFv();
extern "C" void getCommandHeap__9JASKernelFv();
extern "C" void* __nw__FUlP7JKRHeapi();
extern "C" void __dl__FPv();
extern "C" void __ct__9JKRThreadFP7JKRHeapUlii();
extern "C" void __dt__9JKRThreadFv();
extern "C" void _savegpr_26();
extern "C" void _savegpr_27();
extern "C" void _savegpr_28();
extern "C" void _restgpr_26();
extern "C" void _restgpr_27();
extern "C" void _restgpr_28();
extern "C" u8 sSystemHeap__7JKRHeap[4];

//
// Declarations:
//

/* 8028F6C4-8028F724 28A004 0060+00 0/0 1/1 0/0 .text            __ct__13JASTaskThreadFiiUl */
JASTaskThread::JASTaskThread(int param_0, int param_1, u32 param_2) : JKRThread(JASDram, param_2, param_1, param_0) {
    field_0x84 = false;
    OSInitThreadQueue(&mpThreadQueue);
}

/* 8028F724-8028F850 28A064 012C+00 1/0 0/0 0/0 .text            __dt__13JASTaskThreadFv */
JASTaskThread::~JASTaskThread() {
    OSMessage msg;
    BOOL received;
    while (true) {
        msg = waitMessage(&received);
        if (!received) {
            return;
        }
        ThreadMemPool* heap = JASKernel::getCommandHeap();
        heap->free(msg);
    }
}

/* 8028F850-8028F9EC 28A190 019C+00 1/1 0/0 0/0 .text allocCallStack__13JASTaskThreadFPFPv_vPCvUl
 */
void* JASTaskThread::allocCallStack(void (*param_0)(void*), void const* param_1, u32 param_2) {
    ThreadMemPool* heap;
    u32 size = param_2 + 8;
    heap = JASKernel::getCommandHeap();
    JASThreadCallStack *callStack = (JASThreadCallStack*) heap->alloc(size);
    if (callStack == NULL) {
        return NULL;
    }
    callStack->field_0x4 = 1;
    JASCalc::bcopy(param_1, callStack->field_0x8.buffer, param_2);
    callStack->mRunFunc = param_0;
    return callStack;
}

/* 8028F9EC-8028FB5C 28A32C 0170+00 1/1 0/0 0/0 .text allocCallStack__13JASTaskThreadFPFPv_vPv */
void* JASTaskThread::allocCallStack(void (*runFunc)(void*), void* param_1) {
    ThreadMemPool* heap;
    JASThreadCallStack *callStack;
    heap = JASKernel::getCommandHeap();
    callStack = (JASThreadCallStack*)heap->alloc(0xc);
    if (callStack == NULL) {
        return NULL;
    }
    callStack->field_0x4 = 0;
    callStack->field_0x8.pBuffer = param_1;
    callStack->mRunFunc = runFunc;
    return callStack;
}

/* 8028FB5C-8028FC54 28A49C 00F8+00 0/0 6/6 0/0 .text sendCmdMsg__13JASTaskThreadFPFPv_vPCvUl */
int JASTaskThread::sendCmdMsg(void (*param_0)(void*), void const* param_1, u32 param_2) {
    void* pvVar1;

    pvVar1 = allocCallStack(param_0, param_1, param_2);
    if (pvVar1 == NULL) {
        return 0;
    }
    int iVar2 = sendMessage(pvVar1);
    if (iVar2 == 0) {
        ThreadMemPool* heap = JASKernel::getCommandHeap();
        heap->free(pvVar1);
    }
    return iVar2;
}

/* 8028FC54-8028FD4C 28A594 00F8+00 0/0 3/3 0/0 .text sendCmdMsg__13JASTaskThreadFPFPv_vPv */
int JASTaskThread::sendCmdMsg(void (*param_0)(void*), void* param_1) {
    void* pvVar1;

    pvVar1 = allocCallStack(param_0, param_1);
    if (pvVar1 == NULL) {
        return 0;
    }
    int iVar2 = sendMessage(pvVar1);
    if (iVar2 == 0) {
        ThreadMemPool* heap = JASKernel::getCommandHeap();
        heap->free(pvVar1);
    }
    return iVar2;
}

/* 8028FD4C-8028FE88 28A68C 013C+00 1/0 0/0 0/0 .text            run__13JASTaskThreadFv */
// Regalloc
#ifdef NONMATCHING
void* JASTaskThread::run() {
    OSInitFastCast();
    do {
        JASThreadCallStack* ppcVar1 = (JASThreadCallStack*)waitMessageBlock();
        if (field_0x84) {
            OSSleepThread(&mpThreadQueue);
        }
        if (ppcVar1->field_0x4) {
            ppcVar1->mRunFunc(ppcVar1->field_0x8.buffer);
        } else {
            ppcVar1->mRunFunc(ppcVar1->field_0x8.pBuffer);
        }
        ThreadMemPool* heap = JASKernel::getCommandHeap();
        heap->free(ppcVar1);
    } while (true);
}
#else
#pragma push
#pragma optimization_level 0
#pragma optimizewithasm off
asm void* JASTaskThread::run() {
    nofralloc
#include "asm/JSystem/JAudio2/JASTaskThread/run__13JASTaskThreadFv.s"
}
#pragma pop
#endif

/* 8028FE88-8028FEFC 28A7C8 0074+00 0/0 1/1 0/0 .text            pause__13JASTaskThreadFb */
void JASTaskThread::pause(bool param_0) {
    JASCriticalSection aJStack_14;
    if (param_0) {
        field_0x84 = 1;
    } else {
        if (field_0x84) {
            OSWakeupThread(&mpThreadQueue);
        }
        field_0x84 = 0;
    }
}