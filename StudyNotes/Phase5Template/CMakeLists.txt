cmake_minimum_required(VERSION 3.24)
project(Phase5)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")
# 可执行文件的输出目录
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

link_directories(${PROJECT_SOURCE_DIR}/lib)
include_directories(${PROJECT_SOURCE_DIR}/include)

set(SOURCES
        src/main.cpp
        src/swap.cpp
        src/compare.cpp
        src/inherit.cpp
        src/script.cpp
        )

#------------------------------------
add_executable(Phase5 ${SOURCES})

target_include_directories(Phase5
        PRIVATE
        ${PROJECT_SOURCE_DIR}/include
        )