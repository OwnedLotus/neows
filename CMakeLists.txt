cmake_minimum_required(VERSION 3.30)
project(neows_visualization)

# nlohmann/json https://json.nlohmann.me/integration/cmake/#supporting-both
# include(FetchContent) FetchContent_Declare( json URL
# https://github.com/nlohmann/json/releases/download/v3.11.3/json.tar.xz)
# FetchContent_MakeAvailable(json)
find_package(nlohmann_json QUIET)

# https://github.com/RobLoach/raylib-cpp/blob/master/projects/CMake/CMakeLists.txt
# reference material

# raylib find_package(raylib QUIET) if(NOT raylib_FOUND) include(FetchContent)
# FetchContent_Declare( raylib GIT_REPOSITORY
# https://github.com/raysan5/raylib.git GIT_TAG 5.0 GIT_SHALLOW 1)
# FetchContent_MakeAvailable(raylib) endif()

find_package(httplib)

# raylib-cpp
find_package(raylib_cpp QUIET)
if(NOT raylib_cpp_FOUND)
  include(FetchContent)
  FetchContent_Declare(
    raylib_cpp
    GIT_REPOSITORY https://github.com/RobLoach/raylib-cpp.git
    GIT_TAG v5.0.1)
  FetchContent_MakeAvailable(raylib_cpp)
endif()

# pull in desired version of catch through cmake automatically, make it
# available
find_package(Catch2 QUIET)

set(CMAKE_CXX_STANDARD 23)

set(GCC_COVERAGE_COMPILE_FLAGS "-Wall -Werror")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")

include_directories(src)

add_executable(Main src/main.cpp)

add_executable(Tests tests/test.cpp)

target_link_libraries(Main PUBLIC raylib_cpp nlohmann_json)
target_link_libraries(Tests PRIVATE Catch2::Catch2WithMain raylib_cpp
                                    nlohmann_json)

include(CTest)
include(Catch)
catch_discover_tests(Tests)
