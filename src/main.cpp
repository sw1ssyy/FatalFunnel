//
// Created by sw1ssyy on 28/09/2026.
//
#include "raylib.h"
#include "Constants/GameConstants.h"
#include "States/StateManager.h"
#include "Utils/TextureManager.h"
#include "Utils/FontManager.h"

int main()
{
    InitWindow(GameConstants::SCREEN_WIDTH, GameConstants::SCREEN_HEIGHT, GameConstants::GAME_NAME);
    SetTargetFPS(60);

    TextureManager::GetInstance().LoadAll();
    FontManager::GetInstance().LoadAll();

    StateManager stateManager = {};

    stateManager.SetState(MENU);


    while (!WindowShouldClose() && !stateManager.ShouldQuit())
    {
        BeginDrawing();
        ClearBackground(DARKGREEN);
        stateManager.GetCurrentState().Draw();
        stateManager.GetCurrentState().Update();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}

