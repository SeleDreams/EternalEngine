#include <Scene.hpp>

using namespace EternalEngine;

Scene::Scene()
{

}

Scene::~Scene()
{
    
}

void Scene::update(float delta)
{
    printf("FPS : %.8f\n",(1.0f / delta));
}