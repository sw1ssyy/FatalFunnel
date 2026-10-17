//
// Created by sw1ssyy on 17/10/2026.
//

#ifndef TOPDOWNSHOOTER_TILEMAP
#define TOPDOWNSHOOTER_TILEMAP

#include <string>
#include <vector>

#include "Tiles.h"

class TileMap
{
public:
    TileMap();

    bool IsMoveAllowed(float x, float y);

    void Draw();

private:
    std::vector<Tiles> _tiles;

    void LoadFromCsv(const std::string& path);

    bool IsSolid(int x, int y);

    const int _tileMaxSize = 10;
};


#endif //TOPDOWNSHOOTER_TILEMAP
