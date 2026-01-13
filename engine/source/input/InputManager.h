#pragma once
#include <array>

namespace eng {
    /**
     * @class InputManager
     * @brief Manages keyboard input states.
     */
    class InputManager {
    private:
        InputManager() = default;

        InputManager(const InputManager &) = delete;

        InputManager(InputManager &&) = delete;

        InputManager &operator=(const InputManager &) = delete;

        InputManager &operator=(InputManager &&) = delete;

    public:
        /**
         * @brief Sets the state of a key.
         * @param key The key code.
         * @param pressed True if the key is pressed, false otherwise.
         */
        void SetKeyPressed(int key, bool pressed);

        /**
         * @brief Checks if a key is currently pressed.
         * @param key The key code.
         * @return True if the key is pressed, false otherwise.
         */
        bool IsKeyPressed(int key);

    private:
        std::array<bool, 256> m_keys = {false};
        friend class Engine;
    };
}
