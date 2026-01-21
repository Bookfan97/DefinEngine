#pragma once

#include "scene/Component.h"
#include <memory>

namespace eng
{
    class Material;
    class Mesh;

    /**
     * @class MeshComponent
     * @brief Component that encapsulates a mesh and a material for rendering.
     */
    class MeshComponent : public Component
    {
        COMPONENT(MeshComponent)
    public:
        /**
         * @brief Constructs a MeshComponent.
         * @param material Shared pointer to the material.
         * @param mesh Shared pointer to the mesh.
         */
        MeshComponent(const std::shared_ptr<Material>& material, const std::shared_ptr<Mesh>& mesh);

        /**
         * @brief Updates the mesh component (handles rendering submission).
         * @param deltaTime The time since the last frame in seconds.
         */
        void Update(float deltaTime) override;

    private:
        std::shared_ptr<Material> m_material; ///< The material used for rendering.
        std::shared_ptr<Mesh> m_mesh; ///< The mesh used for rendering.
    };

}