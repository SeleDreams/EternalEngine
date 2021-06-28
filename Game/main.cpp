#include <Game.hpp>
#include <Rendering/Renderer.hpp>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>

using namespace EternalEngine;

GLFWwindow *window = nullptr;

bool update_glfw()
{
    glfwSwapBuffers(window);
    glfwPollEvents();
    return !glfwWindowShouldClose(window);
}

int main(int argc, char **argv)
{
    if (!glfwInit())
    {
        printf("GLFW initialization failed !\n");
        return 0;
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT,GL_TRUE);

    window = glfwCreateWindow(800,600,"Eternal Engine",NULL,NULL);
    if (!window)
    {
        printf("GLFW window creation failed !`n");
        glfwTerminate();
        return 0;
    }
    int viewportWidth, viewportHeight;
    glfwGetFramebufferSize(window,&viewportWidth,&viewportHeight);
    glfwMakeContextCurrent(window);
    Game game;
    bool result = game.run(800,600,update_glfw);
    glfwTerminate();
    return 1;
}