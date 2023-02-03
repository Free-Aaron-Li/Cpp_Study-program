cmake_minimum_required(VERSION 3.24)
project(ChapterThree)

set(CMAKE_CXX_STANDARD 17)


link_directories(${PROJECT_SOURCE_DIR}/lib)

set(SOURCES
        src/Chapter3_1_find.cpp
        )

#------------------------------------
add_executable(ChapterThree ${SOURCES})

target_include_directories(ChapterThree
        PRIVATE
        ${PROJECT_SOURCE_DIR}/include
        )
