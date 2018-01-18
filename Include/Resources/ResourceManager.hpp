#pragma once

#include <memory>
#include <list>
#include <unordered_map>

class Scene;
class Shader;
class Texture;
typedef int GLint;
typedef unsigned int GLuint;
/* Need to understand bit specification to replace GlInt */
class ResourceManager
{
public:
	ResourceManager();
	~ResourceManager();
	
	//load a xml file and fill a scene
	bool loadLevel(const std::string &levelFile, Scene *scene);

	/* Load Shader*/
	Shader* loadShader(const std::string &name, const char *pathVertex, const char *pathFragment);
	/* Get shader according to name */
	Shader *getShader(const std::string &name) const;

	/* Texture2D*/

	Texture *loadTexture(const std::string &name, const char* textureSource, bool alpha);
	Texture *getTexture(const std::string &name) const;

	/* RessourceManager singleton */
	static std::shared_ptr<ResourceManager> getInstance();
private:
	std::unordered_map<std::string, Shader*> _shaderList;
	std::unordered_map<std::string, Texture*> _textureList;
	static std::shared_ptr<ResourceManager> _instance;
};