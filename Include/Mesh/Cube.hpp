#pragma once

#include "Mesh/Mesh.hpp"

typedef int GLint;
typedef unsigned int GLuint;
typedef float GLfloat;

class Cube : public Mesh
{
public:
	explicit Cube();//const glm::vec3 &pos, const glm::vec3 &size = glm::vec3(1.0), const glm::vec3& color = glm::vec3(1.0));
	~Cube();
};