//
// Created by sw1ssyy on 26/09/2026.
//

#ifndef TOPDOWNSHOOTER_GAMESTATE
#define TOPDOWNSHOOTER_GAMESTATE

#include "IState.h"
#include "../Camera/GameCamera.h"
#include "../Characters/Character.h"
#include "../Map/TileMap.h"
#include "../UI/GameUI.h"
#include "../vision/VisionCone.h"

class GameState : public IState
{
public:
    explicit GameState(StateManager *manager);

    void Draw() override;

    void Update() override;

    void OnEnter() override;

    void OnExit() override;

    void DrawAimingLine() const;

private:
    Character _character;

    GameUI _ui;

    GameCamera _camera;

    TileMap _map;
};

#endif //TOPDOWNSHOOTER_GAMESTATE
