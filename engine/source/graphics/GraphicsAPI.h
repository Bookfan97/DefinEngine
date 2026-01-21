#pragma once
#include <memory>
#include <string>
#include <vector>
#include <GL/glew.h>

namespace eng
{
    class ShaderProgram;
    class Material;
    class Mesh;

    /**
     * @class GraphicsAPI
     * @brief Interface for graphics operations and resource management.
     */
    class GraphicsAPI
    {
    public:
        /**
         * @brief Initializes the graphics API (e.g., GLEW).
         */
        void Init();

        /**
         * @brief Creates a shader program from vertex and fragment shader sources.
         * @param vertexSource The source code of the vertex shader.
         * @param fragmentSource The source code of the fragment shader.
         * @return A shared pointer to the created ShaderProgram.
         */
        std::shared_ptr<ShaderProgram> CreateShaderProgram(const std::string& vertexSource, 
            const std::string& fragmentSource);

        /**
         * @brief Creates a vertex buffer on the GPU.
         * @param vertices The vertex data.
         * @return The OpenGL ID of the created vertex buffer.
         */
        GLuint CreateVertexBuffer(const std::vector<float>& vertices);

        /**
         * @brief Creates an index buffer on the GPU.
         * @param indices The index data.
         * @return The OpenGL ID of the created index buffer.
         */
        GLuint CreateIndexBuffer(const std::vector<uint32_t>& indices);

        /**
         * @brief Sets the clear color for the frame buffers.
         * @param r Red component (0.0 to 1.0).
         * @param g Green component (0.0 to 1.0).
         * @param b Blue component (0.0 to 1.0).
         * @param a Alpha component (0.0 to 1.0).
         */
        void SetClearColor(float r, float g, float b, float a);

        /**
         * @brief Clears the color and depth buffers.
         */
        void ClearBuffers();

        /**
         * @brief Binds a shader program for use in rendering.
         * @param shaderProgram Pointer to the shader program to bind.
         */
        void BindShaderProgram(ShaderProgram* shaderProgram);

        /**
         * @brief Binds a material for use in rendering.
         * @param material Pointer to the material to bind.
         */
        void BindMaterial(Material* material);

        /**
         * @brief Binds a mesh's buffers and layout for rendering.
         * @param mesh Pointer to the mesh to bind.
         */
        void BindMesh(Mesh* mesh);

        /**
         * @brief Draws a mesh using its index buffer.
         * @param mesh Pointer to the mesh to draw.
         */
        void DrawMesh(Mesh* mesh);
    };
} // namespace eng