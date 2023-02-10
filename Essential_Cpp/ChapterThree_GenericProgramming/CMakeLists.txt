cmake_minimum_required(VERSION 3.24)
project(ChapterThree)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
link_directories(${PROJECT_SOURCE_DIR}/lib)

set(SOURCES
        src/swap.cpp
        src/main.cpp
        src/BubbleSort.cpp
        src/Print.cpp
        src/struct.cpp
        src/menu.cpp
        )

#------------------------------------
add_executable(ChapterThree ${SOURCES})

target_link_libraries(ChapterThree easyx)

target_include_directories(ChapterThree
        PRIVATE
        ${PROJECT_SOURCE_DIR}/include
        )
