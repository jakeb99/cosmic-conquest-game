#include <Button.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
Button::Button(SDL_Renderer *r, const std::string text, int w, int h, int x, int y, std::function<void()> clickHandler, int textSize, SDL_Color normalColor, SDL_Color hoverColor) {
    _renderer = r;
    _normalColor = normalColor;
    _hoverColor = hoverColor;

    onClick = clickHandler;

    // load the font
    TTF_Font *font = TTF_OpenFont("../assets/KleinHeadline-BoldOblique.ttf", textSize);

    if (!font) {
        std::cerr << "Could not load font: " << TTF_GetError() << std::endl;
        exit(1);
    }

    // create a surface for the normal text and hover text
    SDL_Surface *normalSurfaceText = TTF_RenderText_Solid(font, text.c_str(), _normalColor);
    SDL_Surface *hoverSurfaceText = TTF_RenderText_Solid(font, text.c_str(), _hoverColor);

    // create texture from the surface
    _textureNormal = SDL_CreateTextureFromSurface(_renderer, normalSurfaceText);
    _textureHover = SDL_CreateTextureFromSurface(_renderer, hoverSurfaceText);

    _currentTexture = _textureNormal;


    // now we can free the surface
    SDL_FreeSurface(normalSurfaceText);
    SDL_FreeSurface(hoverSurfaceText);

    // set the rect we want to draw on
    _rect.h = h;
    _rect.w = w;
    _rect.x = x;
    _rect.y = y;
}

Button::~Button() {

}

void Button::Update() {
    int x, y;
    Uint32 mouseState = SDL_GetMouseState(&x, &y);

    SDL_Rect mouseRect;
    mouseRect.w = mouseRect.h = 1;
    mouseRect.x = x;
    mouseRect.y = y;

    if(SDL_HasIntersection(&mouseRect, &_rect)) {
        _isSelected = true;
        _currentTexture = _textureHover;
        if (mouseState && SDL_BUTTON_LEFT && onClick) {
            onClick();
        }
    } else {
        _isSelected = false;
        _currentTexture = _textureNormal;
    }
}

void Button::Draw() {
    SDL_RenderCopy(_renderer, _currentTexture, NULL, &_rect);
}

const void Button::HandleClick() const {
    onClick();
}

bool Button::IsSelected() {
    return _isSelected;
}