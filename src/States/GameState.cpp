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


GameState::GameState(StateManager *manager)
    : IState(manager)
    , _character(CharacterAnimations(
        Animation2D(AssetConstants::ANIM_OPERATOR_NVG_EQUIPPED_IDLE_LOW, 30, GameConstants::FRAME_TIME_60, 6  , 5),
        Animation2D(AssetConstants::ANIM_OPERATOR_NVG_EQUIPPED_IDLE, 30, GameConstants::FRAME_TIME_60, 6, 5),
        Animation2D(AssetConstants::ANIM_OPERATOR_NVG_EQUIPPED_FIRE_WITH_FLASH, 30, GameConstants::FRAME_TIME_240, 6, 5),
        Animation2D(AssetConstants::ANIM_OPERATOR_NVG_EQUIPPED_RELOAD, 30, GameConstants::FRAME_TIME_60, 6, 5)
        )),
    _ui(_character)
{}

void GameState::Draw()
{
    ClearBackground(BLACK);
    _camera.Begin();
    _map.Draw();
    _character.Draw();
    DrawAimingLine();
    _camera.End();
}

void GameState::Update()
{
    InputManager::GetInstance().Poll();
    const PlayerInput &input = InputManager::GetInstance().Get();

    const Vector2 worldMousePos = _camera.ScreenToWorld(GetMousePosition());

    _character.Update(input, worldMousePos, _map);

    _camera.Update({_character.GetRect().x, _character.GetRect().y}, input.aim);
}

void GameState::OnEnter()
{
    _character.SetPosition(170, 850);

    _camera.Init({_character.GetRect().x, _character.GetRect().y});
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

    const Vector2 worldMousePos = _camera.ScreenToWorld(GetMousePosition());

    DrawLineV(_character.GetBodyCenter(), worldMousePos, YELLOW);
}
