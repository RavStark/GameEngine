#include "Scene/Scene.hpp"
#include "Scene/SceneElement.hpp"
#include "Camera/Camera.hpp"
#include "Resources/ResourceManager.hpp"
#include "Renderer/LightsManager.hpp"
#include <iostream>

#include "GL\glew.h"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


Scene::Scene(const std::shared_ptr<Camera> &camera)
	: _camera(camera)
{
	_lightsManager = std::make_shared<LightsManager>();
}

Scene::~Scene()
{}

void Scene::initialize()
{
	for (auto element : _sceneElements)
	{
		element.lock()->initRenderData();
	}
}

void Scene::addObject(const std::shared_ptr<SceneElement>&obj)
{
	if (obj)
	{
		_sceneElements.push_back(obj);
	}
}

void Scene::addLight(const std::shared_ptr<PointLight>&light)
{
	if (light)
	{
		_lightsManager->addLight(light);
	}
}

void Scene::addLight(const std::shared_ptr<DirectionLight>&light)
{
	if (light)
	{
		_lightsManager->addLight(light);
	}
}

void Scene::draw()
{
	_lightsManager->preRender(ResourceManager::getInstance()->getShader("color"));
	/* DRAW OBJECT */

	for (auto obj : _sceneElements)
	{
		obj.lock()->draw(_camera);
	}
}
