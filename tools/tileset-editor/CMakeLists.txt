set(TILESET_EDITOR_SOURCES
    tileset.cpp)

add_executable(tileset-editor ${TILESET_EDITOR_SOURCES})
target_link_libraries(tileset-editor sfml-graphics zzb-core)

install(TARGETS tileset-editor RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX}/tools)
