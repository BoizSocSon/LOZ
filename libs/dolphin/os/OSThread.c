//
// Generated By: dol2asm
// Translation Unit: OSThread
//

#include "dolphin/os/OSThread.h"
#include "dol2asm.h"
#include "dolphin/os.h"

OSThread* __OSCurrentThread : OS_BASE_CACHED + 0x00E4;
OSThreadQueue __OSActiveThreadQueue : OS_BASE_CACHED + 0x00DC;
volatile OSContext __OSCurrentContext : OS_BASE_CACHED + 0x00D4;
volatile OSContext* __OSFPUContext : OS_BASE_CACHED + 0x00D8;

#define AddTail(queue, thread, link)                                                               \
    do {                                                                                           \
        OSThread* prev;                                                                            \
                                                                                                   \
        prev = (queue)->tail;                                                                      \
        if (prev == NULL)                                                                          \
            (queue)->head = (thread);                                                              \
        else                                                                                       \
            prev->link.next = (thread);                                                            \
        (thread)->link.prev = prev;                                                                \
        (thread)->link.next = NULL;                                                                \
        (queue)->tail = (thread);                                                                  \
    } while (0)

#define AddPrio(queue, thread, link)                                                               \
    do {                                                                                           \
        OSThread *prev, *next;                                                                     \
                                                                                                   \
        for (next = (queue)->head; next && next->effective_priority <= thread->effective_priority; \
             next = next->link.next)                                                               \
            ;                                                                                      \
        if (next == NULL)                                                                          \
            AddTail(queue, thread, link);                                                          \
        else {                                                                                     \
            (thread)->link.next = next;                                                            \
            prev = next->link.prev;                                                                \
            next->link.prev = (thread);                                                            \
            (thread)->link.prev = prev;                                                            \
            if (prev == NULL)                                                                      \
                (queue)->head = (thread);                                                          \
            else                                                                                   \
                prev->link.next = (thread);                                                        \
        }                                                                                          \
    } while (0)

#define RemoveItem(queue, thread, link)                                                            \
    do {                                                                                           \
        OSThread *next, *prev;                                                                     \
        next = (thread)->link.next;                                                                \
        prev = (thread)->link.prev;                                                                \
        if (next == NULL)                                                                          \
            (queue)->tail = prev;                                                                  \
        else                                                                                       \
            next->link.prev = prev;                                                                \
        if (prev == NULL)                                                                          \
            (queue)->head = next;                                                                  \
        else                                                                                       \
            prev->link.next = next;                                                                \
    } while (0)

#define RemoveHead(queue, thread, link)                                                            \
    do {                                                                                           \
        OSThread* __next;                                                                          \
        (thread) = (queue)->head;                                                                  \
        __next = (thread)->link.next;                                                              \
        if (__next == NULL)                                                                        \
            (queue)->tail = NULL;                                                                  \
        else                                                                                       \
            __next->link.prev = NULL;                                                              \
        (queue)->head = __next;                                                                    \
    } while (0)

//
// External References:
//

extern OSErrorHandlerEx __OSErrorTable[17];
extern u32 __OSFpscrEnableBits;
void _epilog();

//
// Declarations:
//

/* 80340AA4-80340AA8 33B3E4 0004+00 2/1 0/0 0/0 .text            DefaultSwitchThreadCallback */
static void DefaultSwitchThreadCallback(OSThread* from, OSThread* to) {}

/* ############################################################################################## */
/* 804509B8-804509BC -00001 0004+00 3/3 0/0 0/0 .sdata           SwitchThreadCallback */
static OSSwitchThreadCallback SwitchThreadCallback = DefaultSwitchThreadCallback;

/* 80340AA8-80340B1C 33B3E8 0074+00 0/0 1/1 0/0 .text            OSSetSwitchThreadCallback */
OSSwitchThreadCallback OSSetSwitchThreadCallback(OSSwitchThreadCallback func) {
    BOOL enable = OSDisableInterrupts();
    OSSwitchThreadCallback prev = SwitchThreadCallback;
    OSSwitchThreadCallback temp;
    if (func) {
        temp = func;
    } else {
        temp = DefaultSwitchThreadCallback;
    }
    SwitchThreadCallback = temp;

    OSRestoreInterrupts(enable);
    if (prev == DefaultSwitchThreadCallback) {
        return NULL;
    }

    return prev;
}

