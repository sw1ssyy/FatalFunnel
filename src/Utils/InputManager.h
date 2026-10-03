//
// Created by sw1ssyy on 28/09/2026.
//

#ifndef TOPDOWNSHOOTER_INPUTMANAGER
#define TOPDOWNSHOOTER_INPUTMANAGER
#include "raylib.h"


class InputManager
{
public:
    static InputManager& GetInstance() {
        static InputManager instance;
        return instance;
    }

    bool IsAimHeld() const;

    bool IsShooting() const;

    bool IsReloading() const;

    bool IsShotFired() const;

    bool IsPlayerMoving();

    bool IsPlayerSprinting()const;

    Vector2 GetPlayerMovementDirection();


private:
    Vector2 movementVector = {};

    InputManager() = default;
    ~InputManager() = default;

    // Delete copy/move semantics
    InputManager(const InputManager&) = delete;
    InputManager(InputManager&&) = delete;
    InputManager& operator=(const InputManager&) = delete;
    InputManager& operator=(InputManager&&) = delete;
};


#endif //TOPDOWNSHOOTER_INPUTMANAGER
