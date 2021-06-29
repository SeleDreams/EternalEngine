#include <SceneManagement/Scene.hpp>

using namespace EternalEngine;

Scene::Scene()
{

}

Scene::~Scene()
{
    
}

void Scene::update(float delta)
{
    _system_manager.update_systems(delta);
   // printf("FPS : %.8f\n",(1.0f / delta));
}