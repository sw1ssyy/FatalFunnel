//
// Created by sw1ssyy on 26/09/2026.
//

#include "GameState.h"
#include "raylib.h"
#include "StateManager.h"
#include "../Constants/AssetConstants.h"
#include "../Constants/GameConstants.h"
#include "../Utils/InputManager.h"


GameState::GameState(StateManager *manager)
    : IState(manager)
      , _player(CharacterAnimations(
          Animation2D(AssetConstants::ANIM_OPERATOR_NVG_EQUIPPED_IDLE_LOW, 30, GameConstants::FRAME_TIME_60, 6, 5),
          Animation2D(AssetConstants::ANIM_OPERATOR_NVG_EQUIPPED_IDLE, 30, GameConstants::FRAME_TIME_60, 6, 5),
          Animation2D(AssetConstants::ANIM_OPERATOR_NVG_EQUIPPED_FIRE_WITH_FLASH, 30, GameConstants::FRAME_TIME_240, 6,5),
          Animation2D(AssetConstants::ANIM_OPERATOR_NVG_EQUIPPED_RELOAD, 30, GameConstants::FRAME_TIME_60, 6, 5)
      )), _insurgent(CharacterAnimations(
      Animation2D(AssetConstants::ANIM_INSURGENT_IDLE_LOW, 30, GameConstants::FRAME_TIME_60, 6, 5),
Animation2D(AssetConstants::ANIM_INSURGENT_IDLE, 30, GameConstants::FRAME_TIME_60, 6, 5),
Animation2D(AssetConstants::ANIM_INSURGENT_FIRE_WITH_FLASH, 30, GameConstants::FRAME_TIME_240, 6,5),
Animation2D(AssetConstants::ANIM_INSURGENT_RELOAD, 30, GameConstants::FRAME_TIME_60, 6, 5)
          )),
      _ui(_player)
{
}

void GameState::Draw()
{
    ClearBackground(BLACK);
    _camera.Begin();
    _map.Draw();
    _player.Draw();
    _insurgent.Draw();
    DrawAimingLine();
    _camera.End();
}

void GameState::Update()
{
    InputManager::GetInstance().Poll();
    const PlayerInput &input = InputManager::GetInstance().Get();

    const Vector2 worldMousePos = _camera.ScreenToWorld(GetMousePosition());

    _player.Update(input, worldMousePos, _map);

    _insurgent.Update();

    _camera.Update({_player.GetRect().x, _player.GetRect().y}, input.aim);
}

void GameState::OnEnter()
{
    _player.SetPosition(170, 850);

    _insurgent.SetPosition(1200, 400);

    _camera.Init({_player.GetRect().x, _player.GetRect().y});
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

    DrawLineV(_player.GetBodyCenter(), worldMousePos, YELLOW);
}
