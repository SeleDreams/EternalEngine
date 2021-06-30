#pragma once
#include <memory>
#include <Components/MeshComponent.hpp>
#include <Components/ShaderComponent.hpp>
#include <Components/TransformComponent.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace EternalEngine
{
    class Viewport
    {
    public:
        Viewport();
        ~Viewport();
        int create_viewport(int width, int height);
        void resize_viewport(int new_width, int new_height);
        void render(const MeshComponent &model,const ShaderComponent &shader,const TransformComponent &transform);
        unsigned int width() const { return _width; }
        unsigned int height() const { return _height; }
        void clear_viewport();

    private:
        glm::mat4 _projection = glm::mat4(1.0f);
        unsigned int _width, _height;
    };
}