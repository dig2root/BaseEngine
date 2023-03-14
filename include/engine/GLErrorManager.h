#pragma once

#define ASSERT(x) if (!(x)) __debugbreak();
#define GLCall(x) GLErrorManager::clearError();\
	x;\
	ASSERT(GLErrorManager::logCall(#x, __FILE__, __LINE__))

class GLErrorManager
{
public:
	static void clearError();
	static bool logCall(const char* function, const char* file, int line);
};