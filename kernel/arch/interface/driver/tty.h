#ifndef __TTY_STARTER_DRIVE__
#define __TTY_STARTER_DRIVE__
#include "utils.h"
#define KDEBUG

namespace driver
{
    class tty_startup_driver
    {
    public:
        virtual void putc(char c) = 0;
    };

    void set_tty_startup_driver(tty_startup_driver*);
} // namespace driver

#endif
