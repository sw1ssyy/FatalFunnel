//
// Created by sw1ssyy on 17/10/2026.
//

#include "Tiles.h"

#include "raylib.h"
#include "../Constants/AssetConstants.h"
#include "../Utils/TextureManager.h"

Tiles::Tiles(int type, int row, int column) : _type(static_cast<TileTypes>(type)), _row(row), _column(column)
{
    SetupTile();
}

void Tiles::SetupTile()
{
    switch (_type)
    {
        case BRICK:
            _textureRect = {0,0,128,128};
            break;
        case GRASS:
            _textureRect = {128,0,128,128};
            break;
        case PAVEMENT:
            _textureRect = {256,0,128,128};
            break;
    }

    _positonRect = {static_cast<float>(_column * 128), static_cast<float>(_row * 128), 128,128};
}

bool Tiles::IsSolid() const
{
    return _type == BRICK;
}

TileTypes Tiles::GetTileType() const
{
    return _type;
}

void Tiles::Draw()
{
    DrawTexturePro(TextureManager::GetInstance().Get(AssetConstants::MAP_TILESET), _textureRect, _positonRect,{0,0},0,WHITE);
}
