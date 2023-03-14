#include "engine/EngineManager.h"

EngineManager::EngineManager(WindowManager window) : m_window(window) {}

void EngineManager::init()
{
	m_window.init();
	m_renderer.init();
}

void EngineManager::start()
{
	init();
	if (m_isRunning)
		return;
	run();
}

void EngineManager::run()
{
	m_isRunning = true;

	long lastTime = glfwGetTime();
	long timer = lastTime;
	float delta = 0.0f;
	int frames = 0;
	int updates = 0;

	while (m_isRunning) {
		long now = glfwGetTime();
		delta += (now - lastTime) / m_frameTime;
		lastTime = now;
		while (delta >= 1) {
			update();
			updates++;
			delta--;
		}
		render();
		frames++;
		if (glfwGetTime() - timer > 1) {
			timer++;
			m_fps = frames;
			frames = 0;
			updates = 0;
			m_window.setTitle("BaseEngine - @" + std::to_string(m_fps) + "fps"); // Update the window title
		}
		if (m_window.windowShouldClose()) {
			stop();
		}
	}
	cleanUp();
}

void EngineManager::render()
{	
	m_window.update();
	m_renderer.render();
}

void EngineManager::input() {}

void EngineManager::update()
{
	
}

void EngineManager::stop() {
	if (!m_isRunning)
		return;
	m_isRunning = false;
} 

void EngineManager::cleanUp()
{
	m_window.cleanUp();
	m_renderer.cleanUp();
}