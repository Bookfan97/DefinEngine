#include "game.h"

#include <iostream>
#include <ostream>

bool Game::Init() {
    return true;
}

void Game::Update(float deltaTime) {
    std::cout << "Current delta: " << deltaTime << std::endl;
}

void Game::Destroy() {
}
