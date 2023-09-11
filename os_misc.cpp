#include "os_misc.h"
#include "stdlib.h"
#include "global_includes.h"
void OS_ASSERT(bool valid)
{
    if (valid)
    {
        for (;;)
        {
            os_thread_sleep_s(1);
        }
    }
}