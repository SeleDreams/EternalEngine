#pragma once
#include "Component.hpp"
#include <Components/ComponentFactory.hpp>
namespace EternalEngine
{
    struct ShaderComponent : public Component
    {
        ShaderComponent()
        {

        }
        unsigned int program_location = 0;
        unsigned int model_uniform = 0;
        unsigned int projection_uniform = 0;
    };
 //   REGISTER_COMPONENT(ShaderComponent);
}