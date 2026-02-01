#pragma once
#include <eng.h>
#include <memory>

class Game : public eng::Application
{
  public:
    /**
     * @brief Initializes the game.
     * @return true if initialization was successful, false otherwise.
     */
    bool Init() override;
    void Update(float deltaTime) override;
    void Destroy() override;

private:
    eng::Scene* m_scene = nullptr;
};