/* ############################################################################################## */
/* 8044BB78-8044BC78 078898 0100+00 6/6 0/0 0/0 .bss             RunQueue */
static OSThreadQueue RunQueue[32];

/* 8044BC78-8044BF90 078998 0318+00 0/0 0/0 0/0 .bss             IdleThread */
#pragma push
#pragma force_active on
static OSThread IdleThread;
#pragma pop

/* 8044BF90-8044C2A8 078CB0 0318+00 0/1 0/0 0/0 .bss             DefaultThread */
#pragma push
#pragma force_active on
static OSThread DefaultThread;
#pragma pop

/* 8044C2A8-8044C570 078FC8 02C8+00 0/2 0/0 0/0 .bss             IdleContext */
#pragma push
#pragma force_active on
static OSContext IdleContext;
#pragma pop

/* 804516C0-804516C4 000BC0 0004+00 7/7 0/0 0/0 .sbss            RunQueueBits */
static vu32 RunQueueBits;

/* 804516C4-804516C8 000BC4 0004+00 11/11 0/0 0/0 .sbss            RunQueueHint */
static volatile BOOL RunQueueHint;

/* 804516C8-804516D0 000BC8 0004+04 4/4 0/0 0/0 .sbss            Reschedule */
static volatile s32 Reschedule;

extern u8 _stack_end[];
extern u8 _stack_addr[];

static inline void OSInitMutexQueue(OSMutexQueue* queue) {
    queue->head = queue->tail = NULL;
}

static inline void OSSetCurrentThread(OSThread* thread) {
    SwitchThreadCallback(__OSCurrentThread, thread);
    __OSCurrentThread = thread;
}

/* 80340B1C-80340C74 33B45C 0158+00 0/0 1/1 0/0 .text            __OSThreadInit */
void __OSThreadInit() {
    OSThread* thread = &DefaultThread;
    int prio;

    thread->state = OS_THREAD_STATE_RUNNING;
    thread->attributes = OS_THREAD_ATTR_DETACH;
    thread->effective_priority = thread->base_priority = 16;
    thread->suspend_count = 0;
    thread->exit_value = (void*)-1;
    thread->mutex = NULL;
    OSInitThreadQueue(&thread->join_queue);
    OSInitMutexQueue(&thread->owned_mutexes);

    __OSFPUContext = &thread->context;

    OSClearContext(&thread->context);
    OSSetCurrentContext(&thread->context);
    thread->stack_base = (void*)_stack_addr;
    thread->stack_end = (void*)_stack_end;
    *(thread->stack_end) = OS_THREAD_STACK_MAGIC;

    OSSetCurrentThread(thread);
    OSClearStack(0);

    RunQueueBits = 0;
    RunQueueHint = FALSE;
    for (prio = OS_PRIORITY_MIN; prio <= OS_PRIORITY_MAX; ++prio) {
        OSInitThreadQueue(&RunQueue[prio]);
    }

    OSInitThreadQueue(&__OSActiveThreadQueue);
    AddTail(&__OSActiveThreadQueue, thread, active_threads_link);
    OSClearContext(&IdleContext);
    Reschedule = 0;
}

/* 80340C74-80340C84 33B5B4 0010+00 1/1 9/9 0/0 .text            OSInitThreadQueue */
void OSInitThreadQueue(OSThreadQueue* queue) {
    queue->tail = NULL;
    queue->head = NULL;
}

/* 80340C84-80340C90 33B5C4 000C+00 0/0 20/20 0/0 .text            OSGetCurrentThread */
OSThread* OSGetCurrentThread(void) {
    return OS_CURRENT_THREAD;
}

/* 80340C90-80340CC4 33B5D0 0034+00 0/0 1/1 0/0 .text            OSIsThreadTerminated */
BOOL OSIsThreadTerminated(OSThread* thread) {
    return thread->state == OS_THREAD_STATE_DEAD || thread->state == OS_THREAD_STATE_UNINITIALIZED ?
               TRUE :
               FALSE;
}

/* 80340CC4-80340D04 33B604 0040+00 0/0 8/8 0/0 .text            OSDisableScheduler */
s32 OSDisableScheduler(void) {
    BOOL intr = OSDisableInterrupts();
    s32 ret = Reschedule++;
    OSRestoreInterrupts(intr);
    return ret;
}

