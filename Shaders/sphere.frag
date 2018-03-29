#version 330 core

out vec4 FragColor;

in float height;
void main(){
	float color;
	color = abs(height) / 60.f;
	/*else
	{
		color = height / 100.f;
	}*/
	FragColor = vec4 (0.0, color, 0.0, 1.0);
}