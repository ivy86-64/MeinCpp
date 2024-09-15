#include "Core.h"
#include "Renderer.h"



namespace RendererOGL {
    unsigned int initShaderProgram() {
        std::cout << "Entered OpenGL renderer\n";

        //Shader Sources
        const char *vertexShaderSource =    "#version 330 core\n"
                                                "layout (location = 0) in vec3 aPos;\n"
                                                "layout (location = 1) in vec3 aColor;\n"

                                                "out vec3 ourColor;\n"

                                                "void main()\n"
                                                "{\n"
                                                "   gl_Position = vec4(aPos, 1.0);\n"
                                                "   ourColor = aColor;\n"
                                                "}\0";



        const char *fragmentShaderSource =      "#version 330 core\n"

                                                "out vec4 FragColor;\n"

                                                "in vec3 ourColor;"

                                                "void main()\n"
                                                "{\n"
                                                "    FragColor = vec4(ourColor, 1.0);\n"
                                                "}\0";

        //Vertex Shader
        unsigned int vertexShader { glCreateShader(GL_VERTEX_SHADER) };
        glShaderSource(vertexShader, 1, &vertexShaderSource, nullptr);
        glCompileShader(vertexShader);

        int success; //Declare success variable for all subsequent error checks
        //Vertex Shader Error Check
        glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
        if(!success) { rendererErrorHandler(vertexShader, "SHADER::VERTEX::COMPILATION"); }



        //Fragment Shader
        unsigned int fragmentShader { glCreateShader(GL_FRAGMENT_SHADER) };
        glShaderSource(fragmentShader, 1, &fragmentShaderSource, nullptr);
        glCompileShader(fragmentShader);

        //Fragment Shader Error Check
        glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
        if(!success) { rendererErrorHandler(vertexShader, "SHADER::FRAGMENT::COMPILATION"); }



        //Shader Program
        unsigned int shaderProgram { glCreateProgram() };
        glAttachShader(shaderProgram, vertexShader);
        glAttachShader(shaderProgram, fragmentShader);
        glLinkProgram(shaderProgram);

        //Shader Program Error Check
        glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
        if(!success) { rendererErrorHandler(vertexShader, "SHADER::PROGRAM::LINKAGE"); }



        //Finalizing
        glUseProgram(shaderProgram);
        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);

        std::cout << "Initialized shader program.\n";
        return shaderProgram;
    }

    unsigned int initVAO() {
        float vertices[] = {
            //position          //colors
            0.5f, -0.5f, 0.0f,   1.0f, 0.0f, 0.0f,
           -0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,
            0.0f,  0.5f, 0.0f,   0.0f, 0.0f, 1.0f
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

    void rendererErrorHandler(auto shaderError, std::string_view errorMessage) {
        char infoLog[512];
        glGetShaderInfoLog(shaderError, 512, nullptr, infoLog);
        std::cerr << "ERROR::" << errorMessage << "_FAILED\n" << infoLog << '\n';
    }
}