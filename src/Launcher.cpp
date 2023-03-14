#include "engine/WindowManager.h"
#include "engine/EngineManager.h"


int main()
{
	WindowManager window = WindowManager("BaseEngine - Loading...", 1280, 720, true);

	EngineManager engine = EngineManager(window);
	engine.start();

	return 0;
}