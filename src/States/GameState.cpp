//
// Created by sw1ssyy on 26/09/2026.
//

#include "GameState.h"

#include <string>

#include "raylib.h"
#include "StateManager.h"
#include "../Constants/AssetConstants.h"
#include "../Constants/GameConstants.h"
#include "../Utils/InputManager.h"
#include "../Utils/TextureManager.h"

namespace
{
    Animation2D LoadAnimation(const char* assetId, const int frames, const float tickRate, const int columns,
                              const int rows)
    {
        return Animation2D(&TextureManager::GetInstance().Get(assetId), frames, tickRate, columns, rows);
    }
}

GameState::GameState(StateManager *manager)
    : IState(manager)
    , character(CharacterAnimations(
        LoadAnimation(AssetConstants::ANIM_OPERATOR_NVG_EQUIPPED_IDLE_LOW, 30, GameConstants::FRAME_TIME_60, 6, 5),
        LoadAnimation(AssetConstants::ANIM_OPERATOR_NVG_EQUIPPED_IDLE, 30, GameConstants::FRAME_TIME_60, 6, 5),
        LoadAnimation(AssetConstants::ANIM_OPERATOR_NVG_EQUIPPED_FIRE_WITH_FLASH, 30, GameConstants::FRAME_TIME_240, 6, 5),
        LoadAnimation(AssetConstants::ANIM_OPERATOR_NVG_EQUIPPED_WALK_AIM, 30, GameConstants::FRAME_TIME_60, 6, 5),
        LoadAnimation(AssetConstants::ANIM_OPERATOR_NVG_EQUIPPED_RELOAD, 30, GameConstants::FRAME_TIME_60, 6, 5)))
{}

void GameState::Draw()
{
    ClearBackground(DARKGRAY);
    camera.Begin();
    character.Draw();
    DrawAimingLine();
    camera.End();
    ui.DrawAmmo();
}

void GameState::Update()
{
    if (IsKeyPressed(KEY_LEFT_ALT))
    {
        stateManager->SetState(MENU);
    }

    InputManager::GetInstance().Poll();
    const PlayerInput& input = InputManager::GetInstance().Get();

    camera.Update(camera.Get().target, input.aim);

    const Vector2 worldMousePos = camera.ScreenToWorld(GetMousePosition());

    character.Update(input, worldMousePos);

    camera.Update({character.GetRect().x, character.GetRect().y}, input.aim);
}

void GameState::OnEnter()
{
    character.SetPosition(400, 1600);

    camera.Init({character.GetRect().x, character.GetRect().y});
}

void GameState::OnExit()
{
    TraceLog(LOG_INFO, "GameState: Exit");
}

void GameState::DrawAimingLine() const
{
    if (!InputManager::GetInstance().Get().aim)
    {
        return;
    }

    const Vector2 worldMousePos = camera.ScreenToWorld(GetMousePosition());

    DrawLine(character.GetRect().x + + GameConstants::CHARACTER_WIDTH / 2, character.GetRect().y + + GameConstants::CHARACTER_HEIGHT / 2, worldMousePos.x, worldMousePos.y, YELLOW);
}
