cmake_minimum_required(VERSION 3.29)
project(MeinCpp)

set(CMAKE_CXX_STANDARD 20)

INCLUDE_DIRECTORIES(Headers/
                    Libraries/)

add_executable(MeinCpp  main.cpp
        glad.c
        Core/Window.cpp
        Headers/Window.h
        Headers/Core.h
        Core/Input.cpp
        Headers/Input.h
        Core/Config.cpp
        Headers/Config.h
        Core/Renderer.cpp
        Headers/Renderer.h
        Headers/Shader.h
        Core/Shader.cpp
        Core/Textures.cpp)

#Add GLFW
find_package(glfw3 3.3 REQUIRED)
find_package(glm REQUIRED)
target_link_libraries(MeinCpp glfw config++ glm::glm)

#Make GLFW work on linux
add_link_options(-lglfw3 -lGL -lX11 -lpthread -lXrandr -lXi -ldl -lconfig++)

add_compile_options(LANG=en_US.UTF-8)