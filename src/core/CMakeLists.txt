set(CORE_SOURCES
    Dimension.cpp
    Insets.cpp
    State.cpp
    StateStack.cpp
    StateStackEvent.cpp
    StateStackEventList.cpp
    Tileset.cpp)

add_library(zzb-core STATIC ${CORE_SOURCES})
set_target_properties(zzb-core PROPERTIES OUTPUT_NAME zzb-core)

target_link_libraries(zzb-core sfml-graphics)
