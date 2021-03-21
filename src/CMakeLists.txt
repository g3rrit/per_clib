
set(SOURCES
    "${PROJECT_SOURCE_DIR}/src/per_util.c"
    "${PROJECT_SOURCE_DIR}/src/per_config.c"
)

set(EXTERNAL_INCLUDES
    "${PROJECT_SOURCE_DIR}/include/per_util.h"
    "${PROJECT_SOURCE_DIR}/include/per_config.h"
)

configure_file (
    "${PROJECT_SOURCE_DIR}/src/internal_include/per_version.h.in"
    "${PROJECT_BINARY_DIR}/src/internal_include/per_version.h"
)

set(INTERAL_INCLUDES
    "${PROEJECT_SOURCE_DIR}/src/internal_include/per_version.h"
)

add_library(per_clib SHARED ${SOURCES})

set_target_properties(per_clib PROPERTIES 
    VERSION ${PROJECT_VERSION}
    PUBLIC_HEADER "${EXTERNAL_INCLUDES}"
)

target_include_directories(per_clib PUBLIC "${PROJECT_SOURCE_DIR}/include")
target_include_directories(per_clib PRIVATE "${PROJECT_SOURCE_DIR}/src/internal_include")

target_compile_definitions(per_clib PUBLIC INCLUDE_GLIBC)