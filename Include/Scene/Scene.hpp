#pragma once

#include <memory>
#include <list>
#include <unordered_map>

class SceneElement;
class PointLight;
class DirectionLight;
class LightsManager;

class Scene
{
public:
	explicit Scene();
	~Scene();

	void preRender();
	void addObject(SceneElement*);
	void addLight(const std::shared_ptr<PointLight>&);
	void addLight(const std::shared_ptr<DirectionLight>&);

	//TODO: Get elements from a certain id, type?
	std::list<SceneElement*> getSceneElements() const;
private:
	std::shared_ptr<LightsManager> _lightsManager;

	std::list<SceneElement*> _sceneElements;
	long long int _id = 0;
};