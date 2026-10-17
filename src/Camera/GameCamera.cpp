//
// Created by sw1ssyy on 17/10/2026.
//

#include "GameCamera.h"

#include "../Constants/GameConstants.h"

void GameCamera::Init(const Vector2 target)
{
    _camera.target = target;
    _camera.offset = {GameConstants::SCREEN_WIDTH / 2, GameConstants::SCREEN_HEIGHT / 2};
    _camera.rotation = 0.0f;
    _camera.zoom = GameConstants::CAMERA_ZOOM_DEFAULT;
}

void GameCamera::Update(const Vector2 target, const bool aiming)
{
    _camera.zoom = aiming ? GameConstants::CAMERA_ZOOM_AIM : GameConstants::CAMERA_ZOOM_DEFAULT;
    _camera.target = target;
}

void GameCamera::Begin() const
{
    BeginMode2D(_camera);
}

void GameCamera::End() const
{
    EndMode2D();
}

void GameCamera::Shake() const
{
}

Vector2 GameCamera::ScreenToWorld(const Vector2 screenPos) const
{
    return GetScreenToWorld2D(screenPos, _camera);
}

Camera2D& GameCamera::Get()
{
    return _camera;
}
