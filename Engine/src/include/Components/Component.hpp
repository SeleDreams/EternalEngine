#pragma once
#include <string>
#include <map>

namespace EternalEngine
{
    class ComponentFactory;
    enum PropertyType
    {
        PROPERTY_TYPE_NONE,
        PROPERTY_TYPE_INT,
        PROPERTY_TYPE_FLOAT,
        PROPERTY_TYPE_STRING,
        PROPERTY_TYPE_VEC2,
        PROPERTY_TYPE_VEC3,
        PROPERTY_TYPE_VEC4,
        PROPERTY_TYPE_MAT4
    };
    enum PropertyAccess
    {
        PROPERTY_ACCESS_NONE,
        PROPERTY_ACCESS_READ,
        PROPERTY_ACCESS_WRITE
    };
    struct ComponentProperty
    {
        std::string property_name;
        PropertyType property_type;
        PropertyAccess property_access;
        void *property_address;
    };

    struct Component
    {
        ComponentProperty get_property(std::string name)
        {
            if (properties.count(name))
            {
                return properties[name];
            }
            else
            {
                return ComponentProperty();
            }
        }

    protected:
        std::map<std::string, ComponentProperty> properties;
        friend ComponentFactory;
    };

#define REGISTER_COMPONENT(name)    \
    static const bool ____registered_component_##name = ComponentFactory::singleton().RegisterComponent(#name, []() -> std::shared_ptr<name> \
    {\
        return std::shared_ptr<name>(new name());\
    })
}