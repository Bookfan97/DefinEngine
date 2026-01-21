#pragma once

#include <eng.h>

/**
 * @class TestObject
 * @brief A sample game object used for testing engine functionality.
 */
class TestObject : public eng::GameObject
{
public:
    TestObject();

    /**
     * @brief Updates the TestObject's state.
     * @param deltaTime The time since the last frame.
     */
    void Update(float deltaTime) override;

private:
    eng::Material m_material; ///< The material used by the object.
    std::shared_ptr<eng::Mesh> m_mesh; ///< The mesh used by the object.
    float m_offsetX = 0.0f; ///< Offset on the X axis.
    float m_offsetY = 0.0f; ///< Offset on the Y axis.
};