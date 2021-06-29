#pragma once
#include <glm/glm.hpp>
#include <string>
#include <Components/Component.hpp>
#include <Components/ComponentFactory.hpp>

namespace EternalEngine
{
    struct TransformComponent : public Component
    {
        TransformComponent()
        {
            properties.clear();
            ComponentProperty transform;
            transform.PropertyAccess = PROPERTY_ACCESS_WRITE;
            transform.PropertyName = "Transform";
            transform.PropertyType = PROPERTY_TYPE_MAT4;
            transform.PropertyAddress = &Transform;
            properties.insert_or_assign(transform.PropertyName,transform);
        }
        glm::mat4 Transform;
    };
    REGISTER_COMPONENT(TransformComponent);
};
