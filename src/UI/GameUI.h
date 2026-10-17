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
    explicit GameUI(Character& character);

    void DrawAmmo();

private:
    Character* _character;

    const int UI_DEFAULT_FONT_SIZE = 60;
};


#endif //TOPDOWNSHOOTER_GAMEUI
