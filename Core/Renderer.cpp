#include "Core.h"
#include "Renderer.h"



namespace RendererOGL {
    unsigned int initVAO() {
        float vertices[] = {
            //position          //colors
            0.5f, -0.5f, 0.0f,   91.0f  / 255.0f, 206.0f / 255.0f, 250.0f / 255.0f,
           -0.5f, -0.5f, 0.0f,   255.0f / 255.0f, 255.0f / 255.0f, 255.0f / 255.0f,
            0.0f,  0.5f, 0.0f,   245.0f / 255.0f, 169.0f / 255.0f, 184.0f / 255.0f
        };


        //VBOs and VAOs
        unsigned int VBO{};
        glGenBuffers(1, &VBO);

        unsigned int VAO{};
        glGenVertexArrays(1, &VAO);

        //Initialization
        glBindVertexArray(VAO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

        //position attribute
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);
        //color attribute
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3* sizeof(float)));
        glEnableVertexAttribArray(1);
        return VAO;
    }

    void rendererErrorHandler(auto shaderError, const std::string_view errorMessage) {
        char infoLog[512];
        glGetShaderInfoLog(shaderError, 512, nullptr, infoLog);
        std::cerr << "ERROR::" << errorMessage << "_FAILED\n" << infoLog << '\n';
    }
}