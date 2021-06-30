#include <Components/ComponentFactory.hpp>

using namespace EternalEngine;

ComponentFactory::ComponentFactory()
{
}

ComponentFactory::~ComponentFactory()
{
}

bool ComponentFactory::RegisterComponent(const std::string &name,const std::function<std::shared_ptr<Component>()> &func)
{
    _components.insert_or_assign(name, func);
    return true;
}

std::shared_ptr<Component> ComponentFactory::InstantiateComponent(const std::string &component)
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