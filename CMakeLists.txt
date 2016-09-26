cmake_minimum_required(VERSION 3.1)

project(AsepriteToSFMLImage)

# Default compiler args
if (CMAKE_CXX_COMPILER_ID MATCHES "(GNU|.*Clang)")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pedantic -Werror -Wall -Wextra -Wno-unused-parameter -Wno-error=unused-variable -Wno-error=sign-compare -std=c++14 -Wno-error=deprecated-declarations -Wno-unused-local-typedefs")
    if (CMAKE_CXX_COMPILER_ID MATCHES "(.*Clang)")
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-missing-field-initializers -Qunused-arguments")
    endif()
    if (CMAKE_CXX_COMPILER_ID MATCHES "(GNU)")
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-error=unused-local-typedefs")
    endif()
    set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g")
    set(CMAKE_CXX_FLAGS_MINSIZEREL "-g -Os -DNDEBUG")
    set(CMAKE_CXX_FLAGS_RELEASE "-g -O2 -DNDEBUG")
    set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-O2 -g")
elseif(CMAKE_CXX_COMPILER_ID STREQUAL 'MSVC')
    # /Zi - Produces a program database (PDB) that contains type information and symbolic debugging information for use with the debugger.
    # /FS - Allows multiple cl.exe processes to write to the same .pdb file
    # /DEBUG - Enable debug during linking
    # /Od - Disables optimization
    set(CMAKE_CXX_FLAGS_DEBUG "/Zi /FS /DEBUG /Od /MDd")
    # /Ox - Full optimization
    set(CMAKE_CXX_FLAGS_RELEASE "/Ox -DNDEBUG")
    set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "/Ox /Zi /FS /DEBUG")
endif()


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
