#pragma once
#ifdef USE_GLEW
#include <GL/glew.h>
#endif

namespace EternalEngine
{
    class Mesh
    {
        public:
            Mesh();
            ~Mesh();
            bool create(const float *vertices, unsigned int vertices_count, const unsigned int *indices, unsigned int indices_count);
            void clear();
            void render() const;
        private:
#if defined(USE_GLEW)
        GLuint _vao;
        GLuint _vbo;
        GLuint _ibo;
        GLuint _indices_count;
#endif
    };
}