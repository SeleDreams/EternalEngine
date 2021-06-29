#pragma once
#include <entt/entt.hpp>
#include <Systems/SystemManager.hpp>

namespace EternalEngine
{
    class Scene
    {
    public:
        Scene();
        ~Scene();
        void init();
        void update(float delta);
        SystemManager &system_manager() { return _system_manager; }
        entt::registry &entity_registry() { return _entity_registry; }
    private:
        entt::registry _entity_registry;
        SystemManager _system_manager;

    };
}