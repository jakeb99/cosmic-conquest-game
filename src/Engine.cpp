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
        exit(1);
    } else {
        std::cout << "SDL init successfully!" << std::endl;
    }

    // create the window and renderer
    _window = SDL_CreateWindow("Cosmic", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, internalWidth, internalHeight, SDL_WINDOW_SHOWN);

    if (!_window) {
        std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        exit(1);
    }
    _renderer = SDL_CreateRenderer(_window, -1, 0);
    if (!_renderer) {
        std::cerr << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        exit(1);
    }

    _isRunning = true;
}

Engine::~Engine() {
    SetScreen(NULL);
    SDL_DestroyRenderer(_renderer);
    SDL_DestroyWindow(_window);
    SDL_Quit();
}

void Engine::DoGameLoop() {
    const float frameFrequency = 1000.0f / framerateLimit; // How frequently, in ms, we do another "frame." Ex: at a  
                                                           // limit of 30 FPS this comes out to 1 frame per ~33.3 ms.
    Uint32 accumulatedTime = 0;
    Uint32 previousTime = SDL_GetTicks();

    while (_isRunning) {
        Uint32 currentTime = SDL_GetTicks();
        accumulatedTime += currentTime - previousTime;
        previousTime = SDL_GetTicks();

        while (accumulatedTime >= frameFrequency) {
            PollEvents();
            if (_isRunning) {
                Update();
                Draw();
            }
            accumulatedTime -= frameFrequency;
        }
    }
}

void Engine::SetScreen(Screen* const screen) {
    if (_currentScreen != NULL)
        delete _currentScreen;
    _currentScreen = screen;
}

Engine* Engine::GetInstance() {
    if(_instance == NULL) 
        _instance = new Engine();
    
    return _instance;
}

SDL_Window* Engine::GetWindow() const {
    return _window;
}

SDL_Renderer* Engine::GetRenderer() const {
    return _renderer;
}

void Engine::Update() {
    if (_currentScreen)
        _currentScreen->Update();
}

void Engine::Draw() {
    SDL_SetRenderDrawColor(_renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(_renderer);
    if (_currentScreen)
        _currentScreen->Draw();
    SDL_RenderPresent(_renderer);
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