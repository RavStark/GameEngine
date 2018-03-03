#pragma once
#include <glm/glm.hpp>
#include <memory>
typedef int GLint;
typedef unsigned int GLuint;
typedef float GLfloat;

class LightsManager;
class Camera;
class Material;
class Mesh;

class SceneElement
{
public:
	explicit SceneElement(const glm::vec3 &pos, const glm::vec3 &size);
	explicit SceneElement(Mesh *mesh, Material *material);
	virtual ~SceneElement();

	void setPos(const glm::vec3 &pos);
	glm::vec3 getPos() const;
	void setSize(const glm::vec3 &size);
	glm::vec3 getSize() const;
	void setColor(const glm::vec3 &color);
	glm::vec3 getColor() const;
	void setRotate(const float &rotate);
	float getRotate() const;

	void setMaterial(Material *material);
	Material *getMaterial() const;
	void setMesh(Mesh*);
	Mesh* getMesh();
	
protected:

	Material *_material;
	Mesh *_mesh;

	glm::vec3 _pos;
	glm::vec3 _size;
	glm::vec3 _color;
	float _rotate;
};