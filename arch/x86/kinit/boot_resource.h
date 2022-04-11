#ifndef __KERNEL_ARCH_X86_KINIT_BOOT_RESOURCE_H__
#define __KERNEL_ARCH_X86_KINIT_BOOT_RESOURCE_H__
#include "stivale2.h"
#include <cstddef>
#include <cstdint>

class boot_resource
{
    uint64_t phys_addr;
    uint64_t ksize;
    std::size_t mmap_length;
    stivale2_mmap_entry mmap_entries[0x100];

public:
    boot_resource(stivale2_struct*);
    static boot_resource& instance();

    constexpr uint64_t kernel_phys_addr() { return phys_addr; }
    constexpr uint64_t kernel_size() { return ksize; }

    template <typename T>
    void iterator_mmap(T cb)
    {
        for (int i = 0; i < mmap_length; i++)
            cb(mmap_entries[i]);
    }
};

#endif
