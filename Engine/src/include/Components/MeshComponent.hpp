#pragma once
#include <Components/Component.hpp>
#include <Rendering/Mesh/Mesh.hpp>
#include <Components/ComponentFactory.hpp>
namespace EternalEngine
{
    struct MeshComponent : Component
    {
        MeshComponent()
        {
            properties.clear();
            ComponentProperty mesh_property;
            mesh_property.property_access = PROPERTY_ACCESS_WRITE;
            mesh_property.property_name = "mesh";
            mesh_property.property_type = PROPERTY_TYPE_NONE;
            mesh_property.property_address = &mesh;
            properties.insert_or_assign(mesh_property.property_name,mesh_property);
        }
        Mesh mesh;
    };
   REGISTER_COMPONENT(MeshComponent);
}