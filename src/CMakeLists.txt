set(RICK_SOURCES
    State.cpp
    StateStack.cpp
    StateStackEvent.cpp
    StateStackEventList.cpp
    rick/rickdangerous.cpp
    rick/RickApplication.cpp
    rick/RickConfiguration.cpp
    rick/RickContext.cpp
    rick/RickState.cpp
    rick/RickStateStack.cpp
    rick/RickTitleState.cpp)

add_executable(rickdangerous ${RICK_SOURCES})
target_link_libraries(rickdangerous sfml-graphics sfml-window sfml-system)

install(TARGETS rickdangerous RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX})
