#include <Systems/RenderSystem.hpp>
#include <Game.hpp>
#include <Rendering/Window/RenderSurface.hpp>
#include <Rendering/Viewport/Viewport.hpp>
#include <Components/TransformComponent.hpp>

void EternalEngine::RenderSystem::update(float delta)
{
    auto viewport = Game::instance()->render_surface()->viewport();
    auto &registry = Game::instance()->main_scene()->entity_registry();
    auto view = registry.view<TransformComponent,MeshComponent, ShaderComponent>();
    for (auto &entity : view)
    {
        auto &transform = view.get<TransformComponent>(entity);
        auto &mesh = view.get<MeshComponent>(entity);
        auto &shader = view.get<ShaderComponent>(entity);
        viewport.render(mesh, shader, transform);
    }
}