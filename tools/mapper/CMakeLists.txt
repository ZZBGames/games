set(MAPPER_SOURCES
    mapper.cpp
    ImageComparator.cpp
    TileMapper.cpp)

add_executable(mapper ${MAPPER_SOURCES})
target_link_libraries(mapper sfml-graphics zzb-core)

install(TARGETS mapper RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX}/tools)