/* 80340D04-80340D44 33B644 0040+00 0/0 10/10 0/0 .text            OSEnableScheduler */
s32 OSEnableScheduler(void) {
    BOOL intr = OSDisableInterrupts();
    s32 ret = Reschedule--;
    OSRestoreInterrupts(intr);
    return ret;
}

static inline void SetRun(OSThread* thread) {
    thread->queue = &RunQueue[thread->effective_priority];
    AddTail(thread->queue, thread, link);
    RunQueueBits |= 1u << (OS_PRIORITY_MAX - thread->effective_priority);
    RunQueueHint = TRUE;
}

/* 80340D44-80340DAC 33B684 0068+00 3/3 0/0 0/0 .text            UnsetRun */
#pragma dont_inline on
static void UnsetRun(OSThread* thread) {
    OSThreadQueue* queue;
    OSThread* next;
    OSThread* prev;

    prev = thread->link.next;
    queue = thread->queue;
    next = thread->link.prev;

    if (prev == NULL) {
        queue->tail = next;
    } else {
        prev->link.prev = next;
    }

    if (next == NULL) {
        queue->head = prev;
    } else {
        next->link.next = prev;
    }

    if (queue->head == NULL) {
        RunQueueBits &= ~(1 << 31 - thread->effective_priority);
    }

    thread->queue = NULL;
}
#pragma dont_inline reset

/* 80340DAC-80340DE8 33B6EC 003C+00 4/4 2/2 0/0 .text            __OSGetEffectivePriority */
s32 __OSGetEffectivePriority(OSThread* thread) {
    s32 prio = thread->base_priority;

    OSMutex* mutex;
    for (mutex = thread->owned_mutexes.head; mutex != NULL; mutex = mutex->link.next) {
        OSThread* mutexThread = mutex->queue.head;
        if (mutexThread != NULL && mutexThread->effective_priority < prio) {
            prio = mutexThread->effective_priority;
        }
    }

    return prio;
}

/* 80340DE8-80340FA8 33B728 01C0+00 5/5 0/0 0/0 .text            SetEffectivePriority */
static OSThread* SetEffectivePriority(OSThread* thread, s32 priority) {
    switch (thread->state) {
    case OS_THREAD_STATE_READY:
        UnsetRun(thread);
        thread->effective_priority = priority;
        SetRun(thread);
        break;
    case OS_THREAD_STATE_WAITING:
        RemoveItem(thread->queue, thread, link);
        thread->effective_priority = priority;
        AddPrio(thread->queue, thread, link);
        if (thread->mutex) {
            return thread->mutex->thread;
        }
        break;
    case OS_THREAD_STATE_RUNNING:
        RunQueueHint = TRUE;
        thread->effective_priority = priority;
        break;
    }
    return NULL;
}

static void UpdatePriority(OSThread* thread) {
    OSPriority priority;

    do {
        if (0 < thread->suspend_count) {
            break;
        }
        priority = __OSGetEffectivePriority(thread);
        if (thread->effective_priority == priority) {
            break;
        }
        thread = SetEffectivePriority(thread, priority);
    } while (thread);
}

/* 80340FA8-80340FF8 33B8E8 0050+00 0/0 1/1 0/0 .text            __OSPromoteThread */
void __OSPromoteThread(OSThread* thread, s32 priority) {
    do {
        if (thread->suspend_count > 0 || thread->effective_priority <= priority) {
            break;
        }

        thread = SetEffectivePriority(thread, priority);
    } while (thread != NULL);
}

static inline void __OSSwitchThread(OSThread* nextThread) {
    OSSetCurrentThread(nextThread);
    OSSetCurrentContext(&nextThread->context);
    OSLoadContext(&nextThread->context);
}

/* 80340FF8-80341220 33B938 0228+00 9/9 0/0 0/0 .text            SelectThread */
inline OSThread* i_OSGetCurrentThread(void) {
    return OS_CURRENT_THREAD;
}

