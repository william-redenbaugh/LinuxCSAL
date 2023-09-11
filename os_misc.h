#ifndef _OS_MISC_H
#define _OS_MISC_H

#include "stdio.h"

#define println(e) \
    printf(e);     \
    printf("\n")

void OS_ASSERT(bool valid);

#define os_printf(e, ...) printf(e)

#define os_println(e, ...) \
    printf(e);             \
    printf("\n")
#endif