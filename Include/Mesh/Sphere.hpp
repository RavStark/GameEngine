#pragma once

#include <glm/glm.hpp>
#include "Mesh/Mesh.hpp"

class Sphere : public Mesh
{
public:
	Sphere();
	~Sphere();
	
	unsigned _numToDraw;
	unsigned VBO;

};