static OSThread* SelectThread(BOOL yield) {
    OSContext* currentContext;
    OSThread* currentThread;
    OSThread* nextThread;
    OSPriority priority;
    OSThreadQueue* queue;

    if (0 < Reschedule) {
        return 0;
    }

    currentContext = OSGetCurrentContext();
    currentThread = i_OSGetCurrentThread();
    if (currentContext != &currentThread->context) {
        return 0;
    }

    if (currentThread) {
        if (currentThread->state == OS_THREAD_STATE_RUNNING) {
            if (!yield) {
                priority = __cntlzw(RunQueueBits);
                if (currentThread->effective_priority <= priority) {
                    return 0;
                }
            }
            currentThread->state = OS_THREAD_STATE_READY;
            SetRun(currentThread);
        }

        if (!(currentThread->context.state & OS_CONTEXT_STATE_EXC) &&
            OSSaveContext(&currentThread->context))
        {
            return 0;
        }
    }

    if (RunQueueBits == 0) {
        OSSetCurrentThread(NULL);
        OSSetCurrentContext(&IdleContext);
        do {
            OSEnableInterrupts();
            while (RunQueueBits == 0)
                ;
            OSDisableInterrupts();
        } while (RunQueueBits == 0);

        OSClearContext(&IdleContext);
    }

    RunQueueHint = FALSE;

    priority = __cntlzw(RunQueueBits);
    queue = &RunQueue[priority];
    RemoveHead(queue, nextThread, link);
    if (queue->head == 0) {
        RunQueueBits &= ~(1u << (OS_PRIORITY_MAX - priority));
    }
    nextThread->queue = NULL;
    nextThread->state = OS_THREAD_STATE_RUNNING;
    __OSSwitchThread(nextThread);
    return nextThread;
}

/* 80341220-80341250 33BB60 0030+00 0/0 3/3 0/0 .text            __OSReschedule */
void __OSReschedule(void) {
    if (!RunQueueHint) {
        return;
    }

    SelectThread(FALSE);
}

/* 80341250-8034128C 33BB90 003C+00 0/0 2/2 0/0 .text            OSYieldThread */
void OSYieldThread(void) {
    BOOL enabled;

    enabled = OSDisableInterrupts();
    SelectThread(TRUE);
    OSRestoreInterrupts(enabled);
}

/* 8034128C-80341474 33BBCC 01E8+00 0/0 5/5 3/3 .text            OSCreateThread */
BOOL OSCreateThread(OSThread* thread_, void* func, void* param, void* stackBase, u32 stackSize,
                    s32 priority, u16 attribute) {
    BOOL enabled;
    u32 i;
    u32* stack;
    OSThread* thread;
    u32 stack1, stack2;

    if (priority < 0 || priority > 31) {
        return FALSE;
    }

    thread = thread_;

    thread->state = OS_THREAD_STATE_READY;
    thread->attributes = attribute & 1;
    thread->base_priority = priority;
    thread->effective_priority = priority;
    thread->suspend_count = 1;
    thread->exit_value = (void*)-1;
    thread->mutex = NULL;
    thread->join_queue.tail = NULL;
    thread->join_queue.head = NULL;
    thread->owned_mutexes.tail = NULL;
    thread->owned_mutexes.head = NULL;
    stack = (u32*)((u32)stackBase & 0xfffffff8);
    stack[-2] = 0;
    stack[-1] = 0;
    OSInitContext(&thread->context, (u32)func, (u32)stack - 8);
    thread->context.lr = (u32)OSExitThread;
    thread->context.gpr[3] = (u32)param;
    thread->stack_base = (u8*)stackBase;
    thread->stack_end = (void*)((u32)stackBase - stackSize);
    *(u32*)thread->stack_end = OS_THREAD_STACK_MAGIC;
    thread->error_code = NULL;
    thread->data[0] = NULL;
    thread->data[1] = NULL;
    enabled = OSDisableInterrupts();
    if (__OSErrorTable[16]) {
        thread->context.srr1 |= 0x900;
        thread->context.state |= 1;
        thread->context.fpscr = (__OSFpscrEnableBits & 0xf8) | 4;
        for (i = 0; i < 32; ++i) {
            *(u64*)&thread->context.fpr[i] = (u64)0xffffffffffffffffLL;
            *(u64*)&thread->context.ps[i] = (u64)0xffffffffffffffffLL;
        }
    }

    AddTail(&OS_THREAD_QUEUE, thread, active_threads_link);
    OSRestoreInterrupts(enabled);
    return TRUE;
}

