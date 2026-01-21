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
        static constexpr float DEFAULT_FOV = 60.0f;
        static constexpr float DEFAULT_NEAR_PLANE = 0.1f;
        static constexpr float DEFAULT_FAR_PLANE = 1000.0f;

        float m_fov = DEFAULT_FOV; ///< Field of view in degrees.
        float m_nearPlane = DEFAULT_NEAR_PLANE; ///< Near clipping plane distance.
        float m_farPlane = DEFAULT_FAR_PLANE; ///< Far clipping plane distance.
    };

} // namespace eng