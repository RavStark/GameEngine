#include "Mesh/Cubemap.hpp"
#include "GL\glew.h"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


Cubemap::Cubemap()
{
	GLuint VBO;
	//vertices for triangles

	_vertices = std::vector<glm::vec3> {
		// positions          
		glm::vec3(-1.0f,  1.0f, -1.0f),
		glm::vec3(-1.0f, -1.0f, -1.0f),
		glm::vec3(1.0f, -1.0f, -1.0f),
		glm::vec3(1.0f, -1.0f, -1.0f),
		glm::vec3(1.0f,  1.0f, -1.0f),
		glm::vec3(-1.0f,  1.0f, -1.0f),

		glm::vec3(-1.0f, -1.0f,  1.0f),
		glm::vec3(-1.0f, -1.0f, -1.0f),
		glm::vec3(-1.0f,  1.0f, -1.0f),
		glm::vec3(-1.0f,  1.0f, -1.0f),
		glm::vec3(-1.0f,  1.0f,  1.0f),
		glm::vec3(-1.0f, -1.0f,  1.0f),

		glm::vec3(1.0f, -1.0f, -1.0f),
		glm::vec3(1.0f, -1.0f,  1.0f),
		glm::vec3(1.0f,  1.0f,  1.0f),
		glm::vec3(1.0f,  1.0f,  1.0f),
		glm::vec3(1.0f,  1.0f, -1.0f),
		glm::vec3(1.0f, -1.0f, -1.0f),

		glm::vec3(-1.0f, -1.0f,  1.0f),
		glm::vec3(-1.0f,  1.0f,  1.0f),
		glm::vec3(1.0f,  1.0f,  1.0f),
		glm::vec3(1.0f,  1.0f,  1.0f),
		glm::vec3(1.0f, -1.0f,  1.0f),
		glm::vec3(-1.0f, -1.0f,  1.0f),

		glm::vec3(-1.0f,  1.0f, -1.0f),
		glm::vec3(1.0f,  1.0f, -1.0f),
		glm::vec3(1.0f,  1.0f,  1.0f),
		glm::vec3(1.0f,  1.0f,  1.0f),
		glm::vec3(-1.0f,  1.0f,  1.0f),
		glm::vec3(-1.0f,  1.0f, -1.0f),

		glm::vec3(-1.0f, -1.0f, -1.0f),
		glm::vec3(-1.0f, -1.0f,  1.0f),
		glm::vec3(1.0f, -1.0f, -1.0f),
		glm::vec3(1.0f, -1.0f, -1.0f),
		glm::vec3(-1.0f, -1.0f,  1.0f),
		glm::vec3(1.0f, -1.0f,  1.0f)
	};

	initRenderData();

}

Cubemap::~Cubemap()
{

}
