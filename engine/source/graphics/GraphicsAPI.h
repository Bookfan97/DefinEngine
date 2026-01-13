#pragma once
#include <memory>
#include <string>
#include <vector>
#include <GL/glew.h>

namespace eng {
    class ShaderProgram;
    class Material;
    class Mesh;

    /**
     * @class GraphicsAPI
     * @brief Interface for interacting with the graphics hardware.
     * 
     * This class provides abstraction over OpenGL calls, allowing for
     * resource creation, binding, and drawing.
     */
    class GraphicsAPI {
    public:
        /**
         * @brief Creates a shader program from vertex and fragment source.
         * @param vertexSource The source code for the vertex shader.
         * @param fragmentSource The source code for the fragment shader.
         * @return A shared pointer to the created ShaderProgram.
         */
        std::shared_ptr<ShaderProgram> CreateShaderProgram(const std::string &vertexSource,
                                                           const std::string &fragmentSource);

        /**
         * @brief Creates a vertex buffer on the GPU.
         * @param vertices The list of vertex data.
         * @return The OpenGL ID of the created buffer.
         */
        GLuint CreateVertexBuffer(const std::vector<float> &vertices);

        /**
         * @brief Creates an index buffer on the GPU.
         * @param indices The list of index data.
         * @return The OpenGL ID of the created buffer.
         */
        GLuint CreateIndexBuffer(const std::vector<uint32_t> &indices);

        /**
         * @brief Sets the clear color for the frame buffer.
         */
        void SetClearColor(float r, float g, float b, float a);

        /**
         * @brief Clears the color and depth buffers.
         */
        void ClearBuffers();

        /**
         * @brief Binds a shader program for use.
         * @param shaderProgram The shader program to bind.
         */
        void BindShaderProgram(ShaderProgram *shaderProgram);

        /**
         * @brief Binds a material and its parameters for use.
         * @param material The material to bind.
         */
        void BindMaterial(Material *material);

        /**
         * @brief Binds a mesh's data for use.
         * @param mesh The mesh to bind.
         */
        void BindMesh(Mesh *mesh);

        /**
         * @brief Executes a draw call for a mesh.
         * @param mesh The mesh to draw.
         */
        void DrawMesh(Mesh *mesh);
    };
}
