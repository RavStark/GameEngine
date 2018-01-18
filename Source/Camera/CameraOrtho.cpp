#pragma once
#include "Camera/CameraOrtho.hpp"
#include "GL\glew.h"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


CameraOrtho::CameraOrtho(const glm::vec3 &pos)
	: Camera(pos)
{

}

CameraOrtho::CameraOrtho(const glm::vec3 &pos, int screenWidth, int screenHeight)
	: Camera(pos, screenWidth, screenHeight)
{
}

CameraOrtho::~CameraOrtho()
{

}

glm::mat4 CameraOrtho::viewMatrix() const
{
	return glm::mat4();
}

glm::mat4 CameraOrtho::projectionMatrix() const
{
	return glm::ortho(0.0f, static_cast<GLfloat>(_screenWidth),
		static_cast<GLfloat>(_screenHeight), 0.0f, -1.0f, 1.0f);
}

void CameraOrtho::updateDirection(float , float , float)
{


}