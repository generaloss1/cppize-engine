cmake_minimum_required(VERSION 3.26)
project(Pizza_Engine_Cpp)
set(CMAKE_CXX_STANDARD 17)

add_subdirectory(
        lib/glfw-3.3.8
)

include_directories(
        ${CMAKE_SOURCE_DIR}/src
        ${CMAKE_SOURCE_DIR}/lib/glad/include
        ${CMAKE_SOURCE_DIR}/lib/glfw-3.3.8/deps
        ${CMAKE_SOURCE_DIR}/lib/glfw-3.3.8/include
        ${CMAKE_SOURCE_DIR}/lib/stb
)

add_executable(${PROJECT_NAME}
        lib/glad/include/glad/glad.h
        lib/glad/src/glad.c
        lib/stb/stb_image.h

        src/pize/test/main.cpp
)

target_link_libraries(${PROJECT_NAME}
        glfw
)