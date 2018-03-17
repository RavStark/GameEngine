#include "Resources/ResourceManager.hpp"
#include "Resources/Texture.hpp"
#include "Resources/Shader.hpp"
#include <SOIL.h>
#include <iostream>
std::shared_ptr<ResourceManager> ResourceManager::_instance = nullptr;

ResourceManager::ResourceManager()
{
	
}

ResourceManager::~ResourceManager()
{

}

/* Load Shader*/
Shader* ResourceManager::loadShader(const std::string &name, const char *pathVertex, const char *pathFragment)
{
	Shader *shader = new Shader(pathVertex, pathFragment);

	if (shader)
	{
		if (_shaderList.insert(std::make_pair(name, shader)).second == false)
		{
			std::cerr << "Error loading shader: name " << name.c_str() << " already used" << std::endl;
			return nullptr;
		}
		return shader;
	}
	return nullptr;
}

/* Get shader according to name */
Shader *ResourceManager::getShader(const std::string &name) const
{
	auto it = _shaderList.find(name);
	if (it != _shaderList.end())
		return it->second;
	return nullptr;
}
/* Texture */
Texture *ResourceManager::loadTexture(const std::string &name, const char* textureSource, bool alpha)
{
	// first check if texture has been loader already, if so; return earlier loaded texture
	auto it = _textureList.find(name);
	if (it != _textureList.end())
		return it->second;

	Texture *texture = new Texture();
	// Generate texture from file
	if (alpha)
	{
		texture->InternalFormat = GL_RGBA;
		texture->ImageFormat = GL_RGBA;
	}
	// Load image
	int width, height;
	unsigned char* image = SOIL_load_image(textureSource, &width, &height, 0, texture->ImageFormat == GL_RGBA ? SOIL_LOAD_RGBA : SOIL_LOAD_RGB);
	if (image == 0)
	{
		std::cerr << "TEXTUREMANAGER::LOADNEWTEXTURE::FAILED " << textureSource << std::endl;
		return nullptr;
	}
	// Now generate texture
	texture->generate(width, height, image);
	// And finally free image data
	SOIL_free_image_data(image);

	// Store and return
	_textureList.insert(std::make_pair(name, texture));
	return texture;
}

/* Cubemap */
Texture *ResourceManager::loadCubemap(const std::string &name, const std::vector<const char*> &textureSources, bool alpha)
{
	// first check if texture has been loader already, if so; return earlier loaded texture
	
	auto it = _textureList.find(name);
	if (it != _textureList.end())
		return it->second;

	Texture *texture = new CubemapTexture();
	// Generate texture from file
	if (alpha)
	{
		texture->InternalFormat = GL_RGBA;
		texture->ImageFormat = GL_RGBA;
	}
	// Load image
	int width, height;
	cubemapVec cubemapImages;
	int idx = 0;
	for (auto src : textureSources)
	{
		unsigned char* image = SOIL_load_image(src, &width, &height, 0, texture->ImageFormat == GL_RGBA ? SOIL_LOAD_RGBA : SOIL_LOAD_RGB);
		if (image == 0)
		{
			std::cerr << "TEXTUREMANAGER::LOADNEWTEXTURE::FAILED " << src << std::endl;
			return nullptr;
		}
		texture->generate(width, height, image, idx++);
		// And finally free image data
		SOIL_free_image_data(image);
	}
	// Store and return
	_textureList.insert(std::make_pair(name, texture));
	return texture;
}

Texture *ResourceManager::getTexture(const std::string &name) const
{
	auto it = _textureList.find(name);
	if (it != _textureList.end())
		return it->second;
	return nullptr;
}

std::shared_ptr<ResourceManager> ResourceManager::getInstance()
{
	if (_instance == nullptr)
	{
		_instance = std::make_shared<ResourceManager>();
	}
	return _instance;
}
