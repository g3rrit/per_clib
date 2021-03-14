#ifndef PER_TEST_COMMON_H_
#define PER_TEST_COMMON_H_

#define SNOW_ENABLED

#include "per_std.h"
#include "per_config.h"
#include "snow.h"

#define PER_TEST_MAIN \
    snow_main_decls; \
    int main(int argc, char **argv) { \
                                                \
        per_config_t const * per_config = per_libc_config(); \
        per_init(per_config); \
                                 \
        return snow_main_function(argc, argv); \
 \
        per_cleanup(); \
    }

#endif // PER_TEST_COMMON_H_