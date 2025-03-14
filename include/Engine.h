#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <Screen.h>

class Engine {
    private:
        static Engine *_instance;
        SDL_Window *_window;
        SDL_Renderer *_renderer;
        Screen *_currentScreen;
        bool _isRunning;

        Engine();
        void PollEvents();
        void Update();
        void Draw();

    public:
        const static int internalWidth;
        const static int internalHeight;
        const static int framerateLimit;

        ~Engine();
        Engine(const Engine &other) = delete;
        Engine& operator=(const Engine &other) = delete;

        static Engine *GetInstance();
        SDL_Window *GetWindow() const;
        SDL_Renderer *GetRenderer() const;

        void DoGameLoop();

        void SetScreen(Screen *screen);

        void ExitGame();
};