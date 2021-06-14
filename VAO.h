#ifndef VAO_CLASS_H
#define VAO_CLASS_H

#include<glad/glad.h>
#include"VBO.h"

class VertexArrayObject
{
public:
	GLuint ID;
	VertexArrayObject();

	void LinkAttrib(VertexBufferObject& VBO, GLuint layout, GLuint numComponents, GLenum type, GLsizei stride, void* offset);
	void Bind();
	void Unbind();
	void Delete();
};
#endif