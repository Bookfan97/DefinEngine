#include "Game.h"
#include <eng.h>

int main()
{
    Game* game = new Game();
    eng::Engine& engine = eng::Engine::GetInstance();
    engine.SetApplication(game);

    static constexpr int WINDOW_WIDTH = 1280;
    static constexpr int WINDOW_HEIGHT = 720;

    if (engine.Init(WINDOW_WIDTH, WINDOW_HEIGHT))
    {
        engine.Run();
    }

    engine.Destroy();
    return 0;
}