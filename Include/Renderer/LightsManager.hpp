#pragma once

#include <memory>
#include <vector>

class PointLight;
class DirectionLight;
class Shader;

class LightsManager
{
public:
	LightsManager();
	~LightsManager();

	/* update Shader */
	void preRender(Shader *shader) const;

	void addLight(const std::shared_ptr<PointLight>&);
	void addLight(const std::shared_ptr<DirectionLight>&);

	std::vector<std::shared_ptr<PointLight>> getPointLights() const;
	std::vector<std::shared_ptr<DirectionLight>> getDirectionLights() const;
private:
	std::vector<std::shared_ptr<PointLight>> _pointLights;
	std::vector<std::shared_ptr<DirectionLight>> _dirLights;
};