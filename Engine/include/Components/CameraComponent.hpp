#pragma once
#include "Component.hpp"

namespace EternalEngine
{
    struct CameraComponent : public Component
    {
        CameraComponent() = default;
        glm::mat4 view_matrix = glm::mat4(1.0);
        bool active = true;
    };
}