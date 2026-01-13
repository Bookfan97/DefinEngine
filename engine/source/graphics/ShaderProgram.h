#pragma once
#include <string>
#include <unordered_map>
#include <GL/glew.h>

namespace eng {
    /**
     * @class ShaderProgram
     * @brief Represents a compiled and linked shader program on the GPU.
     */
    class ShaderProgram {
    public:
        ShaderProgram() = delete;

        ShaderProgram(const ShaderProgram &) = delete;

        ShaderProgram &operator=(const ShaderProgram &) = delete;

        /**
         * @brief Constructs a ShaderProgram with an existing OpenGL shader program ID.
         * @param shaderProgramID The ID of the linked shader program.
         */
        explicit ShaderProgram(GLuint shaderProgramID);

        /**
         * @brief Destructor that deletes the shader program from the GPU.
         */
        ~ShaderProgram();

        /**
         * @brief Binds this shader program for use in the current rendering state.
         */
        void Bind();

        /**
         * @brief Retrieves the location of a uniform variable.
         * @param name The name of the uniform variable.
         * @return The location of the uniform, or -1 if not found.
         */
        GLint GetUniformLocation(const std::string &name);

        /**
         * @brief Sets a float uniform value.
         * @param name The name of the uniform.
         * @param value The value to set.
         */
        void SetUniform(const std::string &name, float value);

        /**
         * @brief Sets a 2-component float uniform value.
         * @param name The name of the uniform.
         * @param v0 First component.
         * @param v1 Second component.
         */
        void SetUniform(const std::string &name, float v0, float v1);

    private:
        std::unordered_map<std::string, GLint> m_uniformLocationCache;
        GLuint m_shaderProgramID = 0;
    };
}
