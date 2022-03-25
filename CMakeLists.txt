cmake_minimum_required(VERSION 3.10)

project(ColonialSpace VERSION 1.0)
set(CMAKE_BUILD_TYPE Release)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

if(FALSE)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pg")
SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -pg")
SET(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -pg")
endif()

include_directories("inc")
set(SOURCES
	src/common.cpp
	src/log.cpp
	src/universe.cpp
	src/faction.cpp
	src/system.cpp
	src/planet.cpp
	src/colony.cpp
	src/fleet.cpp
	src/ship.cpp)

if(FALSE)
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
endif()
add_library(Modules SHARED ${SOURCES})

add_executable(ColonialSpace main.cpp)
target_compile_options(ColonialSpace PRIVATE -Wall)
target_link_libraries(ColonialSpace Modules)
if(FALSE)
target_link_libraries(ColonialSpace sfml-graphics sfml-audio Modules)
endif()
