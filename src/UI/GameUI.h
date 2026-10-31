//
// Created by sw1ssyy on 03/10/2026.
//

#ifndef TOPDOWNSHOOTER_GAMEUI
#define TOPDOWNSHOOTER_GAMEUI
#include "raylib.h"
#include "../Characters/Player.h"


class GameUI
{
public:
    explicit GameUI(Player& player);

    void DrawAmmo();

private:
    Player* _player;

    const int UI_DEFAULT_FONT_SIZE = 60;
};


#endif //TOPDOWNSHOOTER_GAMEUI
