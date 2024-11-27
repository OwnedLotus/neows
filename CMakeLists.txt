cmake_minimum_required(VERSION 3.30)
project(neows_visualization)

include(FetchContent)
FetchContent_Declare(
        json
        GIT_REPOSITORY https://github.com/nlohmann/json.git
        GIT_TAG v3.11.3
)

FetchContent_Declare(
    cpp-httplib
    GIT_REPOSITORY https://github.com/yhirose/cpp-httplib.git
    GIT_TAG v0.18.1
)

FetchContent_Declare(
        raylib
        URL https://github.com/raysan5/raylib/archive/refs/tags/5.5.tar.gz
)

FetchContent_Declare(
        catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v3.7.1
)


FetchContent_MakeAvailable(catch2 raylib cpp-httplib json)

set(CMAKE_CXX_STANDARD 23)

set(GCC_COVERAGE_COMPILE_FLAGS "-Wall -Werror")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")

include_directories(src)

add_executable(Main src/main.cpp src/Neo.cpp src/Diameter.cpp
                    src/CloseApproach.cpp src/NeosCurrier.cpp)

add_executable(Tests tests/test.cpp src/Neo.cpp src/Diameter.cpp
                     src/CloseApproach.cpp src/NeosCurrier.cpp)

target_link_libraries(Main PUBLIC raylib nlohmann_json httplib)
target_link_libraries(Tests PRIVATE Catch2::Catch2WithMain raylib nlohmann_json
                                    httplib)


set(GLFW_BUILD_WAYLAND ON CACHE BOOL "Build with Wayland support")
set(GLFW_BUILD_X11 ON CACHE BOOL "Build with X11 support")

include(CTest)
include(Catch)
catch_discover_tests(Tests)
