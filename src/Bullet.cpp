#include <iostream>

#include <Bullet.h>

Bullet::Bullet() : _bulletSpeed(2.0) {
    _sprite = new Sprite("../assets/bullet.png");

    _xClamp = Engine::GetInstance()->internalWidth;
    _yClamp = Engine::GetInstance()->internalHeight;
}

void Bullet::Update() {
    _sprite->SetPosition(50, 50);
}

void Bullet::Draw() {
    _sprite->Draw();
}