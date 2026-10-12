cmake_minimum_required( VERSION 3.6 )

project( codebase )

set( CMAKE_CXX_STANDARD           20 )
set( CMAKE_CXX_STANDARD_REQUIRED  ON )

list(APPEND CMAKE_PREFIX_PATH "/home/nobahu/libs/drogon")
find_package( Drogon REQUIRED )

add_subdirectory( entities )
add_subdirectory( logic )
add_subdirectory( http )

add_executable( codebase main.cpp )

target_include_directories( codebase PRIVATE
        ${CMAKE_SOURCE_DIR}/..
)

target_link_libraries( codebase PRIVATE
        http
        Drogon::Drogon
)