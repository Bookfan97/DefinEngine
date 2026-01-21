#pragma once
#include "graphics/GraphicsAPI.h"
#include "input/InputManager.h"
#include "render/RenderQueue.h"
#include "scene/Scene.h"
#include <chrono>
#include <memory>

struct GLFWwindow;
namespace eng
{
class Application;

/**
 * @class Engine
 * @brief The core engine class managing subsystems and the application lifecycle.
 */
class Engine
{
  public:
    /**
     * @brief Gets the singleton instance of the Engine.
     * @return Reference to the Engine instance.
     */
    static Engine &GetInstance();

    Engine(const Engine &) = delete;
    Engine(Engine &&) = delete;
    Engine &operator=(const Engine &) = delete;
    Engine &operator=(Engine &&) = delete;

  private:
    Engine() = default;

  public:
    /**
     * @brief Initializes the engine and its subsystems.
     * @param width The width of the game window.
     * @param height The height of the game window.
     * @return true if initialization was successful, false otherwise.
     */
    bool Init(int width, int height);

    /**
     * @brief Runs the main engine loop.
     */
    void Run();

    /**
     * @brief Shuts down the engine and cleans up resources.
     */
    void Destroy();

    /**
     * @brief Sets the current application.
     * @param app Pointer to the application.
     */
    void SetApplication(Application *app);

    /**
     * @brief Gets the current application.
     * @return Pointer to the current application.
     */
    Application *GetApplication();

    /**
     * @brief Gets the input manager.
     * @return Reference to the input manager.
     */
    InputManager &GetInputManager();

    /**
     * @brief Gets the graphics API interface.
     * @return Reference to the graphics API.
     */
    GraphicsAPI &GetGraphicsAPI();

    /**
     * @brief Gets the render queue.
     * @return Reference to the render queue.
     */
    RenderQueue &GetRenderQueue();

    /**
     * @brief Sets the current scene.
     * @param scene Pointer to the scene.
     */
    void SetScene(std::unique_ptr<Scene> scene);

    /**
     * @brief Gets the current scene.
     * @return Pointer to the current scene.
     */
    Scene *GetScene();

  private:
    std::unique_ptr<Application> m_application;            ///< The managed application instance.
    std::chrono::steady_clock::time_point m_lastTimePoint; ///< Timestamp of the last frame.
    GLFWwindow *m_window = nullptr;                        ///< Pointer to the GLFW window.
    InputManager m_inputManager;                           ///< The input manager subsystem.
    GraphicsAPI m_graphicsAPI;                             ///< The graphics API subsystem.
    RenderQueue m_renderQueue;                             ///< The rendering queue.
    std::unique_ptr<Scene> m_currentScene;                 ///< The current scene.
};
} // namespace eng