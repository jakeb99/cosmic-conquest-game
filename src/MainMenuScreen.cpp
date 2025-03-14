#include <MainMenuScreen.h>
#include <PlayScreen.h>
#include <Button.h>
#include <Engine.h>

#define BUTTON_WIDTH 250
#define BUTTON_HEIGHT 100

inline void HandleStartButton() {
    Engine::GetInstance()->SetScreen(new PlayScreen());
}

inline void HandleExitButton() {
    Engine::GetInstance()->ExitGame();
}

MainMenuScreen::MainMenuScreen() {
    Engine *engine = Engine::GetInstance();

    // Game Title
    Button *gameTitle = new Button(engine->GetRenderer(), "Cosmic Conquest", BUTTON_WIDTH*2, BUTTON_HEIGHT*2, (engine->internalWidth/2) - (BUTTON_WIDTH), ((engine->internalHeight / 2) - (BUTTON_HEIGHT / 2)) - BUTTON_HEIGHT * 3, NULL, 134, {100, 255, 100}, {100, 255, 100});
    _buttons.push_back(*gameTitle);

    // start game button
    Button *startButton = new Button(engine->GetRenderer(), "START", BUTTON_WIDTH, BUTTON_HEIGHT, (engine->internalWidth / 2) - (BUTTON_WIDTH / 2), (engine->internalHeight / 2) - (BUTTON_HEIGHT / 2), HandleStartButton, 100, {255, 255, 255}, {100, 255, 100});
    _buttons.push_back(*startButton);

    // score screen button
    Button *scoreButton = new Button(engine->GetRenderer(), "SCORE", BUTTON_WIDTH, BUTTON_HEIGHT, (engine->internalWidth / 2) - (BUTTON_WIDTH / 2), ((engine->internalHeight / 2) - (BUTTON_HEIGHT / 2)) + BUTTON_HEIGHT, NULL, 100, {255, 255, 255}, {100, 255, 100});
    _buttons.push_back(*scoreButton);

    // exit button
    Button *exitButton = new Button(engine->GetRenderer(), "EXIT", BUTTON_WIDTH, BUTTON_HEIGHT, (engine->internalWidth / 2) - (BUTTON_WIDTH / 2), ((engine->internalHeight / 2) - (BUTTON_HEIGHT / 2)) + BUTTON_HEIGHT * 2, HandleExitButton, 100, {255, 255, 255}, {100, 255, 100});
    _buttons.push_back(*exitButton);

}

MainMenuScreen::~MainMenuScreen() {}

void MainMenuScreen::Update() {
    for (Button &button : _buttons) {
        button.Update();
    }
}

void MainMenuScreen::Draw() {
    for (Button &button : _buttons) {
        button.Draw();
    }
}

