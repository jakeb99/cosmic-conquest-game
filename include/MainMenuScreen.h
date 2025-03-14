#pragma once

#include <vector>

#include <SDL2/SDL.h>

#include <Screen.h>
#include <Button.h>

class MainMenuScreen : public Screen {
    private:
        std::vector<Button> _buttons;
    public:
        MainMenuScreen();
        virtual ~MainMenuScreen();
        virtual void Update();
        virtual void Draw();
};