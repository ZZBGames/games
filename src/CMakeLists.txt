set(RICK_SOURCES
    Dimension.cpp
    ExceptionBuilder.cpp
    Insets.cpp
    State.cpp
    StateStack.cpp
    StateStackEvent.cpp
    StateStackEventList.cpp
    Tileset.cpp
    rick/rickdangerous.cpp
    rick/RickApplication.cpp
    rick/RickConfiguration.cpp
    rick/RickContext.cpp
    rick/RickHallOfFameState.cpp
    rick/RickHighscore.cpp
    rick/RickHighscoreList.cpp
    rick/RickState.cpp
    rick/RickStateStack.cpp
    rick/RickText.cpp
    rick/RickTextBuilder.cpp
    rick/RickTileset.cpp
    rick/RickTitleState.cpp)

add_executable(rickdangerous ${RICK_SOURCES})
target_link_libraries(rickdangerous sfml-graphics sfml-window sfml-system)

install(TARGETS rickdangerous RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX})
