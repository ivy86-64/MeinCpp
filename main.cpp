#include "Core.h"
#include "Window.h"
#include "Config.h"
const int windowWidth{800};
const int windowHeight{600};
const char* windowTitle{"MineC++"};

int main() {
    if ( !glfwInit() ) {
        std::cout << "Failed to initialize GLFW\n";
        return -1;
    }

    ConfigHandler config{};
    config.initConfig();
    gl
    GLFWwindow* window = Window::createWindow(windowWidth, windowHeight, windowTitle, false);
    Window::installCallbacks(window); //Input Callbacks

    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);

    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD\n";
        return -1;
    }
    glViewport(0, 0, windowWidth, windowHeight);

    //Init for get current cursor pos
    //double xPos = 0, yPos = 0;

    while(!glfwWindowShouldClose(window)) {
        glClearColor(200.0f / 255.0f, 100.0f / 255.0f, 100.0f / 255.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        //Get current cursor pos
        //glfwGetCursorPos(window, &xPos, &yPos);

        glfwSwapBuffers(window);

        //input
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}