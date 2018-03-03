#pragma once

#include <unordered_map>
#include <glm/glm.hpp>

class Mesh
{
public:
	Mesh();
	~Mesh();

	size_t getVerticesSize() { return _vertices.size(); }
	// Render data 
	unsigned int  _vao, _vbo, _ebo;
protected:

	void initRenderData();

	// Mesh's vertices
	std::vector<glm::vec3> _vertices;
	// indices between points
	std::vector<glm::vec3> _indices;

	std::vector<glm::vec3> _normals;
	// Texture coords
	std::vector<glm::vec2> _UV;
	

};
