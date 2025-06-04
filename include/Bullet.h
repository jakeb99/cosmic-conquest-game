#pragma once

#include <vector>
#include <cmath>

#include <Engine.h>
#include <Sprite.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Bullet {
    private:
        const double _bulletSpeed;
        Sprite* _sprite;
        int _xClamp;    // destroy bullet once its out of the screen
        int _yClamp;

    public:
        Bullet();
        ~Bullet();
        void Update();
        void Draw();
};