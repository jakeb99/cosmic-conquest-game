#include <PlayScreen.h>

PlayScreen::PlayScreen() {
    _player.SetPosition((Engine::internalWidth / 2) - (_player.GetBounds().w / 2), (Engine::internalHeight / 2) - (_player.GetBounds().h / 2));
}

PlayScreen::~PlayScreen() {}

void PlayScreen::Update() {
    _player.Update();
}

void PlayScreen::Draw() {
    _player.Draw();
}