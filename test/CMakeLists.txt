if (NOT GTEST_FOUND)
    message(FATAL_ERROR "Google Test is needed to build the tests.")
endif ()

set(UNIT_TEST_SOURCES
    core/DimensionTest.cpp
    core/InsetsTest.cpp
    core/TilesetTest.cpp)

add_executable(unittest ${UNIT_TEST_SOURCES})
target_link_libraries(unittest gtest_main pthread gtest zzb-core)

add_custom_target(tests unittest DEPENDS unittest COMMENT "Running unit tests...")

set(TEST_RESOURCES
    res/map.png
    res/tileset.png)
file(COPY ${TEST_RESOURCES} DESTINATION res)
