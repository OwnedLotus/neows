# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

# If CMAKE_DISABLE_SOURCE_CHANGES is set to true and the source directory is an
# existing directory in our source tree, calling file(MAKE_DIRECTORY) on it
# would cause a fatal error, even though it would be a no-op.
if(NOT EXISTS "/home/jonahr/Documents/Code/CCPP/neows_visualization/_deps/raylib_cpp-src")
  file(MAKE_DIRECTORY "/home/jonahr/Documents/Code/CCPP/neows_visualization/_deps/raylib_cpp-src")
endif()
file(MAKE_DIRECTORY
  "/home/jonahr/Documents/Code/CCPP/neows_visualization/_deps/raylib_cpp-build"
  "/home/jonahr/Documents/Code/CCPP/neows_visualization/_deps/raylib_cpp-subbuild/raylib_cpp-populate-prefix"
  "/home/jonahr/Documents/Code/CCPP/neows_visualization/_deps/raylib_cpp-subbuild/raylib_cpp-populate-prefix/tmp"
  "/home/jonahr/Documents/Code/CCPP/neows_visualization/_deps/raylib_cpp-subbuild/raylib_cpp-populate-prefix/src/raylib_cpp-populate-stamp"
  "/home/jonahr/Documents/Code/CCPP/neows_visualization/_deps/raylib_cpp-subbuild/raylib_cpp-populate-prefix/src"
  "/home/jonahr/Documents/Code/CCPP/neows_visualization/_deps/raylib_cpp-subbuild/raylib_cpp-populate-prefix/src/raylib_cpp-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/jonahr/Documents/Code/CCPP/neows_visualization/_deps/raylib_cpp-subbuild/raylib_cpp-populate-prefix/src/raylib_cpp-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/jonahr/Documents/Code/CCPP/neows_visualization/_deps/raylib_cpp-subbuild/raylib_cpp-populate-prefix/src/raylib_cpp-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
