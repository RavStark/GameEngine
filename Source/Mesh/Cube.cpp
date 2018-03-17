#include "Mesh/Cube.hpp"
#include <iostream>

#include "GL\glew.h"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Renderer/LightsManager.hpp"
#include "Resources/Shader.hpp"
#include "Resources/Texture.hpp"
#include "Camera/CameraFps.hpp"
#include "Renderer/Objects/Material.hpp"

Cube::Cube()
{
	GLuint VBO;
	//vertices for triangles

	_vertices = std::vector<glm::vec3>{
		// positions          // normals           // texture coords
		// Back Face
		glm::vec3(-0.5f, -0.5f, -0.5f),
		glm::vec3(0.5f,  0.5f, -0.5f),
		glm::vec3(0.5f, -0.5f, -0.5f),
		glm::vec3(0.5f,  0.5f, -0.5f),
		glm::vec3(-0.5f, -0.5f, -0.5f),
		glm::vec3(-0.5f,  0.5f, -0.5f),

		// Front face
		glm::vec3(-0.5f, -0.5f,  0.5f),
		glm::vec3(0.5f, -0.5f,  0.5f),
		glm::vec3(0.5f,  0.5f,  0.5f),
		glm::vec3(0.5f,  0.5f,  0.5f),
		glm::vec3(-0.5f,  0.5f,  0.5f),
		glm::vec3(-0.5f, -0.5f,  0.5f),
		//Left face
		glm::vec3(-0.5f,  0.5f,  0.5f),
		glm::vec3(-0.5f,  0.5f, -0.5f),
		glm::vec3(-0.5f, -0.5f, -0.5f),
		glm::vec3(-0.5f, -0.5f, -0.5f),
		glm::vec3(-0.5f, -0.5f,  0.5f),
		glm::vec3(-0.5f,  0.5f,  0.5f),
		//Right face
		glm::vec3(0.5f,  0.5f,  0.5f),
		glm::vec3(0.5f, -0.5f, -0.5f),
		glm::vec3(0.5f,  0.5f, -0.5f),
		glm::vec3(0.5f, -0.5f, -0.5f),
		glm::vec3(0.5f,  0.5f,  0.5f),
		glm::vec3(0.5f, -0.5f,  0.5f),

		//Bottom
		glm::vec3(-0.5f, -0.5f, -0.5f),
		glm::vec3(0.5f, -0.5f, -0.5f),
		glm::vec3(0.5f, -0.5f,  0.5f),
		glm::vec3(0.5f, -0.5f,  0.5f),
		glm::vec3(-0.5f, -0.5f,  0.5f),
		glm::vec3(-0.5f, -0.5f, -0.5f),
		//Top face
		glm::vec3(-0.5f,  0.5f, -0.5f),
		glm::vec3(0.5f,  0.5f,  0.5f),
		glm::vec3(0.5f,  0.5f, -0.5f),
		glm::vec3(0.5f,  0.5f,  0.5f),
		glm::vec3(-0.5f,  0.5f, -0.5f),
		glm::vec3(-0.5f,  0.5f,  0.5f)
	};
	
	_normals = std::vector<glm::vec3>{
		glm::vec3(0.0f,  0.0f, -1.0f),
		glm::vec3(0.0f,  0.0f, -1.0f),
		glm::vec3(0.0f,  0.0f, -1.0f),
		glm::vec3(0.0f,  0.0f, -1.0f),
		glm::vec3(0.0f,  0.0f, -1.0f),
		glm::vec3(0.0f,  0.0f, -1.0f),

		// Front face
		glm::vec3(0.0f,  0.0f,  1.0f),
		glm::vec3(0.0f,  0.0f,  1.0f),
		glm::vec3(0.0f,  0.0f,  1.0f),
		glm::vec3(0.0f,  0.0f,  1.0f),
		glm::vec3(0.0f,  0.0f,  1.0f),
		glm::vec3(0.0f,  0.0f,  1.0f),
		//Left face
		glm::vec3(-1.0f,  0.0f,  0.0f),
		glm::vec3(-1.0f,  0.0f,  0.0f),
		glm::vec3(-1.0f,  0.0f,  0.0f),
		glm::vec3(-1.0f,  0.0f,  0.0f),
		glm::vec3(-1.0f,  0.0f,  0.0f),
		glm::vec3(-1.0f,  0.0f,  0.0f),
		//Right face
		glm::vec3(1.0f,  0.0f,  0.0f),
		glm::vec3(1.0f,  0.0f,  0.0f),
		glm::vec3(1.0f,  0.0f,  0.0f),
		glm::vec3(1.0f,  0.0f,  0.0f),
		glm::vec3(1.0f,  0.0f,  0.0f),
		glm::vec3(1.0f,  0.0f,  0.0f),

		//Bottom
		glm::vec3(0.0f, -1.0f,  0.0f),
		glm::vec3(0.0f, -1.0f,  0.0f),
		glm::vec3(0.0f, -1.0f,  0.0f),
		glm::vec3(0.0f, -1.0f,  0.0f),
		glm::vec3(0.0f, -1.0f,  0.0f),
		glm::vec3(0.0f, -1.0f,  0.0f),
		//Top face
		glm::vec3(0.0f,  1.0f,  0.0f),
		glm::vec3(0.0f,  1.0f,  0.0f),
		glm::vec3(0.0f,  1.0f,  0.0f),
		glm::vec3(0.0f,  1.0f,  0.0f),
		glm::vec3(0.0f,  1.0f,  0.0f),
		glm::vec3(0.0f,  1.0f,  0.0f)
	};

	_UV = std::vector<glm::vec2>{
		glm::vec2(0.0f,  0.0f),
		glm::vec2(1.0f,  1.0f),
		glm::vec2(1.0f,  0.0f),
		glm::vec2(1.0f,  1.0f),
		glm::vec2(0.0f,  0.0f),
		glm::vec2(0.0f,  1.0f),

		// Front face
		glm::vec2(0.0f,  0.0f),
		glm::vec2(1.0f,  0.0f),
		glm::vec2(1.0f,  1.0f),
		glm::vec2(1.0f,  1.0f),
		glm::vec2(0.0f,  1.0f),
		glm::vec2(0.0f,  0.0f),
		//Left face
		glm::vec2(1.0f,  0.0f),
		glm::vec2(1.0f,  1.0f),
		glm::vec2(0.0f,  1.0f),
		glm::vec2(0.0f,  1.0f),
		glm::vec2(0.0f,  0.0f),
		glm::vec2(1.0f,  0.0f),
		//Right face
		glm::vec2(1.0f,  0.0f),
		glm::vec2(0.0f,  1.0f),
		glm::vec2(1.0f,  1.0f),
		glm::vec2(0.0f,  1.0f),
		glm::vec2(1.0f,  0.0f),
		glm::vec2(0.0f,  0.0f),

		//Bottom
		glm::vec2(0.0f,  1.0f),
		glm::vec2(1.0f,  1.0f),
		glm::vec2(1.0f,  0.0f),
		glm::vec2(1.0f,  0.0f),
		glm::vec2(0.0f,  0.0f),
		glm::vec2(0.0f,  1.0f),
		//Top face
		glm::vec2(0.0f,  1.0f),
		glm::vec2(1.0f,  0.0f),
		glm::vec2(1.0f,  1.0f),
		glm::vec2(1.0f,  0.0f),
		glm::vec2(0.0f,  1.0f),
		glm::vec2(0.0f,  0.0f)
	};
	initRenderData();
	/*glGenVertexArrays(1, &this->_vao);
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(_vertices), &_vertices[0], GL_STATIC_DRAW);

	glBindVertexArray(this->_vao);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);
	/*//*/ Color attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 11 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);*/
	/**/
	// Nomal attribute
	/*glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);
	// TexCoord attribute
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
	glEnableVertexAttribArray(2);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);*/
}

