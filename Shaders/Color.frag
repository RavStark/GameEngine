#version 330 core
out vec4 FragColor;

struct Material {
    vec3 ambient;
    vec3 diffuse;
	sampler2D diffuseText;
    vec3 specular;
    float shininess;
};

struct Light {
    vec3 position;
  
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

uniform Material material;
uniform Light light;

uniform int hasTexture;

uniform vec3 viewPos;

in vec2 TexCoords; //textCoord from vs
in vec3 Normal; //Normal vector from vs
in vec3 FragPos; //world position vertex

void main()
{
	
    vec3 ambient;
	if (hasTexture == 1)
		ambient = light.ambient * texture(material.diffuseText, TexCoords).rgb;
    else
		ambient = material.ambient * light.ambient;
	vec3 norm = normalize(Normal);
	vec3 lightDir = normalize(light.position - FragPos);
	float diff = max(dot(norm, lightDir), 0.0);
	vec3 diffuse;
	if (hasTexture ==1)
		diffuse = light.diffuse * diff * texture(material.diffuseText, TexCoords).rgb;
    else
		diffuse = (diff * material.diffuse) * light.diffuse;
    // specular
	float specularStrength = 0.5;
	vec3 viewDir = normalize(viewPos - FragPos);
	vec3 reflectDir = reflect(-lightDir, norm);
	float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
	vec3 specular = (material.specular * spec) * light.specular;  

	vec3 result = (ambient + diffuse + specular);
	FragColor = vec4(result, 1.0f);//texture(ourTexture, TexCoord);
} 