cmake_minimum_required(VERSION 3.24)
project(ChapterThree)

set(CMAKE_CXX_STANDARD 17)


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

target_include_directories(ChapterThree
        PRIVATE
        ${PROJECT_SOURCE_DIR}/include
        )
