#ifdef USE_GLEW
#include <GL/glew.h>
#endif
#include <stdio.h>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>
#include <Rendering/Viewport/Viewport.hpp>

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
    _projection = glm::perspective(45.0f, (float)_width / (float)_height, 0.01f, 100.0f);
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
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Viewport::render(const MeshComponent &model, const ShaderComponent &shader, const TransformComponent &_transform,const CameraComponent &_camera)
{
    shader.shader.use(true);
    shader.shader.set_uniform("xTransform", _transform.Transform);
    shader.shader.set_uniform("xProjection", _projection);
    shader.shader.set_uniform("xViewMatrix", _camera.view_matrix);
    model.mesh.render();
    shader.shader.use(false);
}