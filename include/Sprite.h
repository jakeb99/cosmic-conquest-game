#include <vector>

#include <Engine.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

/**
 * This class creates a sprite that can be drawn to the game screen
 */
class Sprite {
    private:
        SDL_Renderer* _r;
        SDL_Surface* _spriteSurface;
        SDL_Texture* _sprite;
        SDL_FRect _destRect;
        double _localX;
        double _localY;
        double _velocityX;
        double _velocityY;

        SDL_Rect GetBounds() const;
        

    public:
        Sprite(std::string imgPath);
        ~Sprite();
        void SetPosition(int x, int y);     /* set screen pos of sprite */
        void Update();
        void Draw();
};