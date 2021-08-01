#define USE_GLEW

#include <stdio.h>
#include <Game.hpp>
#include <Rendering/Window/Window.hpp>
#include <Components/TransformComponent.hpp>
#include <Components/MeshComponent.hpp>
#include <Components/ShaderComponent.hpp>
#include <string>
#include <sstream>
#include <fstream>
#include "MovementSystem.hpp"

using namespace EternalEngine;

void CreateMesh(MeshComponent &mesh)
{
    unsigned int indices[] =
        {
            0, 3, 1,
            1, 3, 2,
            2, 3, 0,
            0, 1, 2};

    // Define points of the vertex array
    float vertices[] = {
        -1.0f, -1.0f, 0.0f,
        0.0f, -1.0f, 1.0f,
        1.0f, -1.0f, 0.0f,
        0.0f, 1.0f, 0.0f};
    mesh.mesh.create(vertices, 12, indices, 12);
}

std::string LoadFile(std::string path)
{
    std::ifstream t(path);
    std::stringstream buffer;
    buffer << t.rdbuf();
    return buffer.str();
}

void CreateEntity(entt::registry &registry)
{
    auto entity = registry.create();
    auto &mesh = registry.emplace<MeshComponent>(entity);
    CreateMesh(mesh);
    auto &shader = registry.emplace<ShaderComponent>(entity);
    shader.shader.create(LoadFile("assets/shaders/vert.glsl"), LoadFile("assets/shaders/frag.glsl"));
    auto &_transform = registry.emplace<TransformComponent>(entity);
    //  _transform.Transform = glm::mat4(1.0f);
}
constexpr const float toRadians = M_PI / 180.0f;
int main(int argc, char **argv)
{
    Game game;
    if (!game.init(800, 600, "My Game"))
    {
        printf("An error occurred while initializing the game !");
    }
    Window *main_window = dynamic_cast<Window *>(game.render_surface().get());
    auto scene = game.main_scene();
    auto &registry = scene->entity_registry();
    auto view = registry.view<MeshComponent>();
    for (const auto &entity : view)
    {
        printf("entity !\n");
    }
    const auto &entity = registry.create();
    auto &_transform = registry.emplace_or_replace<TransformComponent>(entity);
    _transform.Transform = glm::mat4(1.0f);
    auto &_camera = registry.emplace_or_replace<CameraComponent>(entity);
    _camera.active = true;
    const auto &entity2 = registry.create();
    auto &mesh = registry.emplace_or_replace<MeshComponent>(entity2);
    CreateMesh(mesh);
    auto &shader = registry.emplace_or_replace<ShaderComponent>(entity2);
    shader.shader.create(LoadFile("assets/shaders/vert.glsl"), LoadFile("assets/shaders/frag.glsl"));
    auto &transform = registry.emplace_or_replace<TransformComponent>(entity2);

    scene->system_manager().add_system(std::shared_ptr<MovementSystem>(new MovementSystem()));

    game.run();
}