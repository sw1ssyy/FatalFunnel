//
// Created by sw1ssyy on 17/10/2026.
//

#include "GameCamera.h"

#include "../Constants/GameConstants.h"

void GameCamera::Init(const Vector2 target)
{
    camera.target = target;
    camera.offset = {GameConstants::SCREEN_WIDTH / 2, GameConstants::SCREEN_HEIGHT / 2};
    camera.rotation = 0.0f;
    camera.zoom = GameConstants::CAMERA_ZOOM_DEFAULT;
}

void GameCamera::Update(const Vector2 target, const bool aiming)
{
    camera.zoom = aiming ? GameConstants::CAMERA_ZOOM_AIM : GameConstants::CAMERA_ZOOM_DEFAULT;
    camera.target = target;
}

void GameCamera::Begin() const
{
    BeginMode2D(camera);
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
    return GetScreenToWorld2D(screenPos, camera);
}

Camera2D& GameCamera::Get()
{
    return camera;
}
