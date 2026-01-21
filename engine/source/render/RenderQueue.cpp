#include "render/RenderQueue.h"
#include "render/Mesh.h"
#include "render/Material.h"
#include "graphics/GraphicsAPI.h"
#include "graphics/ShaderProgram.h"

namespace eng
{
    void RenderQueue::Submit(const RenderCommand& command)
    {
        m_commands.push_back(command);
    }

    void RenderQueue::Draw(GraphicsAPI& graphicsAPI, const CameraData& cameraData)
    {
        for (auto& command : m_commands)
        {
            if (command.material && command.mesh)
            {
                graphicsAPI.BindMaterial(command.material.get());
                auto shaderProgram = command.material->GetShaderProgram();
                shaderProgram->SetUniform("uModel", command.modelMatrix);
                shaderProgram->SetUniform("uView", cameraData.viewMatrix);
                shaderProgram->SetUniform("uProjection", cameraData.projectionMatrix);
                graphicsAPI.BindMesh(command.mesh.get());
                graphicsAPI.DrawMesh(command.mesh.get());
            }
        }

        m_commands.clear();
    }
}