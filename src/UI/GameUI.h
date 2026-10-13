//
// Created by sw1ssyy on 03/10/2026.
//

#ifndef TOPDOWNSHOOTER_GAMEUI
#define TOPDOWNSHOOTER_GAMEUI
#include "raylib.h"
#include "../Characters/Character.h"


class GameUI
{

public:
    GameUI(Camera2D& camera2D, Character& character);

    void DrawAmmo();

private:
    Character* _character;
    Camera2D* _camera;
};


#endif //TOPDOWNSHOOTER_GAMEUI
