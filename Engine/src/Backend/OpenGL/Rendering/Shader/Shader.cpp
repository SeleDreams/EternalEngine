#include <Rendering/Shader/Shader.hpp>
#include <string.h>
#include <Backend/OpenGL/GLUtils.hpp>
#include <glm/gtc/type_ptr.hpp>

using namespace EternalEngine;

Shader::Shader()
{
    _program = 0;
}

Shader::~Shader()
{
    clear();
}

bool Shader::add_shader(const std::string &code, GLenum shader_type)
{
    GLuint theShader = glCreateShader(shader_type);
    const GLchar *theCode[1];
    theCode[0] = code.c_str();
    GLint codeLength[1];
    codeLength[0] = strlen(code.c_str());
    glShaderSource(theShader, 1, theCode, codeLength);
    glCompileShader(theShader);
    GLint result = 0;
    GLchar eLog[1024];
    glGetShaderiv(theShader, GL_COMPILE_STATUS, &result);
    if (!result)
    {
        glGetShaderInfoLog(theShader, sizeof(eLog), NULL, eLog);
        printf("Error compiling shader %s\n", eLog);
        return false;
    }

    glAttachShader(_program, theShader);
    return true;
}

bool Shader::create(const std::string &vert_shader, const std::string &frag_shader)
{
    _program = glCreateProgram();
    bool first_added = add_shader(vert_shader.c_str(), GL_VERTEX_SHADER);
    bool second_added = add_shader(frag_shader.c_str(), GL_FRAGMENT_SHADER);
    if (!first_added || !second_added)
    {
        return false;
    }
    GLint result = 0;
    GLchar eLog[1024];
    glLinkProgram(_program);
    glGetProgramiv(_program, GL_LINK_STATUS, &result);
    if (!result)
    {
        glGetProgramInfoLog(_program, sizeof(eLog), NULL, eLog);
        printf("Error linking program %s\n", eLog);
        return false;
    }
    glValidateProgram(_program);
    glGetProgramiv(_program, GL_VALIDATE_STATUS, &result);
    if (!result)
    {
        glGetProgramInfoLog(_program, sizeof(eLog), NULL, eLog);
        printf("Error validating program %s\n", eLog);
        return false;
    }
    GLint count = 0;
    GLint size;  // size of the variable
    GLenum type; // type of the variable (float, vec3 or mat4, etc)

    const GLsizei bufSize = 16; // maximum name length
    GLchar name[bufSize];       // variable name in GLSL
    GLsizei length;             // name length

    glGetProgramiv(_program, GL_ACTIVE_UNIFORMS, &count);
    printf("Active Uniforms: %d\n", count);

    for (GLint i = 0; i < count; i++)
    {
        glGetActiveUniform(_program, (GLuint)i, bufSize, &length, &size, &type, name);
        Uniform uniform;
        uniform.index = i;
        uniform.name = name;
        uniform.type = type;
        uniform.type_size = size;
        _uniforms.insert_or_assign(uniform.name, uniform);
        printf("Uniform #%d Type: %u Name: %s\n", i, type, name);
    }
    return true;
}

void Shader::set_uniform(const std::string &uniform, const glm::mat4 &value) const
{
    GLint id;
    glGetIntegerv(GL_CURRENT_PROGRAM, &id);
    glUseProgram(_program);
    GLuint location = _uniforms.at(uniform).index;
    glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(value));
    glUseProgram(id);
}

void Shader::clear()
{
    if (_program)
    {
        glDeleteProgram(_program);
        _program = 0;
    }
    _uniforms.clear();
}

void Shader::use(bool status) const
{
    if (status)
    {
        glUseProgram(_program);
    }
    else
    {
        glUseProgram(0);
    }
}