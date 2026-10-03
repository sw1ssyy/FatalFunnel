//
// Created by johnc on 26/09/2026.
//

#ifndef TOPDOWNSHOOTER_GAMESTATE
#define TOPDOWNSHOOTER_GAMESTATE

#include "IState.h"
#include "../Characters/Character.h"

class GameState : public IState
{
public:
    explicit GameState(StateManager *manager);

    void Draw() override;
    void Update() override;
    void OnEnter() override;
    void OnExit() override;

    void ShakeCamera() const;
    void DrawAimingLine() const;

private:
    Character character;
    Camera2D camera = {};
};

#endif //TOPDOWNSHOOTER_GAMESTATE
