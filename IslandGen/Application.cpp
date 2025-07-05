#include "Application.h"

void Application::Run() {
    InitWindow();
    MainLoop();
    Cleanup();
}

void Application::InitWindow() {
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS);

    SDL_WindowFlags flags = SDL_WINDOW_OPENGL;

    m_Window = SDL_CreateWindow("IslandGen", m_WIDTH, m_HEIGHT, flags);
}

void Application::MainLoop() {
    bool running = true;
    while (running) {
        SDL_Event ev;
        while (SDL_PollEvent(&ev)) {  // poll until all events are handled!

            if (ev.type == SDL_EVENT_QUIT) {
                running = false;
                break;
            }

        }
    }
}
void Application::Cleanup() {
    SDL_DestroyWindow(m_Window);
    SDL_Quit();
}