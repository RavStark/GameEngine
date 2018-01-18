#pragma once

#define GLEW_STATIC
#include <GL/glew.h>

class Texture
{
public:
	Texture();
	~Texture();

	// Texture render state
	GLuint _id = 0; // holds the ID of the texture object, used for all texture operations to reference to this particlar texture
				   // Texture image dimensions
	GLuint _width = 0; // width of loaded image in pixels
	GLuint _height = 0; // height of loaded image in pixels
					   // Texture Format
	GLenum InternalFormat = GL_RGB; // format of texture object
	GLenum ImageFormat = GL_RGB; // format of loaded image
								 // Texture configuration
	GLenum FilterMin = GL_LINEAR;          // filtering mode if texture pixels < screen pixels
	GLenum FilterMax = GL_LINEAR;          // filtering mode if texture pixels > screen pixels
	GLenum WrapS = GL_MIRRORED_REPEAT; // wrapping mode on S axis
	GLenum WrapT = GL_MIRRORED_REPEAT; // wrapping mode on T axis
		//GL_CLAMP_TO_EDGE
		//GL_REPEAT
		//GL_NEAREST
		//GL_LINEAR
	void generate(GLuint width, GLuint height, const unsigned char *data, GLboolean mipmaps = GL_FALSE);
	void bind(GLbyte unit = -1) const;

};
