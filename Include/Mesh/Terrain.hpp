#pragma once

#include "Mesh/Mesh.hpp"

class Terrain : public Mesh
{
public:
	Terrain(const char * heightMapPath);
	float getVertexHeight(int x, int z,const unsigned char *heightMapData) const;
	glm::vec3 Terrain::calculateNormal(int x, int z, const unsigned char *heightMapData) const;

private:
	int _height, _width;
	int _heightMapScale;
};