
#pragma once
#include <string>
#include <map>
#include <functional>
#include <Components/Component.hpp>
#include <memory>
namespace EternalEngine
{
    class ComponentFactory
    {
    public:
        static bool RegisterComponent(std::string name, std::function<std::shared_ptr<Component>()> func)
        {
            _components.insert_or_assign(name, func);
            return true;
        }

        static std::shared_ptr<Component> InstantiateComponent(std::string component)
        {
            if (_components.count(component))
            {
                return _components[component]();
            }
            else
            {
                return std::shared_ptr<Component>(nullptr);
            }
        }

    private:
        static std::map<std::string, std::function<std::shared_ptr<Component>()>> _components;
    };
}
