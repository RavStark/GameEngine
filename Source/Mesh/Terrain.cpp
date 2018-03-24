#include "Mesh/Terrain.hpp"
#include "Resources/ResourceManager.hpp"
#include <iostream>

/*
TODO:
	Load terrain from other data than a heightmap
*/

Terrain::Terrain(const char * heightMapPath)
	:Mesh()
{
	auto resources = ResourceManager::getInstance();
	
	unsigned char *data = resources->loadImage(heightMapPath, _width, _height);
	if (data != 0)
	{
		if (_height != _width) {
			std::cerr << "ERROR: Can't use a heightmap with a different width and height" << std::endl;
			return;
		}

		int terrainSize = 1;
		_heightMapScale = 15;

		// Vertex generation
		for (GLuint z = 0; z < _width; z++) {
			for (GLuint x = 0; x < _width; x++) {

				_vertices.push_back(glm::vec3(x * terrainSize, getVertexHeight(x, z, data), z * terrainSize));
				_normals.push_back(calculateNormal(x, z, data));
				_UV.push_back(glm::vec2(x * terrainSize, z * terrainSize));
			}
		}
		//Generate indices CW 
		for (GLuint z = 0; z < _width - 1; ++z)
		{
			for (GLuint x = 0; x < _width - 1; ++x)
			{
				//First triangle
				_indices.push_back(x + (z * _width) + 1);
				_indices.push_back(x + (z * _width));
				_indices.push_back(x + (z * _width) + _width);
				//Second triange
				_indices.push_back(x + (z * _width) + _width);
				_indices.push_back(x + (z * _width) + _width + 1);
				_indices.push_back(x + (z * _width) +1);	
				
			}
		}
		resources->freeImage(data);
		initRenderData();
	}
}

float Terrain::getVertexHeight(int x, int z, const unsigned char *heightMapData) const
{
	if (x < 0 || x >= _height || z < 0 || z >= _height) {
		return 0.0f;
	}

	// Normalize height to [-1, 1] then multiply it by the height map scale
	return ((heightMapData[x + (z * _height)] / 127.5f) - 1) * _heightMapScale;
}

glm::vec3 Terrain::calculateNormal(int x, int z, const unsigned char *heightMapData) const
{
	/*
		Get each neighbor's height then calculate a normal vector
		Normal vector y always point to the top and coord x and z is calculate according to the neighbor's height

	*/
	float heightRight = getVertexHeight(x + 1, z, heightMapData);
	float heightLeft = getVertexHeight(x - 1, z, heightMapData);
	float heightUp = getVertexHeight(x, z + 1, heightMapData);
	float heightDown = getVertexHeight(x, z - 1, heightMapData);

	glm::vec3 normal(heightLeft - heightRight, 1.0f, heightDown - heightUp);
	normal = glm::normalize(normal);

	return normal;
}