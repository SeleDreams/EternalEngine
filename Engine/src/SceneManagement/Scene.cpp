#include <SceneManagement/Scene.hpp>
#include <Backend/OpenGL/GLUtils.hpp>
using namespace EternalEngine;

Scene::Scene()
{
}

Scene::~Scene()
{
}

void Scene::update(float delta)
{
    _system_manager.update_systems(_entity_registry,delta);
   // printf("FPS : %.8f\n",(1.0f / delta));
}