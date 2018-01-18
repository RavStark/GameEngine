#pragma once

#include <glm/glm.hpp>
#include "Scene/SceneElement.hpp"

typedef int GLint;
typedef unsigned int GLuint;
typedef float GLfloat;

class Model;
class Shader;
class ModelRenderer : public SceneElement
{
public:
	explicit ModelRenderer(const std::shared_ptr<Shader>& shader, const std::shared_ptr<Model> &model,const glm::vec3 &pos, const glm::vec3 &size = glm::vec3(1.f));
	~ModelRenderer();

	virtual void initRenderData();
	virtual void draw(const std::shared_ptr<Camera> &camera) const ;

private:
	std::shared_ptr<Model> _model;
};