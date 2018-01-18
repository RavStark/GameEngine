#pragma once

#include "Camera.hpp"


class CameraOrtho : public Camera
{
public:
	CameraOrtho(const glm::vec3 &pos);
	CameraOrtho(const glm::vec3 &pos, int screenWidth, int screenHeight);
	~CameraOrtho();

	virtual glm::mat4 viewMatrix() const;
	virtual glm::mat4 projectionMatrix() const;
	virtual void updateDirection(float pitch, float yaw, float roll);
};