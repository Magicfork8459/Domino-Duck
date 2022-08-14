# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project ("DominoDuck")

file(TO_CMAKE_PATH $ENV{BOOST_ROOT} BOOST_ROOT)

set(Boost_USE_STATIC_LIBS		ON)
set(Boost_USE_MULTITHREADED		ON)
set(Boost_USE_STATIC_RUNTIME	ON)

find_package(Boost 1.79.0 COMPONENTS describe mp11 json log)

# Include sub-projects.
add_subdirectory ("DominoDuck")
add_subdirectory("GlobalLogger")