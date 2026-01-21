#pragma once
#include "scene/Component.h"
#include <glm/gtc/quaternion.hpp>
#include <glm/mat4x4.hpp>
#include <glm/vec3.hpp>
#include <memory>
#include <string>
#include <vector>

namespace eng
{
/**
 * @class GameObject
 * @brief Base class for all entities in the game world.
 */
class GameObject
{
  public:
    /**
     * @brief Virtual destructor.
     */
    virtual ~GameObject() = default;

    /**
     * @brief Updates the game object and its components.
     * @param deltaTime The time since the last frame in seconds.
     */
    virtual void Update(float deltaTime);

    /**
     * @brief Gets the name of the game object.
     * @return The name string.
     */
    [[nodiscard]] const std::string &GetName() const;

    /**
     * @brief Sets the name of the game object.
     * @param name The new name string.
     */
    void SetName(const std::string &name);

    /**
     * @brief Gets the parent game object.
     * @return Pointer to the parent GameObject, or nullptr if none.
     */
    GameObject *GetParent();

    /**
     * @brief Checks if the object is still alive (not marked for destruction).
     * @return true if alive, false otherwise.
     */
    [[nodiscard]] bool IsAlive() const;

    /**
     * @brief Marks the object for destruction at the end of the frame.
     */
    void MarkForDestroy();

    /**
     * @brief Adds a component to the game object.
     * @param component Pointer to the component to add.
     */
    void AddComponent(Component *component);

    /**
     * @brief Gets a component of a specific type.
     * @tparam T The type of the component.
     * @return Pointer to the component if found, nullptr otherwise.
     */
    template <typename T, typename = typename std::enable_if_t<std::is_base_of_v<Component, T>>> T *GetComponent()
    {
        size_t typeId = Component::StaticTypeId<T>();

        for (auto &component : m_components)
        {
            if (component->GetTypeId() == typeId)
            {
                return static_cast<T *>(component.get());
            }
        }

        return nullptr;
    }

    /**
     * @brief Gets the local position of the object.
     * @return Reference to the position vector.
     */
    [[nodiscard]] const glm::vec3 &GetPosition() const;

    /**
     * @brief Sets the local position of the object.
     * @param pos The new position vector.
     */
    void SetPosition(const glm::vec3 &pos);

    /**
     * @brief Gets the local rotation of the object.
     * @return Reference to the rotation quaternion.
     */
    [[nodiscard]] const glm::quat &GetRotation() const;

    /**
     * @brief Sets the local rotation of the object.
     * @param rot The new rotation quaternion.
     */
    void SetRotation(const glm::quat &rot);

    /**
     * @brief Gets the local scale of the object.
     * @return Reference to the scale vector.
     */
    [[nodiscard]] const glm::vec3 &GetScale() const;

    /**
     * @brief Sets the local scale of the object.
     * @param scale The new scale vector.
     */
    void SetScale(const glm::vec3 &scale);

    /**
     * @brief Calculates the local transformation matrix.
     * @return The 4x4 local transform matrix.
     */
    [[nodiscard]] glm::mat4 GetLocalTransform() const;

    /**
     * @brief Calculates the world transformation matrix.
     * @return The 4x4 world transform matrix.
     */
    [[nodiscard]] glm::mat4 GetWorldTransform() const;

  protected:
    GameObject() = default;

  private:
    std::string m_name;                                       ///< The name of the object.
    GameObject *m_parent = nullptr;                           ///< Pointer to the parent object.
    std::vector<std::unique_ptr<GameObject>> m_children;      ///< List of child objects.
    std::vector<std::unique_ptr<Component>> m_components;     ///< List of attached components.
    bool m_isAlive = true;                                    ///< Lifespan state of the object.
    glm::vec3 m_position = glm::vec3(0.0f);                   ///< Local position.
    glm::quat m_rotation = glm::quat(1.0f, 0.0f, 0.0f, 0.0f); ///< Local rotation.
    glm::vec3 m_scale = glm::vec3(1.0f);                      ///< Local scale.

    friend class Scene;
};
} // namespace eng