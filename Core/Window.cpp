#include <iostream>
#include "Window.h"
#include "Core.h"
#include "Input.h"

namespace Window {
    void fullscreenSwitch(GLFWwindow *window) {

        GLFWmonitor* monitor = glfwGetPrimaryMonitor();
        const GLFWvidmode* mode = glfwGetVideoMode(monitor);


        static bool s_fullscreenMode{false};
        std::cout << "Switch fullscreen mode.\n";

        if(s_fullscreenMode == false) {
            glfwSetWindowMonitor(window, glfwGetPrimaryMonitor(), 0, 0, mode->width, mode->height, mode->refreshRate);
            s_fullscreenMode = true;
        }
        else if(s_fullscreenMode == true) {
            glfwSetWindowMonitor(window, nullptr, 100, 100, 800, 600, 0);
            s_fullscreenMode = false;
        }
    }

    GLFWwindow* createWindow(int windowWidth, int windowHeight, const char* windowTitle, bool fullscreenMode) {
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


        GLFWwindow* window = glfwCreateWindow(
            windowWidth, windowHeight, windowTitle, (fullscreenMode ? glfwGetPrimaryMonitor() : nullptr), nullptr);

        if (window == nullptr) {
            std::cout << "Failed to initialize GLFW window\n";
            return nullptr;
        }
        glfwMakeContextCurrent(window);
        return window;
    }

    void framebufferSizeCallback(GLFWwindow* window, int width, int height) {
        glViewport(0, 0, width, height);
    }

    void installCallbacks(GLFWwindow* window) {
        glfwSetKeyCallback(window, Input::keyCallback);
        glfwSetCursorPosCallback(window, Input::cursorPositionCallback);
        glfwSetCursorEnterCallback(window, Input::cursorEnterCallback);
        glfwSetMouseButtonCallback(window, Input::mouseButtonCallback);
        glfwSetScrollCallback(window, Input::scrollCallback);
        glfwSetInputMode(window, GLFW_STICKY_MOUSE_BUTTONS, 1);
        glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);
    }

};
