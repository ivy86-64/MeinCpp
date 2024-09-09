#include "Core.h"
#include "Renderer.h"

namespace RendererOGL {
    void init() {
        glCreateBuffers(1, &myBufferId);

    }
}