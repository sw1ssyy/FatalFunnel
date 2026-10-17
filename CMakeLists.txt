cmake_minimum_required(VERSION 4.3)
project(TopDownShooter)

set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS src/*.cpp src/*.h)
add_executable(TopDownShooter ${SOURCES})

# raylib (prebuilt, vendored in external/raylib)
set(RAYLIB_DIR ${CMAKE_SOURCE_DIR}/external/raylib)

target_include_directories(TopDownShooter PRIVATE ${RAYLIB_DIR}/include)

# Link the static raylib library
target_link_libraries(TopDownShooter PRIVATE ${RAYLIB_DIR}/lib/raylib.lib)

# System libraries raylib depends on when linked statically on Windows
if (WIN32)
    target_link_libraries(TopDownShooter PRIVATE winmm gdi32 opengl32 shell32 user32)
endif ()
