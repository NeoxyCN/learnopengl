#include <stdio.h>
#include <stdbool.h>
#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include "logger.h"

int main() {
	char* info = "This is a test program. ";
	logInfo("learnopengl @ Neoxy");
	logInfo(info);
	if (!glfwInit()) {
		logError("Failed to initialize GLFW");
		return -1;
	}
	logInfo("Initialize GLFW ... Succeed");

	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GLFW_OPENGL_CORE_PROFILE);


	GLFWwindow* window;
	window = glfwCreateWindow(1024, 768, "Title", NULL, NULL);

	static const GLfloat vertexBufferData[] = {
		-1.0f,-1.0f,0.0f,
		 1.0f,-1.0f,0.0f,
		 0.0f,1.0f,0.0f,
	};

	if (window == NULL) {
		logError("Failed to create GLFW window");
		glfwTerminate();
		return -1;
	}
	logInfo("Create GLFW window ... Succeed");

	glfwMakeContextCurrent(window);
	//If you want to use "true" in C project, you must include "stdbool.h".
	glewExperimental = true;
	if (glewInit() != GLEW_OK) {
		logError("Failed to initialize GLEW");
		return -1;
	}
	logInfo("Initialize GLFW window ... Succeed");

	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
	glClearColor(0.0f, 0.0f, 0.4f, 0.0f);
	GLuint VertexArryID;
	glGenVertexArrays(1, &VertexArryID);
	glBindVertexArray(VertexArryID);
	GLuint vertexBuffer;
	glGenBuffers(1, &vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexBufferData), vertexBufferData, GL_STATIC_DRAW);

	do {
		glClear(GL_COLOR_BUFFER_BIT);

		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
		glVertexAttribPointer(
			0,
			3,
			GL_FLOAT,
			GL_FALSE,
			0,
			(void*)0
		);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glDisableVertexAttribArray(0);
		glfwSwapBuffers(window);
		glfwPollEvents();
	} while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(window) == 0);

}
