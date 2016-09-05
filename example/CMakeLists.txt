cmake_minimum_required(VERSION 3.1)

project(AsepriteToSFMLTest)

# Default compiler args
if (CMAKE_CXX_COMPILER_ID MATCHES "(GNU|.*Clang)")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pedantic -Werror -Wall -Wextra -Wno-unused-parameter -Wno-error=unused-variable -Wno-error=sign-compare -std=c++14 -DBOOST_NO_AUTO_PTR -Wno-error=deprecated-declarations -Wno-unused-local-typedefs")
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

if(SFML_STATIC_LIBRARIES)
    add_definitions(-DSFML_STATIC)
endif()

include_directories(${AsepriteToSFMLImage_SOURCE_DIR})
find_package(SFML 2 REQUIRED system window graphics)
message(status "** SFML Include: ${SFML_INCLUDE_DIR}")
message(status "** SFML Libraries: ${SFML_LIBRARIES}")
add_executable(AsepriteToSFMLTest main.cpp)
target_link_libraries(AsepriteToSFMLTest AsepriteToSFMLImage)
target_link_libraries(AsepriteToSFMLTest ${SFML_LIBRARIES} ${SFML_DEPENDENCIES} )
