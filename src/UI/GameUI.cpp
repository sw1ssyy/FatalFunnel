//
// Created by sw1ssyy on 03/10/2026.
//

#include "GameUI.h"

#include <filesystem>
#include <string>

GameUI::GameUI(Camera2D &camera2D, Character& character) : _camera(&camera2D), _character(&character)
{
}

void GameUI::DrawAmmo()
{
    Vector2 position = GetScreenToWorld2D({20,20}, *_camera);

    DrawText(std::to_string(_character->GetCurrentAmmo()).c_str(),position.x, position.y , 60, RED);
}
