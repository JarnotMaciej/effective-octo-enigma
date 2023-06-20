cmake_minimum_required(VERSION 3.24)
project(tamagotchi VERSION 1.0)

include(FetchContent)

set(BUILD_SHARED_LIBS OFF)
# SFML
FetchContent_Declare(
        SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.5.1
)
FetchContent_MakeAvailable(SFML)
# ------------------

# Google Test
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG v1.13.0
)
FetchContent_MakeAvailable(googletest)
# ------------------

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED true)

add_executable(
        april
        main.cpp
        interface/screen.cpp
        interface/screen.h
        mechanics/assetManager.cpp
        mechanics/assetManager.h
        interface/menu/button.cpp
        functions.cpp functions.h
        interface/tamagotchiScreen/indicator.cpp
        interface/tamagotchiScreen/indicator.h
        tests/assetManagerTest.cpp tests/regexTest.cpp
        structures/tamagotchi.cpp structures/food.cpp
        mechanics/tamagotchiMechanics.cpp mechanics/tamagotchiMechanics.h
        mechanics/tamagotchiMechanics.h structures/score.cpp
        structures/score.h structures/score.h
        mechanics/foodMechanics.cpp mechanics/foodMechanics.h
        structures/cat.cpp structures/cat.h
        interface/menu/menu.cpp interface/menu/menu.h
        interface/tamagotchiScreen/topBar.cpp interface/tamagotchiScreen/topBar.h
        interface/tamagotchiScreen/bottomBar.cpp interface/tamagotchiScreen/bottomBar.h
        interface/keycapButton.cpp interface/keycapButton.h
        interface/tamagotchiScreen/tamagotchiScreen.cpp interface/tamagotchiScreen/tamagotchiScreen.h
        interface/tamagotchiScreen/indicatorBar.cpp interface/tamagotchiScreen/indicatorBar.h
        interface/scoreboard/scoreboard.cpp interface/scoreboard/scoreboard.h
        interface/minigame/minigame.cpp interface/minigame/minigame.h
        interface/minigame/flyingElement.cpp interface/minigame/flyingElement.h
        interface/minigame/coin.cpp interface/minigame/coin.h
        mechanics/game.cpp mechanics/game.h
        interface/minigame/gameOver.cpp interface/minigame/gameOver.h
        interface/minigame/minigameConnector.cpp interface/minigame/minigameConnector.h interface/tamagotchiScreen/foodStuff/foodButton.cpp interface/tamagotchiScreen/foodStuff/foodButton.h interface/tamagotchiScreen/foodStuff/foodBar.cpp interface/tamagotchiScreen/foodStuff/foodBar.h interface/exit/exitScreen.cpp interface/exit/exitScreen.h mechanics/errorHandler.cpp mechanics/errorHandler.h)

target_link_libraries(
        april
        sfml-graphics
        sfml-window
        sfml-system
        sfml-audio
        gtest_main
)