Cube::~Cube()
{

}
/*
void CubeRenderer::draw(const std::shared_ptr<Camera> &camera) const
{
	// Prepare transformations

	
	_material->getShader()->use();
	glBindVertexArray(this->_vao);
	glm::mat4 model;
	model = glm::translate(model, _pos);

	//model = glm::translate(model, glm::vec3(0.5f * size.x, 0.5f * size.y, 0.5f * size.z));
	//model = glm::rotate(model, glm::radians(_rotate), glm::vec3(1.0f, 0.0f, 0.0f));
	//model = glm::translate(model, glm::vec3(-0.5f * size.x, -0.5f * size.y, -0.5f * size.z));

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
	//Default
	/*this->_shader->setVec3("material.ambient", _color);
	this->_shader->setVec3("material.diffuse", _color);
	this->_shader->setVec3("material.specular", 0.5f, 0.5f, 0.5f);
	this->_shader->setFloat("material.shininess", 32.0f);*/

	
	//glActiveTexture(GL_TEXTURE0);
	//glBindTexture(GL_TEXTURE_2D, textureManger->getTexture("container"));
//	glActiveTexture(GL_TEXTURE1);
	//glBindTexture(GL_TEXTURE_2D, textureManger->getTexture("container2_specular"));

	/*glDrawArrays(GL_TRIANGLES, 0, 36);
	glBindVertexArray(0);
}*/