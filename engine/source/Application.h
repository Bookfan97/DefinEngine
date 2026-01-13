#pragma once

namespace eng {
    /**
     * @class Application
     * @brief Base class for game applications.
     * 
     * Users should inherit from this class to create their game logic.
     */
    class Application {
    public:
        virtual ~Application() = default;

        /**
         * @brief Initializes the application.
         * @return true if initialization was successful, false otherwise.
         */
        virtual bool Init() = 0;

        /**
         * @brief Updates the application state.
         * @param deltaTime The time elapsed since the last frame in seconds.
         */
        virtual void Update(float deltaTime) = 0;

        /**
         * @brief Cleans up application resources.
         */
        virtual void Destroy() = 0;

        /**
         * @brief Sets whether the application should close.
         * @param value True if the application should close, false otherwise.
         */
        void SetNeedsToBeClosed(bool value);

        /**
         * @brief Checks if the application needs to be closed.
         * @return True if the application should close, false otherwise.
         */
        bool NeedsToBeClosed() const;

    private:
        bool m_needsToBeClosed = false;
    };
}
