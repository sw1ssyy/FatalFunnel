//
// Created by sw1ssyy on 17/10/2026.
//

#include "TileMap.h"

#include <cmath>
#include <fstream>
#include <sstream>
#include <string>
#include "raylib.h"

TileMap::TileMap()
{
    LoadFromCsv("../resources/Map/map.csv");
}

bool TileMap::IsMoveAllowed(float x, float y)
{
    const int gridX = static_cast<int>(std::floor(x / 128));
    const int gridY = static_cast<int>(std::floor(y / 128));

    if (gridX < 0 || gridY < 0 || gridX >= _tileMaxSize || gridY >= _tileMaxSize)
    {
        return false;
    }

    return !IsSolid(gridX, gridY);
}

void TileMap::Draw()
{
    for (auto tile: _tiles)
    {
        tile.Draw();
    }
}

void TileMap::LoadFromCsv(const std::string &path)
{
    std::ifstream file(path);
    if (!file.is_open())
    {
        TraceLog(LOG_ERROR, "TileMap: could not open %s", path.c_str());
        return;
    }

    _tiles = {};

    std::string line = {};

    for (int row = 0; row < _tileMaxSize; row++)
    {
        std::getline(file, line);
        std::stringstream stream(line);
        std::string cell;

        for (int col = 0; col < _tileMaxSize; col++)
        {
            std::getline(stream, cell, ',');

            _tiles.emplace_back(std::stoi(cell), row, col);
        }
    }
}

bool TileMap::IsSolid(int x, int y)
{
    return _tiles.at(y * _tileMaxSize + x).IsSolid();
}
