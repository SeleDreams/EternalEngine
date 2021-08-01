
#include <Game.hpp>
#include "MovementSystem.hpp"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
constexpr const float toRadians = M_PI / 180.0f;
float rotation = 0.0f;
float movement = 0.0f;
bool right = false;
void EternalEngine::MovementSystem::update(entt::registry &registry, float delta)
{
    auto viewport = Game::instance()->render_surface()->viewport();
    auto view = registry.view<TransformComponent, MeshComponent>();
    for (auto &entity : view)
    {
        unsigned int id = static_cast<std::uint32_t>(entity);
        auto &_transform = view.get<TransformComponent>(entity);
        _transform.Transform = glm::mat4(1.0f);
        _transform.Transform = glm::translate(_transform.Transform, glm::vec3(0.0f, 0.0f, 3.0f));
        if (right)
        {
            movement += 10 * delta;
        }
        else
        {
            movement -= 10 * delta;
        }
        if (abs(movement) >= 30.0f)
        {
            right = !right;
        }
        rotation += 10 * delta;
        if (rotation >= 360)
        {
            rotation -= 360;
        }

        _transform.Transform = glm::rotate(_transform.Transform, 10 * rotation * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));

        auto camv = registry.view<CameraComponent,TransformComponent>();
        for (auto &ent : camv)
        {
            auto &trans = camv.get<TransformComponent>(ent);
            trans.Transform = glm::mat4(1.0f);
            trans.Transform = glm::translate(trans.Transform,glm::vec3(0.0f,0.0f,0.0f));
            printf("Value : %.2f\n", movement);
            trans.Transform = glm::rotate(trans.Transform, movement * toRadians, glm::vec3(1.0f,0.0f,0.0f));
        }
    }
}