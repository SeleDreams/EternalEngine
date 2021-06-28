#include <Rendering/Renderer.hpp>
#ifdef USE_GLEW
#include <GL/glew.h>
#endif
#include <stdio.h>

using namespace EternalEngine;

Viewport::Viewport()
{
    width = 0;
    height = 0;
}

Viewport::~Viewport()
{

}

#ifdef USE_GLEW
int init_glew()
{
    if (glewInit() != GLEW_OK)
    {
        printf("An error occurred while initializing glew !\n");
        return 0;
    }
    return 1;
}
#endif

int Viewport::create_viewport(int width, int height)
{
    this->width = width;
    this->height = height;
    #ifdef USE_GLEW
    return init_glew();
    #endif
    glEnable(GL_DEPTH_TEST);
    glViewport(0,0,width,height);
    return 1;
}