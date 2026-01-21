#pragma once
#include <eng.h>
#include <memory>

/**
 * @class Game
 * @brief The main game class which inherits from the engine's Application class.
 */
class Game : public eng::Application
{
public:
    /**
     * @brief Initializes the game.
     * @return true if initialization was successful, false otherwise.
     */
    bool Init() override;

    /**
     * @brief Updates the game state.
     * @param deltaTime The time since the last frame.
     */
    void Update(float deltaTime) override;

    /**
     * @brief Cleans up game resources.
     */
    void Destroy() override;

private:
    eng::Scene m_scene; ///< The game's main scene.
};