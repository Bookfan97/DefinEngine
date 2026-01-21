#pragma once
#include <memory>
#include <unordered_map>
#include <string>

namespace eng
{
    class ShaderProgram;

    /**
     * @class Material
     * @brief Represents a surface's visual properties, including shader and parameters.
     */
    class Material
    {
    public:
        /**
         * @brief Sets the shader program used by this material.
         * @param shaderProgram Shared pointer to the shader program.
         */
        void SetShaderProgram(const std::shared_ptr<ShaderProgram>& shaderProgram);

        /**
         * @brief Gets the shader program used by this material.
         * @return Pointer to the shader program.
         */
        ShaderProgram* GetShaderProgram();

        /**
         * @brief Sets a float parameter (uniform) for the material.
         * @param name The name of the parameter.
         * @param value The value to set.
         */
        void SetParam(const std::string& name, float value);

        /**
         * @brief Sets a vec2 parameter (two floats) for the material.
         * @param name The name of the parameter.
         * @param v0 The first component.
         * @param v1 The second component.
         */
        void SetParam(const std::string& name, float v0, float v1);

        /**
         * @brief Binds the material (shader and parameters) for rendering.
         */
        void Bind();

    private:
        std::shared_ptr<ShaderProgram> m_shaderProgram; ///< The shader program linked to this material.
        std::unordered_map<std::string, float> m_floatParams; ///< Cached float parameters.
        std::unordered_map<std::string, std::pair<float, float>> m_float2Params; ///< Cached vec2 parameters.
    };
} // namespace eng