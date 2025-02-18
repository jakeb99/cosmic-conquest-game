#include <iostream>
#include <Engine.h>

const int Engine::internalWidth = 1920;
const int Engine::internalHeight = 1080;
const int Engine::framerateLimit = 60;

Engine* Engine::_instance = NULL;

Engine::Engine() {
    // init SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL did not init! SDL_Error: " << SDL_GetError() << std::endl;
    } else {
        std::cout << "SDL init successfully!" << std::endl;
    }

    // create the window and renderer
    _window = SDL_CreateWindow("Cosmic", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, internalWidth, internalHeight, SDL_WINDOW_SHOWN);

    if (!_window) {
        std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
    }
    _renderer = SDL_CreateRenderer(_window, -1, 0);
        if (!_renderer) {
        std::cerr << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
    }

    _isRunning = true;
}

void Engine::DoGameLoop() {
    while (_isRunning) {
        PollEvents();
        if (_isRunning) {
            // TODO: screen update and draw methods
        }
    }
    
}

void Engine::PollEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) { // while there are still events to handle
        switch(event.type) {
            case SDL_QUIT:
                _isRunning = false;
                break;
        }
    }
}

Engine::~Engine() {
    // TODO: destroy screen here...
    SDL_DestroyRenderer(_renderer);
    SDL_DestroyWindow(_window);
    SDL_Quit();
}

Engine* Engine::GetInstance() {
    if(_instance == NULL) 
        _instance = new Engine();
    
    return _instance;
}
