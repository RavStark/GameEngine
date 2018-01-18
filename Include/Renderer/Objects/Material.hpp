#pragma once

#include <glm/glm.hpp>

typedef int GLint;
typedef unsigned int GLuint;
typedef float GLfloat;

class Shader;
class Texture;
/*
  Material class contains color, ambient, diffuse, specular
   and Shader
   TODO:
   Add texture2D normal map
*/

class Material
{
public:
	Material();
	~Material();

	/* pre set shader data */
	void preRender();

	void setShader(Shader *shader);
	Shader *getShader() const;

	void setTexture(Texture *texture);
	Texture *getTexture() const;

	void setColor(const glm::vec3 &color);
	glm::vec3 getColor() const;

	void setAmbient(const glm::vec3 &ambient);
	glm::vec3 getAmbient() const;

	void setDiffuse(const glm::vec3 &diffuse);
	glm::vec3 getDiffuse() const;

	void setSpecular(const glm::vec3 &specular);
	glm::vec3 getSpecular() const;

	void setShininess(const float shininess);
	float getShininess() const;

private:
	Shader *_shader = nullptr;
	Texture *_texture = nullptr;
	glm::vec3 _color;
	glm::vec3 _ambient;
	glm::vec3 _diffuse;
	glm::vec3 _specular;
	float _shininess;
};