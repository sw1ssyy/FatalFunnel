//
// Created by sw1ssyy on 26/09/2026.
//

#include "GameState.h"
#include "raylib.h"
#include "StateManager.h"
#include "../Constants/AssetConstants.h"
#include "../Constants/GameConstants.h"
#include "../Utils/InputManager.h"
#include "../Utils/TextureManager.h"

GameState::GameState(StateManager *manager)
    : IState(manager)
    , character(CharacterAnimations(
    Animation2D(&TextureManager::GetInstance().Get(AssetConstants::ANIM_OPERATOR_NVG_EQUIPPED_IDLE_LOW), 24, GameConstants::FRAME_TIME_60, 5, 5),
        Animation2D(&TextureManager::GetInstance().Get(AssetConstants::ANIM_OPERATOR_NVG_EQUIPPED_IDLE), 24, GameConstants::FRAME_TIME_60, 5, 5),
        Animation2D(&TextureManager::GetInstance().Get(AssetConstants::ANIM_OPERATOR_NVG_EQUIPPED_FIRE_WITH_FLASH), 24, GameConstants::FRAME_TIME_60, 5, 1),
        Animation2D(&TextureManager::GetInstance().Get(AssetConstants::ANIM_OPERATOR_NVG_EQUIPPED_WALK_AIM), 24, GameConstants::FRAME_TIME_60, 5, 5),
        Animation2D(&TextureManager::GetInstance().Get(AssetConstants::ANIM_OPERATOR_NVG_EQUIPPED_RELOAD), 24, GameConstants::FRAME_TIME_120, 5, 5)
        ))
{}

void GameState::Draw()
{
    ClearBackground(DARKGRAY);
    BeginMode2D(camera);
    character.Draw();
    DrawAimingLine();
    DrawText(std::to_string(character.GetCurrentAmmo()).c_str(), 20,20,60,RED);
    EndMode2D();
}

void GameState::Update()
{
    if (IsKeyPressed(KEY_LEFT_ALT))
    {
        stateManager->SetState(MENU);
    }

    if (InputManager::GetInstance().IsShooting())
    {
        ShakeCamera();
    }

    Vector2 worldMousePos = GetScreenToWorld2D(GetMousePosition(), camera);

    character.Update(worldMousePos);
}

void GameState::OnEnter()
{
    camera.target = {character.GetRect().x, character.GetRect().y};
    camera.offset = {};
    camera.rotation = 0.0f;
    camera.zoom = 0.4f;

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
    if (InputManager::GetInstance().IsAimHeld())
    {
        Vector2 worldMousePos = GetScreenToWorld2D(GetMousePosition(), camera);

        DrawLine(character.GetRect().x, character.GetRect().y, worldMousePos.x, worldMousePos.y, YELLOW);
    }
}
