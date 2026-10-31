//
// Created by sw1ssyy on 03/10/2026.
//

#include "GameUI.h"

#include <filesystem>
#include <string>

GameUI::GameUI(Player& player) : _player(&player)
{
}

void GameUI::DrawAmmo()
{
    DrawText(std::to_string(_player->GetCurrentAmmo()).c_str(), 20, 20, UI_DEFAULT_FONT_SIZE , RED);
}
