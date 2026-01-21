#pragma once
#include <GL/glew.h>
#include <glm/mat4x4.hpp>
#include <string>
#include <unordered_map>

namespace eng
{
/**
 * @class ShaderProgram
 * @brief Manages an OpenGL shader program, including uniforms and binding.
 */
class ShaderProgram
{
  public:
    ShaderProgram() = delete;
    ShaderProgram(const ShaderProgram &) = delete;
    ShaderProgram &operator=(const ShaderProgram &) = delete;

    /**
     * @brief Constructs a ShaderProgram with an existing OpenGL shader program ID.
     * @param shaderProgramID The OpenGL ID of the shader program.
     */
    explicit ShaderProgram(GLuint shaderProgramID);

    /**
     * @brief Destructor. Deletes the OpenGL shader program.
     */
    ~ShaderProgram();

    /**
     * @brief Binds the shader program for rendering.
     */
    void Bind() const;

    /**
     * @brief Gets the location of a uniform variable.
     * @param name The name of the uniform variable.
     * @return The location of the uniform, or -1 if not found.
     */
    GLint GetUniformLocation(const std::string &name);

    /**
     * @brief Sets a float uniform.
     * @param name The name of the uniform.
     * @param value The value to set.
     */
    void SetUniform(const std::string &name, float value);

    /**
     * @brief Sets a vec2 uniform (two floats).
     * @param name The name of the uniform.
     * @param v0 The first component.
     * @param v1 The second component.
     */
    void SetUniform(const std::string &name, float v0, float v1);

    /**
     * @brief Sets a mat4 uniform.
     * @param name The name of the uniform.
     * @param mat The 4x4 matrix to set.
     */
    void SetUniform(const std::string &name, const glm::mat4 &mat);

  private:
    std::unordered_map<std::string, GLint> m_uniformLocationCache; ///< Cache for uniform locations.
    GLuint m_shaderProgramID = 0;                                  ///< The OpenGL ID of the shader program.
};
} // namespace eng