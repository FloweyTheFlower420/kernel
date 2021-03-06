#ifndef __ARCH_X86_PAGING_PGFAULT_H__
#define __ARCH_X86_PAGING_PGFAULT_H__
#include <cstdint>
#include <panic.h>

namespace paging
{
    void handle_page_fault(uint64_t id, void* stackpointer)
    {
        // if this is kernel space code this is very bad
        // if it is a module, unload
        // the problem is determine if it is a module

        std::panic("unexcepted page fault");
    }
}; // namespace paging

#endif
