//
// Created by sw1ssyy on 28/09/2026.
//

#ifndef TOPDOWNSHOOTER_INPUTMANAGER
#define TOPDOWNSHOOTER_INPUTMANAGER
#include "raylib.h"

// Snapshot of everything the player is asking for this frame.
struct PlayerInput
{
    Vector2 move = {};      // normalized movement direction, (0,0) when idle
    bool aim = false;
    bool fire = false;      // only true while aiming
    bool reload = false;    // true only on the frame the key is pressed
    bool sprint = false;
};

class InputManager
{
public:
    static InputManager& GetInstance() {
        static InputManager instance;
        return instance;
    }

    // Reads the hardware once. Call exactly once per frame before consuming input.
    void Poll();

    const PlayerInput& Get() const;

private:
    PlayerInput input;

    InputManager() = default;
    ~InputManager() = default;

    // Delete copy/move semantics
    InputManager(const InputManager&) = delete;
    InputManager(InputManager&&) = delete;
    InputManager& operator=(const InputManager&) = delete;
    InputManager& operator=(InputManager&&) = delete;
};


#endif //TOPDOWNSHOOTER_INPUTMANAGER
