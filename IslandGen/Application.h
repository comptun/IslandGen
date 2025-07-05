#pragma once
#include <SDL3/SDL.h>

class Application
{
public:
	void Run();
private:
	SDL_Window* m_Window;
	const uint32_t m_WIDTH = 600;
	const uint32_t m_HEIGHT = 600;

	void InitWindow();
	void MainLoop();
	void Cleanup();
};

