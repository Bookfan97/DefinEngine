#pragma once
#include "input/InputManager.h"
#include "graphics/GraphicsAPI.h"
#include "render/RenderQueue.h"
#include <memory>
#include <chrono>

struct GLFWwindow;

namespace eng {
    class Application;

    /**
     * @class Engine
     * @brief The core engine class managing the game lifecycle and systems.
     * 
     * This class follows the Singleton pattern and provides access to major
     * engine systems like GraphicsAPI, InputManager, and RenderQueue.
     */
    class Engine {
    public:
        /**
         * @brief Gets the singleton instance of the Engine.
         * @return Reference to the Engine instance.
         */
        static Engine &GetInstance();

    private:
        Engine() = default;

        Engine(const Engine &) = delete;

        Engine(Engine &&) = delete;

        Engine &operator=(const Engine &) = delete;

        Engine &operator=(Engine &&) = delete;

    public:
        /**
         * @brief Initializes the engine and its systems.
         * @param width The width of the game window.
         * @param height The height of the game window.
         * @return true if initialization was successful, false otherwise.
         */
        bool Init(int width, int height);

        /**
         * @brief Starts the main game loop.
         */
        void Run();

        /**
         * @brief Shuts down the engine and cleans up resources.
         */
        void Destroy();

        /**
         * @brief Sets the current application to be managed by the engine.
         * @param app Pointer to the application instance.
         */
        void SetApplication(Application *app);

        /**
         * @brief Gets the current application instance.
         * @return Pointer to the Application instance.
         */
        Application *GetApplication();

        /**
         * @brief Gets the InputManager system.
         * @return Reference to the InputManager.
         */
        InputManager &GetInputManager();

        /**
         * @brief Gets the GraphicsAPI system.
         * @return Reference to the GraphicsAPI.
         */
        GraphicsAPI &GetGraphicsAPI();

        /**
         * @brief Gets the RenderQueue system.
         * @return Reference to the RenderQueue.
         */
        RenderQueue &GetRenderQueue();

    private:
        std::unique_ptr<Application> m_application;
        std::chrono::steady_clock::time_point m_lastTimePoint;
        GLFWwindow *m_window = nullptr;
        InputManager m_inputManager;
        GraphicsAPI m_graphicsAPI;
        RenderQueue m_renderQueue;
    };
}
