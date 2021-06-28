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
        static SystemManager &get_singleton()
        {
            static SystemManager singleton;
            return singleton;
        }
        SystemManager();
        ~SystemManager();
        bool add_system(const char *name, std::function<std::shared_ptr<ISystem>()> func);
        void update_systems(float delta);

    private:
        std::vector<ISystem*> _systems; 
        std::map<const char*, std::function<std::shared_ptr<ISystem>()>> _systems_map;
    };
};