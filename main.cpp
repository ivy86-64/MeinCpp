#include "Core.h"
#include <cmath>

#include "Shader.h"
#include "Window.h"
#include "Config.h"
#include "Renderer.h"

constexpr int windowWidth{800};
constexpr int windowHeight{600};
const char* windowTitle{"MineC++"};

void exitGame();

int main() {
    if ( !glfwInit() ) {
        std::cout << "Failed to initialize GLFW\n";
        return -1;
    }

    //ConfigHandler config{};
    //config.initConfig();

    GLFWwindow* window = Window::createWindow(windowWidth, windowHeight, windowTitle, false);
    Window::installCallbacks(window); //Input Callbacks

    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);

    if(!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress))) {
        std::cout << "Failed to initialize GLAD\n";
        return -1;
    }
    glViewport(0, 0, windowWidth, windowHeight);

    //Init the OpenGL Renderer

    const Shader triangleShader("../Shaders/triangle.vert", "../Shaders/triangle.frag");
    const unsigned int VAO{ RendererOGL::initVAO() };
    //Init for get current cursor pos
    //double xPos = 0, yPos = 0;

    //Texture code, move later
    //------------------------
    float texCoords[] = {
        0.0f, 0.0f, //lower-left corner
        1.0f, 0.0f, //lower-right corner
        0.5f, 1.0f  //top-center corner
    };

    //Set Texture Wrapping Parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);

    //Set Texture Filtering Parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    while(!glfwWindowShouldClose(window)) {
        glClearColor(101.0f / 255.0f, 100.0f / 255.0f, 100.0f / 255.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        //Get current cursor pos
        //glfwGetCursorPos(window, &xPos, &yPos);
        triangleShader.use();

        float timeValue = glfwGetTime();
        float positionx = sin(timeValue) / 2.0f + 0.5f;
        triangleShader.setFloat("offsetx", positionx);

        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        //glBindVertexArray(VAO2);
        glfwSwapBuffers(window);

        //input
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
