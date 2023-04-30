cmake_minimum_required(VERSION 3.24)
project(project_name VERSION 1.0)

include(FetchContent)

set(BUILD_SHARED_LIBS OFF)
# SFML
FetchContent_Declare(
        SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.5.1
)
FetchContent_MakeAvailable(SFML)

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
        interface/assetManager.cpp
        interface/assetManager.h
        interface/menu/button.cpp
        interface/menu/programLogo.cpp
        functions.cpp functions.h
        interface/tamagotchiScreen/indicator.cpp
        interface/tamagotchiScreen/indicator.h
        tests/assetManagerTest.cpp tests/regexTest.cpp structures/tamagotchi.cpp structures/food.cpp mechanics/tamagotchiMechanics.cpp mechanics/tamagotchiMechanics.h mechanics/tamagotchiMechanics.h structures/score.cpp structures/score.h structures/score.h mechanics/foodMechanics.cpp mechanics/foodMechanics.h)

target_link_libraries(
        april
        sfml-graphics
        gtest_main
)