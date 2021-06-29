#pragma once
#include <entt/entt.hpp>
namespace EternalEngine
{
    class Scene
    {
    public:
        Scene();
        ~Scene();
        void init();
        void update(float delta);
    private:
        entt::registry m_Registry;
    };
}