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
            0, 1, 2
            };

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
    auto entity = registry.create();
    auto &_transform = registry.emplace<TransformComponent>(entity);
    _transform.Transform = glm::mat4(1.0f);
    auto &mesh = registry.emplace<MeshComponent>(entity);
    CreateMesh(mesh);
    auto &shader = registry.emplace<ShaderComponent>(entity);
    shader.shader.create(LoadFile("assets/shaders/vert.glsl"),LoadFile("assets/shaders/frag.glsl"));
    scene->system_manager().add_system(std::shared_ptr<MovementSystem>(new MovementSystem()));
    game.run();
}