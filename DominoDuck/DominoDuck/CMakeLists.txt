cmake_minimum_required (VERSION 3.8)

file(GLOB SOURCE
	${PROJECT_SOURCE_DIR}/DominoDuck/*.cpp
	${PROJECT_SOURCE_DIR}/DominoDuck/*.hpp
	${PROJECT_SOURCE_DIR}/DominoDuck/*.h
)

add_executable (DominoDuck ${SOURCE})
add_dependencies(DominoDuck GlobalLogger)

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

include_directories(
	$ENV{SDL_ROOT}/include
	${Boost_INCLUDE_DIRS}
	${PROJECT_SOURCE_DIR}/GlobalLogger
)

#XXX Shouldn't have to use this, must be doing something wrong with the find_package for boost
target_link_directories(DominoDuck PUBLIC
	${BOOST_ROOT}/stage/lib
)

target_link_libraries(DominoDuck
	${LIBS}
	${Boost_LIBRARIES}
	GlobalLogger
)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET DominoDuck PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
