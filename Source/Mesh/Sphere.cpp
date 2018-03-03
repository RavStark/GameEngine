#include <vector>
#include "Mesh/Sphere.hpp"
#include "Resources/Shader.hpp"
#include "Resources/Texture.hpp"
#include "Camera/CameraFps.hpp"
#include "GL\glew.h"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

Sphere::Sphere()
	: Mesh()
{
	_numToDraw = 0;
}

Sphere::~Sphere()
{

}
/*
void SphereRenderer::initRenderData()
{
	int lats = 40;
	int longs = 40;
	int i, j;
	std::vector<GLfloat> vertices;
	std::vector<GLuint> indices;
	int indicator = 0;
	for (i = 0; i <= lats; i++) {
		double lat0 = glm::pi<double>() * (-0.5 + (double)(i - 1) / lats);
		double z0 = sin(lat0);
		double zr0 = cos(lat0);

		double lat1 = glm::pi<double>() * (-0.5 + (double)i / lats);
		double z1 = sin(lat1);
		double zr1 = cos(lat1);

		for (j = 0; j <= longs; j++) {
			double lng = 2 * glm::pi<double>() * (double)(j - 1) / longs;
			double x = cos(lng);
			double y = sin(lng);

			vertices.push_back(x * zr0);
			vertices.push_back(y * zr0);
			vertices.push_back(z0);
			indices.push_back(indicator);
			indicator++;

			vertices.push_back(x * zr1);
			vertices.push_back(y * zr1);
			vertices.push_back(z1);
			indices.push_back(indicator);
			indicator++;
		}
		indices.push_back(GL_PRIMITIVE_RESTART_FIXED_INDEX);
	}

	glGenVertexArrays(1, &this->_vao);
	glBindVertexArray(_vao);

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(GLfloat), &vertices[0], GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
	glEnableVertexAttribArray(0);

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, VBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLuint), &indices[0], GL_STATIC_DRAW);
	_numToDraw = indices.size();

	//isInited = true;
}

void SphereRenderer::draw(const std::shared_ptr<Camera> &camera) const
{
	_material->getShader()->use();
	glBindVertexArray(this->_vao);
	glm::mat4 model;
	model = glm::translate(model, _pos);
	model = glm::scale(model, _size);
	glm::mat4 inverseModel;
	glm::mat4 view;
	glm::mat4 projection;
	/* DEBUG*/
	/* ****** */
/*	_material->getShader()->setMat4("model", model);
	view = glm::translate(view, camera->getPos());
	inverseModel = glm::inverse(model);
	//this->_shader->setMat4("inverseModel", inverseModel);
	_material->getShader()->setVec3("viewPos", camera->getPos());
	_material->getShader()->setMat4("view", camera->viewMatrix());
	_material->getShader()->setMat4("projection", camera->projectionMatrix());
	_material->preRender();
	glEnable(GL_PRIMITIVE_RESTART);
	glPrimitiveRestartIndex(GL_PRIMITIVE_RESTART_FIXED_INDEX);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, VBO);
	glDrawElements(GL_QUAD_STRIP, _numToDraw, GL_UNSIGNED_INT, NULL);
	//glDrawArrays(GL_QUAD_STRIP, 0, _numToDraw);
	glBindVertexArray(0);
}*/