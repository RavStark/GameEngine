#pragma once

#include <memory>
#include <list>
#include <unordered_map>

class SceneElement;
class Camera;
class PointLight;
class DirectionLight;
class LightsManager;

class Scene
{
public:
	explicit Scene(const std::shared_ptr<Camera> &camera);
	~Scene();

	void addObject(const std::shared_ptr<SceneElement>&);
	void addLight(const std::shared_ptr<PointLight>&);
	void addLight(const std::shared_ptr<DirectionLight>&);
	void initialize();
	void update();
	void draw();
private:
	std::shared_ptr<Camera> _camera;
	std::shared_ptr<LightsManager> _lightsManager;

	std::list<std::weak_ptr<SceneElement>> _sceneElements;
	long long int _id = 0;
};