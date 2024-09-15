#ifndef WINDOW_H
#define WINDOW_H

#include "Core.h"

namespace Window {
    void fullscreenSwitch(GLFWwindow* window);
    GLFWwindow* createWindow(int windowWidth, int windowHeight, const char* windowTitle, bool fullscreenMode);
    void installCallbacks(GLFWwindow* window);
    void framebufferSizeCallback(GLFWwindow* window, int width, int height);
}
#endif //WINDOW_H
