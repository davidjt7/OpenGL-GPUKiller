#ifndef VBO_CLASS_H
#define VBO_CLASS_H

#include<glad/glad.h>

class VertexBufferObject
{
public:
	GLuint ID;
	VertexBufferObject(GLfloat* vertices, GLsizeiptr size);

	void Bind();
	void Unbind();
	void Delete();
};

#endif