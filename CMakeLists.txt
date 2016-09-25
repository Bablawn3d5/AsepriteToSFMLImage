cmake_minimum_required(VERSION 3.1)

project(AsepriteToSFMLImage)

option(ASEPRITE_CONVERT_EXAMPLES  "Compile Aseprite conversion examples" Off)
option(ZLIB_TESTS  "Compile with zlib examples/tests" Off)
set(SKIP_INSTALL_ALL 1)


add_subdirectory(${PROJECT_SOURCE_DIR}/aseprite-rgba-converter)
include_directories(${AsepriteRgbaConvert_SOURCE_DIR})

if(NOT SFML_FOUND)
    find_package(SFML 2 REQUIRED graphics)
    message(status "** SFML Include: ${SFML_INCLUDE_DIR}")
    message(status "** SFML Libraries: ${SFML_LIBRARIES}")
endif()

set(SOURCES
    ${PROJECT_SOURCE_DIR}/Aseprite/SFML/convert.cpp
    )

set(INCLUDES
    ${PROJECT_SOURCE_DIR}/Aseprite/SFML/convert.h
    )

add_library(AsepriteToSFMLImage STATIC ${SOURCES} ${INCLUDES})
include_directories(${PROJECT_SOURCE_DIR}/Aseprite/SFML)
include_directories(${SFML_INCLUDE_DIR})
target_link_libraries(AsepriteToSFMLImage AsepriteRgbaConvert)
target_link_libraries(AsepriteToSFMLImage ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})

if(ASEPRITE_CONVERT_EXAMPLES)
    add_subdirectory(${PROJECT_SOURCE_DIR}/example)
endif()
