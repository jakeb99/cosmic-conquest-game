#include <PlayScreen.h>
#include <iostream>

PlayScreen::PlayScreen() {
    // _player.SetPosition((Engine::internalWidth / 2) - (_player.GetBounds().w / 2), (Engine::internalHeight / 2) - (_player.GetBounds().h / 2));
    _player.SetPosition(600, 600);
}

PlayScreen::~PlayScreen() {}

void PlayScreen::Update() {
    _player.Update();
    
    std::cout << "bullets: " << _player.bullets.size() << std::endl;

    for (Bullet *b : _player.bullets) {
        b->Update();
    }

}

void PlayScreen::Draw() {
    _player.Draw();
    for (Bullet *b : _player.bullets) {
        b->Draw();
    }
}