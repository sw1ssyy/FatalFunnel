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

bool InputManager::IsPlayerMoving()
{
    Vector2 movement = GetPlayerMovementDirection();

    return movement.x == 1 || movement.x == -1 || movement.y == 1 || movement.y == -1;
}

bool InputManager::IsPlayerSprinting()const
{
    if (IsKeyDown(KEY_LEFT_SHIFT))
    {
        TraceLog(LOG_INFO, "Player Input: SPRINT");
    }


    return IsKeyDown(KEY_LEFT_SHIFT);
}

Vector2 InputManager::GetPlayerMovementDirection()
{
    movementVector = {0,0};

    if (IsKeyDown(KEY_A))
    {
        movementVector.x = -1;
    }
    if (IsKeyDown(KEY_D))
    {
        movementVector.x = 1;
    }
    if (IsKeyDown(KEY_W))
    {
        movementVector.y = -1;
    }
    if (IsKeyDown(KEY_S))
    {
        movementVector.y = 1;
    }

    return movementVector;
}
