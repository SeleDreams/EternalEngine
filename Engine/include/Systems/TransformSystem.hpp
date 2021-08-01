#pragma once
#include <Systems/ISystem.hpp>
#include <glm/glm.hpp>

namespace EternalEngine
{
    class TransformSystem : public ISystem
    {
        virtual const char *name() { return "TransformSystem"; }
        virtual void update(entt::registry &registry,float delta);

    private:
        glm::vec3 forward = glm::vec3(0.0f, 0.0f, -1.0f);
        glm::vec3 up = glm::vec3(0.0f, 0.0f, 1.0f);
        glm::vec3 right = glm::vec3(1.0f, 0.0f, 0.0f);
    };
};