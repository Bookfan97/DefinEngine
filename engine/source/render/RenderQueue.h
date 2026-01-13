#pragma once
#include <vector>

namespace eng {
    class Mesh;
    class Material;
    class GraphicsAPI;

    /**
     * @struct RenderCommand
     * @brief Encapsulates all data needed to perform a single draw call.
     */
    struct RenderCommand {
        Mesh *mesh = nullptr;         ///< The geometry to draw.
        Material *material = nullptr; ///< The visual properties to use.
    };

    /**
     * @class RenderQueue
     * @brief Collects and executes render commands.
     */
    class RenderQueue {
    public:
        /**
         * @brief Submits a command to the queue.
         * @param command The render command to add.
         */
        void Submit(const RenderCommand &command);

        /**
         * @brief Executes all submitted render commands.
         * @param graphicsAPI The graphics API instance to use for drawing.
         */
        void Draw(GraphicsAPI &graphicsAPI);

    private:
        std::vector<RenderCommand> m_commands;
    };
}
