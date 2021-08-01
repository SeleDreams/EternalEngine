#pragma once
#include <entt/entt.hpp>
#include <memory>
namespace EternalEngine
{
    class ISystem
    {
    public:
        ISystem() = default;
        ~ISystem() = default;
        virtual const char *name() = 0;
        virtual void update(entt::registry &registry, float delta) = 0;
    };
};
