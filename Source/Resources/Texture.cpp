#include "Resources/Texture.hpp"
#include <iostream>

#include "GL\glew.h"


Texture::Texture()
{
	glGenTextures(1, &_id);
}

Texture::~Texture()
	{

	}

void Texture::generate(GLuint width, GLuint height, const unsigned char *data, GLboolean mipmaps)
{
	this->_width = width;
	this->_height = height;
	GLuint texture;
	glBindTexture(GL_TEXTURE_2D, _id); // All upcoming GL_TEXTURE_2D operations now have effect on this texture object
											// Set the texture wrapping parameters
	std::cerr << _id << std::endl;
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, WrapS);	// Set texture wrapping to GL_REPEAT (usually basic wrapping method)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, WrapT);
	// Set texture filtering parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, FilterMin);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, FilterMax);
	// Load image, create texture and generate mipmaps
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
	glGenerateMipmap(GL_TEXTURE_2D);

	if (mipmaps)
		glGenerateMipmap(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, 0); // Unbind texture when done, so we won't accidentily mess up our texture.
}

void Texture::bind(GLbyte unit) const
{
	if (unit >= 0)
		glActiveTexture(GL_TEXTURE0 + unit);
	glBindTexture(GL_TEXTURE_2D, _id);
}
