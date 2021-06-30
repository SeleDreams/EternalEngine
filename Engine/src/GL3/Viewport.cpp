#include <Rendering/Renderer.hpp>
#ifdef USE_GLEW
#include <GL/glew.h>
#endif
#include <stdio.h>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>
#include <Rendering/Mesh/MeshRenderer.hpp>

using namespace EternalEngine;

Viewport::Viewport()
{
    _width = 0;
    _height = 0;
}

Viewport::~Viewport()
{
}

void Viewport::resize_viewport(int new_width, int new_height)
{
    _width = new_width;
    _height = new_height;
    glViewport(0, 0, _width, _height);
    _projection = glm::perspective(45.0f,(float)_width / (float)_height,0.001f,100.0f);
}

int Viewport::create_viewport(int width, int height)
{
#ifdef USE_GLEW
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK)
    {
        printf("An error occurred while initializing glew !\n");
    }
#endif
    glEnable(GL_DEPTH_TEST);
    resize_viewport(width, height);
    return 1;
}

void Viewport::clear_viewport()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

 void _CheckGLError(const char *file, int line)
    {
        GLenum err(glGetError());

        while (err != GL_NO_ERROR)
        {
            std::string error;
            switch (err)
            {
            case GL_INVALID_OPERATION:
                error = "INVALID_OPERATION";
                break;
            case GL_INVALID_ENUM:
                error = "INVALID_ENUM";
                break;
            case GL_INVALID_VALUE:
                error = "INVALID_VALUE";
                break;
            case GL_OUT_OF_MEMORY:
                error = "OUT_OF_MEMORY";
                break;
            case GL_INVALID_FRAMEBUFFER_OPERATION:
                error = "INVALID_FRAMEBUFFER_OPERATION";
                break;
            }
            std::cout << "GL_" << error.c_str() << " - " << file << ":" << line << std::endl;
            err = glGetError();
        }

        return;
    }
#define CheckGLError() _CheckGLError(__FILE__, __LINE__)

void Viewport::render(const MeshComponent &model,const ShaderComponent &shader,TransformComponent &transform)
{
    glUseProgram(shader.program_location);
    glUniformMatrix4fv(shader.model_uniform,1,GL_FALSE,glm::value_ptr(transform.Transform));
    glUniformMatrix4fv(shader.projection_uniform,1,GL_FALSE,glm::value_ptr(_projection));
    glBindVertexArray(model.mesh.VertexArrayObject);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, model.mesh.IndexBufferObject);
    glDrawElements(GL_TRIANGLES, model.mesh.IndexCount, GL_UNSIGNED_INT, 0);
    CheckGLError();
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    glUseProgram(0);
}