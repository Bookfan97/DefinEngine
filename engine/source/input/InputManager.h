#pragma once
#include <array>
#include <glm/vec2.hpp>

namespace eng
{
    /**
     * @class InputManager
     * @brief Manages keyboard and mouse input states.
     */
    class InputManager
    {
    private:
        InputManager() = default;
        InputManager(const InputManager&) = delete;
        InputManager(InputManager&&) = delete;
        InputManager& operator=(const InputManager&) = delete;
        InputManager& operator=(InputManager&&) = delete;

    public:
        /**
         * @brief Updates the pressed state of a key.
         * @param key The key code.
         * @param pressed true if the key is pressed, false otherwise.
         */
        void SetKeyPressed(int key, bool pressed);

        /**
         * @brief Checks if a key is currently pressed.
         * @param key The key code.
         * @return true if the key is pressed, false otherwise.
         */
        bool IsKeyPressed(int key);

        /**
         * @brief Updates the pressed state of a mouse button.
         * @param button The mouse button code.
         * @param pressed true if the button is pressed, false otherwise.
         */
        void SetMouseButtonPressed(int button, bool pressed);

        /**
         * @brief Checks if a mouse button is currently pressed.
         * @param button The mouse button code.
         * @return true if the button is pressed, false otherwise.
         */
        bool IsMouseButtonPressed(int button);

        /**
         * @brief Sets the previous frame's mouse position.
         * @param pos The mouse position.
         */
        void SetMousePositionOld(const glm::vec2& pos);

        /**
         * @brief Gets the previous frame's mouse position.
         * @return Reference to the mouse position.
         */
        const glm::vec2& GetMousePositionOld() const;

        /**
         * @brief Sets the current frame's mouse position.
         * @param pos The mouse position.
         */
        void SetMousePositionCurrent(const glm::vec2& pos);

        /**
         * @brief Gets the current frame's mouse position.
         * @return Reference to the mouse position.
         */
        const glm::vec2& GetMousePositionCurrent() const;

    private:
        std::array<bool, 256> m_keys = { false }; ///< Array of key states.
        std::array<bool, 16> m_mouseKeys = { false }; ///< Array of mouse button states.
        glm::vec2 m_mousePositionOld = glm::vec2(0.0f); ///< Mouse position in the previous frame.
        glm::vec2 m_mousePositionCurrent = glm::vec2(0.0f); ///< Mouse position in the current frame.

        friend class Engine;
    };
}