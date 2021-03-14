#include "per_std.h"
#include "per_config.h"

#define PER_OFFSETOF( type, member ) ( (unsigned long long) &( ( (type *) 0 )->member ) )


extern per_config_t PER_STATIC_CONFIG;

void per_init(per_config_t const * per_config)
{
    PER_STATIC_CONFIG.alloc_fn = per_config->alloc_fn;
    PER_STATIC_CONFIG.free_fn = per_config->free_fn;
    PER_STATIC_CONFIG.memcpy_fn = per_config->memcpy_fn;
}

void per_cleanup()
{

}

// ----- MEMORY -----

typedef struct per_ptr_t {
    u32 rc;
    u8 data[];
} per_ptr_t;

void * per_alloc(uint size)
{
    per_config_t const * per_config = per_config_get();
    per_ptr_t * per_ptr = per_config->alloc_fn(sizeof(per_ptr_t) + size);

    per_ptr->rc = 1;

    return &per_ptr->data;
}

void per_free(void * ptr)
{
    per_config_t const * per_config = per_config_get();
    per_ptr_t * per_ptr = (per_ptr_t*) ptr - PER_OFFSETOF(per_ptr_t, data);

    if (per_ptr->rc > 1) {
        per_ptr->rc--;
        return;
    }

    per_config->free_fn(per_ptr->data);
}

void * per_share(void * ptr)
{
    per_ptr_t * per_ptr = (per_ptr_t*) ptr - PER_OFFSETOF(per_ptr_t, data);
    per_ptr->rc++;
    return ptr;
}


void per_memcpy(void * dst, void * src, uint size)
{
    per_config_t const * per_config = per_config_get();

    per_config->memcpy_fn(dst, src, size);
}