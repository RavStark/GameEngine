#include "Resources/ResourceManager.hpp"
#include "Resources/TextureManager.hpp"
#include "Resources/Shader.hpp"
#include <iostream>
std::shared_ptr<ResourceManager> ResourceManager::_instance = nullptr;

ResourceManager::ResourceManager()
{
	_textureManager = std::make_unique<TextureManager>();
}

ResourceManager::~ResourceManager()
{

}

void ResourceManager::loadTexture2D(const std::string &name, const char *path, GLint texture_wrap_s, GLint texture_wrap_t,
	GLint texture_min_filter, GLint texture_mag_filter)
{
	_textureManager->loadNewTexture2D(name, path, texture_wrap_s, texture_wrap_t,
		texture_min_filter, texture_mag_filter);
}


int ResourceManager::getTexture2D(const std::string &name) const
{
	return _textureManager->getTexture(name);
}

/* Load Shader*/
Shader* ResourceManager::loadShader(const char *name, const char *pathVertex, const char *pathFragment)
{
	Shader *shader = new Shader(pathVertex, pathFragment);

	if (shader)
	{
		if (_shaderList.insert(std::make_pair(name, shader)).second == false)
		{
			std::cerr << "Error loading shader: name " << name << " already used" << std::endl;
			return nullptr;
		}
		return shader;
	}
	return nullptr;
}

/* Get shader according to name */
Shader *ResourceManager::getShader(const char *name) const
{
	auto it = _shaderList.find(name);
	if (it != _shaderList.end())
		return it->second;
	return nullptr;
}

std::shared_ptr<ResourceManager> ResourceManager::getInstance()
{
	if (_instance == nullptr)
		return std::make_shared<ResourceManager>();
	return _instance;
}