/* 80341474-80341558 33BDB4 00E4+00 1/1 1/1 0/0 .text            OSExitThread */
void OSExitThread(void* exitValue) {
    OSThread* currentThread;
    BOOL enabled;
    enabled = OSDisableInterrupts();
    currentThread = OS_CURRENT_THREAD;
    OSClearContext(&currentThread->context);

    if (currentThread->attributes & OS_THREAD_ATTR_DETACH) {
        RemoveItem(&OS_THREAD_QUEUE, currentThread, active_threads_link);
        currentThread->state = OS_THREAD_STATE_UNINITIALIZED;
    } else {
        currentThread->state = OS_THREAD_STATE_DEAD;
        currentThread->exit_value = exitValue;
    }

    __OSUnlockAllMutex(currentThread);
    OSWakeupThread(&currentThread->join_queue);
    RunQueueHint = TRUE;

    if (RunQueueHint) {
        SelectThread(FALSE);
    }

    OSRestoreInterrupts(enabled);
}

/* 80341558-80341714 33BE98 01BC+00 0/0 4/4 3/3 .text            OSCancelThread */
void OSCancelThread(OSThread* thread) {
    BOOL enabled;

    enabled = OSDisableInterrupts();

    switch (thread->state) {
    case OS_THREAD_STATE_READY:
        if (!(0 < thread->suspend_count)) {
            UnsetRun(thread);
        }
        break;
    case OS_THREAD_STATE_RUNNING:
        RunQueueHint = TRUE;
        break;
    case OS_THREAD_STATE_WAITING:
        RemoveItem(thread->queue, thread, link);
        thread->queue = NULL;
        if (!(0 < thread->suspend_count) && thread->mutex) {
            UpdatePriority(thread->mutex->thread);
        }
        break;
    default:
        OSRestoreInterrupts(enabled);
        return;
    }

    OSClearContext(&thread->context);
    if (thread->attributes & OS_THREAD_ATTR_DETACH) {
        RemoveItem(&__OSActiveThreadQueue, thread, active_threads_link);
        thread->state = 0;
    } else {
        thread->state = OS_THREAD_STATE_DEAD;
    }

    __OSUnlockAllMutex(thread);

    OSWakeupThread(&thread->join_queue);

    __OSReschedule();
    OSRestoreInterrupts(enabled);
}

/* 80341714-803417B4 33C054 00A0+00 0/0 2/2 0/0 .text            OSDetachThread */
void OSDetachThread(OSThread* thread) {
    BOOL enabled;

    enabled = OSDisableInterrupts();
    thread->attributes |= OS_THREAD_ATTR_DETACH;

    if (thread->state == OS_THREAD_STATE_DEAD) {
        RemoveItem(&__OSActiveThreadQueue, thread, active_threads_link);
        thread->state = OS_THREAD_STATE_UNINITIALIZED;
    }

    OSWakeupThread(&thread->join_queue);
    OSRestoreInterrupts(enabled);
}

/* 803417B4-80341A3C 33C0F4 0288+00 0/0 13/13 3/3 .text            OSResumeThread */
s32 OSResumeThread(OSThread* thread) {
    BOOL enabled;
    s32 suspendCount;

    enabled = OSDisableInterrupts();
    suspendCount = thread->suspend_count--;
    if (thread->suspend_count < 0) {
        thread->suspend_count = 0;
    } else if (thread->suspend_count == 0) {
        switch (thread->state) {
        case OS_THREAD_STATE_READY:
            thread->effective_priority = __OSGetEffectivePriority(thread);
            SetRun(thread);
            break;
        case OS_THREAD_STATE_WAITING:
            RemoveItem(thread->queue, thread, link);
            thread->effective_priority = __OSGetEffectivePriority(thread);
            AddPrio(thread->queue, thread, link);
            if (thread->mutex) {
                UpdatePriority(thread->mutex->thread);
            }
            break;
        }
        __OSReschedule();
    }
    OSRestoreInterrupts(enabled);
    return suspendCount;
}

