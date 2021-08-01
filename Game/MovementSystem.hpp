#pragma once
#include <Systems/ISystem.hpp>
#include <Components/TransformComponent.hpp>

namespace EternalEngine
{
    class MovementSystem : public ISystem
    {
        virtual const char *name() { return "MovementSystem"; }
        virtual void update(entt::registry &registry,float delta);
    };
};