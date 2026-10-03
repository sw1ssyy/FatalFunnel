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
        LoadAnimation(AssetConstants::ANIM_OPERATOR_NVG_EQUIPPED_IDLE_LOW, 24, GameConstants::FRAME_TIME_60, 5, 5),
        LoadAnimation(AssetConstants::ANIM_OPERATOR_NVG_EQUIPPED_IDLE, 24, GameConstants::FRAME_TIME_60, 5, 5),
        LoadAnimation(AssetConstants::ANIM_OPERATOR_NVG_EQUIPPED_FIRE_WITH_FLASH, 5, GameConstants::FRAME_TIME_120, 5, 1),
        LoadAnimation(AssetConstants::ANIM_OPERATOR_NVG_EQUIPPED_WALK_AIM, 24, GameConstants::FRAME_TIME_60, 5, 5),
        LoadAnimation(AssetConstants::ANIM_OPERATOR_NVG_EQUIPPED_RELOAD, 24, GameConstants::FRAME_TIME_60, 5, 5)))
{}

void GameState::Draw()
{
    ClearBackground(DARKGRAY);
    BeginMode2D(camera);
    character.Draw();
    DrawAimingLine();
    DrawText(std::to_string(character.GetCurrentAmmo()).c_str(), 20, 20, 60, RED);
    EndMode2D();
}

void GameState::Update()
{
    if (IsKeyPressed(KEY_LEFT_ALT))
    {
        stateManager->SetState(MENU);
    }

    InputManager::GetInstance().Poll();
    const PlayerInput& input = InputManager::GetInstance().Get();

    if (input.fire)
    {
        ShakeCamera();
    }

    const Vector2 worldMousePos = GetScreenToWorld2D(GetMousePosition(), camera);

    character.Update(input, worldMousePos);
}

void GameState::OnEnter()
{
    camera.target = {character.GetRect().x, character.GetRect().y};
    camera.offset = {};
    camera.rotation = 0.0f;
    camera.zoom = GameConstants::CAMERA_ZOOM_DEFAULT;

    character.SetPosition(400, 400);
}

void GameState::OnExit()
{
    TraceLog(LOG_INFO, "GameState: Exit");
}

void GameState::ShakeCamera() const
{
}

void GameState::DrawAimingLine() const
{
    if (!InputManager::GetInstance().Get().aim)
    {
        return;
    }

    const Vector2 worldMousePos = GetScreenToWorld2D(GetMousePosition(), camera);

    DrawLine(character.GetRect().x, character.GetRect().y, worldMousePos.x, worldMousePos.y, YELLOW);
}
