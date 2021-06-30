#include <Backend/OpenGL/GLUtils.hpp>
#include <iostream>
#ifdef USE_GLEW
#include <GL/glew.h>
#else
#error You need to set an OpenGL library >= 3
#endif


using namespace EternalEngine;

bool GLUtils::CheckError(const char *file, const char *method, int line)
{
    auto error = glGetError();
    if (error == GL_NO_ERROR)
    {
        return false;
    }
    std::cout << "File : " << file << " Method : " << method << " Line : " << line << std::endl;
    std::cout << "An OpenGL error occurred : " << gluErrorString(error) << std::endl;
    return true;
}