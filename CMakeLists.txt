cmake_minimum_required(VERSION 4.3)
project(TopDownShooter)

set(CMAKE_CXX_STANDARD 20)

add_executable(TopDownShooter src/main.cpp
        src/Utils/TextureManager.cpp
        src/Utils/TextureManager.h
        src/Utils/FontManager.cpp
        src/Utils/FontManager.h
        src/Constants/AssetConstants.h
        src/States/StateManager.cpp
        src/States/StateManager.h
        src/States/StateID.h
        src/States/IState.h
        src/States/GameState.h
        src/States/MenuState.cpp
        src/States/MenuState.h
        src/States/GameState.cpp
        src/Utils/components/Button.cpp
        src/Utils/components/Button.h
        src/Constants/GameConstants.h
        src/Characters/Character.cpp
        src/Characters/Character.h
        src/Utils/Animation2D.cpp
        src/Utils/Animation2D.h
        src/Utils/InputManager.cpp
        src/Utils/InputManager.h
        src/Utils/DrawUtils.cpp
        src/Utils/DrawUtils.h)

# raylib (prebuilt, vendored in external/raylib)
set(RAYLIB_DIR ${CMAKE_SOURCE_DIR}/external/raylib)

target_include_directories(TopDownShooter PRIVATE ${RAYLIB_DIR}/include)

# Link the static raylib library
target_link_libraries(TopDownShooter PRIVATE ${RAYLIB_DIR}/lib/raylib.lib)

# System libraries raylib depends on when linked statically on Windows
if (WIN32)
    target_link_libraries(TopDownShooter PRIVATE winmm gdi32 opengl32 shell32 user32)
endif ()
