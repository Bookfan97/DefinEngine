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
    eng::Material m_material;           ///< Material used for rendering.
    std::unique_ptr<eng::Mesh> m_mesh;  ///< Mesh object for the game.
    float m_offsetX = 0.0f;             ///< X-axis offset for movement.
    float m_offsetY = 0.0f;             ///< Y-axis offset for movement.
};