/* 80341A3C-80341BAC 33C37C 0170+00 0/0 7/7 4/4 .text            OSSuspendThread */
s32 OSSuspendThread(OSThread* thread) {
    BOOL enabled;
    s32 suspendCount;

    enabled = OSDisableInterrupts();
    suspendCount = thread->suspend_count++;
    if (suspendCount == 0) {
        switch (thread->state) {
        case OS_THREAD_STATE_RUNNING:
            RunQueueHint = TRUE;
            thread->state = OS_THREAD_STATE_READY;
            break;
        case OS_THREAD_STATE_READY:
            UnsetRun(thread);
            break;
        case OS_THREAD_STATE_WAITING:
            RemoveItem(thread->queue, thread, link);
            thread->effective_priority = 32;
            AddTail(thread->queue, thread, link);
            if (thread->mutex) {
                UpdatePriority(thread->mutex->thread);
            }
            break;
        }

        __OSReschedule();
    }
    OSRestoreInterrupts(enabled);
    return suspendCount;
}

/* 80341BAC-80341C98 33C4EC 00EC+00 0/0 12/12 0/0 .text            OSSleepThread */
void OSSleepThread(OSThreadQueue* queue) {
    BOOL enabled;
    OSThread* currentThread;

    enabled = OSDisableInterrupts();
    currentThread = OSGetCurrentThread();

    currentThread->state = OS_THREAD_STATE_WAITING;
    currentThread->queue = queue;
    AddPrio(queue, currentThread, link);
    RunQueueHint = TRUE;
    __OSReschedule();
    OSRestoreInterrupts(enabled);
}

/* 80341C98-80341D9C 33C5D8 0104+00 3/3 13/13 0/0 .text            OSWakeupThread */
void OSWakeupThread(OSThreadQueue* queue) {
    BOOL enabled;
    OSThread* thread;

    enabled = OSDisableInterrupts();
    while (queue->head) {
        RemoveHead(queue, thread, link);
        thread->state = OS_THREAD_STATE_READY;
        if (!(0 < thread->suspend_count)) {
            SetRun(thread);
        }
    }
    __OSReschedule();
    OSRestoreInterrupts(enabled);
}

/* 80341D9C-80341E5C 33C6DC 00C0+00 0/0 1/1 0/0 .text            OSSetThreadPriority */
s32 OSSetThreadPriority(OSThread* thread, s32 priority) {
    BOOL enabled;

    if (priority < 0 || priority > 31) {
        return FALSE;
    }

    enabled = OSDisableInterrupts();
    if ((s32)thread->base_priority != priority) {
        thread->base_priority = priority;

        UpdatePriority(thread);
        __OSReschedule();
    }
    OSRestoreInterrupts(enabled);
    return TRUE;
}

/* 80341E5C-80341E64 33C79C 0008+00 0/0 4/4 0/0 .text            OSGetThreadPriority */
s32 OSGetThreadPriority(OSThread* thread) {
    return thread->base_priority;
}

/* 80341E64-80341F00 33C7A4 009C+00 1/1 0/0 0/0 .text            CheckThreadQueue */
s32 CheckThreadQueue(OSThreadQueue* thread) {
    OSThread* current;
    if (thread->head && thread->head->link.prev) {
        return 0;
    }

    if (thread->tail && thread->tail->link.next) {
        return 0;
    }

    current = thread->head;

    while (current) {
        if (current->link.next && current != current->link.next->link.prev) {
            return 0;
        }

        if (current->link.prev && current != current->link.prev->link.next) {
            return 0;
        }

        current = current->link.next;
    }

    return 1;
}

static BOOL isMember(OSThreadQueue* queue, OSThread* thread) {
    OSThread* current = queue->head;
    while (current != NULL) {
        if (thread == current) {
            return TRUE;
        }

        current = current->link.next;
    }
    return FALSE;
}

