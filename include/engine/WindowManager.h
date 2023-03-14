#pragma once

#include <iostream>

#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"
#include "glad/glad.h"

static const float FOV = 70.0f;
static const float NEAR_PLANE = 0.01f;
static const float FAR_PLANE = 1000.0f;

class WindowManager
{
public:
	WindowManager(std::string title, int width, int height, bool vsync);

	void init(); // Initialize the window
	void update(); // Update the window
	void cleanUp(); // Clean up the window

	bool windowShouldClose(); // Check if the window should close

	// Getters and setters
	GLFWwindow* getWindow() { return m_window; }
	void setTitle(std::string title) { m_title = title; }

private:
	GLFWwindow* m_window;
	std::string m_title;
	int m_width;
	int m_height;
	bool m_vsync;
	bool m_is_resizable;
};