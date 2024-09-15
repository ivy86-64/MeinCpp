//
// Created by madeline on 24/09/08.
//

#ifndef RENDERER_H
#define RENDERER_H

#include "Core.h"

namespace RendererOGL {


    void rendererErrorHandler(auto shaderError, std::string_view errorMessage);
    unsigned int initShaderProgram();
    unsigned int initVAO();
}
#endif //RENDERER_H
