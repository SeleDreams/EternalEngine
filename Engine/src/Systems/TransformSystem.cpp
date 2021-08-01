#include <Systems/TransformSystem.hpp>
#include <Components/TransformComponent.hpp>
#include <Game.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/quaternion.hpp>
#include <Components/CameraComponent.hpp>

using namespace EternalEngine;

void TransformSystem::update(entt::registry &registry, float delta)
{
    auto viewport = Game::instance()->render_surface()->viewport();
    auto cam_view = registry.view<TransformComponent>();

    for (auto &entity : cam_view)
    {
        CameraComponent *cam_component = registry.try_get<CameraComponent>(entity);
        auto &transform = cam_view.get<TransformComponent>(entity);
        transform.forward = glm::normalize(glm::vec3(transform.Transform[2]));
        transform.right = glm::normalize(glm::vec3(transform.Transform[0]));
        transform.up = glm::normalize(glm::vec3(transform.Transform[1]));
        if (cam_component)
        {
            glm::vec3 cam_pos = glm::vec3(transform.Transform[3]);
            cam_component->view_matrix = glm::lookAt(cam_pos, cam_pos + transform.forward, transform.up);
            return;
        }
    }
}