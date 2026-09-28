//
// Created by sw1ssyy on 28/09/2026.
//

#include "InputManager.h"

bool InputManager::IsAimHeld() const
{
    return IsMouseButtonDown(MOUSE_BUTTON_RIGHT);
}

bool InputManager::IsShooting()const
{
    return IsAimHeld() && IsMouseButtonDown(MOUSE_BUTTON_LEFT);
}

bool InputManager::IsPlayerMoving() const
{
    return movementVector.x == 1 || movementVector.x == -1 || movementVector.y == 1 || movementVector.y == -1;
}

Vector2 InputManager::GetPlayerMovementDirection()
{
    if (IsKeyDown(KEY_A))
    {
        TraceLog(LOG_INFO, "Player Input: LEFT");

        movementVector.x = -1;
    }
    if (IsKeyDown(KEY_D))
    {
        TraceLog(LOG_INFO, "Player Input: RIGHT");

        movementVector.x = 1;
    }
    if (IsKeyDown(KEY_W))
    {
        TraceLog(LOG_INFO, "Player Input: UP");

        movementVector.y = -1;
    }
    if (IsKeyDown(KEY_S))
    {
        TraceLog(LOG_INFO, "Player Input: DOWN");

        movementVector.y = 1;
    }

    return movementVector;
}
