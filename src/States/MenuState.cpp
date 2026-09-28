//
// Created by sw1ssyy on 26/09/2026.
//

#include "MenuState.h"
#include "raylib.h"
#include "StateManager.h"
#include "../Constants/AssetConstants.h"
#include "../Constants/GameConstants.h"
#include "../Utils/FontManager.h"

void MenuState::Draw()
{
    DrawTextEx(FontManager::GetInstance().Get(AssetConstants::FONT_MAIN), GameConstants::GAME_NAME, {260,50}, 72,0, WHITE);

    startButton.Draw();
    helpButton.Draw();
    exitButton.Draw();
}

void MenuState::Update()
{

    if (startButton.IsClicked())
    {
        stateManager->SetState(GAME);
    }
    else if (exitButton.IsClicked())
    {
        stateManager->RequestQuit();
    }
}

void MenuState::OnEnter()
{
    TraceLog(LOG_INFO, "MenuState: Enter");
}

void MenuState::OnExit()
{
    TraceLog(LOG_INFO, "MenuState: Exit");
}
