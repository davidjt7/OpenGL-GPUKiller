#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<random>

#include"shaderClass.h"
#include"VAO.h"
#include"VBO.h"
#include"EBO.h"

GLfloat vertices[] =
{
	-0.5f, -0.5f * float(sqrt(3)) * 1 / 3, 0.0f, 0.207f, 0.360f, 0.490f,
	 0.5f, -0.5f * float(sqrt(3)) * 1 / 3, 0.0f, 0.207f, 0.360f, 0.490f,
	 0.0f,  0.5f * float(sqrt(3)) * 2 / 3, 0.0f, 0.423f, 0.356f, 0.482f,
	-0.25f, 0.5f * float(sqrt(3)) * 1 / 6, 0.0f, 0.423f, 0.356f, 0.482f,
	 0.25f, 0.5f * float(sqrt(3)) * 1 / 6, 0.0f, 0.752f, 0.423f, 0.517f,
	 0.0f, -0.5f * float(sqrt(3)) * 1 / 3, 0.0f, 0.752f, 0.423f, 0.517f
};

GLuint indices[] =
{
	0, 3, 5,
	3, 2, 4,
	5, 4, 1
};

int main() {
	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(400, 400, "OpenGL GPU Killer", NULL, NULL);
	if (window == NULL) {
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	gladLoadGL();
	glViewport(0, 0, 400, 400);

	Shader shaderProgram("default.vert", "default.frag");

	VertexArrayObject VAO1;
	VAO1.Bind();
	VertexBufferObject VBO1(vertices, sizeof(vertices));
	ElementBufferObject EBO1(indices, sizeof(indices));

	VAO1.LinkAttrib(VBO1, 0, 3, GL_FLOAT, 6 * sizeof(float), (void*)0);
	VAO1.LinkAttrib(VBO1, 1, 3, GL_FLOAT, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	VAO1.Unbind();
	VBO1.Unbind();
	EBO1.Unbind();

	GLuint scaleUniformID = glGetUniformLocation(shaderProgram.ID, "scale");
	GLuint translateXUniformID = glGetUniformLocation(shaderProgram.ID, "translateX");
	GLuint translateYUniformID = glGetUniformLocation(shaderProgram.ID, "translateY");
	GLuint translateZUniformID = glGetUniformLocation(shaderProgram.ID, "translateZ");

	std::default_random_engine generator;
	std::uniform_real_distribution<float> distribution(-1.0f, 1.0f);

	int makeShiftTimer = 100000;
	while (!glfwWindowShouldClose(window)) {
		if (makeShiftTimer == 100000) {
			glClearColor(1.0f, 0.764f, 0.301f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);
			shaderProgram.Activate();
			glUniform1f(scaleUniformID, distribution(generator));
			glUniform1f(translateXUniformID, distribution(generator));
			glUniform1f(translateYUniformID, distribution(generator));
			glUniform1f(translateZUniformID, distribution(generator));
			VAO1.Bind();
			glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_INT, 0);
			glfwSwapBuffers(window);
			makeShiftTimer = 0;
		}		

		glfwPollEvents();
		makeShiftTimer++;
	}

	VAO1.Delete();
	VBO1.Delete();
	EBO1.Delete();
	shaderProgram.Delete();

	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}