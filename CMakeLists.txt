cmake_minimum_required(VERSION 3.29)
project(MineC__)

set(CMAKE_CXX_STANDARD 20)

INCLUDE_DIRECTORIES(/home/madeline/projects/libs/include/ include/)

add_executable(MineC__  main.cpp
        glad.c
        Core/Window.cpp
        include/Window.h
        include/Core.h
        Core/Input.cpp
        include/Input.h
        Core/Config.cpp
        include/Config.h
        Renderer.cpp
        Renderer.h)

#Add GLFW
find_package(glfw3 3.3 REQUIRED)
find_package(glm REQUIRED)
target_link_libraries(MineC__ glfw config++ glm::glm)

#Make GLFW work on linux
add_link_options(-lglfw3 -lGL -lX11 -lpthread -lXrandr -lXi -ldl -lconfig++)