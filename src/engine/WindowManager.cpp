#include "engine/WindowManager.h"

#include "engine/GLErrorManager.h"
#include <iostream>

WindowManager::WindowManager(std::string title, int width, int height, bool vsync)
{
	m_title = title;
	m_width = width;
	m_height = height;
	m_vsync = vsync;
	m_is_resizable = false;
}

void WindowManager::init()
{
	if (!glfwInit()) {
		std::cout << "Failed to initialize GLFW" << std::endl;
		return;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	
	glfwWindowHint(GLFW_RESIZABLE, m_is_resizable);

	m_window = glfwCreateWindow(m_width, m_height, m_title.c_str(), nullptr, nullptr);
	if (m_window == nullptr) {
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return;
	}
	glfwMakeContextCurrent(m_window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "Failed to initialize GLAD" << std::endl;
		return;
	}

	std::string versionString = std::string((const char*)glGetString(GL_VERSION));
	std::cout << "OpenGL version: " << versionString << std::endl;
	
	glViewport(0, 0, m_width, m_height);
	glfwGetFramebufferSize(m_window, &m_width, &m_height);

	glfwSwapInterval(m_vsync);
}

void WindowManager::update()
{
	glfwSetWindowTitle(m_window, m_title.c_str());

	glfwSwapBuffers(m_window);
	glfwPollEvents();
}

void WindowManager::cleanUp()
{
	glfwDestroyWindow(m_window);
	glfwTerminate();
}

bool WindowManager::windowShouldClose()
{
	return glfwWindowShouldClose(m_window);
}

