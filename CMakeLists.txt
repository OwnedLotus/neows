cmake_minimum_required(VERSION 3.30)
project(neows_visualization)

set(JSON_VERSION 3.11.3)
#find_package(nlohmann_json QUIET)
#if(NOT nlohmann_json)
  include(FetchContent)
  FetchContent_Declare(
    json
    URL https://github.com/nlohmann/json/releases/download/v${JSON_VERSION}/json.tar.xz
  )
  FetchContent_MakeAvailable(json)
#endif()

set(CPP_HTTPLIB_VERSION 0.18.1)
#find_package(cpp-httplib ${CPP_HTTPLIB_VERSION} QUIET)
#if(NOT cpp-httplib_FOUND)
  include(FetchContent)
  FetchContent_Declare(
    cpp-httplib
    GIT_REPOSITORY https://github.com/yhirose/cpp-httplib.git
    GIT_TAG v${CPP_HTTPLIB_VERSION}
  )
  FetchContent_MakeAvailable(cpp-httplib)
#endif()

# raylib
set(RAYLIB_VERSION 5.0)
find_package(raylib ${RAYLIB_VERSION} QUIET)
if(NOT raylib_FOUND)
  include(FetchContent)
  FetchContent_Declare(
    raylib
    DOWNLOAD_EXTRACT_TIMESTAMP OFF
    URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
  )
  FetchContent_GetProperties(raylib)
  FetchContent_MakeAvailable(raylib)
endif()

# pull in desired version of catch through cmake automatically, make it
# available
set(CATCH2_VERSION 3.7.1)
find_package(catch2 QUIET)
if(NOT catch2_FOUND)
  include(FetchContent)
  FetchContent_Declare(
    catch2
    URL https://github.com/catchorg/Catch2/archive/refs/tags/v${CATCH2_VERSION}.tar.gz
  )
  FetchContent_MakeAvailable(catch2)
endif()

set(CMAKE_CXX_STANDARD 23)

set(GCC_COVERAGE_COMPILE_FLAGS "-Wall -Werror")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")

include_directories(src)

add_executable(Main src/main.cpp src/Neo.cpp src/Diameter.cpp
                    src/CloseApproach.cpp src/NeosCurrier.cpp)

add_executable(Tests tests/test.cpp src/Neo.cpp src/Diameter.cpp
                     src/CloseApproach.cpp src/NeosCurrier.cpp)

target_link_libraries(Main PUBLIC raylib nlohmann_json cpp-httplib)
target_link_libraries(Tests PRIVATE Catch2::Catch2WithMain raylib nlohmann_json
                                    cpp-httplib)

include(CTest)
include(Catch)
catch_discover_tests(Tests)
