#include "Application.h"

#include <iostream>

void Application::Run() {
    InitWindow();
    MainLoop();
    Cleanup();
}

void Application::InitWindow() {
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS);

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 6);

    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

    SDL_WindowFlags flags = SDL_WINDOW_OPENGL;

    m_Window = SDL_CreateWindow("IslandGen", m_WIDTH, m_HEIGHT, flags);

    m_Context = SDL_GL_CreateContext(m_Window);

    // Check OpenGL properties
    printf("OpenGL loaded\n");
    gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress);
    printf("Vendor:   %s\n", glGetString(GL_VENDOR));
    printf("Renderer: %s\n", glGetString(GL_RENDERER));
    printf("Version:  %s\n", glGetString(GL_VERSION));

    // Use v-sync
    SDL_GL_SetSwapInterval(1);

    // Disable depth test and face culling.
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_CULL_FACE);

    m_Renderer = std::make_unique<Renderer>();
}

void Application::MainLoop() {
    bool running = true;
    SDL_Event ev;
    while (running) {
        SDL_GL_SwapWindow(m_Window);
        while (SDL_PollEvent(&ev)) {  // poll until all events are handled!

            if (ev.type == SDL_EVENT_QUIT) {
                running = false;
                break;
            }

        }

        DrawWindow();
    }
}
void Application::Cleanup() {
    SDL_DestroyWindow(m_Window);
    SDL_Quit();
}

void Application::DrawWindow() {
    int w, h;
    SDL_GetWindowSize(m_Window, &w, &h);
    glViewport(0, 0, w, h);
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1.0f, 0.5f, 1.0f, 0.0f);

    m_Renderer->Render();
}