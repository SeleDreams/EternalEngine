#pragma once
#ifdef USE_GLEW
#include <GL/glew.h>
#elif USE_GL3
#include <GL/gl.h>
#endif

namespace EternalEngine
{
    struct Mesh
    {
#ifdef USE_GL3
        GLuint VertexArrayObject = 0;
        GLuint VertexBufferObject = 0;
        GLuint IndexBufferObject = 0;
        GLuint IndexCount = 0;
#endif
    };
}