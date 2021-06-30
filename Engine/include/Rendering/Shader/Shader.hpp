#pragma once
#include <string>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <map>
#ifdef USE_GLEW
#include <GL/glew.h>
#endif

namespace EternalEngine
{
    struct Uniform
    {
        std::string name;
        GLenum type;
        GLuint type_size;
        GLuint index;
    };

    class Shader
    {
    public:
        Shader();
        ~Shader();
        bool create(const std::string &vert_shader,const std::string &frag_shader);
        void use(bool status = true) const;
        void clear();
        void set_uniform(const std::string &uniform,const glm::mat4 &value) const;
    private:
        GLuint _program;
        bool add_shader(const std::string &code,GLenum shader_type);
        std::map<std::string,Uniform> _uniforms;
    };
}