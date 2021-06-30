
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
        static ComponentFactory &singleton()
        {
            static ComponentFactory factory;
            return factory;
        }
        ComponentFactory();
        ~ComponentFactory();

        bool RegisterComponent(const std::string &name, const std::function<std::shared_ptr<Component>()> &func);

        std::shared_ptr<Component> InstantiateComponent(const std::string &component);

    private:
        std::map<std::string, std::function<std::shared_ptr<Component>()>> _components;
    };
}
