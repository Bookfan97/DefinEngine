#pragma once

#include "scene/Component.h"

namespace eng
{
/**
 * @class PlayerControllerComponent
 * @brief Component that provides player-controlled movement and rotation.
 */
class PlayerControllerComponent : public Component
{
    COMPONENT(PlayerControllerComponent)

  public:
    /**
     * @brief Updates the player controller, processing input for movement and rotation.
     * @param deltaTime The time since the last frame in seconds.
     */
    void Update(float deltaTime) override;

  private:
    float m_sensitivity = 1.5f; ///< Mouse look sensitivity.
    float m_moveSpeed = 3.0f;   ///< Movement speed.
};

} // namespace eng