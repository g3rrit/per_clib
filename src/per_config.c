#include "per_std.h"
#include "per_config.h"

per_config_t PER_STATIC_CONFIG;

per_config_t const * per_config_get()
{
    return &PER_STATIC_CONFIG;
}

#if defined(INCLUDE_GLIBC)

#include <stdlib.h>
#include <string.h>

// TODO: handle cases where we can't cast uint to size_t
static void * per_static_libc_alloc(uint size)
{
    return malloc((size_t) size);
}

static void per_static_libc_memcpy(void * dst, void * src, uint size)
{
    memcpy(dst, src, (size_t)size);
}

per_config_t const * per_libc_config()
{
    static per_config_t per_config = {
        .alloc_fn = &per_static_libc_alloc,
        .free_fn = &free,
        .memcpy_fn = &per_static_libc_memcpy,
    };

    return &per_config;
}

#endif // defined(INCLUDE_GLIBC)
