#pragma once

#include <memory>
#include <list>
#include <unordered_map>

class Scene;
class Shader;
class TextureManager;
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

	/* LoadTexture */
	void loadTexture2D(const std::string &name, const char *path, GLint texture_wrap_s, GLint texture_wrap_t,
		GLint texture_min_filter, GLint texture_mag_filter);
	/* Get texture2d according to name */
	int getTexture2D(const std::string &name) const;

	/* Load Shader*/
	Shader* loadShader(const std::string &name, const char *pathVertex, const char *pathFragment);
	/* Get shader according to name */
	Shader *getShader(const std::string &name) const;
	/* RessourceManager singleton */
	static std::shared_ptr<ResourceManager> getInstance();
private:
	std::unordered_map<std::string, Shader*> _shaderList;
	std::unique_ptr<TextureManager> _textureManager = nullptr;
	static std::shared_ptr<ResourceManager> _instance;
};