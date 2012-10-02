cmake_minimum_required(VERSION 2.6)
project(CSEngine)

set (CMAKE_MODULE_PATH "${CSEngine_SOURCE_DIR}/" ${CMAKE_MODULE_PATH})

#set (CMAKE_INCLUDE_PATH ${CMAKE_INCLUDE_PATH} "/usr/lib/nvidia-current")


find_package(OpenGL REQUIRED)
find_package(SDL REQUIRED)
find_package(FreeImagePlus REQUIRED)
include_directories(${OPENGL_INCLUDE_DIR}
					${SDL_INCLUDE_DIR})
add_subdirectory(src)
add_subdirectory(bin)
