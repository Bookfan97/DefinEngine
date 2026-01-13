#pragma once
#include <GL/glew.h>
#include <vector>
#include <stdint.h>

namespace eng {
    /**
     * @struct VertexElement
     * @brief Describes a single attribute in a vertex (e.g., position, color).
     */
    struct VertexElement {
        GLuint index;    ///< Attribute location in the shader.
        GLuint size;     ///< Number of components (e.g., 3 for RGB).
        GLuint type;     ///< Data type (e.g., GL_FLOAT).
        uint32_t offset; ///< Byte offset from the start of the vertex.
    };

    /**
     * @struct VertexLayout
     * @brief Describes the memory layout of a vertex.
     */
    struct VertexLayout {
        std::vector<VertexElement> elements; ///< List of elements in the layout.
        uint32_t stride = 0;                 ///< Total size of a single vertex in bytes.
    };
}
