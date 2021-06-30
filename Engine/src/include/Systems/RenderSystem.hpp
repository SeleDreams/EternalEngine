#pragma once
#include <Systems/ISystem.hpp>
#include <Components/ShaderComponent.hpp>
#include <Components/MeshComponent.hpp>

namespace EternalEngine
{
    class RenderSystem : public ISystem
    {
        virtual const char *name() { return "RenderSystem"; }
        virtual void update(float delta);
    };
};