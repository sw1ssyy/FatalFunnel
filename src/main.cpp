//
// Created by sw1ssyy on 28/09/2026.
//
#include "raylib.h"
#include "Constants/GameConstants.h"
#include "States/StateManager.h"
#include "Utils/TextureManager.h"
#include "Utils/FontManager.h"
#include "Utils/SoundManager.h"

int main()
{
    InitWindow(GameConstants::SCREEN_WIDTH, GameConstants::SCREEN_HEIGHT, GameConstants::GAME_NAME);
    InitAudioDevice();
    SetTargetFPS(60);

    TextureManager::GetInstance().LoadAll();
    FontManager::GetInstance().LoadAll();
    SoundManager::GetInstance().LoadAll();

    StateManager stateManager = {};

    stateManager.Init();

    while (!WindowShouldClose() && !stateManager.ShouldQuit())
    {
        stateManager.GetCurrentState().Update();
        BeginDrawing();
        stateManager.GetCurrentState().Draw();
        EndDrawing();
    }
    TextureManager::GetInstance().UnloadAll();
    FontManager::GetInstance().UnloadAll();
    SoundManager::GetInstance().UnloadAll();
    CloseAudioDevice();
    CloseWindow();
    return 0;
}

