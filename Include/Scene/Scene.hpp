#pragma once

#include <memory>
#include <list>
#include <unordered_map>

class SceneElement;
class TextureManager;
class Camera;
typedef int GLint;
typedef unsigned int GLuint;
typedef float GLfloat;

class Scene
{
public:
	Scene(const std::shared_ptr<Camera> &camera, const std::shared_ptr<TextureManager> &textureManager);
	~Scene();

	void addObject(std::shared_ptr<SceneElement>&);
	void initialize();
	void update();
	void draw();
private:
	std::shared_ptr<Camera> _camera;
	std::shared_ptr<TextureManager> _textureManager;
	std::list<std::weak_ptr<SceneElement>> _sceneElements;
	long long int _id = 0;
};