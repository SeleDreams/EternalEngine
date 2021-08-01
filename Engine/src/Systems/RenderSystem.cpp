#include <Systems/RenderSystem.hpp>
#include <Game.hpp>
#include <Rendering/Window/RenderSurface.hpp>
#include <Rendering/Viewport/Viewport.hpp>
#include <Components/TransformComponent.hpp>
#include <Components/MeshComponent.hpp>
#include <Components/ShaderComponent.hpp>

//constexpr const float toRadians = M_PI / 180.0f;
void EternalEngine::RenderSystem::update(entt::registry &registry,float delta)
{
    auto viewport = Game::instance()->render_surface()->viewport();
    auto view = registry.view<TransformComponent,MeshComponent, ShaderComponent>();
    auto cam_view = registry.view<CameraComponent>();
    for (const auto &entity : view)
    {
        MeshComponent &mesh = view.get<MeshComponent>(entity);
        ShaderComponent &shader = view.get<ShaderComponent>(entity);
        CameraComponent &cam = cam_view.get<CameraComponent>(cam_view[0]);
        TransformComponent &trans = view.get<TransformComponent>(entity);
        viewport.render(mesh,shader,trans,cam);
    }
}