#include "Scene/SceneElement.hpp"
#include <iostream>

#include "GL\glew.h"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Renderer\Objects\Material.hpp"

SceneElement::SceneElement(const glm::vec3 &pos, const glm::vec3 &size)
	: _pos(pos), _size(size), _rotate(0)

{
	
}

SceneElement::SceneElement(Mesh *mesh, Material *material)
	:_mesh(mesh), _material(material)
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

void SceneElement::setMaterial(Material *material)
{
	_material = material;
}

Material *SceneElement::getMaterial() const
{
	return _material;
}

void SceneElement::setMesh(Mesh *mesh)
{
	_mesh = mesh;
}

Mesh* SceneElement::getMesh()
{
	return _mesh;
}