#pragma once

#include <vector>

#include <SDL2/SDL.h>

#include <Screen.h>
#include <Player.h>
// #include <Bullet.h>

class PlayScreen : public Screen {
    private:
        Player _player;
        // std::vector<Bullet*> _bullets;
    public:
        PlayScreen();
        virtual ~PlayScreen();
        virtual void Update();
        virtual void Draw();
};