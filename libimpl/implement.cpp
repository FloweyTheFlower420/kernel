#include <bits/user_implement.h>
#include <config.h>
#include <panic.h>
#include MALLOC_IMPL_PATH

namespace std::detail
{
    void* malloc(size_t size) { return ::alloc::malloc(size); }
    void* aligned_malloc(size_t size, size_t align) { return ::alloc::aligned_malloc(size, align); }
    void free(void* ptr) { return ::alloc::free(ptr); }

    namespace errors
    {
        [[noreturn]] void __stdexcept_out_of_range() { std::panic("stdexcept out of range"); }
        [[noreturn]] void __stdexcept_bad_alloc() { std::panic("stdexcept bad alloc"); }
        [[noreturn]] void __stdexcept_bad_variant_access() { std::panic("stdexcept bad variant access"); }
        [[noreturn]] void __printf_argument_notfound() { std::panic("what"); }
        [[noreturn]] void __printf_undefined_specifier_for_length() { std::panic("printf undefined specifier for length"); }
        [[noreturn]] void __halt()
        {
            while (1)
                __asm__ __volatile__("hlt");
        }
    } // namespace errors
} // namespace std::detail
