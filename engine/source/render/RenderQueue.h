#pragma once
#include <vector>
#include <glm/mat4x4.hpp>

namespace eng
{
    class Mesh;
    class Material;
    class GraphicsAPI;

namespace eng
{
    class Mesh;
    class Material;
    class GraphicsAPI;

    /**
     * @struct RenderCommand
     * @brief A command containing all information needed to draw an object.
     */
    struct RenderCommand
    {
        Mesh* mesh = nullptr; ///< Pointer to the mesh to draw.
        Material* material = nullptr; ///< Pointer to the material to use.
        glm::mat4 modelMatrix; ///< The transformation matrix of the object.
    };

    /**
     * @struct CameraData
     * @brief Contains view and projection matrices for rendering.
     */
    struct CameraData
    {
        glm::mat4 viewMatrix; ///< The view matrix (camera position and orientation).
        glm::mat4 projectionMatrix; ///< The projection matrix (field of view, aspect ratio, etc.).
    };

    /**
     * @class RenderQueue
     * @brief Collects render commands and executes them in order.
     */
    class RenderQueue
    {
    public:
        /**
         * @brief Submits a render command to the queue.
         * @param command The render command to submit.
         */
        void Submit(const RenderCommand& command);

        /**
         * @brief Executes all submitted render commands.
         * @param graphicsAPI Reference to the graphics API for binding and drawing.
         * @param cameraData Data about the camera to use for rendering.
         */
        void Draw(GraphicsAPI& graphicsAPI, const CameraData& cameraData);

    private:
        std::vector<RenderCommand> m_commands; ///< List of submitted render commands.
    };
}

}