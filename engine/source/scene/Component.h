#pragma once
#include <cstddef>

namespace eng
{
    class GameObject;

    /**
     * @class Component
     * @brief Base class for all components that can be attached to game objects.
     */
    class Component
    {
    public:
        /**
         * @brief Virtual destructor.
         */
        virtual ~Component() = default;

        /**
         * @brief Pure virtual function for the component's update logic.
         * @param deltaTime The time since the last frame in seconds.
         */
        virtual void Update(float deltaTime) = 0;

        /**
         * @brief Gets the type ID of the component.
         * @return The unique type ID.
         */
        virtual size_t GetTypeId() const = 0;

        /**
         * @brief Gets the owner game object.
         * @return Pointer to the owning GameObject.
         */
        GameObject* GetOwner();

        /**
         * @brief Statically generates or retrieves a unique type ID for a component class.
         * @tparam T The component class type.
         * @return The unique type ID for type T.
         */
        template<typename T>
        static size_t StaticTypeId()
        {
            static size_t typeId = nextId++;
            return typeId;
        }

    protected:
        GameObject* m_owner = nullptr; ///< Pointer to the owning game object.

        friend class GameObject;

    private:
        static size_t nextId; ///< Global ID counter for components.
    };

    /**
     * @brief Macro to simplify component class definitions with type ID support.
     */
#define COMPONENT(ComponentClass) \
public: \
    static size_t TypeId() { return Component::StaticTypeId<ComponentClass>(); } \
    size_t GetTypeId() const override { return TypeId(); } 
}