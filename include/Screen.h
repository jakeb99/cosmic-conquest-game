#pragma once

/**
 * Abstract class. Represents a screen or game scene. The engine has a reference to a concrete instance of some screen 
 * at all times to update and draw them. Screens are containers of game objects, and represent the main menu, in game, 
 * the settings menu, etc.
*/
class Screen {
    public:
        Screen();
        virtual ~Screen() = 0;
        virtual void Update() = 0;
        virtual void Draw() = 0;
};