/* 80341F00-80342650 33C840 0750+00 0/0 1/1 0/0 .text            OSCheckActiveThreads */
s32 OSCheckActiveThreads(void) {
    s32 i;
    OSThread* thread;
    s32 rv = 0;
    BOOL enabled;
    enabled = OSDisableInterrupts();

    for (i = 0; i <= 31; i++) {
        if (RunQueueBits & (1 << (31 - i))) {
            if (RunQueue[i].head == NULL || RunQueue[i].tail == NULL) {
                OSReport("OSCheckActiveThreads: Failed RunQueue[prio].head != NULL && "
                         "RunQueue[prio].tail != NULL in %d\n",
                         0x5e0);
                OSPanic(__FILE__, 0x5e0, "");
            }
        } else {
            if (RunQueue[i].head != NULL || RunQueue[i].tail != NULL) {
                OSReport("OSCheckActiveThreads: Failed RunQueue[prio].head == NULL && "
                         "RunQueue[prio].tail == NULL in %d\n",
                         0x5e5);
                OSPanic(__FILE__, 0x5e5, "");
            }
        }

        if (CheckThreadQueue(&RunQueue[i]) == 0) {
            OSReport("OSCheckActiveThreads: Failed CheckThreadQueue(&RunQueue[prio]) in %d\n",
                     0x5e7);
            OSPanic(__FILE__, 0x5e7, "");
        }
    }

    if (OS_THREAD_QUEUE.head != NULL && OS_THREAD_QUEUE.head->active_threads_link.prev != NULL) {
        OSReport("OSCheckActiveThreads: Failed __OSActiveThreadQueue.head == NULL || "
                 "__OSActiveThreadQueue.head->linkActive.prev == NULL in %d\n",
                 0x5ec);
        OSPanic(__FILE__, 0x5ec, "");
    }

    if (OS_THREAD_QUEUE.tail != NULL && OS_THREAD_QUEUE.tail->active_threads_link.next != NULL) {
        OSReport("OSCheckActiveThreads: Failed __OSActiveThreadQueue.tail == NULL || "
                 "__OSActiveThreadQueue.tail->linkActive.next == NULL in %d\n",
                 0x5ee);
        OSPanic(__FILE__, 0x5ee, "");
    }

    thread = OS_THREAD_QUEUE.head;

    while (thread != NULL) {
        rv++;
        if (thread->active_threads_link.next != NULL &&
            thread != thread->active_threads_link.next->active_threads_link.prev)
        {
            OSReport("OSCheckActiveThreads: Failed thread->linkActive.next == NULL || thread == "
                     "thread->linkActive.next->linkActive.prev in %d\n",
                     0x5f6);
            OSPanic(__FILE__, 0x5f6, "");
        }

        if (thread->active_threads_link.prev != NULL &&
            thread != thread->active_threads_link.prev->active_threads_link.next)
        {
            OSReport("OSCheckActiveThreads: Failed thread->linkActive.prev == NULL || thread == "
                     "thread->linkActive.prev->linkActive.next in %d\n",
                     0x5f8);
            OSPanic(__FILE__, 0x5f8, "");
        }

        if (*(u32*)thread->stack_end != OS_THREAD_STACK_MAGIC) {
            OSReport(
                "OSCheckActiveThreads: Failed *(thread->stackEnd) == OS_THREAD_STACK_MAGIC in %d\n",
                0x5fb);
            OSPanic(__FILE__, 0x5fb, "");
        }

        if (OS_PRIORITY_MIN > thread->effective_priority ||
            thread->effective_priority > OS_PRIORITY_MAX + 1)
        {
            OSReport("OSCheckActiveThreads: Failed OS_PRIORITY_MIN <= thread->priority && "
                     "thread->priority <= OS_PRIORITY_MAX+1 in %d\n",
                     0x5fe);
            OSPanic(__FILE__, 0x5fe, "");
        }

        if (thread->suspend_count < 0) {
            OSReport("OSCheckActiveThreads: Failed 0 <= thread->suspend in %d\n", 0x5ff);
            OSPanic(__FILE__, 0x5ff, "");
        }

        if (!CheckThreadQueue(&thread->join_queue)) {
            OSReport("OSCheckActiveThreads: Failed CheckThreadQueue(&thread->queueJoin) in %d\n",
                     0x600);
            OSPanic(__FILE__, 0x600, "");
        }

        switch (thread->state) {
        case OS_THREAD_STATE_READY:
            if (thread->suspend_count <= 0) {
                if (thread->queue != &RunQueue[thread->effective_priority]) {
                    OSReport("OSCheckActiveThreads: Failed thread->queue == "
                             "&RunQueue[thread->priority] in %d\n",
                             0x606);
                    OSPanic(__FILE__, 0x606, "");
                }

                if (!isMember(&RunQueue[thread->effective_priority], thread)) {
                    OSReport("OSCheckActiveThreads: Failed IsMember(&RunQueue[thread->priority], "
                             "thread) in %d\n",
                             0x607);
                    OSPanic(__FILE__, 0x607, "");
                }

                if (thread->effective_priority != __OSGetEffectivePriority(thread)) {
                    OSReport("OSCheckActiveThreads: Failed thread->priority == "
                             "__OSGetEffectivePriority(thread) in %d\n",
                             0x608);
                    OSPanic(__FILE__, 0x608, "");
                }
            }
            break;
        case OS_THREAD_STATE_RUNNING:
            if (thread->suspend_count > 0) {
                OSReport("OSCheckActiveThreads: Failed !IsSuspended(thread->suspend) in %d\n",
                         0x60c);
                OSPanic(__FILE__, 0x60c, "");
            }

            if (thread->queue != NULL) {
                OSReport("OSCheckActiveThreads: Failed thread->queue == NULL in %d\n", 0x60d);
                OSPanic(__FILE__, 0x60d, "");
            }

            if (thread->effective_priority != __OSGetEffectivePriority(thread)) {
                OSReport("OSCheckActiveThreads: Failed thread->priority == "
                         "__OSGetEffectivePriority(thread) in %d\n",
                         0x60e);
                OSPanic(__FILE__, 0x60e, "");
            }
            break;
        case OS_THREAD_STATE_WAITING:
            if (thread->queue == NULL) {
                OSReport("OSCheckActiveThreads: Failed thread->queue != NULL in %d\n", 0x611);
                OSPanic(__FILE__, 0x611, "");
            }

            if (CheckThreadQueue(thread->queue) == 0) {
                OSReport("OSCheckActiveThreads: Failed CheckThreadQueue(thread->queue) in %d\n",
                         0x612);
                OSPanic(__FILE__, 0x612, "");
            }

            if (!isMember(thread->queue, thread)) {
                OSReport("OSCheckActiveThreads: Failed IsMember(thread->queue, thread) in %d\n",
                         0x613);
                OSPanic(__FILE__, 0x613, "");
            }

            if (thread->suspend_count <= 0) {
                if (thread->effective_priority != __OSGetEffectivePriority(thread)) {
                    OSReport("OSCheckActiveThreads: Failed thread->priority == "
                             "__OSGetEffectivePriority(thread) in %d\n",
                             0x616);
                    OSPanic(__FILE__, 0x616, "");
                }
            } else if (thread->effective_priority != 32) {
                OSReport("OSCheckActiveThreads: Failed thread->priority == 32 in %d\n", 0x61a);
                OSPanic(__FILE__, 0x61a, "");
            }

            if (__OSCheckDeadLock(thread)) {
                OSReport("OSCheckActiveThreads: Failed !__OSCheckDeadLock(thread) in %d\n", 0x61c);
                OSPanic(__FILE__, 0x61c, "");
            }
            break;
        case OS_THREAD_STATE_DEAD:
            if (thread->owned_mutexes.head != NULL || thread->owned_mutexes.tail != NULL) {
                OSReport("OSCheckActiveThreads: Failed thread->queueMutex.head == NULL && "
                         "thread->queueMutex.tail == NULL in %d\n",
                         0x620);
                OSPanic(__FILE__, 0x620, "");
            }
            break;
        default:
            OSReport("OSCheckActiveThreads: Failed. unkown thread state (%d) of thread %p\n",
                     thread->state, thread);
            OSPanic(__FILE__, 0x626, "");
            break;
        }

        if (!__OSCheckMutexes(thread)) {
            OSReport("OSCheckActiveThreads: Failed __OSCheckMutexes(thread) in %d\n", 0x62b);
            OSPanic(__FILE__, 0x62b, "");
        }

        thread = thread->active_threads_link.next;
    }

    OSRestoreInterrupts(enabled);
    return rv;
}

/* 80342650-803426FC 33CF90 00AC+00 1/1 0/0 0/0 .text            OSClearStack */
void OSClearStack(u8 val) {
    u32* sp;
    u32* p;
    u32 pattern;

    pattern = ((u32)val << 24) | ((u32)val << 16) | ((u32)val << 8) | (u32)val;
    sp = (u32*)OSGetStackPointer();
    for (p = ((u32*)__OSCurrentThread->stack_end) + 1; p < sp; ++p) {
        *p = pattern;
    }
}

/* ############################################################################################## */
/* 804516D0-804516D8 000BD0 0008+00 0/0 2/1 0/0 .sbss            None */
extern u8 data_804516D0[8];
u8 data_804516D0[8] ALIGN_DECL(8);