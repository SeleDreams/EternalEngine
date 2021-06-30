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
            transform.property_access = PROPERTY_ACCESS_WRITE;
            transform.property_name = "Transform";
            transform.property_type = PROPERTY_TYPE_MAT4;
            transform.property_address = &Transform;
            properties.insert_or_assign(transform.property_name,transform);
        }
        glm::mat4 Transform = glm::mat4(1.0f);
    };
  REGISTER_COMPONENT(TransformComponent);
};
