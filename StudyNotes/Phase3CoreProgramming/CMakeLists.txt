cmake_minimum_required(VERSION 3.24)
project(Phase3)

set(CMAKE_CXX_STANDARD 17)

# 可执行文件的输出目录
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

link_directories(${PROJECT_SOURCE_DIR}/lib)

set(SOURCES
        src/main.cc
        )

#------------------------------------
add_executable(Phase3 ${SOURCES})

target_include_directories(Phase3
        PRIVATE
        ${PROJECT_SOURCE_DIR}/include
        )