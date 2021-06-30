#pragma once
#include "Component.hpp"
#include <Components/ComponentFactory.hpp>
#include <Rendering/Shader/Shader.hpp>

namespace EternalEngine
{
    struct ShaderComponent : public Component
    {
        ShaderComponent()
        {

        }
        Shader shader;
    };
 REGISTER_COMPONENT(ShaderComponent);
}