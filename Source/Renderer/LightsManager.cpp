#include "Renderer/LightsManager.hpp"
#include "Renderer/Lights/PointLight.hpp"
#include "Renderer/Lights/DirectionLight.hpp"
#include "Resources/Shader.hpp"
#include <iostream>

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


LightsManager::LightsManager()
{

}

LightsManager::~LightsManager()
{}

void LightsManager::preRender(Shader *shader) const
{
	//first test, use only the first point light
	if (!_pointLights.empty())
	{
		shader->setVec3("light.position", (*_pointLights.begin())->getPos());
		shader->setVec3("light.ambient", (*_pointLights.begin())->getAmbient());
		shader->setVec3("light.diffuse", (*_pointLights.begin())->getDiffuse());
		shader->setVec3("light.specular", (*_pointLights.begin())->getSpecular());
	}
}

void LightsManager::addLight(const std::shared_ptr<PointLight>&pointlight)
{
	_pointLights.push_back(pointlight);
}

void LightsManager::addLight(const std::shared_ptr<DirectionLight>&dirlight)
{
	_dirLights.push_back(dirlight);
}

std::vector<std::shared_ptr<PointLight>> LightsManager::getPointLights() const
{
	return _pointLights;
}

std::vector<std::shared_ptr<DirectionLight>> LightsManager::getDirectionLights() const
{
	return _dirLights;
}