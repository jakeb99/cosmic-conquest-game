#pragma once

#include <vector>
#include <cmath>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <Engine.h>
#include <Bullet.h>

/**
 * Player Class
 *
 * This class defines the Player object and its functions. Handles input events, collisions with other sprites
 * (e.g., EnemyShip), and contains important information pertaining to the Player instance (health, acceleration,
 * total points, e.t.c.)
 */
class Player {
    private:
        const double _rotateSpeed;       
        const double _moveSpeed;   
        const double _maxVelocity;      
        const int _shootRate;            
        const int _bulletSpeed;

        SDL_Surface* _spriteSurface;     
        SDL_Texture* _sprite;            
        SDL_FRect _destinationRect;      
        double _rotation;                /** The current rotation (in degrees) of the player object */
        double _localX;                  /** The current x-coordinate of the player sprite on the playerscreen */
        double _localY;                  /** The current y-coordinate of the player sprite on the playerscreen */
        double _velocityX;               /** The current the current velocity of the player sprite along the x-axis of the playerscreen */
        double _velocityY;               /** The current the current velocity of the player sprite along the x-axis of the playerscreen */
        
        int _shotRecharge;               /** The timer that determines how long until the player can fire another bullet */
        bool _canShoot;                  
        int _health;          
        int _xClamp;
        int _yClamp;           

        bool PlayerInScreenBounds();

    public:
        
        Player();                       
        ~Player();          
        std::vector<Bullet*> bullets;   /** vector of bullets */
        SDL_Rect GetBounds() const;      /** The function that returns the rectangle associated with the player sprite */
        int GetCenterX() const;          /** Returns the current x-coordinate of the center of the player sprite on the playscreen */
        int GetCenterY() const;          /** Returns the current y-coordinate of the center of the player sprite on the playscreen */
        int GetLocalX() const;           /** Returns the current x-coordinate of the player sprite on the playscreen */
        int GetLocalY() const;           /** Returns the current y-coordinate of the player sprite on the playscreen */
        void SetPosition(int x, int y);  /** Sets the player sprite's new coordinates on the playscreen */
        int GetHealth() const;          
        void DecrementHealth();          /** Decreases the player's total remaining health */

        // void update(std::vector<Bullet*>* const bullets);   /** Updates the player's current position on the board */
        void Update();
        void Draw();                                        /** Draws the player object to the screen */

};
