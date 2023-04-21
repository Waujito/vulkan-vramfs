cmake_minimum_required(VERSION 3.0.0)
project(vulkan-vramfs VERSION 0.1.0)

set (CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH}
    "${CMAKE_SOURCE_DIR}/cmake/Modules/")

find_package(FUSE3)

add_executable(vulkan-vramfs src/main.cpp)

target_link_libraries(${PROJECT_NAME} FUSE3::FUSE3)
target_include_directories(${PROJECT_NAME} PRIVATE ${FUSE_INCLUDE_DIR})