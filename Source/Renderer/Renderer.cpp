#include <string>
#include "Renderer/Renderer.hpp"
#include "Renderer/LightsManager.hpp"
#include "Renderer/Objects/Material.hpp"
#include "Renderer/Lights/PointLight.hpp"
#include "Mesh/Mesh.hpp"
#include "Camera/CameraFps.hpp"
#include "Resources/Shader.hpp"
#include "Resources/ResourceManager.hpp"
#include "Renderer/Model.hpp"
#include "Scene/Scene.hpp"
#include "Scene/SceneElement.hpp"
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

/* 
	TODO : Is update and draw need to loop on all Objects ??
*/

Renderer::Renderer(const std::shared_ptr<Camera>& camera)
	: _camera(camera)
{
}

void Renderer::update(Scene *scene)
{
	// Prepare transformations

	for (auto elements : scene->getSceneElements())
	{
		elements->getMaterial()->getShader()->use();
		glBindVertexArray(elements->getMesh()->_vao);//Needed ?
		//TODO Be sure that the material exit (default)
		
		
		glm::mat4 model;
		model = glm::rotate(model, glm::radians(elements->getRotate()), glm::vec3(1.0f, 0.0f, 0.0f)); //Need to improve, Axis? Quaternion.?
		model = glm::translate(model, elements->getPos());

		model = glm::scale(model, elements->getSize());
		/*glm::mat4 inverseModel;
		glm::mat4 view;
		glm::mat4 projection;*/
		elements->getMaterial()->getShader()->setMat4("model", model);
		/*view = glm::translate(view, _camera->getPos());
		inverseModel = glm::inverse(model);
		//this->_shader->setMat4("inverseModel", inverseModel);*/
		
		elements->getMaterial()->getShader()->setVec3("viewPos", _camera->getPos());
		elements->getMaterial()->getShader()->setMat4("view", _camera->viewMatrix());
		elements->getMaterial()->getShader()->setMat4("projection", _camera->projectionMatrix());
		elements->getMaterial()->preRender();
		glBindVertexArray(0); //Needed ?

	}
}
#include <iostream>
void Renderer::draw(Scene *scene)
{
	scene->preRender();
	for (auto elements : scene->getSceneElements())
	{
	glBindVertexArray(elements->getMesh()->_vao);
	//
	//std::cerr << elements->getMesh()->getVerticesSize() << std::endl;
	glDrawArrays(GL_TRIANGLES, 0, elements->getMesh()->getVerticesSize());
	glBindVertexArray(0);
	}
}