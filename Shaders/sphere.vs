#version 330 core
layout (location = 0) in vec3 position;


uniform float offsetX = 0.0f;
uniform float offsetY = 0.0f;

uniform vec3 lightPos;
uniform mat4 model;
uniform mat4 inverseModelView;
uniform mat4 view;
uniform mat4 projection;



void main()
{

	gl_Position = projection * view * model * vec4(position, 1.0f);
}