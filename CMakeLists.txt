cmake_minimum_required(VERSION 3.0)
project(games)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

# Build games
set(BUILD_RICK TRUE CACHE BOOL "Build Rick Dangerous.")
set(BUILD_TESTS TRUE CACHE BOOL "Build tests.")

find_package(SFML)
find_package(Rapidjson)
find_package(GTest)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "RelWithDebInfo" CACHE STRING "Choose the type of build, options are: Debug Release RelWithDebInfo MinSizeRel." FORCE)
endif ()

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")
    if (CMAKE_CXX_COMPILER_VERSION VERSION_LESS "4.7.0")
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
    else ()
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
    endif ()
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror -std=c++11")
endif ()

include_directories(${SFML_INCLUDE_DIR})
include_directories(${RAPIDJSON_INCLUDE_DIRS})
include_directories(${GTEST_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

if (BUILD_RICK)
    add_subdirectory(src/core)
    add_subdirectory(src/rick)
    add_subdirectory(config/rick)
    add_subdirectory(res/rick)
endif ()

if (BUILD_TESTS)
    add_subdirectory(test)
endif ()
