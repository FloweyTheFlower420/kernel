#ifndef __ARCH_X86_CONTEXT_H__
#define __ARCH_X86_CONTEXT_H__
#include <cstdint>

// this is a fully restorable execution context
struct context
{
    enum registers
    {
        RAX = 0,
        RBX,
        RCX,
        RDX,
        RSI,
        RDI,
        R8,
        R9,
        R10,
        R11,
        R12,
        R13,
        R14,
        R15,
        RBP
    };

    uint64_t rip;
    uint64_t cs;
    uint64_t rflags;
    uint64_t rsp;
    uint64_t ss;
    uint64_t rgp[15];

    // yoinked from intel docs
    // high
    // 0x00: SS             <- RSP before interrupt
    // 0x08: RSP
    // 0x10: RFLAGS
    // 0x18: CS
    // 0x20: RIP
    // 0x28: ERROR ?? 0
    // 0x30: interrupt #
};
#endif
