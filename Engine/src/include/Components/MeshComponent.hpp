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
            mesh_property.PropertyAccess = PROPERTY_ACCESS_WRITE;
            mesh_property.PropertyName = "mesh";
            mesh_property.PropertyType = PROPERTY_TYPE_NONE;
            mesh_property.PropertyAddress = &mesh;
            properties.insert_or_assign(mesh_property.PropertyName,mesh_property);
        }
        Mesh mesh;
    };
   // REGISTER_COMPONENT(MeshComponent);
}