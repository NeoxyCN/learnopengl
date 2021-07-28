#define GLEW_STATIC
#include <gl/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>

int main() {
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	GLFWwindow* window = glfwCreateWindow(800, 600, "Main Window", NULL, NULL);
	if (window == NULL) {

	}
	return 0;
}