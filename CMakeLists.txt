cmake_minimum_required(VERSION 3.19)

set(PER_VERSION_MAJOR 1 CACHE STRING "The major version number")
set(PER_VERSION_MINOR 0 CACHE STRING "The minor version number")
set(PER_VERSION_PATCH 0 CACHE STRING "The patch version number")

set(PER_VERSION "${PER_VERSION_MAJOR}.${PER_VERSION_MINOR}.${PER_VERSION_PATCH}")

project(PER_CLIB
        VERSION ${PER_VERSION}
        DESCRIPTION "A easy to use c library"
        LANGUAGES C)

# Only do these if this is the main project, and not if it is included through add_subdirectory
if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)

    # Optionally set things like CMAKE_CXX_STANDARD, CMAKE_POSITION_INDEPENDENT_CODE here

    # Let's nicely support folders in IDEs
    set_property(GLOBAL PROPERTY USE_FOLDERS ON)

    # Testing only available if this is the main app
    # Note this needs to be done in the main CMakeLists
    # since it calls enable_testing, which must be in the
    # main CMakeLists.
    include(CTest)

    # Docs only available if this is the main app
    find_package(Doxygen)
    if(Doxygen_FOUND)
        add_subdirectory(docs)
    else()
        message(STATUS "Doxygen not found, not building docs")
    endif()
endif()

add_subdirectory(src)

# Testing only available if this is the main app
# Emergency override MODERN_CMAKE_BUILD_TESTING provided as well
if((CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME OR MODERN_CMAKE_BUILD_TESTING)
    AND BUILD_TESTING)

    add_subdirectory(tests)
endif()
