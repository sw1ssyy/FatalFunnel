//
// Created by sw1ssyy on 28/09/2026.
//

#include "InputManager.h"

#include <cmath>

void InputManager::Poll()
{
    input.aim = IsMouseButtonDown(MOUSE_BUTTON_RIGHT);
    input.fire = input.aim && IsMouseButtonDown(MOUSE_BUTTON_LEFT);
    input.reload = IsKeyPressed(KEY_R);
    input.sprint = IsKeyDown(KEY_LEFT_SHIFT);

    Vector2 move = {
        static_cast<float>(IsKeyDown(KEY_D)) - static_cast<float>(IsKeyDown(KEY_A)),
        static_cast<float>(IsKeyDown(KEY_S)) - static_cast<float>(IsKeyDown(KEY_W))
    };

    // Normalize so diagonals aren't faster than cardinal movement.
    const float length = std::sqrt(move.x * move.x + move.y * move.y);
    if (length > 0.0f)
    {
        move.x /= length;
        move.y /= length;
    }
    input.move = move;
}

const PlayerInput& InputManager::Get() const
{
    return input;
}
