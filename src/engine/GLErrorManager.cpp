#include "engine/GLErrorManager.h"

#include <iostream>
#include <glad/glad.h>

void GLErrorManager::clearError()
{
	while (glGetError() != GL_NO_ERROR);
}

bool GLErrorManager::logCall(const char* function, const char* file, int line)
{
	while (GLenum error = glGetError()) {
		std::cout << "[OpenGL Error] (" << error << ") at " << function << " in " << file << " : " << line << std::endl;
		return false;
	}
	return true;
}