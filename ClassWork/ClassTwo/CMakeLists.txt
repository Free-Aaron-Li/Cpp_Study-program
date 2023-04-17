cmake_minimum_required(VERSION 3.24)
project(ClassTwo)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

link_directories(${PROJECT_SOURCE_DIR}/lib)

set(SOURCES
        src/main.cpp
        src/algorithm/baseconversion.cpp
        src/algorithm/orderofjudgment.cpp
        src/algorithm/sharestack.cpp
        src/algorithm/stack.cpp
        src/algorithm/queue.cpp
        src/UI/menu.cpp
        )

#------------------------------------
add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME}
        PRIVATE
        ${PROJECT_SOURCE_DIR}/include
        )