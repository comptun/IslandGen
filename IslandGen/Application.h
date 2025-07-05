#pragma once
#include <SDL3/SDL.h>
#include <glad/glad.h>

#include <memory>

#include "Renderer.h"

class Application
{
public:
	void Run();
private:
	SDL_Window* m_Window;
	SDL_GLContext m_Context;

	std::unique_ptr<Renderer> m_Renderer;

	const uint32_t m_WIDTH = 600;
	const uint32_t m_HEIGHT = 600;

	void DrawWindow();

	void InitWindow();
	void MainLoop();
	void Cleanup();
};

