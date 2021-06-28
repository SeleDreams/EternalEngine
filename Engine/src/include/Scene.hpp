#pragma once
#include <entt/entt.hpp>
namespace EternalEngine
{
    class Scene
    {
    public:
        Scene();
        ~Scene();
    private:
        entt::registry m_Registry;
    };
}