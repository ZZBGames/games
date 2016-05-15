set(RICK_SOURCES
    rickdangerous.cpp
    RickApplication.cpp
    RickConfiguration.cpp
    RickContext.cpp
    RickHallOfFameState.cpp
    RickHighscore.cpp
    RickHighscoreList.cpp
    RickState.cpp
    RickStateStack.cpp
    RickText.cpp
    RickTextBuilder.cpp
    RickTileset.cpp
    RickTitleState.cpp)

add_executable(rickdangerous ${RICK_SOURCES})
target_link_libraries(rickdangerous sfml-graphics sfml-window sfml-system zzb-core)

install(TARGETS rickdangerous RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX}/rick)
