cmake_minimum_required(VERSION 3.20)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VESRION 0.0.${PATCH_VERSION})

project(ip_filter LANGUAGES CXX VERSION ${PROJECT_VESRION})

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(ip_filter main.cpp iphelper.h)

# ======== GOOGLE_TEST start ===========
enable_testing()
include(GoogleTest)

add_executable(test_iphelper test_iphelper.cpp iphelper.h)
target_link_libraries(test_iphelper
    gtest
    gtest_main
)

gtest_discover_tests(test_iphelper)

# ======== GOOGLE_TEST end ===========

if (MSVC)
    target_compile_options(ip_filter PRIVATE
        /W4
    )
else ()
    target_compile_options(ip_filter PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
endif()

install(TARGETS ip_filter RUNTIME DESTINATION bin)


# ======== DEB pack start ===========
set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT pon79job@gmail.com)

include(CPack)
# ======== DEB pack end ===========
