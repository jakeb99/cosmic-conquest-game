#pragma once
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_surface.h>
#include <functional>

/**
 * Button class.
 *
 * This class defines the button object and provides functions to handle mouse events and draw the button
 * to the screen. This class inherits from SDL_Surface.
 *
 */
class Button {
private:
    const std::string _text;    
    SDL_Color _normalColor, _hoverColor;  
    SDL_Texture *_textureNormal;      /* pointer to normal button texture */
    SDL_Texture *_textureHover;      /* pointer to hover button texture */
    SDL_Texture *_currentTexture;    /* pointer to current texture we want to render*/
    SDL_Renderer *_renderer;    
    SDL_Rect _rect;              /** sdl rectangle */
    bool _isSelected = false;   /** true when mouse intersects _dst, else false */
    // ButtonHandler *_buttonHandler;
    std::function<void()> onClick; // function called when button is clicked
public:
    /**
     * Button - Creates a UI button object.
     * \param id the string id of the button.
     * \param r pointer to engine renderer
     */
    Button(SDL_Renderer *r, const std::string text, int w, int h, int x, int y, std::function<void()> clickHandler, int textSize, SDL_Color normalColor, SDL_Color hoverColor);

    /**
     * ~Button - Button object destructor.
     */
    virtual ~Button();

    /**
     * update - checks if the mouse hovers over the button and changes it to selected state.
     */
    void Update();

    /**
     * draw - renders the button to the screen.
     */
    void Draw();

    /**
     * isSelected - returns true when the mouse intersects with the button
     * \return  boolean
     */
    bool IsSelected();

    /**
     * call button handle strategy
    */
    const void HandleClick() const;

};