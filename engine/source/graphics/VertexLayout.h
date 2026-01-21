#pragma once
#include <GL/glew.h>
#include <vector>
#include <stdint.h>

namespace eng
{
    /**
     * @struct VertexElement
     * @brief Describes a single element of a vertex (e.g., position, color).
     */
    struct VertexElement
    {
        GLuint index; ///< Attribute location in the shader.
        GLuint size; ///< Number of components (1, 2, 3, or 4).
        GLuint type; ///< Data type (e.g., GL_FLOAT).
        uint32_t offset; ///< Byte offset from the start of the vertex.
    };

    /**
     * @struct VertexLayout
     * @brief Describes the layout of a full vertex in a buffer.
     */
    struct VertexLayout
    {
        std::vector<VertexElement> elements; ///< List of vertex elements.
        uint32_t stride = 0; ///< Total size of a single vertex in bytes.
    };
}