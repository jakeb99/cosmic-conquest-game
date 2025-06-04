#include <math.h>
#include <cmath>
#include <iostream>

#include <Player.h>

Player::Player() : _rotateSpeed(12.0), _moveSpeed(2), _maxVelocity(5), _shootRate(20), _bulletSpeed(10) {
    _spriteSurface = IMG_Load("../assets/player.png");
    if (_spriteSurface == NULL) {
        std::cerr << "IMG_Load Error: " << IMG_GetError() << std::endl;
        exit(1);
    }

    _sprite = SDL_CreateTextureFromSurface(Engine::GetInstance()->GetRenderer(), _spriteSurface);
    if (_sprite == NULL) {
        std::cerr << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
        exit(1);
    }
    SDL_FreeSurface(_spriteSurface);    // free surface after creating texture bc its no longer needed

    int width, height;
    if (SDL_QueryTexture(_sprite, NULL, NULL, &width, &height) < 0) {
        std::cerr << "SDL_QueryTexture Error: " << SDL_GetError() << std::endl;
        exit(1);
    } 

    std::cout << _sprite << std::endl;

    // _destinationRect.x = 0;
    // _destinationRect.y = 0;
    _destinationRect.w = (float)width;
    _destinationRect.h = (float)height;

    _rotation = 0;
    // _localX = 0;
    // _localY = 0;
    _velocityX = 0;
    _velocityY = 0;

    _xClamp = Engine::GetInstance()->internalWidth;
    _yClamp = Engine::GetInstance()->internalHeight;

    _canShoot = true;
    _shotRecharge = 0;

    _health = 10;

}

Player::~Player() {
    SDL_DestroyTexture(_sprite);
}

SDL_Rect Player::GetBounds() const {
    SDL_Rect destinationRectInt;
    destinationRectInt.x = (int) _destinationRect.x;
    destinationRectInt.y = (int) _destinationRect.y;
    destinationRectInt.w = (int) _destinationRect.w;
    destinationRectInt.h = (int) _destinationRect.h;

    return destinationRectInt;
}

int Player::GetCenterX() const {
    return _destinationRect.x + _destinationRect.w / 2;
}

int Player::GetCenterY() const {
    return _destinationRect.y + _destinationRect.h / 2;
}

int Player::GetLocalX() const {
    return _localX;
}

int Player::GetLocalY() const {
    return _localY;
}

void Player::SetPosition(int x, int y) {
    _destinationRect.x = x;
    _destinationRect.y = y;
    _localX = x;
    _localY = y;
}

int Player::GetHealth() const {
    return _health;
}

void Player::DecrementHealth() {
    _health--;
}

void Player::Update() {
    const Uint8 *keyBoardState = SDL_GetKeyboardState(NULL);

    if (keyBoardState[SDL_SCANCODE_A]) {
        _rotation -= _rotateSpeed;
    }
    if (keyBoardState[SDL_SCANCODE_D]) {
        _rotation += _rotateSpeed;
    }
    if (_rotation >= 360) {
        _rotation -= 360;
    }
    if (_rotation <= -360) {
        _rotation += 360;
    }
    if (keyBoardState[SDL_SCANCODE_SPACE]) {
        std::cout << "shooting" << std::endl;
        Bullet *b = new Bullet();
        bullets.push_back(b);
    }
    
    // get direction we are facing
    double rotationRads = _rotation * (M_PI / 180);
    double directionX = sin(rotationRads);
    double directionY = -cos(rotationRads);

    double prevLocalX = _localX;
    double prevLocalY = _localY;

    // accelerate with W
    if (keyBoardState[SDL_SCANCODE_W]) {
        _velocityX += directionX * _moveSpeed;
        _velocityY += directionY * _moveSpeed;
    }
    
    // std::cout << "VelocityX:" << _velocityX << ", VelocityY: " << _velocityY << std::endl;
    // std::cout << "(" << _localX << ", " << _localY << ")" << std::endl;
    
    // only set position if we are inside the screen boundries
    if (PlayerInScreenBounds()) {
        _localX += _velocityX;
        _localY += _velocityY;  
        SetPosition(_localX, _localY);
        // std::cout << "Set Pos: (" << _localX << ", " << _localY << ")" << std::endl;
    } else {
        _velocityX = _velocityY = 0;
        SetPosition(prevLocalX, prevLocalY);
    }
    
}

bool Player::PlayerInScreenBounds() {
    return _localX + _velocityX >= 0 && _localX + _velocityX <= _xClamp && _localY + _velocityY >= 0 && _localY + _velocityY <= _yClamp;
}

void Player::Draw() {
    SDL_Rect destinationBoundsInt = GetBounds();
    SDL_Point center;
    center.x = _destinationRect.w / 2;
    center.y = _destinationRect.h / 2;
    
    if (SDL_RenderCopyEx(Engine::GetInstance()->GetRenderer(), _sprite, NULL, &destinationBoundsInt, _rotation, &center, SDL_FLIP_NONE) < 0) {
        std::cerr << "SDL_RenderCopyEx Error: " << SDL_GetError() << std::endl;
        exit(1);
    }
}