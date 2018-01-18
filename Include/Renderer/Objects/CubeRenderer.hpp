#pragma once

#include <glm/glm.hpp>
#include "Scene/SceneElement.hpp"

typedef int GLint;
typedef unsigned int GLuint;
typedef float GLfloat;

class CubeRenderer : public SceneElement
{
public:
	explicit CubeRenderer(const glm::vec3 &pos, const glm::vec3 &size = glm::vec3(1.0), const glm::vec3& color = glm::vec3(1.0));
	~CubeRenderer();

	virtual void initRenderData();
	virtual void draw(const std::shared_ptr<Camera> &camera) const ;

};