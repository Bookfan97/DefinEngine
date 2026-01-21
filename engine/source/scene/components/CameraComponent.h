#pragma once

#include "scene/Component.h"
#include <glm/mat4x4.hpp>

namespace eng
{
    /**
     * @class CameraComponent
     * @brief Component that provides camera functionality to a game object.
     */
    class CameraComponent : public Component
    {
        COMPONENT(CameraComponent)
    public:
        /**
         * @brief Updates the camera component.
         * @param deltaTime The time since the last frame in seconds.
         */
        void Update(float deltaTime) override;

        /**
         * @brief Calculates the view matrix based on the object's transform.
         * @return The 4x4 view matrix.
         */
        glm::mat4 GetViewMatrix() const;

        /**
         * @brief Calculates the projection matrix.
         * @param aspect The aspect ratio of the viewport.
         * @return The 4x4 projection matrix.
         */
        glm::mat4 GetProjectionMatrix(float aspect) const;

    private:
        float m_fov = 60.0f; ///< Field of view in degrees.
        float m_nearPlane = 0.1f; ///< Near clipping plane distance.
        float m_farPlane = 1000.0f; ///< Far clipping plane distance.
    };

}