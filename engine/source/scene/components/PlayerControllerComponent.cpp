#include "scene/components/PlayerControllerComponent.h"
#include "Engine.h"
#include "input/InputManager.h"
#include <GLFW/glfw3.h>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/vec4.hpp>

namespace eng
{
void PlayerControllerComponent::Update(float deltaTime)
{
    auto &inputManager = Engine::GetInstance().GetInputManager();
    auto rotation = m_owner->GetRotation();

    if (inputManager.IsMouseButtonPressed(GLFW_MOUSE_BUTTON_LEFT))
    {
        const auto &oldPos = inputManager.GetMousePositionOld();
        const auto &currentPos = inputManager.GetMousePositionCurrent();

        float deltaX = currentPos.x - oldPos.x;
        float deltaY = currentPos.y - oldPos.y;

        // rot around Y axis
        float yAngle = -deltaX * m_sensitivity * deltaTime;
        glm::quat yRot = glm::angleAxis(yAngle, glm::vec3(0.0f, 1.0f, 0.0f));

        // rot around X axis
        float xAngle = -deltaY * m_sensitivity * deltaTime;
        glm::vec3 right = rotation * glm::vec3(1.0f, 0.0f, 0.0f);
        glm::quat xRot = glm::angleAxis(xAngle, right);

        glm::quat deltaRot = yRot * xRot;
        rotation = glm::normalize(deltaRot * rotation);

        m_owner->SetRotation(rotation);
    }

    glm::vec3 front = rotation * glm::vec3(0.0f, 0.0f, -1.0f);
    glm::vec3 right = rotation * glm::vec3(1.0f, 0.0f, 0.0f);

    auto position = m_owner->GetPosition();

    glm::vec3 moveDirection(0.0f);

    if (inputManager.IsKeyPressed(GLFW_KEY_A))
    {
        moveDirection -= right;
    }
    if (inputManager.IsKeyPressed(GLFW_KEY_D))
    {
        moveDirection += right;
    }
    if (inputManager.IsKeyPressed(GLFW_KEY_W))
    {
        moveDirection += front;
    }
    if (inputManager.IsKeyPressed(GLFW_KEY_S))
    {
        moveDirection -= front;
    }

    if (glm::length(moveDirection) > 0.0f)
    {
        moveDirection = glm::normalize(moveDirection);
        position += moveDirection * m_moveSpeed * deltaTime;
    }
    m_owner->SetPosition(position);
}
} // namespace eng