#include <Rendering/Mesh/Mesh.hpp>
#include <Backend/OpenGL/GLUtils.hpp>
#include <iostream>

using namespace EternalEngine;

Mesh::Mesh()
{
    _vao = 0;
    _vbo = 0;
    _ibo = 0;
    _indices_count = 0;
}

Mesh::~Mesh()
{
    clear();
}

bool Mesh::create(const float *vertices, unsigned int vertices_count, const unsigned int *indices, unsigned int indices_count)
{
    _indices_count = indices_count;

    glGenVertexArrays(1, &_vao);
    glBindVertexArray(_vao);

    glGenBuffers(1, &_ibo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _ibo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices[0]) * indices_count, indices, GL_STATIC_DRAW);
    
    glGenBuffers(1, &_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, _vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices[0]) * vertices_count, vertices, GL_STATIC_DRAW);
    
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(0);

    if (GLUtils::CheckError(__FILE__,__FUNCTION__,__LINE__))
    {
        return false;
    }

    // Unbind the _vao,_vbo and _ibo
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    return true;
}

void Mesh::clear()
{
    if (_ibo)
    {
        glDeleteBuffers(1, &_ibo);
        _ibo = 0;
    }
    if (_vbo)
    {
        glDeleteBuffers(1, &_vbo);
        _vbo = 0;
    }
    if (_vao)
    {
        glDeleteVertexArrays(1, &_vao);
        _vao = 0;
    }
    _indices_count = 0;
}

void Mesh::render() const
{
    glBindVertexArray(_vao);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _ibo);
    glDrawElements(GL_TRIANGLES, _indices_count, GL_UNSIGNED_INT, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}
