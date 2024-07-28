cmake_minimum_required(VERSION 3.30)
project(neows_visualization)

# nlohmann/json https://json.nlohmann.me/integration/cmake/#supporting-both
# include(FetchContent) FetchContent_Declare( json URL
# https://github.com/nlohmann/json/releases/download/v3.11.3/json.tar.xz)
# FetchContent_MakeAvailable(json)
find_package(nlohmann_json)

# https://github.com/RobLoach/raylib-cpp/blob/master/projects/CMake/CMakeLists.txt
# reference material

# raylib find_package(raylib QUIET) if(NOT raylib_FOUND) include(FetchContent)
# FetchContent_Declare( raylib GIT_REPOSITORY
# https://github.com/raysan5/raylib.git GIT_TAG 5.0 GIT_SHALLOW 1)
# FetchContent_MakeAvailable(raylib) endif()

find_package(httplib)

# raylib
find_package(raylib QUIET)

# pull in desired version of catch through cmake automatically, make it
# available
find_package(Catch2 QUIET)

set(CMAKE_CXX_STANDARD 23)

set(GCC_COVERAGE_COMPILE_FLAGS "-Wall -Werror")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")

include_directories(src)

add_executable(Main src/main.cpp src/Neo.cpp src/Neo.hpp src/Diameter.hpp
                    src/CloseApproach.hpp)

add_executable(Tests tests/test.cpp src/Neo.cpp src/Neo.hpp src/Diameter.hpp
                     src/CloseApproach.hpp)

target_link_libraries(Main PUBLIC raylib nlohmann_json)
target_link_libraries(Tests PRIVATE Catch2::Catch2WithMain raylib nlohmann_json)

include(CTest)
include(Catch)
catch_discover_tests(Tests)
