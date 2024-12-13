# neows
I have refactored the CMakeLists.txt that it will work correctly using FetchContent and Cmake

To build this project use cmake.
To build on commandline as I do, use the command:
      cmake CMakeLists.txt && make

then to run:
      ./Main

requires X11 currently for raylib

Packages utilized in this projects are enumerated in the CMakeLists.txt file as well as hereafter:
Raylib -- https://github.com/raysan5/raylib
httplib-cpp -- https://github.com/yhirose/cpp-httplib
json -- https://github.com/nlohmann/json
catch2 -- https://github.com/catchorg/Catch2
