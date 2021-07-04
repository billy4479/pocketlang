cmake_minimum_required(VERSION 3.7)
project(pocketlang)

option(MAKE_CLI "Do NOT build the CLI" ON)
option(MAKE_STATIC "Do NOT build the static library" ON)
option(MAKE_SHARED "Do NOT build the shared library" ON)

add_compile_options(-Wall -Wextra)

if(MAKE_CLI)
    set(MAKE_STATIC ON)
endif()

if(MAKE_STATIC)
    set(STATIC_TARGET ${PROJECT_NAME}_static)
endif()
if(MAKE_SHARED)
    set(SHARED_TARGET ${PROJECT_NAME}_shared)
endif()

file( GLOB LIB_SOURCES src/*.c )

if(MAKE_CLI)
    set(CLI_TARGET ${PROJECT_NAME})
    file( GLOB CLI_SOURCES cli/*.c )
endif()

if(MAKE_STATIC)
    add_library(${STATIC_TARGET} STATIC ${LIB_SOURCES})
    set_target_properties(${STATIC_TARGET} PROPERTIES PUBLIC_HEADER src/include/pocketlang.h)
    target_include_directories(${STATIC_TARGET} PUBLIC src/include PRIVATE src)
    target_link_libraries(${STATIC_TARGET} m)
endif()

if(MAKE_SHARED)
    add_library(${SHARED_TARGET} SHARED ${LIB_SOURCES})
    set_target_properties(${SHARED_TARGET} PROPERTIES PUBLIC_HEADER src/include/pocketlang.h)
    target_include_directories(${SHARED_TARGET} PUBLIC src/include PRIVATE src)
    target_link_libraries(${SHARED_TARGET} m)
endif()

if(MAKE_CLI)
    add_executable(${CLI_TARGET} ${CLI_SOURCES} ${LIB_SOURCES})
    target_link_libraries(${CLI_TARGET} ${STATIC_TARGET})
endif()
