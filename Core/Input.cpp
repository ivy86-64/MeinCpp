//
// Created by madeline on 24/09/07.
//
#include "Core.h"
#include "Input.h"

#include "Window.h"

namespace Input {
    bool keyPressedData[GLFW_KEY_LAST] = {};

    void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
        if( key == GLFW_KEY_F11 && action == GLFW_PRESS) {
                     Window::fullscreenSwitch(window);

        }
    }

    void cursorPositionCallback(GLFWwindow* window, double xPos, double yPos) {
    }

    void cursorEnterCallback(GLFWwindow* window, int entered) {
    }

    void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods) {
        if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
            std::cout << "Pressed left button\n";
        }
    }

    void scrollCallback(GLFWwindow* window, double xOffset, double yOffset) {
        std::cout << xOffset << " : " << yOffset << '\n';
    }
    bool isKeyDown(int key) {
        if (key >= 0 && key < GLFW_KEY_LAST) {
            return keyPressedData[key];
        }

        return false;
    }
}
