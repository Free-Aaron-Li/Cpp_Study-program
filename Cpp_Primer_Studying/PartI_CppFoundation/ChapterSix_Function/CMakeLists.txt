cmake_minimum_required(VERSION 3.24)
project(Primer_ChapterSix)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

link_directories(${PROJECT_SOURCE_DIR}/lib)

set(SOURCES
        src/main.cpp
        src/exercise/6_1.cpp
        src/exercise/6_2.cpp
        src/exercise/6_3.cpp
        src/exercise/6_4.cpp
        src/exercise/6_5.cpp
        )

#------------------------------------
add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME}
        PRIVATE
        ${PROJECT_SOURCE_DIR}/include
        )

add_subdirectory(test)