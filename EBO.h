#ifndef EBO_CLASS_H
#define EBO_CLASS_H

#include<glad/glad.h>

class ElementBufferObject
{
public:
	GLuint ID;
	ElementBufferObject(GLuint* indices, GLsizeiptr size);

	void Bind();
	void Unbind();
	void Delete();
};

#endif