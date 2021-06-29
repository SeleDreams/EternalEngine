#pragma once
#include <memory>
#include <vector>
#include <map>
#include <functional>
#include "ISystem.hpp"

namespace EternalEngine
{
    class SystemManager
    {
    public:
        SystemManager() = default;
        ~SystemManager() = default;
        unsigned int add_system(std::shared_ptr<ISystem> system);
        void update_systems(float delta);

    private:
        std::vector<std::shared_ptr<ISystem>> _systems; 
        //std::map<const char*, std::function<std::shared_ptr<ISystem>()>> _systems_map;
    };
};