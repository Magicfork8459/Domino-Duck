cmake_minimum_required(VERSION 3.8)

file(GLOB SOURCE
	${PROJECT_SOURCE_DIR}/GlobalLogger/*.cpp
	${PROJECT_SOURCE_DIR}/GlobalLogger/*.h
)

add_library(GlobalLogger ${SOURCE})

include_directories(
	${Boost_INCLUDE_DIRS}
)

target_link_libraries(GlobalLogger
	${Boost_LIBRARIES}
)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET GlobalLogger PROPERTY CXX_STANDARD 20)
endif()