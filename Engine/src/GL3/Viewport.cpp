#include <Rendering/Renderer.hpp>
#ifdef USE_GLEW
#include <GL/glew.h>
#endif
#include <stdio.h>

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
}

int Viewport::create_viewport(int width, int height)
{
#ifdef USE_GLEW
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