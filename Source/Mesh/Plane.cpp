#include "Mesh/Plane.hpp"
#include <iostream>

#include "GL\glew.h"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Camera/Camera.hpp"
#include "Resources/Shader.hpp"
#include "Renderer/Objects/Material.hpp"

Plane::Plane()
	:Mesh()
{
	_vertices = std::vector<glm::vec3>{
		glm::vec3(-5.0f, -0.5f, -5.0f), 
		glm::vec3(5.0f, -0.5f,  5.0f),
		glm::vec3(5.0f, -0.5f, -5.0f),
		glm::vec3(5.0f, -0.5f,  5.0f),
		glm::vec3(-5.0f, -0.5f, -5.0f),
		glm::vec3(-5.0f, -0.5f,  5.0f),
	}; 
	_normals = std::vector<glm::vec3>{

		glm::vec3(0.0f, 1.0f, 0.0f),
		glm::vec3(0.0f, 1.0f, 0.0f),
		glm::vec3(0.0f, 1.0f, 0.0f),
		glm::vec3(0.0f, 1.0f, 0.0f),
		glm::vec3(0.0f, 1.0f,0.0f),
		glm::vec3(0.0f, 1.0f, 0.0f),
	};
	_UV = std::vector<glm::vec2>{
		glm::vec2(0.0f, 2.0f),
		glm::vec2(2.0f, 0.0f),
		glm::vec2(2.0f, 2.0f),
		glm::vec2(2.0f, 0.0f),
		glm::vec2(0.0f, 2.0f),
		glm::vec2(0.0f, 0.0f)
	};
	initRenderData();
}

Plane::~Plane()
{

}
/*
void PlaneRenderer::initRenderData()
{
	GLuint VBO;
	GLfloat verticesPlane[] = {
		-5.0f, -0.5f, -5.0f,0.0f, 1.0f,0.0f,  0.0f, 2.0f,
		5.0f, -0.5f,  5.0f, 0.0f, 1.0f,0.0f, 2.0f, 0.0f,
		5.0f, -0.5f, -5.0f, 0.0f, 1.0f,0.0f,  2.0f, 2.0f,
		5.0f, -0.5f,  5.0f, 0.0f, 1.0f,0.0f, 2.0f, 0.0f,
		-5.0f, -0.5f, -5.0f, 0.0f, 1.0f,0.0f, 0.0f, 2.0f,
		-5.0f, -0.5f,  5.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f
		
		
	};
	
	glGenVertexArrays(1, &this->_vao);
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(verticesPlane), verticesPlane, GL_STATIC_DRAW);

	glBindVertexArray(this->_vao);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);
	
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
	glEnableVertexAttribArray(2);
	
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}*/
/*
void PlaneRenderer::draw(const std::shared_ptr<Camera> &camera) const
{
	_material->getShader()->use();
	glBindVertexArray(this->_vao);
	glm::mat4 model;
	model = glm::translate(model, _pos);

	model = glm::translate(model, glm::vec3(0.5f * _size.x, 0.5f * _size.y, 0.5f * _size.z));
	model = glm::rotate(model, glm::radians(_rotate), glm::vec3(1.0f, 0.0f, 0.0f));
	model = glm::translate(model, glm::vec3(-0.5f * _size.x, -0.5f * _size.y, -0.5f * _size.z));

	model = glm::scale(model, _size);
	glm::mat4 inverseModel;
	glm::mat4 view;
	glm::mat4 projection;
	/* DEBUG*/
	/* ****** */
	/*_material->getShader()->setMat4("model", model);
	view = glm::translate(view, camera->getPos());
	inverseModel = glm::inverse(model);
	//this->_shader->setMat4("inverseModel", inverseModel);
	_material->getShader()->setVec3("viewPos", camera->getPos());
	_material->getShader()->setMat4("view", camera->viewMatrix());
	_material->getShader()->setMat4("projection", camera->projectionMatrix());
	_material->preRender();
	

	glDrawArrays(GL_TRIANGLES, 0, 6);
	glBindVertexArray(0);
}*/