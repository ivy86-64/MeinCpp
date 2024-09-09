//
// Created by madeline on 24/09/07.
//

#ifndef INPUT_H
#define INPUT_H

#include <Core.h>

namespace Input {
    void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
    void cursorPositionCallback(GLFWwindow* window, double xPos, double yPos);
    bool isKeyDown(int key);
    void cursorEnterCallback(GLFWwindow* window, int entered);
    void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
    void scrollCallback(GLFWwindow* window, double xOffset, double yOffset);

}
#endif //INPUT_H
