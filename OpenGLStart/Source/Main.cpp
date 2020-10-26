#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>

//PROBANDO COMENTARIO
//HOLA XD

int main(void)
{
    GLFWwindow* window;

    /* Inicializamos la libreria */
    if (!glfwInit())
        return -1;


    /* Cree una ventana en modo ventana y su contexto OpenGL */
    window = glfwCreateWindow(1200, 720, "First window", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Actualice el contexto de la ventana */
    glfwMakeContextCurrent(window);

    if (glewInit() != GLEW_OK)
        std::cout << "Error!" << std::endl;

    /* Bucle hasta que el usuario cierre la ventana. */
    while (!glfwWindowShouldClose(window))
    {
        /* Render aqu� */
        glClear(GL_COLOR_BUFFER_BIT);

        glBegin(GL_TRIANGLES);
            glVertex3f(-0.5f,0.5f,0);
            glVertex3f(-0.5f,-0.5f,0);
            glVertex3f(0.5f,-0.5f,0);
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