#include "GameScene.h"
#include <iostream>
#include <fstream>

#include "Renderer.h"
#include "Constants.h"
#include "json.hpp"

GameScene::GameScene()
    : Scene(Type::GameScene) {
    m_keys = SDL_GetKeyboardState(NULL);
}

void GameScene::start() {
}

void GameScene::stop() {

}

void GameScene::handleEvents(const SDL_Event& event) {
}

void GameScene::update(float dt) {
}

void GameScene::render(const Renderer& renderer) const {
}
