#pragma once
#include <GL/glew.h>
#include "graphics/VertexLayout.h"

namespace eng
{
namespace eng
 {
+    /**
+     * @class Mesh
+     * @brief Represents a 3D geometry consisting of vertices and optional indices.
+     */
     class Mesh
     {
     public:
+        /**
+         * @brief Constructs a mesh from vertex and index data.
+         * @param layout The layout of the vertices.
+         * @param vertices The vertex data.
+         * @param indices The index data.
+         */
         Mesh(const VertexLayout& layout, const std::vector<float>& vertices, const std::vector<uint32_t>& indices);
+
+        /**
+         * @brief Constructs a mesh from vertex data only.
+         * @param layout The layout of the vertices.
+         * @param vertices The vertex data.
+         */
         Mesh(const VertexLayout& layout, const std::vector<float>& vertices);
+
         Mesh(const Mesh&) = delete;
         Mesh& operator=(const Mesh&) = delete;
 
+        /**
+         * @brief Binds the mesh's VAO for rendering.
+         */
         void Bind();
+
+        /**
+         * @brief Draws the mesh using glDrawElements or glDrawArrays.
+         */
         void Draw();
 
     private:
-        VertexLayout m_vertexLayout;
-        GLuint m_VBO = 0;
-        GLuint m_EBO = 0;
-        GLuint m_VAO = 0;
-
-        size_t m_vertexCount = 0;
-        size_t m_indexCount = 0;
+        VertexLayout m_vertexLayout; ///< The layout information for the vertices.
+        GLuint m_VBO = 0; ///< Vertex Buffer Object ID.
+        GLuint m_EBO = 0; ///< Element Buffer Object ID.
+        GLuint m_VAO = 0; ///< Vertex Array Object ID.
+
+        size_t m_vertexCount = 0; ///< Number of vertices in the mesh.
+        size_t m_indexCount = 0; ///< Number of indices in the mesh.
     };
 }

}