#include <Rendering/Renderer.hpp>
#include <memory>
#include <stdio.h>
#include <Components/ShaderComponent.hpp>
#include <string.h>
#ifdef USE_GLEW
#include <GL/glew.h>
#else
#error No gl3 library defined
#endif
#include <iostream>

using namespace EternalEngine;
int MeshRenderer::CreateMesh(Mesh &mesh, const float *vertices, unsigned int vertices_count, const unsigned int *indices, unsigned int indices_count)
{
    GLuint VAO;
    GLuint VBO;
    GLuint IBO;

    // Create the VAO and VBO then bind them
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    glGenBuffers(1, &IBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices[0]) * indices_count, indices, GL_STATIC_DRAW);
    
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices[0]) * vertices_count, vertices, GL_STATIC_DRAW);
     
    // Bind the VAO, VBO and IBO
 

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(0);
    // Unbind the VAO,VBO and IBO
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    mesh.VertexArrayObject = VAO;
    mesh.VertexBufferObject = VBO;
    mesh.IndexCount = indices_count;
    mesh.IndexBufferObject = IBO;
    return 1;
}

void MeshRenderer::ClearMesh(Mesh &mesh)
{
    GLuint VAO = mesh.VertexArrayObject;
    GLuint VBO = mesh.VertexBufferObject;
    GLuint IBO = mesh.IndexBufferObject;

    glDeleteBuffers(1, &IBO);
    glDeleteBuffers(1, &VBO);
    glDeleteVertexArrays(1, &VAO);

    mesh.VertexArrayObject = 0;
    mesh.VertexBufferObject = 0;
    mesh.IndexBufferObject = 0;
}

void AddShader(GLuint theProgram, const char *shaderCode, GLenum shaderType)
{
    GLuint theShader = glCreateShader(shaderType);
    const GLchar *theCode[1];
    theCode[0] = shaderCode;
    GLint codeLength[1];
    codeLength[0] = strlen(shaderCode);
    glShaderSource(theShader, 1, theCode, codeLength);
    glCompileShader(theShader);
    GLint result = 0;
    GLchar eLog[1024];
    glGetShaderiv(theShader, GL_COMPILE_STATUS, &result);
    if (!result)
    {
        glGetShaderInfoLog(theShader, sizeof(eLog), NULL, eLog);
        printf("Error compiling shader %s\n", eLog);
        return;
    }

    glAttachShader(theProgram, theShader);
}

void MeshRenderer::CreateShader(ShaderComponent &shader, std::string vert_shader, std::string frag_shader)
{
    GLuint program, vert, frag;
    program = glCreateProgram();
    AddShader(program, vert_shader.c_str(), GL_VERTEX_SHADER);
    AddShader(program, frag_shader.c_str(), GL_FRAGMENT_SHADER);

    GLint result = 0;
    GLchar eLog[1024];
    glLinkProgram(program);
    glGetProgramiv(program, GL_LINK_STATUS, &result);
    if (!result)
    {
        glGetProgramInfoLog(program, sizeof(eLog), NULL, eLog);
        printf("Error linking program %s\n", eLog);
        return;
    }
    glValidateProgram(program);
    glGetProgramiv(program, GL_VALIDATE_STATUS, &result);
    if (!result)
    {
        glGetProgramInfoLog(program, sizeof(eLog), NULL, eLog);
        printf("Error validating program %s\n", eLog);
        return;
    }
    GLuint uniformModel = glGetUniformLocation(program, "xModel");
    GLuint uniformProjection = glGetUniformLocation(program,"xProjection");
    shader.program_location = program;
    shader.model_uniform = uniformModel;
    shader.projection_uniform = uniformProjection;
}