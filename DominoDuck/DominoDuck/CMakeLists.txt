# CMakeList.txt : CMake project for DominoDuck, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

file(GLOB SOURCE
	${PROJECT_SOURCE_DIR}/DominoDuck/*.cpp
	${PROJECT_SOURCE_DIR}/DominoDuck/*.h
)

# Add source to this project's executable.
add_executable (DominoDuck ${SOURCE})

include_directories($ENV{SDL_ROOT}/include)

set(CMAKE_PREFIX_PATH $ENV{SDL_ROOT}/lib/x64)

find_library( SDL
	NAMES SDL2
	HINTS "${CMAKE_PREFIX_PATH}/lib/x64"
)

find_library( SDL_MAIN
	NAMES SDL2main
	HINTS "${CMAKE_PREFIX_PATH}/lib/x64"
)

set(LIBS
	${SDL}
	${SDL_MAIN}
)

target_link_libraries(DominoDuck
	${LIBS}
)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET DominoDuck PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
