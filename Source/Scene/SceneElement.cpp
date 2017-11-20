#include "Scene/SceneElement.hpp"
#include <iostream>

#include "GL\glew.h"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Resources/TextureManager.hpp"

SceneElement::SceneElement(const std::shared_ptr<Shader>& shader, const glm::vec3 &pos, const glm::vec3 &size, const glm::vec3& color)
	: _shader(shader), _pos(pos), _size(size), _color(color), _rotate(0)

{
	
}

SceneElement::~SceneElement()
{

}

void SceneElement::setPos(const glm::vec3 &pos)
{
	_pos = pos;
}

glm::vec3 SceneElement::getPos() const
{
	return _pos;
}

void SceneElement::setSize(const glm::vec3 &size)
{
	_size = size;
}

glm::vec3 SceneElement::getSize() const
{
	return _size;
}

void SceneElement::setColor(const glm::vec3 &color)
{
	_color = color;
}

glm::vec3 SceneElement::getColor() const
{
	return _color;
}

void SceneElement::setRotate(const float &rotate)
{
	_rotate = rotate;
}

float SceneElement::getRotate() const
{
	return _rotate;
}