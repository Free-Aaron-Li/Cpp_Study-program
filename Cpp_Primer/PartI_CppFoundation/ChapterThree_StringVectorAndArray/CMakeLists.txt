cmake_minimum_required(VERSION 3.24)
project(Primer_ChapterThree)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

link_directories(${PROJECT_SOURCE_DIR}/lib)

set(SOURCES
        src/main.cpp
        src/exercise/3_1.cpp
        src/exercise/3_2.cpp
        src/exercise/3_3.cpp
        )

#------------------------------------
add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME}
        PRIVATE
        ${PROJECT_SOURCE_DIR}/include
        )