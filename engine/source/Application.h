#pragma once

namespace eng
{
/**
 * @class Application
 * @brief Base class for all engine-based applications.
 */
class Application
{
  public:
    /**
     * @brief Virtual destructor.
     */
    virtual ~Application() = default;

    /**
     * @brief Pure virtual function for application initialization.
     * @return true if initialization was successful, false otherwise.
     */
    [[nodiscard]] virtual bool Init() = 0;

    /**
     * @brief Pure virtual function for the application update loop.
     * @param deltaTime The time since the last frame in seconds.
     */
    virtual void Update(float deltaTime) = 0;

    /**
     * @brief Pure virtual function for application cleanup.
     */
    virtual void Destroy() = 0;

    /**
     * @brief Sets whether the application should close.
     * @param value true to request closing, false otherwise.
     */
    void SetNeedsToBeClosed(bool value);

    /**
     * @brief Checks if the application has been requested to close.
     * @return true if closing is requested, false otherwise.
     */
    [[nodiscard]] bool NeedsToBeClosed() const;

  private:
    bool m_needsToBeClosed = false; ///< Whether the application should close.
};
} // namespace eng