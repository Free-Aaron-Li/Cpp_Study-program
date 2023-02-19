cmake_minimum_required(VERSION 3.24)
project(Test)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

link_directories(${PROJECT_SOURCE_DIR}/lib)

set(SOURCES
        src/main.cpp
        )

#------------------------------------
add_executable(Test ${SOURCES})

target_link_libraries(Test easyx)

target_include_directories(Test
        PRIVATE
        ${PROJECT_SOURCE_DIR}/include
        )
