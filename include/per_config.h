#ifndef PER_CONFIG_H_
#define PER_CONFIG_H_

#include "per_util.h"

typedef struct per_config_t {
    per_rcode (*alloc_fn)(uint size, void ** res);
    void (*free_fn)();
    void (*memcpy_fn)(void * dst, void * src, uint size);
} per_config_t;

per_config_t const * per_config_get();

#if defined(INCLUDE_GLIBC)

per_config_t const * per_libc_config();

#endif // defined(INCLUDE_GLIBC)

#endif