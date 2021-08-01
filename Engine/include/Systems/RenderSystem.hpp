#pragma once
#include <Systems/ISystem.hpp>

namespace EternalEngine
{
    class RenderSystem : public ISystem
    {
        virtual const char *name() { return "RenderSystem"; }
        virtual void update(entt::registry &registry,float delta);
    };
};