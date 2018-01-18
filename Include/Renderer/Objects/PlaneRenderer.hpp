#pragma once

#include <glm/glm.hpp>
#include "Scene/SceneElement.hpp"

typedef int GLint;
typedef unsigned int GLuint;
typedef float GLfloat;
class Shader;

class PlaneRenderer : public SceneElement
{
public:
	explicit PlaneRenderer(const glm::vec3 &pos, const glm::vec3 &size = glm::vec3(1.f), const glm::vec3& color = glm::vec3(1.f));
	~PlaneRenderer();

	virtual void initRenderData();
	virtual void draw(const std::shared_ptr<Camera> &camera) const;

};