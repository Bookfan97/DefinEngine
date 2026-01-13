#pragma once
#include <memory>
#include <unordered_map>
#include <string>

namespace eng {
    class ShaderProgram;

    /**
     * @class Material
     * @brief Defines the visual properties of a surface.
     * 
     * A material consists of a shader program and a set of parameters
     * (uniforms) that are passed to the shader.
     */
    class Material {
    public:
        /**
         * @brief Sets the shader program used by this material.
         * @param shaderProgram A shared pointer to the ShaderProgram.
         */
        void SetShaderProgram(const std::shared_ptr<ShaderProgram> &shaderProgram);

        /**
         * @brief Sets a float parameter for the material.
         * @param name The name of the uniform in the shader.
         * @param value The value to set.
         */
        void SetParam(const std::string &name, float value);

        /**
         * @brief Sets a 2-component float parameter for the material.
         * @param name The name of the uniform in the shader.
         * @param v0 First component.
         * @param v1 Second component.
         */
        void SetParam(const std::string &name, float v0, float v1);

        /**
         * @brief Binds the material (shader and parameters) for rendering.
         */
        void Bind();

    private:
        std::shared_ptr<ShaderProgram> m_shaderProgram;
        std::unordered_map<std::string, float> m_floatParams;
        std::unordered_map<std::string, std::pair<float, float> > m_float2Params;
    };
}
