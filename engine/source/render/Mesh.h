#pragma once
#include <GL/glew.h>
#include "graphics/VertexLayout.h"

namespace eng {
    /**
     * @class Mesh
     * @brief Represents 3D geometry stored on the GPU.
     */
    class Mesh {
    public:
        /**
         * @brief Constructs a mesh with vertex and index data.
         * @param layout The layout of the vertex data.
         * @param vertices The vertex data.
         * @param indices The index data.
         */
        Mesh(const VertexLayout &layout, const std::vector<float> &vertices, const std::vector<uint32_t> &indices);

        /**
         * @brief Constructs a mesh with only vertex data (for non-indexed rendering).
         * @param layout The layout of the vertex data.
         * @param vertices The vertex data.
         */
        Mesh(const VertexLayout &layout, const std::vector<float> &vertices);

        Mesh(const Mesh &) = delete;

        Mesh &operator=(const Mesh &) = delete;

        /**
         * @brief Binds the mesh buffers (VAO, VBO, EBO) for rendering.
         */
        void Bind();

        /**
         * @brief Executes the draw call for this mesh.
         */
        void Draw();

    private:
        VertexLayout m_vertexLayout;
        GLuint m_VBO = 0;
        GLuint m_EBO = 0;
        GLuint m_VAO = 0;

        size_t m_vertexCount = 0;
        size_t m_indexCount = 0;
    };
}
