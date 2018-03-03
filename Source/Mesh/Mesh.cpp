#include "Mesh/Mesh.hpp"
#include <iostream>
#include <SOIL.h>
#include "GL\glew.h"

Mesh::Mesh()
{
}

Mesh::~Mesh()
{
}

void Mesh::initRenderData()
{
	std::vector<float> data;

	//Format every mesh information in data vector
	for (unsigned i = 0; i !=  _vertices.size(); ++i)
	{
		data.push_back(_vertices[i].x);
		data.push_back(_vertices[i].y);
		data.push_back(_vertices[i].z);

		if (!_normals.empty())
		{
			data.push_back(_normals[i].x);
			data.push_back(_normals[i].y);
			data.push_back(_normals[i].z);
		}

		//Texture coords
		if (!_UV.empty())
		{
			data.push_back(_UV[i].x);
			data.push_back(_UV[i].y);
		}
		
	}

	/*std::vector<float> verticesPlane = {
		-5.0f, -0.5f, -5.0f,0.0f, 1.0f,0.0f,  0.0f, 2.0f,
		5.0f, -0.5f,  5.0f, 0.0f, 1.0f,0.0f, 2.0f, 0.0f,
		5.0f, -0.5f, -5.0f, 0.0f, 1.0f,0.0f,  2.0f, 2.0f,
		5.0f, -0.5f,  5.0f, 0.0f, 1.0f,0.0f, 2.0f, 0.0f,
		-5.0f, -0.5f, -5.0f, 0.0f, 1.0f,0.0f, 0.0f, 2.0f,
		-5.0f, -0.5f,  5.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f


	};*/
	/*glGenVertexArrays(1, &this->_vao);
	glGenBuffers(1, &_vbo);
	glBindBuffer(GL_ARRAY_BUFFER, _vbo);
	glBufferData(GL_ARRAY_BUFFER, verticesPlane.size() * sizeof(float), &verticesPlane[0], GL_STATIC_DRAW);

	glBindVertexArray(this->_vao);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (GLvoid*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (GLvoid*)(6 * sizeof(GLfloat)));
	glEnableVertexAttribArray(2);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);*/
	size_t offset = 0;
	size_t stride = 3 * sizeof(float);
	if (!_normals.empty())
		stride += 3 * sizeof(float);
	if (!_UV.empty())
		stride += 2 * sizeof(float);

	glGenVertexArrays(1, &this->_vao);
	if (stride == 8 * sizeof(float))
		std::cerr << this->_vao << std::endl;
	glGenBuffers(1, &_vbo);
	glBindBuffer(GL_ARRAY_BUFFER, _vbo);
	glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(float), &data[0], GL_STATIC_DRAW);

	glBindVertexArray(this->_vao);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, stride, (GLvoid*)offset);
	glEnableVertexAttribArray(0);
	
	
	offset += 3 * sizeof(float);
	if (!_normals.empty())
	{
		
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, stride, (GLvoid*)offset);
		glEnableVertexAttribArray(1);
		offset += 3 * sizeof(float);
	}
	if (!_UV.empty())
	{
		
		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, stride, (GLvoid*)offset);
		glEnableVertexAttribArray(2);
		offset += 2 * sizeof(float);
	}
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}
