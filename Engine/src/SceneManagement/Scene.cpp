#include <SceneManagement/Scene.hpp>
#include <Backend/OpenGL/GLUtils.hpp>
using namespace EternalEngine;

Scene::Scene()
{

}

Scene::~Scene()
{
    _system_manager.clear();
    _entity_registry.clear();
}

void Scene::update(float delta)
{
    _system_manager.update_systems(delta);
   // printf("FPS : %.8f\n",(1.0f / delta));
}