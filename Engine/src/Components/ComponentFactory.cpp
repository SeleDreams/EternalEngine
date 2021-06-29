#include <Components/ComponentFactory.hpp>

using namespace EternalEngine;

std::map<std::string, std::function<std::shared_ptr<Component>()>> ComponentFactory::_components;