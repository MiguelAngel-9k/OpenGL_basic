#include <stdio.h>
#include <stdlib.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
using namespace glm;

#include <../../common/shader.hpp>
#include <../../common/texture.hpp>
#include <../../common/controls.hpp>

GLFWwindow* window;

#define CURSOR_CENTER(value) ((value/2))

int main(void)
{

	/* Inicializamos la libreria */
	if (!glfwInit())
	{
		fprintf(stderr, "GLFW Failed");
		return -1;
	}

	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


	/* Cree una ventana en modo ventana y su contexto OpenGL */
	window = glfwCreateWindow(1200, 720, "First window", NULL, NULL);
	if (!window)
	{
		fprintf(stderr, "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n");
		getchar();
		glfwTerminate();
		return -1;
	}

	/* Actualice el contexto de la ventana */
	glfwMakeContextCurrent(window);

	glewExperimental = true;
	if (glewInit() != GLEW_OK)
	{
		fprintf(stderr, "Failed to initialize GLEW\n");
		getchar();
		glfwTerminate();
		return -1;
	}

	//Tecla de ESC
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
	//Escondemos el mouse en la ventana
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	//Colocamos el cursor en medio de la ventana
	glfwPollEvents();
	glfwSetCursorPos(window, 1200 / 2, 720 / 2);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	glEnable(GL_CULL_FACE);

	GLuint VertexArrayID;
	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);

	glClearColor(0.0f, 0.0f, 0.4f, 0.0f);

	//Creamos ¿y compilamos los pogramas GLSL
	GLuint programID = LoadShaders("TransformVertexShader.vertexshader", "TextureFragmentShader.fragmentshader");

	//Handler del MVP
	GLuint MatrixID = glGetUniformLocation(programID, "MVP");

	//Handler para "myTextureSampler"
	//GLuint Texture = loadDDS("uvtemplate.DDS");

	/* Bucle hasta que el usuario cierre la ventana. */
	while (!glfwWindowShouldClose(window))
	{
		/* Render aqu� */
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//usamos el shader
		//glUseProgram(programID);

		/*computeMatricesFromInputs();
		glm::mat4 ProjectionMatrix = getProjectionMatrix();
		glm::mat4 ViewMatrix = getViewMatrix();
		glm::mat4 ModelMatrix = glm::mat4(1.0);
		glm::mat4 MVP = ProjectionMatrix * ViewMatrix * ModelMatrix;

		glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);*/

		glBegin(GL_TRIANGLES);
		glVertex3f(-0.5f, 0.5f, 0);
		glVertex3f(-0.5f, -0.5f, 0);
		glVertex3f(0.5f, -0.5f, 0);
		glColor3f(0.4f, 0.5f, 0.6f);
		glEnd();

		glBegin(GL_TRIANGLES);
		glVertex3f(-0.5f, 0.5f, 0);
		glVertex3f(0.5f, 0.5f, 0);
		glVertex3f(0.5f, -0.5f, 0);
		glColor3f(0.4f, 0.0f, 0.1f);
		glEnd();

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}