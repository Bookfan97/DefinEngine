#pragma once
#include "eng.h"
#include <memory>

/**
 * @class Game
 * @brief Main game application class.
 * 
 * This class handles the lifecycle of the game, including initialization,
 * updates, and destruction.
 */
class Game : public eng::Application {
public:
    /**
     * @brief Initializes the game.
     * @return true if initialization was successful, false otherwise.
     */
    bool Init() override;

    /**
     * @brief Updates the game state.
     * @param deltaTime The time elapsed since the last frame.
     */
    void Update(float deltaTime) override;

    /**
     * @brief Cleans up game resources.
     */
    void Destroy() override;

private:
    eng::Scene m_scene;
};
