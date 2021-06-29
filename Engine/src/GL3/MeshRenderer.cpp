#include <Rendering/Renderer.hpp>
#include <memory>
#include <stdio.h>

#ifdef USE_GLEW
#include <GL/glew.h>
#else
#error No gl3 library defined
#endif

using namespace EternalEngine;

int MeshRenderer::CreateMesh(std::shared_ptr<Mesh> mesh,const float *vertices, unsigned int vertices_count, const unsigned int *indices,unsigned int indices_count)
{
    GLuint VAO;
    GLuint VBO;
    GLuint IBO;

    // Create the VAO and VBO then bind them
    glGenVertexArrays(1,&VAO);
    glGenBuffers(1,&VBO);
    glGenBuffers(1,&IBO);

    // Bind the VAO, VBO and IBO
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER,VBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,IBO);

    glBufferData(GL_ARRAY_BUFFER,sizeof(vertices[0]) * vertices_count,vertices,GL_STATIC_DRAW);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(indices[0]) * indices_count,indices,GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3,GL_FLOAT,GL_FALSE,0,indices);
    glEnableVertexAttribArray(0);
    
    // Unbind the VAO,VBO and IBO
    glBindBuffer(GL_ARRAY_BUFFER,0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);
    glBindVertexArray(0);

    mesh->VertexArrayObject = VAO;
    mesh->VertexBufferObject = VBO;
    mesh->IndexCount = indices_count;
    mesh->IndexBufferObject = IBO;
    return 1;
}

void MeshRenderer::ClearMesh(std::shared_ptr<Mesh> mesh)
{
    GLuint VAO = mesh->VertexArrayObject;
    GLuint VBO = mesh->VertexBufferObject;
    GLuint IBO = mesh->IndexBufferObject;
    
    glDeleteBuffers(1,&IBO);
    glDeleteBuffers(1,&VBO);
    glDeleteVertexArrays(1,&VAO);

    mesh->VertexArrayObject = 0;
    mesh->VertexBufferObject = 0;
    mesh->IndexBufferObject = 0;
}