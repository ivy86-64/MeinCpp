cmake_minimum_required(VERSION 3.29)
project(MeinCpp)

set(CMAKE_CXX_STANDARD 20)

INCLUDE_DIRECTORIES(include/)

add_executable(MeinCpp  main.cpp
        glad.c
        Core/Window.cpp
        include/Window.h
        include/Core.h
        Core/Input.cpp
        include/Input.h
        Core/Config.cpp
        include/Config.h
        Core/Renderer.cpp
        include/Renderer.h
        include/Shader.h)

#Add GLFW
find_package(glfw3 3.3 REQUIRED)
find_package(glm REQUIRED)
target_link_libraries(MeinCpp glfw config++ glm::glm)

#Make GLFW work on linux
add_link_options(-lglfw3 -lGL -lX11 -lpthread -lXrandr -lXi -ldl -lconfig++)

add_compile_options(LANG=en_US.UTF-8)