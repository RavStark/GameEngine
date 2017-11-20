#include "Scene/Scene.hpp"
#include "Scene/SceneElement.hpp"
#include "Camera/Camera.hpp"
#include "Resources/TextureManager.hpp"
#include <iostream>

#include "GL\glew.h"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


Scene::Scene(const std::shared_ptr<Camera> &camera, const std::shared_ptr<TextureManager> &textureManager)
	: _camera(camera), _textureManager(textureManager)
{

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

void Scene::addObject(std::shared_ptr<SceneElement>&obj)
{
	if (obj)
	{
		_sceneElements.push_back(obj);
	}
}

void Scene::draw()
{
	/* DRAW OBJECT */
	for (auto obj : _sceneElements)
	{
		obj.lock()->draw(_textureManager, _camera);
	}
}
