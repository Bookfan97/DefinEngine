#pragma once
#include "scene/GameObject.h"
#include <vector>
#include <string>
#include <memory>

namespace eng
{
    /**
     * @class Scene
     * @brief Manages a collection of game objects and the active camera.
     */
    class Scene
    {
    public:
        /**
         * @brief Updates all active game objects in the scene.
         * @param deltaTime The time since the last frame in seconds.
         */
        void Update(float deltaTime);

        /**
         * @brief Clears all game objects from the scene.
         */
        void Clear();

        /**
         * @brief Creates a new game object in the scene.
         * @param name The name of the new object.
         * @param parent Pointer to the parent object, or nullptr if it's a root object.
         * @return Pointer to the created GameObject.
         */
        GameObject* CreateObject(const std::string& name, GameObject* parent = nullptr);

        /**
         * @brief Creates a new game object of a specific type in the scene.
         * @tparam T The type of the game object.
         * @param name The name of the new object.
         * @param parent Pointer to the parent object, or nullptr if it's a root object.
         * @return Pointer to the created object.
         */
        template<typename T, typename = typename std::enable_if_t<std::is_base_of_v<GameObject, T>>>
        T* CreateObject(const std::string& name, GameObject* parent = nullptr)
        {
            auto obj = new T();
            obj->SetName(name);
            SetParent(obj, parent);
            return obj;
        }

        /**
         * @brief Changes the parent of a game object.
         * @param obj Pointer to the object to reparent.
         * @param parent Pointer to the new parent object.
         * @return true if successful, false otherwise.
         */
        bool SetParent(GameObject* obj, GameObject* parent);

        /**
         * @brief Sets the main camera for the scene.
         * @param camera Pointer to the camera GameObject.
         */
        void SetMainCamera(GameObject* camera);

        /**
         * @brief Gets the main camera of the scene.
         * @return Pointer to the main camera object.
         */
        GameObject* GetMainCamera();

    private:
        std::vector<std::unique_ptr<GameObject>> m_objects; ///< Root game objects in the scene.
        GameObject* m_mainCamera = nullptr; ///< Pointer to the active camera.
    };
}