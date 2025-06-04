#include <Sprite.h>
#include <iostream>

Sprite::Sprite(std::string imgPath) {
    _r = Engine::GetInstance()->GetRenderer();
    _spriteSurface = IMG_Load(imgPath.c_str());
    if (_spriteSurface == NULL) {
        std::cerr << "IMG_Load Error: " << IMG_GetError() << std::endl;
        exit(1);
    }

    _sprite = SDL_CreateTextureFromSurface(_r, _spriteSurface);

    SDL_FreeSurface(_spriteSurface);

    int width, height;
    if (SDL_QueryTexture(_sprite, NULL, NULL, &width, &height) < 0) {
        std::cerr << "SDL_QueryTexture Error: " << SDL_GetError() << std::endl;
        exit(1);  
    }

    _destRect.w = (float) width;
    _destRect.h = (float) height;
}

void Sprite::Update() {

}

void Sprite::Draw() {
    SDL_Rect destBoundsInt = GetBounds();
    SDL_Point center;
    center.x = _destRect.w / 2;
    center.y = _destRect.h / 2;

    if (SDL_RenderCopyEx(_r, _sprite, NULL, &destBoundsInt, 0.0, &center, SDL_FLIP_NONE) < 0) {
        std::cerr << "SDL_RenderCopyEx Error: " << SDL_GetError() << std::endl;
        exit(1);
    }
}

SDL_Rect Sprite::GetBounds() const {
    SDL_Rect destinationRectInt;
    destinationRectInt.x = (int) _destRect.x;
    destinationRectInt.y = (int) _destRect.y;
    destinationRectInt.w = (int) _destRect.w;
    destinationRectInt.h = (int) _destRect.h;

    return destinationRectInt;
}

void Sprite::SetPosition(int x, int y) {
    _destRect.x = x;
    _destRect.y = y;

    _localX = x;
    _localY = y;
}