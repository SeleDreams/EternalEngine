#include <Systems/SystemManager.hpp>

using namespace EternalEngine;


unsigned int SystemManager::add_system(std::shared_ptr<ISystem> system)
{
    unsigned int id = _systems.size();
    _systems.push_back(system);
    return id;
}

void SystemManager::update_systems(entt::registry &registry,float delta)
{
    for (std::shared_ptr<ISystem> system : _systems)
    {
        system->update(registry,delta);
    }
}