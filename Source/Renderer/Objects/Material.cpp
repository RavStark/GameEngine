#include "Renderer/Objects/Material.hpp"
#include "Resources/Shader.hpp"
#include <iostream>

Material::Material()
	:_shader(nullptr),
	_shininess(32.f)
{

}

Material::~Material()
{

}

void Material::preRender()
{
	if (_shader)
	{
		_shader->setVec3("material.ambient", _ambient);
		_shader->setVec3("material.diffuse", _diffuse);
		_shader->setVec3("material.specular", _specular);
		_shader->setFloat("material.shininess", _shininess);
	}
	else
		std::cerr << "No shader has been set" << std::endl;
}

void Material::setShader(Shader *shader)
{
	_shader = shader;
}

Shader *Material::getShader() const
{
	return _shader;
}

void Material::setColor(const glm::vec3 &color)
{
	_color = color;
}

glm::vec3 Material::getColor() const
{
	return _color;
}

void Material::setAmbient(const glm::vec3 &ambient)
{
	_ambient = ambient;
}

glm::vec3 Material::getAmbient() const
{
	return _ambient;
}

void Material::setDiffuse(const glm::vec3 &diffuse)
{
	_diffuse = diffuse;
}

glm::vec3 Material::getDiffuse() const
{
	return _diffuse;
}

void Material::setSpecular(const glm::vec3 &specular)
{
	_specular = specular;
}

glm::vec3 Material::getSpecular() const
{
	return _specular;
}

void Material::setShininess(const float shininess)
{
	_shininess = shininess;
}

float Material::getShininess() const
{
	return _shininess;
}