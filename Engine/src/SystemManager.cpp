#include <Systems/SystemManager.hpp>

using namespace EternalEngine;

bool SystemManager::add_system(const char *name, std::function<std::shared_ptr<ISystem>()> func)
{
    _systems_map.emplace(name,func);
    return true;
}

void SystemManager::update_systems(float delta)
{
    for (ISystem *system : _systems)
    {
        system->update(delta);
    }
}