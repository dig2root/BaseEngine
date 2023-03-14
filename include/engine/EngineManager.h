#pragma once

#include "WindowManager.h"
#include "RenderManager.h"

#include <string>

static const long NANOSECOND = 1000000000L;
static const float FRAMERATE = 5000.0f;

class EngineManager
{
public:
	EngineManager(WindowManager window);
	void start();
	void run();

private:
	int m_fps = 0;
	float m_frameTime = 1.0f / FRAMERATE;
	bool m_isRunning = false;
	WindowManager m_window;
	RenderManager m_renderer;

	void init();
	void render();
	void input();
	void update();
	void stop();
	void cleanUp();
};