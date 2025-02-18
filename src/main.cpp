#include <iostream>

#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

#include <Engine.h>

int SDLCheck() {
    std::cout << "-----------------------------------------------------------" << std::endl;
    std::cout << "Checking SDL is properly installed" << std::endl;
    // Check SDL2
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0) {
        std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 1;
    }
    std::cout << "SDL2 initialized successfully!" << std::endl;

    // Check SDL2_image
    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
        std::cerr << "SDL2_image Initialization Error: " << IMG_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }
    std::cout << "SDL2_image initialized successfully!" << std::endl;

    // Check SDL2_ttf
    if (TTF_Init() != 0) {
        std::cerr << "SDL2_ttf Initialization Error: " << TTF_GetError() << std::endl;
        IMG_Quit();
        SDL_Quit();
        return 1;
    }
    std::cout << "SDL2_ttf initialized successfully!" << std::endl;

    // Check SDL2_mixer
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        std::cerr << "SDL2_mixer Initialization Error: " << Mix_GetError() << std::endl;
        TTF_Quit();
        IMG_Quit();
        SDL_Quit();
        return 1;
    }
    std::cout << "SDL2_mixer initialized successfully!" << std::endl;

    // Clean up
    Mix_CloseAudio();
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();

    std::cout << "All SDL2 components initialized and cleaned up successfully!" << std::endl;
    std::cout << "-----------------------------------------------------------" << std::endl;
    return 0;
}

int main() {
    SDLCheck();

    Engine* engine = Engine::GetInstance();
    // TODO: create screen and set current screen
    engine->DoGameLoop();

    delete engine;
    std::cout << "Exiting game!" << std::endl;
}