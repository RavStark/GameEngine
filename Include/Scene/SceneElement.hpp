#pragma once
#include <glm/glm.hpp>
#include <memory>
typedef int GLint;
typedef unsigned int GLuint;
typedef float GLfloat;

class LightsManager;
class Camera;
class Material;

class TextureManager;


class SceneElement
{
public:
	explicit SceneElement(const glm::vec3 &pos, const glm::vec3 &size);
	virtual ~SceneElement();

	virtual void initRenderData() = 0;
	virtual void draw(const glm::mat4 &view, const glm::mat4 &projection) const = 0;
	virtual void draw(const std::shared_ptr<TextureManager>& textureManger, const std::shared_ptr<Camera> &camera) const = 0;

	void setPos(const glm::vec3 &pos);
	glm::vec3 getPos() const;
	void setSize(const glm::vec3 &size);
	glm::vec3 getSize() const;
	void setColor(const glm::vec3 &color);
	glm::vec3 getColor() const;
	void setRotate(const float &rotate);
	float getRotate() const;

	void setMaterial(const std::shared_ptr<Material> &material);
	std::shared_ptr<Material> getMaterial() const;
	
protected:

	GLuint _vao;
	std::shared_ptr<Material> _material; //shared_ptr ?

	glm::vec3 _pos;
	glm::vec3 _size;
	glm::vec3 _color;
	float _rotate;
};