cmake_minimum_required(VERSION 3.1)

project(AsepriteToSFMLImage)

option(ZLIB_TESTS  "Compile with zlib examples/tests" Off)
set(SKIP_INSTALL_ALL 1)


add_subdirectory(${PROJECT_SOURCE_DIR}/aseprite-rgba-converter)

find_package(SFML 2 REQUIRED graphics)
message(status "** SFML Include: ${SFML_INCLUDE_DIRS}")
message(status "** SFML Libraries: ${SFML_LIBRARIES}")
if(NOT SFML_FOUND)
    set(SFML_ROOT "" CACHE PATH "SFML top-level directory")
    message("---> SFML 2.0 directory not found. Set SFML_ROOT to SFML's top-level path (containing \"include\" and \"lib\" directories).\n")
endif()
set(SOURCES
    convert.cpp
    )

set(INCLUDES
    convert.h
    )

add_library(AsepriteToSFMLImage STATIC ${SOURCES} ${INCLUDES})
include_directories(${SFML_INCLUDE_DIRS})
include_directories(${AsepriteRgbaConverter_INCLUDE_DIRS})
target_link_libraries(AsepriteToSFMLImage ${AsepriteRgbaConverter_LIBRARIES})
target_link_libraries(AsepriteToSFMLImage ${SFML_LIBRARIES})
