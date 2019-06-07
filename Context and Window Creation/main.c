
#include <stdio.h> // fputs(const char* s, FILE* stream)


#include "GLFW/glfw3.h"


void glfw_error_callback(int error, const char* desc) {
	fprintf(stderr, "GLFW Error(%i): %s\n", desc);
}


int main(int argc, char** argv)
{
	// set glfw error callback
	glfwSetErrorCallback(glfw_error_callback);
	
	
	// initialize glfw
	if(!glfwInit()) {
		fputs("GLFW could not initialize.\n", stderr);
		return 1;
	}
	
	
	// hint at glfw to design the window
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT,	GLFW_TRUE);					// allow future opengl functions
	glfwWindowHint(GLFW_OPENGL_PROFILE,			GLFW_OPENGL_CORE_PROFILE);	// do not allow legacy opengl functions
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,	4);							// major version 4
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,	0);							// minor version 0
	glfwWindowHint(GLFW_RESIZABLE,				GLFW_FALSE);				// window not resizable
	glfwWindowHint(GLFW_SAMPLES,				16);						// 16 samples
	
	
	// assign a new window with opengl context, make that context current
	// the window is 800x600 and initially titled "First Window"
	GLFWwindow* glfw_window;
	glfw_window = glfwCreateWindow(800, 600, "First Window", NULL, NULL);
	glfwMakeContextCurrent(glfw_window);
	
	
	// enable vsync
	glfwSwapInterval(1);
	
	
	// main while loop
	// check every frame if window should close
	while(!glfwWindowShouldClose(glfw_window)) {
		
		// opengl and game logic go here
		
		
		// swap buffers for next frame & execute glfw events for next frame
		glfwSwapBuffers(glfw_window);
		glfwPollEvents();
		
		// opengl and game logic rarely if at all go here
		
	}
	
	
	// clean up window and context & terminate glfw
	glfwDestroyWindow(glfw_window);
	glfwTerminate();
	
	
	// exit gracefully over void exit(int status); unless crash
	return 0;
}
