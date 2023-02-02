cmake_minimum_required(VERSION 3.24)
project(ChapterThree)

set(CMAKE_CXX_STANDARD 17)

include_directories(${PROJECT_SOURCE_DIR}/include)
link_directories(${PROJECT_SOURCE_DIR}/lib)

#------------------------------------
add_executable(chapter3.1 Chapter3_1_find.cpp)

target_link_libraries(chapter3.1 easyx)