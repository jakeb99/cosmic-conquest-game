#include <iostream>

#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

#include <Engine.h>
#include <PlayScreen.h>   // remove when main menu screen is done
#include <MainMenuScreen.h>

int main() {
    if (TTF_Init() == -1) {
        std::cerr << "ERROR Failed to init sdl TTF: " << TTF_GetError() << std::endl;
    }
    Engine* engine = Engine::GetInstance();
    // TODO: create screen and set current screen
    engine->SetScreen(new MainMenuScreen());
    engine->DoGameLoop();

    delete engine;
    std::cout << "Exiting game!" << std::endl;
    return 0;
}