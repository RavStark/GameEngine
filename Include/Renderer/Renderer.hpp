#pragma once
#include "GL\glew.h"
#include <memory>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Resources/Shader.hpp"
#include <vector>
class LightsManager;
class ObjectsManager;
class Object;
class PointLight;
class DirectionLight;
class Camera;
class ModelRenderer;
class Scene;

class Renderer
{
public:
	enum Type {
		LIGHT,
		DEFAULT
	};
	explicit Renderer(const std::shared_ptr<Camera>& camera);
	
	void update(Scene *scene);
	void draw(Scene *scene);
private:
	
	std::shared_ptr<Camera> _camera = nullptr;

	std::shared_ptr<LightsManager> _lightsManager = nullptr;

};