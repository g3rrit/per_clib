#include "per_util.h"
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
static per_rcode per_static_libc_alloc(uint size, void ** res)
{
    void * _res = malloc((size_t) size);
    if (res == 0) {
        return PER_R_ALLOC_FAILURE;
    }

    *res = _res;

    return PER_R_SUCCESS;
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
