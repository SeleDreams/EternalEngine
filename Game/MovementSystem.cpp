
#include <Game.hpp>
#include "MovementSystem.hpp"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
constexpr const float toRadians = M_PI / 180.0f;
float rotation = 0.0f;

void EternalEngine::MovementSystem::update(float delta)
{
    auto viewport = Game::instance()->render_surface()->viewport();
    auto &registry = Game::instance()->main_scene()->entity_registry();
    auto view = registry.view<TransformComponent>();
    for (auto &entity : view)
    {
        auto &_transform = view.get<TransformComponent>(entity);
        _transform.Transform = glm::mat4(1.0f);
        _transform.Transform = glm::translate(_transform.Transform,glm::vec3(0.0f,0.0f,-4.0f));
        rotation += 10 * delta;
        if (rotation >= 360)
        {
            rotation -= 360;
        }
        _transform.Transform = glm::rotate(_transform.Transform,rotation * toRadians,glm::vec3(0.0f,1.0f,0.0f));
    }
}